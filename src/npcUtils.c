#include "global.h"
#include "asm.h"
#include "entity.h"
#include "functions.h"
#include "definitions.h"
#include "save.h"
#include "npc.h"

extern const NPCDefinition gNPCDefinitions[];

extern Hitbox* gNPCHitboxes[];
extern u32 (*gUnk_08114EFC[])();
extern u32 (*gUnk_08114F0C[])(Entity*, u8*);

typedef struct {
    u16 _0;
    u16 _2;
    u16 _4;
} NPCData;
extern NPCData* gUnk_08001A7C[];

u32 sub_0800445C(Entity*);
void sub_08077B20(void);
void sub_0806F69C(Entity*);
u32 sub_080041DC(Entity*, u32, u32);
u32 sub_0806EF88(Entity*);

static void sub_0806EF14(Entity*);
static void sub_0806EF4C(Entity*, u16*);
static u32 sub_0806EF74(Entity*, u32);

void sub_0806EC20(Entity* ent) {
    Entity* e = CreateNPC(0x58, 0, 0);
    if (e != NULL) {
        e->parent = ent;
    }
}

void sub_0806EC38(void) {
    Entity* e = FindEntityByID(7, 0x58, 7);
    if (e != NULL)
        DeleteEntity(e);
}

static const NPCDefinition* GetNPCDefinition(Entity* this) {
    const NPCDefinition* definition = &gNPCDefinitions[this->id];
    if (definition->bitfield.type == 2) {
        definition = &definition->data.definition[this->type];
    }
    return definition;
}

void NPCInit(Entity* this) {
    u32 tmp;
    u32 tmp2;

    if ((this->flags & ENT_DID_INIT) == 0) {
        const NPCDefinition* definition = GetNPCDefinition(this);
        if (definition->bitfield.type == 0) {
            // No sprite for this NPC
            this->flags |= 1;
        } else {
            tmp = definition->bitfield.gfx;
            switch (definition->bitfield.gfx_type) {
                case 2:
                    this->spriteVramOffset = definition->bitfield.gfx;
                    break;
                case 1:
                    LoadSwapGFX(this, tmp, 0);
                    break;
                default:
                    LoadFixedGFX(this, tmp);
                    break;
            }
            tmp = definition->data.sprite.paletteIndex;
            LoadObjPalette(this, tmp);
            this->spriteIndex = definition->data.sprite.spriteIndex;
            this->spriteSettings.shadow = definition->data.sprite.shadow;
            this->spritePriority.b1 = definition->data.sprite.spritePriority;
            this->spriteSettings.draw = definition->data.sprite.draw;
            this->hitbox = gNPCHitboxes[definition->bitfield.hitbox];
            this->flags |= ENT_DID_INIT;
            tmp2 = 0xff;
            this->animIndex = tmp2;
            this->frameIndex = tmp2;
            UpdateSpriteForCollisionLayer(this);
        }
    }
}

Entity* CreateNPC(u32 subtype, u32 form, u32 parameter) {
    Entity* entity = GetEmptyEntity();
    if (entity != NULL) {
        entity->kind = 7;
        entity->id = subtype;
        entity->type = form;
        entity->type2 = parameter;
        AppendEntityToList(entity, 7);
    }
    return entity;
}

u32 sub_0806ED78(Entity* ent) {
    u32 result = sub_0800445C(ent);
    if (result) {
        if (gPlayerState.dash_state & 0x40) {
            sub_08077B20();
        }
    }
    return result;
}

s32 sub_0806ED9C(Entity* ent, u32 x, u32 y) {
    s32 anim = -1;
    if (EntityInRectRadius(ent, &gPlayerEntity, x, y))
        anim = GetAnimationState(ent);
    return anim;
}

u32 GetAnimationState(Entity* ent) {
    u32 direction = GetFacingDirection(ent, &gPlayerEntity);
    return sub_0806F5A4(direction);
}

s32 sub_0806EDD8(Entity* ent, u32 x, u32 y) {
    s32 anim = -1;
    if (EntityInRectRadius(ent, &gPlayerEntity, x, y))
        anim = GetFacingDirection(ent, &gPlayerEntity);
    return anim;
}

void sub_0806EE04(Entity* ent, void* a2, u32 a3) {
    ent->child = a2;
    ent->field_0x3c = a3;
    ent->hitType = 0;
    ent->field_0x46 = 0;
    ent->field_0x16 = 0;
}

u32 sub_0806EE20(Entity* ent) {
    u32 v3;

    if (!ent->interactType) {
        if (ent->child)
            return gUnk_08114EFC[ent->field_0x16](ent);
    } else {
        ent->field_0x46 = 8;
        v3 = GetFacingDirection(ent, &gPlayerEntity);
        ent->knockbackDirection = sub_0806F5A4(v3);
    }
    return 0;
}

u32 sub_0806EE70(Entity* ent) {
    s32 tmp1;
    s32 tmp2;
    u32 result;
    u16 xy[2];

    if (++ent->field_0x46 > 8) {
        ent->field_0x46 = 0;
        sub_0806EF14(ent);
    }
    sub_0806F69C(ent);
    sub_0806EF4C(ent, xy);
    tmp1 = sub_080041DC(ent, xy[0], xy[1]);
    tmp2 = ent->speed;
    if (tmp2 < 0)
        tmp2 = -tmp2;
    if ((u32)tmp2 / 8 <= tmp1)
        result = 0;
    else
        result = sub_0806EF74(ent, 3);
    return result;
}

u32 sub_0806EED0(Entity* ent) {
    if (!--ent->field_0x46)
        return sub_0806EF74(ent, 2);
    return 0;
}

u32 sub_0806EEF4(Entity* ent) {
    if (ent->frame & 0x80)
        return sub_0806EF74(ent, 1);
    return 0;
}

static void sub_0806EF14(Entity* ent) {
    u16 xy[2];
    sub_0806EF4C(ent, xy);
    ent->direction = sub_080045B4(ent, xy[0], xy[1]);
    if ((ent->field_0x3c & 1) == 0)
        ent->knockbackDirection = sub_0806F5A4(ent->direction);
}

static void sub_0806EF4C(Entity* ent, u16* xy) {
    u16* src = &((u16*)ent->child)[ent->hitType];
    xy[0] = gRoomControls.roomOriginX + src[1];
    xy[1] = gRoomControls.roomOriginY + src[2];
}

static u32 sub_0806EF74(Entity* ent, u32 a2) {
    ent->hitType += a2;
    return sub_0806EF88(ent);
}

u32 sub_0806EF88(Entity* ent) {
    u8* v1 = (u8*)&((u16*)ent->child)[ent->hitType];
    return gUnk_08114F0C[*v1](ent, v1);
}

u32 sub_0806EFAC(Entity* ent, u16* a2) {
    ent->hitType = 0;
    return sub_0806EF88(ent);
}

u32 sub_0806EFBC(Entity* ent, u16* a2) {
    ent->field_0x16 = 1;
    ent->field_0x46 = 8;
    return 0;
}

u32 sub_0806EFCC(Entity* ent, u16* a2) {
    ent->field_0x16 = 2;
    ent->field_0x46 = a2[1];
    return 0;
}

u32 sub_0806EFDC(Entity* ent, u16* a2) {
    if (*a2 >> 8) {
        ent->field_0x3c &= ~1;
    } else {
        ent->field_0x3c |= 1;
    }
    ent->hitType++;
    return sub_0806EF88(ent);
}

u32 sub_0806F014(Entity* ent, u16* a2) {
    ent->speed = a2[1];
    ent->hitType += 2;
    return sub_0806EF88(ent);
}

u32 sub_0806F02C(Entity* ent, u16* a2) {
    ent->knockbackDirection = *a2 >> 8;
    ent->hitType++;
    return sub_0806EF88(ent);
}

u32 sub_0806F048(Entity* ent, u16* a2) {
    ent->field_0x16 = 3;
    return 0;
}

u32 sub_0806F050(Entity* ent, u16* a2) {
    (u16*)ent->child = a2 + 1;
    ent->hitType = 0;
    return sub_0806EF88(ent);
}

u32 sub_0806F064(Entity* ent, u16* a2) {
    ent->field_0x16 = 0;
    ent->hitType++;
    return *a2 >> 8;
}

s32 sub_0806F078(Entity* ent, s32 a2) {
    if (a2 != ent->animIndex) {
        if (ent->spriteAnimation[0])
            InitAnimationForceUpdate(ent, a2);
        else
            InitializeAnimation(ent, a2);
        return 1;
    }
    return 0;
}

ASM_FUNC("asm/non_matching/sub_0806FOA4.inc", void sub_0806F0A4(void));

void sub_0806F118(Entity* ent) {
    u32 idx = sub_08002632(ent);
    NPCData* data = gUnk_08001A7C[idx];
    sub_0801DFB4(ent, data->_0, data->_2, data->_4);
    gPlayerState.controlMode = 3;
}

u32 UpdateFuseInteraction(Entity* ent) {
    u32 ret;
    sub_0801E00C();
    ret = -1;
    switch (gUnk_02022740[0]) {
        default:
            ret = 0;
            break;
        case 2:
            gPlayerState.controlMode = 3;
            ret = 1;
        case 1:
            sub_0807919C();
            gPlayerState.controlMode = 1;
            break;
    }
    return ret;
}

void sub_0806F188(Entity* ent) {
    u32 idx = sub_08002632(ent);
    if (idx != 0)
        gSave.unk1C1[idx] = 0xF3;
}

ASM_FUNC("asm/non_matching/showNPCDialogue.inc", void ShowNPCDialogue(Entity* ent, Dialog* dia));
