#define NENT_DEPRECATED
#include "object.h"
#include "area.h"
#include "script.h"
#include "textbox.h"
#include "functions.h"
#include "screen.h"

extern u8 gUnk_08114F30[];
extern u8 gUnk_08114F34[];
extern u8 gUnk_08122AE0[];
extern u16 gUnk_08122AE8[];
extern s8 gUnk_08122AF8[];
extern u16 gUnk_08122B00[];
extern s16 gUnk_08122B0E[];
extern u16 gUnk_08122B1E[];
extern s8 gUnk_08122B2E[];

extern u16 script_Object6ATheLittleHat;
extern u16 script_Object6ASwordInChest;
extern u16 script_08015B14;
extern u16 script_ZeldaMagic;
extern u16 script_08012C48;

typedef struct {
    Entity base;
    u16 px, py, pz;
    u8 off;
    u8 fill[0x14];
    void* ctx;
} Object6AEntity;

typedef struct {
    u16 arr[8];
    u8 filler[4];
    u16 my_x, my_y;
    u8 fill[4];
    u16 parent_x, parent_y;
} Type15Vars;

typedef struct {
    Entity base;
    Type15Vars vars;
} Object6AEntityType15;

typedef struct {
    Entity base;
    u8 fill[0x1C];
    u32 anim;
} Type1F;

typedef struct {
    Hitbox hit;
    u8 _8[4];
    u8 _c;
} HitboxCfg;
extern HitboxCfg gUnk_08122B3C[];

typedef void(Object6ATypeAction)(Object6AEntity*);

Object6ATypeAction sub_08094A5C;
Object6ATypeAction sub_08094A90;
Object6ATypeAction sub_08094C30;
Object6ATypeAction sub_08094C88;
Object6ATypeAction sub_08094D94;
Object6ATypeAction sub_08094E30;
Object6ATypeAction sub_08094FA8;
Object6ATypeAction sub_08095088;
Object6ATypeAction sub_08095120;
Object6ATypeAction sub_08095188;
Object6ATypeAction sub_080951C4;
Object6ATypeAction sub_08095288;
Object6ATypeAction sub_080953A4;
Object6ATypeAction sub_080953A4;
Object6ATypeAction sub_080954DC;
Object6ATypeAction sub_080956B4;
Object6ATypeAction sub_0809577C;
Object6ATypeAction sub_080957DC;
Object6ATypeAction sub_0809584C;
Object6ATypeAction sub_080958D8;
Object6ATypeAction sub_08095918;
Object6ATypeAction sub_08094C88;
Object6ATypeAction sub_080959CC;
Object6ATypeAction sub_08095A8C;
Object6ATypeAction sub_08095B48;
Object6ATypeAction sub_08095C00;
Object6ATypeAction sub_080953A4;
Object6ATypeAction sub_08095C68;
Object6ATypeAction sub_08095CE0;
Object6ATypeAction sub_08095CE0;
Object6ATypeAction sub_08095DBC;
Object6ATypeAction sub_08095F38;
Object6ATypeAction sub_08096058;
Object6ATypeAction sub_08096058;
Object6ATypeAction sub_08094A90;
Object6ATypeAction sub_08096084;
Object6ATypeAction sub_08096084;
Object6ATypeAction sub_08096168;
Object6ATypeAction sub_080961F4;
Object6ATypeAction sub_080961F4;
Object6ATypeAction sub_080961F4;
Object6ATypeAction sub_08096284;
Object6ATypeAction sub_08096290;

extern void sub_08080CB4(Entity*);
extern u32 sub_080002B8(Entity*);
extern u32 sub_080040A8(Entity*);
extern void sub_08078850(Entity*, u32, u32, u8*);

void sub_08095754(Object6AEntity*);
void sub_080957B4(Object6AEntity*);
void sub_08095954(Object6AEntity*);
void sub_08095D30(Object6AEntity*, u32);

static void sub_0809629C(Object6AEntity*, u32);

void Object6A(Entity* this) {
    static Object6ATypeAction* const sTypeTable[] = {
        sub_08094A5C, sub_08094A90, sub_08094C30, sub_08094C88, sub_08094D94, sub_08094E30, sub_08094FA8, sub_08095088,
        sub_08095120, sub_08095188, sub_080951C4, sub_08095288, sub_080953A4, sub_080953A4, sub_080954DC, sub_080956B4,
        sub_0809577C, sub_080957DC, sub_0809584C, sub_080958D8, sub_08095918, sub_08094C88, sub_080959CC, sub_08095A8C,
        sub_08095B48, sub_08095C00, sub_080953A4, sub_08095C68, sub_08095CE0, sub_08095CE0, sub_08095DBC, sub_08095F38,
        sub_08096058, sub_08096058, sub_08094A90, sub_08096084, sub_08096084, sub_08096168, sub_080961F4, sub_080961F4,
        sub_080961F4, sub_08096284, sub_08096290,
    };
    sTypeTable[this->type]((Object6AEntity*)this);
}

void sub_08094A5C(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        sub_0807DD64(super);
        InitializeAnimation(super, 4);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    GetNextFrame(super);
}

void sub_08094A90(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        super->collisionLayer = 2;
        UpdateSpriteForCollisionLayer(super);
        super->spriteRendering.b3 = gUnk_08114F30[super->spriteRendering.b3];
        InitAnimationForceUpdate(super, 0);
        sub_0807DD64(super);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    UpdateAnimationSingleFrame(super);
}

void sub_08094AE8(Entity* this, ScriptExecutionContext* ctx) {
    Object6AEntity* e = (Object6AEntity*)CreateObject(0x6A, 1, 0);
    if (e != NULL) {
        e->ctx = StartCutscene(&e->base, (void*)ctx->intVariable);
    }
}

void sub_08094B0C(Object6AEntity* this) {
    if (--super->z.HALF.HI <= -32)
        super->z.HALF.HI = -32;
    else
        gActiveScriptInfo.commandSize = 0;
}

void sub_08094B3C(Object6AEntity* this) {
    super->z.WORD += 0x8000;
    if (super->z.HALF.HI >= -13)
        super->z.HALF.HI = -13;
    else
        gActiveScriptInfo.commandSize = 0;
}

void sub_08094B6C(Object6AEntity* this) {
    super->spritePriority.b1 = 0x3;
}

void sub_08094B80(Object6AEntity* this) {
    super->spritePriority.b1 = 0x2;
}

void sub_08094B94(Object6AEntity* this) {
    Entity* e = CreateObject(0x6A, 0x22, 0);
    if (e != NULL) {
        CopyPosition(&gPlayerEntity, e);
        e->z.HALF.HI = -48;
        ((Object6AEntity*)e)->ctx = StartCutscene(e, &script_Object6ATheLittleHat);
        CreateDust(e);
        e->z.HALF.HI += 16;
        e->y.HALF.HI++;
    }
}

void sub_08094BE0(Entity* this) {
    Entity* e = FindEntity(6, 0x6A, 6, 0x22, 0);
    if (e != NULL) {
        CopyPosition(&gPlayerEntity, e);
        e->z.HALF.HI = -12;
        e->y.HALF.HI++;
        e->collisionLayer = 2;
        UpdateSpriteForCollisionLayer(e);
        InitAnimationForceUpdate(e, 1);
    }
}

void sub_08094C30(Object6AEntity* this) {
    Entity* p = super->parent;
    if (p == NULL || p->next == NULL)
        DeleteThisEntity();
    if (super->action == 0) {
        super->action++;
        SetDefaultPriority(super, 2);
        super->spriteRendering.b3 = gUnk_08114F30[p->spriteRendering.b3];
        InitAnimationForceUpdate(super, 1);
    }
    CopyPosition(p, super);
    UpdateAnimationSingleFrame(super);
}

void sub_08094C88(Object6AEntity* this) {
    u32 tmp;

    if (super->action != 0) {
        if (super->action & 0x80) {
            DeleteThisEntity();
            return;
        }
    } else {
        super->action++;
        super->spriteSettings.draw = 1;
        SetDefaultPriority(super, 3);
        switch (super->type2) {
            case 0x40:
            case 0x41:
            case 0x42:
            case 0x43:
                ResolveEntityBelow(super, super);
        }
    }

    tmp = super->type;
    super->type = super->type2;
    sub_08080CB4(super);
    super->type = tmp;
}

void sub_08094CDC(Object6AEntity* this) {
    Entity* e = CreateObject(0x6a, 3, 0x62);
    if (e != NULL) {
        e->x.HALF.HI = gRoomControls.roomOriginX + 224;
        e->y.HALF.HI = gRoomControls.roomOriginY + 600;
        SoundReq(324);
    }
}

void sub_08094D10(Object6AEntity* this) {
    Entity* e = FindEntity(6, 0x6a, 6, 3, 98);
    if (e != NULL) {
        e->action = 0xFF;
    }
}

void sub_08094D34(Object6AEntity* this) {
    Entity* e = CreateObject(0x6a, 0x15, 0xd);
    if (e != NULL) {
        e->x.HALF.HI = gRoomControls.roomOriginX + 256;
        e->y.HALF.HI = gRoomControls.roomOriginY + 600;
        SoundReq(324);
    }
}

void sub_08094D70(Object6AEntity* this) {
    Entity* e = FindEntity(6, 0x6a, 6, 0x15, 0xd);
    if (e != NULL) {
        e->action = 0xFF;
    }
}

void sub_08094D94(Object6AEntity* this) {
    u32 tmp;

    if (super->action != 0) {
        if (super->action & 0x80) {
            DeleteThisEntity();
            return;
        }
    } else {
        super->action++;
        super->spriteSettings.draw = 1;
        SetDefaultPriority(super, 3);
        InitAnimationForceUpdate(super, 0);
    }
    UpdateAnimationSingleFrame(super);
}

void sub_08094DD8(Object6AEntity* this) {
    Entity* e = CreateObject(0x6a, 0x4, 0);
    if (e != NULL) {
        e->x.HALF.HI = gRoomControls.roomOriginX + 240;
        e->y.HALF.HI = gRoomControls.roomOriginY + 600;
        SoundReq(324);
    }
}

void sub_08094E0C(Object6AEntity* this) {
    Entity* e = FindEntity(6, 0x6a, 6, 4, 0);
    if (e != NULL) {
        e->action = 0xFF;
    }
}

void sub_08094E30(Object6AEntity* this) {
    if (super->type2 == 0) {
        if ((gScreenTransition.frameCount % 32) == 0) {
            Entity* e = CreateObject(0x6A, 5, 1);
            if (e != NULL) {
                e->x.HALF.HI = gRoomControls.roomScrollX + (s32)Random() % DISPLAY_WIDTH;
                e->y.HALF.HI = gRoomControls.roomScrollY + (s32)Random() % DISPLAY_HEIGHT;
            }
        }
        return;
    }

    if (super->type2 == 1) {
        switch (super->action) {
            case 0:
                super->action++;
                super->z.WORD = -0xA00000;
                super->zVelocity = 0;
                SetDefaultPriority(super, 6);
                InitializeAnimation(super, 0);
                if (sub_080002B8(super) == 13) {
                    super->action = 3;
                }
                break;
            case 1:
                super->z.WORD -= super->zVelocity;
                super->zVelocity -= 0x2000;
                if (super->z.WORD > 0) {
                    super->action++;
                    super->z.WORD = 0;
                    super->zVelocity = 0;
                    InitializeAnimation(super, 1);
                    EnqueueSFX(382);
                }
                break;
            case 2:
                GetNextFrame(super);
                if (super->frame & 0x80) {
                    DeleteThisEntity();
                }
                break;
            case 3:
                super->z.WORD -= super->zVelocity;
                super->zVelocity -= 0x2000;
                if (!sub_080040A8(super)) {
                    DeleteThisEntity();
                }
                break;
        }
    } else if (super->action == 0) {
        super->action++;
        switch (super->actionDelay) {
            case 1:
                InitializeAnimation(super, 2);
                break;
            case 2:
                super->spriteSettings.flipX = 1;
                InitializeAnimation(super, 0);
                break;
            case 0:
                InitializeAnimation(super, 0);
                break;
            case 3:
                super->spriteSettings.flipX = 1;
                InitializeAnimation(super, 2);
                break;
        }
    }
}

void sub_08094F98(Object6AEntity* this) {
    CreateObject(0x6A, 5, 0);
}

void sub_08094FA8(Object6AEntity* this) {
    switch (super->action) {
        case 0:
            super->action = 1;
            super->frameIndex = 0;
            super->spritePriority.b0 = 7;
            sub_080787B4(super);
            break;
        case 1:
            if (super->interactType != 0) {
                super->interactType = 0;
                super->action = 2;
                sub_080788E0(super);
                gPlayerState.playerAction = 12;
                gPlayerState.field_0x38 = 54;
#ifndef EU
                SetPlayerControl(2);
#endif
            }
            break;
        case 2:
            if (GetInventoryValue(54) == 2) {
                super->action = 3;
                super->spriteSettings.draw = 1;
            }
            break;
        case 3:
            if (gPlayerEntity.action != 12) {
                super->action = 4;
#ifndef EU
                if (!CheckGlobalFlag(BIN_DOGFOOD)) {
                    CreateItemEntity(0x1c, 0, 0);
                    SetGlobalFlag(BIN_DOGFOOD);
                    super->actionDelay = 60;
                }
#else
                CreateItemEntity(0x1c, 0, 0);
#endif
            }
            break;
#ifndef EU
        case 4:
            if (!--super->actionDelay) {
                super->action = 5;
                SetPlayerControl(1);
            }
            break;
#endif
    }
}

void sub_08095088(Object6AEntity* this) {
    u32 tmp;

    switch (super->action) {
        case 0:
            if (GetInventoryValue(91))
                DeleteThisEntity();
            super->action = 1;
            super->spritePriority.b0 = 7;
            sub_080787B4(super);
            break;
        case 1:
            if (super->interactType != 0) {
                super->interactType = 0;
                super->action = 2;
                sub_080788E0(super);
                CreateEzloHint(0x1F1F, 0);
            }
            break;
        case 2:
            if ((gMessage.doTextBox & 0x7F) == 0) {
                CreateItemEntity(0x5b, 0, 0);
                DeleteThisEntity();
            }
            break;
    }
    tmp = super->type;
    super->type = 91;
    sub_08080CB4(super);
    super->type = tmp;
}

void sub_08095120(Object6AEntity* this) {
    if (super->action == 0) {
        super->action = 1;
        SetDefaultPriority(super, 3);
        ResolveEntityBelow(super, super);
        sub_0807DD64(super);
        InitAnimationForceUpdate(super, 2);
    }
    ExecuteScriptForEntity(super, NULL);
    HandleEntity0x82Actions(super);
    UpdateAnimationSingleFrame(super);
}

void sub_08095164(Object6AEntity* this) {
    Entity* e = FindEntity(6, 0x6A, 6, 8, 0);
    if (e != NULL) {
        InitAnimationForceUpdate(e, 3);
    }
}

void sub_08095188(Object6AEntity* this) {
    if (super->action == 0) {
        super->action = 1;
        SetDefaultPriority(super, 3);
        ResolveEntityBelow(super, super);
        sub_0807DD64(super);
        InitAnimationForceUpdate(super, 0);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
}

void sub_080951C4(Object6AEntity* this) {
    Entity* p;

    if (super->action == 0) {
        super->action++;
        super->z.HALF.HI = -16;
        super->actionDelay = 0;
        sub_0807DD64(super);
        InitializeAnimation(super, 3);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    GetNextFrame(super);
    if (super->z.HALF.HI == 0) {
        super->z.WORD = 0;
        super->parent = NULL;
        if (super->actionDelay == 0) {
            super->actionDelay++;
            SoundReq(230);
        }
    }
    p = super->parent;
    if (p != NULL) {
        super->spriteSettings.draw = p->spriteSettings.draw;
        super->x.HALF.HI = p->x.HALF.HI + 16;
        super->y.HALF.HI = p->y.HALF.HI - 16;
    }
}

void sub_08095244(Object6AEntity* this) {
    if (super->type == 0) {
        Entity* e = CreateObject(0x6A, 0xA, 0);
        if (e != NULL) {
            e->parent = super;
            PositionRelative(super, e, 0x100000, -0x100000);
            ((Object6AEntity*)e)->ctx = StartCutscene(e, &script_Object6ASwordInChest);
        }
    }
}

void sub_08095288(Object6AEntity* this) {
    Entity* p;

    if (super->action == 0) {
        super->action++;
        super->subAction = 0;
        SetDefaultPriority(super, 3);
        InitAnimationForceUpdate(super, 0);
    }
    if (super->subAction != 0) {
        if ((u32)sub_080044EC(super, 0x1800) <= 1) {
            super->subAction = 0;
            sub_0805EC9C(super, 0x100, 0x100, 0xC000);
        } else {
            sub_0805EC9C(super, 0x100, 0x100, super->actionDelay << 8);
            super->actionDelay += 10;
            sub_0806F69C(super);
        }
    }
    p = super->child;
    if (p != NULL) {
        CopyPosition(p, super);
    }
    UpdateAnimationSingleFrame(super);
    p = super->parent;
    if (p != NULL) {
        super->spriteSettings.draw = p->spriteSettings.draw;
        if (p->next == NULL)
            DeleteThisEntity();
    } else {
        DeleteThisEntity();
    }
}

void sub_08095330(Object6AEntity* this) {
    Entity* e = CreateObject(0x6A, 0xB, 0);
    if (e != NULL) {
        super->child = e;
        e->child = super;
        e->parent = super;
        CopyPosition(super, e);
        e->z.HALF.HI = -16;
        ResolveEntityOnTop(e, e);
    }
}

void sub_08095364(Object6AEntity* this) {
    Entity* e = super->child;
    if (e != NULL) {
        e->frameIndex = 2;
        e->collisionLayer = 1;
        UpdateSpriteForCollisionLayer(e);
        e->child = NULL;
        e->subAction = 1;
        e->z.HALF.HI = -16;
        e->direction = 7;
        e->zVelocity = 0x30000;
        e->speed = 128;
        InitAnimationForceUpdate(e, 1);
    }
}

void sub_080953A4(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        super->z.HALF.HI = -16;
        SetDefaultPriority(super, 2);
        super->spriteRendering.b3 = gUnk_08114F30[super->spriteRendering.b3];
        ResolveEntityOnTop(super, super);
        sub_0807DD64(super);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    GetNextFrame(super);
    if (super->type == 13) {
        u32 x = 0;
        u32 y = 0x139;
        ChangeObjPalette(super, super->frameSpriteSettings & 1 ? x : y);
    }
}

void sub_08095420(Object6AEntity* this, ScriptExecutionContext* ctx) {
    Entity* e = CreateObject(0x6A, 0xC, 0);
    if (e != NULL) {
        PositionRelative(super, e, 0, -0x100000);
        ((Object6AEntity*)e)->ctx = StartCutscene(e, (u16*)ctx->intVariable);
    }
}

void nullsub_527(Object6AEntity* this) {
}

void sub_0809545C(Object6AEntity* this, ScriptExecutionContext* ctx) {
    Entity* p = CreateObject(0x6A, 0xD, 0);
    Entity* e;
    if (p != NULL) {
        PositionRelative(super, p, 0, -0x100000);
        ((Object6AEntity*)p)->ctx = StartCutscene(p, (u16*)ctx->intVariable);
        e = CreateObject(0x6A, 2, 0);
        if (e != NULL) {
            CopyPosition(p, e);
            e->parent = p;
        }
    }
}

void sub_080954AC(Object6AEntity* this) {
    Entity* e = CreateObject(0x6A, 0x1A, 0);
    if (e != NULL) {
        CopyPosition(super, e);
        ((Object6AEntity*)e)->ctx = StartCutscene(e, &script_08015B14);
    }
}

void sub_080954DC(Object6AEntity* this) {
    switch (super->action) {
        case 0:
            if (super->actionDelay != 0) {
                super->actionDelay--;
            } else {
                super->action++;
                super->subAction = 0;
                super->spriteSettings.draw = 1;
                super->z.HALF.HI = 0;
                super->spritePriority.b0 = 1;
                this->px = super->x.HALF.HI;
                this->py = super->y.HALF.HI;
                this->pz = 0;
                this->off = gUnk_08122AE0[super->type2];
                ChangeObjPalette(super, gUnk_08122AE8[super->type2]);
                sub_0807DD64(super);
                InitializeAnimation(super, super->type2 + 2);
                sub_08095754(this);
                SoundReq((s32)Random() % 6 + 0x1BC);
            }
            break;
        case 1:
            if (--super->z.HALF.HI <= -16) {
                super->action++;
                super->z.HALF.HI = -16;
            }
            break;
        case 2:
            if (++this->pz > 0x40)
                this->pz = 0x40;
            super->x.HALF.HI = (gSineTable[this->off + 64] * (this->pz << 8)) >> 16;
            super->y.HALF.HI = (gSineTable[this->off] * (this->pz << 7)) >> 16;
            super->x.HALF.HI += this->px;
            super->y.HALF.HI += this->py;
            break;
        case 3:
            sub_0806F62C(super, super->speed, super->direction);
            break;
    }
    this->off += 4;
    if (super->subAction != 0 && !sub_080040A8(super))
        DeleteThisEntity();
    if (super->direction & 0x80)
        super->spriteSettings.flipX = 0;
    else
        super->spriteSettings.flipX = 1;
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    GetNextFrame(super);
}

void sub_0809567C(Object6AEntity* this) {
    super->action = 3;
    super->subAction = 1;
    super->speed = 0x400;
    super->direction = sub_080045DA(super->x.WORD - ((s16)this->px << 16), super->y.WORD - ((s16)this->py << 16));
}

void sub_080956B4(Object6AEntity* this) {
    Entity* p;
    u16* p1;
    u16* p2;
    Type15Vars* tmp;

    if (super->action == 0) {
        s32 i;
        u16* p;
        u32 x;
        u32 y;

        super->action++;
        InitializeAnimation(super, 0);
        // p = this->v.arr;
        asm("mov r4, r5");
        asm("add r4, #0x68");
        x = super->x.HALF_U.HI;
        y = super->y.HALF_U.HI;
        for (i = 0; i < 8; i++) {
            *p++ = x;
            *p++ = y;
        }
    }
    GetNextFrame(super);
    if ((super->type2 + gScreenTransition.frameCount) % 16 == 0)
        sub_080957B4(this);
    p = super->parent;
    if (p != NULL) {
        super->spriteSettings.draw = p->spriteSettings.draw;
        if (p->next == NULL) {
            DeleteThisEntity();
        }
    } else {
        DeleteThisEntity();
    }
    tmp = &((Object6AEntityType15*)this)->vars;
    MemCopy(&tmp->arr[2], &tmp->arr[0], 0x1C);
    super->x.HALF.HI = tmp->my_x;
    super->y.HALF.HI = tmp->my_y;
    super->z.HALF.HI = p->z.HALF.HI;
    tmp->parent_x = p->x.HALF.HI;
    tmp->parent_y = p->y.HALF.HI;
}

void sub_08095754(Object6AEntity* this) {
    Entity* e = CreateObject(0x6A, 0xF, super->type2);
    if (e != NULL) {
        e->parent = super;
        CopyPosition(super, e);
        ResolveEntityBelow(super, e);
    }
}

void sub_0809577C(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        super->z.HALF.HI = -16;
        InitializeAnimation(super, 1);
    }
    GetNextFrame(super);
    if (super->frame & 0x80)
        DeleteThisEntity();
}

void sub_080957B4(Object6AEntity* this) {
    Entity* e = CreateObject(0x6A, 0x10, 0);
    if (e != NULL) {
        e->parent = super;
        CopyPosition(super, e);
        ResolveEntityBelow(super, e);
    }
}

void sub_080957DC(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        sub_0807DD64(super);
        InitAnimationForceUpdate(super, 0);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    UpdateAnimationSingleFrame(super);
}

void sub_08095810(Object6AEntity* this) {
    Entity* e = CreateObject(0x6A, 0x11, 0);
    if (e != NULL) {
        e->parent = super;
        CopyPosition(super, e);
        ResolveEntityOnTop(super, e);
        ((Object6AEntity*)e)->ctx = StartCutscene(e, &script_ZeldaMagic);
    }
}

void sub_0809584C(Object6AEntity* this) {
    u32 tmp, idx;

    idx = super->health;
    if ((idx & 0x7F) != 0 && !ReadBit((u32*)gArea.filler5, idx - 1))
        DeleteThisEntity();
    if (super->actionDelay != 0 && CheckKinstoneFused(super->type2))
        DeleteThisEntity();
    if (super->action == 0) {
        super->action++;
        super->collisionLayer = 2;
        UpdateSpriteForCollisionLayer(super);
        super->spriteRendering.b3 = gUnk_08114F30[super->spriteRendering.b3];
        sub_0807DD64(super);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    tmp = super->type;
    super->type = 92;
    sub_08080CB4(super);
    super->type = tmp;
}

void sub_080958D8(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        sub_0807DD64(super);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    GetNextFrame(super);
    if (super->frame & 1)
        sub_08095954(this);
}

void sub_08095918(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        SetDefaultPriority(super, 6);
        sub_0807DD64(super);
        InitializeAnimation(super, 0);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    GetNextFrame(super);
}

void sub_08095954(Object6AEntity* this) {
    typedef struct {
        s8 x, y;
    } s8XY;

    Entity* e = CreateObject(0x6A, 0x14, 0);
    if (e != NULL) {
        u32 tmp, x, y;
        e->parent = super;
        tmp = super->animationState;
        x = ((s8XY*)(&gUnk_08122AF8[tmp]))->x << 16;
        y = ((s8XY*)(&gUnk_08122AF8[tmp]))->y << 16;
        PositionRelative(super, e, x, y);
        e->z.HALF.HI = -3;
        ((Object6AEntity*)e)->ctx = StartCutscene(e, &script_08012C48);
        EnqueueSFX(292);
        super->frame &= ~1;
    } else {
        gActiveScriptInfo.syncFlags |= 0x100;
    }
}

void sub_080959CC(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        super->spriteSettings.draw = 0;
        SetDefaultPriority(super, 3);
        sub_0807DD64(super);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    UpdateAnimationSingleFrame(super);
    sub_08095D30(this, super->frame & ~0x80);
}

void sub_08095A1C(Object6AEntity* this, ScriptExecutionContext* ctx) {
    Entity* e = CreateObject(0x6A, 0x16, 0);
    if (e != NULL) {
        e->x.HALF.HI = gRoomControls.roomOriginX + 232;
        e->y.HALF.HI = gRoomControls.roomOriginY + 312;
        e->z.HALF.HI = -4;
        e->collisionLayer = 2;
        ((Object6AEntity*)e)->ctx = StartCutscene(e, (u16*)ctx->intVariable);
    }
}

void sub_08095A68(Object6AEntity* this) {
    Entity* e = FindEntity(6, 0x6A, 6, 0x16, 0);
    if (e != NULL) {
        e->action = 0xFF;
    }
}

void sub_08095A8C(Object6AEntity* this) {
    switch (super->action) {
        case 0:
            super->action++;
            super->frameIndex = 0;
            sub_0807DD64(super);
        case 1:
            ExecuteScriptForEntity(super, 0);
            HandleEntity0x82Actions(super);
            break;
        case 2:
            super->action++;
            super->actionDelay = 120;
        case 3:
            super->spriteSettings.draw ^= 1;
            if (--super->actionDelay == 0) {
                super->action = 1;
                super->spriteSettings.draw = 1;
            }
            break;
        case 4:
            super->action++;
            super->actionDelay = 120;
        case 5:
            super->spriteSettings.draw ^= 1;
            if (--super->actionDelay == 0) {
                super->action = 1;
                super->spriteSettings.draw = 0;
            }
            break;
    }
}

void sub_08095B48(Object6AEntity* this) {
    Entity* p;
    u32 tmp;

    if (super->action == 0) {
        super->action++;
        super->collisionLayer = 2;
        UpdateSpriteForCollisionLayer(super);
        super->spriteRendering.b3 = gUnk_08114F30[super->spriteRendering.b3];
    }
    super->spriteSettings.draw = 0;
    p = super->parent;
    if (p != NULL) {
        if ((p->frame & 0x40) == 0) {
            if (p->frame & 0x80) {
                DeleteThisEntity();
                return;
            }
        } else {
            s8* data;
            super->spriteSettings.draw = 1;
            data = GetSpriteSubEntryOffsetDataPointer((u16)p->spriteIndex, p->frameIndex);
            super->spriteOffsetX = data[0];
            super->spriteOffsetY = data[1];
        }
    }
    tmp = super->type;
    super->type = super->type2;
    sub_08080CB4(super);
    super->type = tmp;
}

void sub_08095BE0(Object6AEntity* this, u32 val) {
    Entity* e = CreateObject(0x6A, 0x18, val);
    if (e != NULL) {
        e->parent = super;
        CopyPosition(super, e);
    }
}

void sub_08095C00(Object6AEntity* this) {
    if (super->action & 0x80) {
        DeleteThisEntity();
    } else {
        Entity* p = super->parent;
        if (p != NULL) {
            super->spriteVramOffset = 232;
            if (p->spriteSettings.draw == 1)
                super->spriteSettings.draw = 0;
            else
                super->spriteSettings.draw = 1;
        }
    }
}

void sub_08095C48(Object6AEntity* this) {
    Entity* e = CreateObject(0x6A, 0x19, 0);
    if (e != NULL) {
        super->child = e;
        e->parent = super;
        CopyPosition(super, e);
    }
}

void sub_08095C68(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        sub_080042D0(super, super->frameIndex, (u16)super->spriteIndex);
    }
    if (super->actionDelay != 0) {
        if (--super->actionDelay < 8) {
            super->spriteSettings.draw ^= 1;
        }
        if (super->actionDelay != 0) {
            return;
        }
    }
    DeleteThisEntity();
}

void sub_08095CB0(Object6AEntity* this) {
    Entity* e = CreateObject(0x6A, 0x1B, 0);
    if (e != NULL) {
        super->child = e;
        e->parent = super;
        CopyPosition(super, e);
        e->actionDelay = 16;
        e->frameIndex = super->frameIndex;
        e->lastFrameIndex = super->frameIndex;
    }
}

void sub_08095CE0(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        super->spriteSettings.draw = 0;
        SetDefaultPriority(super, 6);
        sub_0807DD64(super);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    UpdateAnimationSingleFrame(super);
    sub_08095D30(this, super->frame & ~0x80);
}

void sub_08095D30(Object6AEntity* this, u32 a2) {
    if (a2 != 0)
        ChangeObjPalette(super, gUnk_08122B00[a2] & ~0x80);
}

void sub_08095D54(Object6AEntity* this, ScriptExecutionContext* ctx) {
    Entity* e = CreateObject(0x6A, 0x1C, 0);
    if (e != NULL) {
        CopyPosition(&gPlayerEntity, e);
        e->collisionLayer = 2;
        ((Object6AEntity*)e)->ctx = StartCutscene(e, (u16*)ctx->intVariable);
    }
}

void sub_08095D8C(Object6AEntity* this, ScriptExecutionContext* ctx) {
    Entity* e = CreateObject(0x6A, 0x1D, 0);
    if (e != NULL) {
        CopyPosition(super, e);
        ((Object6AEntity*)e)->ctx = StartCutscene(e, (u16*)ctx->intVariable);
    }
}

void sub_08095DBC(Object6AEntity* this) {
    if (gActiveScriptInfo.syncFlags & 0x10)
        DeleteThisEntity();
    if (super->type2 == 0) {
        if (super->action == 0) {
            super->action++;
            sub_0807DD64(super);
        }
        ExecuteScriptForEntity(super, 0);
    } else {
        if (super->action == 0) {
            super->action++;
            super->spriteSettings.draw = 1;
            InitializeAnimation(super, 75);
            super->spriteRendering.b3 = gUnk_08114F30[super->spriteRendering.b3];
            ResolveEntityOnTop(super, super);
        }
        if ((super->type2 & 0x80) == 0 && gActiveScriptInfo.syncFlags & 0x20000) {
            super->type2 = -1;
            super->zVelocity = 0x40000;
            super->speed = 0xC000;
        }
        sub_08003FC4(super, super->speed);
        GetNextFrame(super);
        if (!sub_080040A8(super))
            DeleteThisEntity();
    }
}

void sub_08095E7C(Object6AEntity* this, ScriptExecutionContext* ctx) {
    Entity* e = CreateObject(0x6A, 0x1E, 0);
    if (e != NULL) {
        CopyPosition(super, e);
        ((Object6AEntity*)e)->ctx = StartCutscene(e, (u16*)ctx->intVariable);
    }
}

NONMATCH("asm/non_matching/object6A/sub_08095EAC.inc",
         void sub_08095EAC(Object6AEntity* this, ScriptExecutionContext* ctx)) {
    Entity* e = CreateObject(0x6A, 0x1E, 1);
    s32 x, y;

    if (e != NULL) {
        s32 a, b, vel, speed;
        if (ctx->intVariable == 0) {
            a = 0x10;
            b = 0x1F;
            vel = 0x4000;
            speed = 0;
        } else {
            a = 0x8;
            b = 0xF;
            vel = 0x40000;
            speed = gUnk_08122B0E[Random() & 7];
            super->type2 = -1;
        }

        x = a - (Random() & b);
        y = a - (Random() & b);
        PositionRelative(super, e, x << 16, y << 16);
        super->zVelocity = vel;
        super->speed = speed;
    }
}
END_NONMATCH

#define local ((Type1F*)this)
void sub_08095F38(Object6AEntity* this) {
    u32 tmp;

    if (super->action == 0) {
        u32 pal;

        super->action = 1;
        super->frameIndex = -1;
        switch (super->type2) {
            case 3:
                pal = 0;
                break;
            case 4:
                pal = 1;
                break;
            case 6:
                pal = 4;
                break;
        }
        ChangeObjPalette(super, pal);
        if ((gPlayerEntity.frame & 1) == 0) {
            local->anim = 0x8BF;
            super->actionDelay = 52;
            super->field_0xf = -75;
        } else {
            local->anim = 0x8E3;
            super->actionDelay = 85;
            super->field_0xf = -42;
        }
        CopyPosition(&gPlayerEntity, super);
        super->spritePriority.b0 = 3;
    }
    if (gPlayerEntity.frame & 0x10) {
        gPlayerEntity.frame &= ~0x10;
        SoundReq(468);
    }
    if ((u16)gPlayerEntity.spriteIndex != local->anim >> 8 || gPlayerEntity.animIndex != (u8)local->anim)
        DeleteThisEntity();
    tmp = gPlayerEntity.frameIndex - super->actionDelay + super->field_0xf;
    if (tmp != super->frameIndex) {
        super->frameIndex = tmp;
        sub_080042D0(super, super->frameIndex, (u16)super->spriteIndex);
    }
}

void sub_08096028(Object6AEntity* this) {
    u32 type2 = 6;
    if (!CheckLocalFlagByBank(768, 123))
        type2 = 4;
    if (!CheckLocalFlagByBank(768, 122))
        type2 = 3;
    CreateObject(0x6A, 0x1F, type2);
}

void sub_08096058(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        sub_0807DD64(super);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    GetNextFrame(super);
}

void sub_08096084(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        sub_0807DD64(super);
        InitializeAnimation(super, super->type2);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    GetNextFrame(super);
    if (super->parent != NULL) {
        CopyPosition(super->parent, super);
    }
}

void sub_080960C4(Object6AEntity* this, ScriptExecutionContext* ctx) {
    Entity* e = CreateObject(0x6A, 0x23, 0x49);
    if (e != NULL) {
        e->parent = super;
        CopyPosition(super, e);
        e->spriteRendering.b3 = gUnk_08114F34[super->spriteRendering.b3];
        ResolveEntityBelow(super, e);
        ((Object6AEntity*)e)->ctx = StartCutscene(e, (u16*)ctx->intVariable);
    }
    e = CreateObject(0x6A, 0x24, 0x4A);
    if (e != NULL) {
        e->parent = super;
        CopyPosition(super, e);
        e->spriteRendering.b3 = gUnk_08114F30[super->spriteRendering.b3];
        ResolveEntityOnTop(super, e);
        e->collisionLayer = 2;
        ((Object6AEntity*)e)->ctx = StartCutscene(e, (u16*)ctx->intVariable);
    }
}

void sub_08096168(Object6AEntity* this) {
    if (super->action == 0) {
        super->action++;
        super->spriteSettings.draw = 1;
        InitializeAnimation(super, 75);
    }
    GetNextFrame(super);
    sub_0806F62C(super, super->speed, super->direction);
    if (!sub_080040A8(super))
        DeleteThisEntity();
}

void sub_080961B0(Object6AEntity* this) {
    int i;
    for (i = 0; i < 8; ++i) {
        Entity* e = CreateObject(0x6A, 0x25, 0);
        if (e != NULL) {
            CopyPosition(super, e);
            e->direction = 32 * i;
            e->speed = (Random() & 0x1F0) + gUnk_08122B1E[i];
        }
    }
}

void sub_080961F4(Object6AEntity* this) {
    super->spriteSettings.draw = 1;
    super->frameIndex = 0;
}

void sub_08096208(Object6AEntity* this, u32 x) {
    s8* p = &gUnk_08122B2E[x * 2];
    Entity* e = CreateObject(0x6A, 0x26, 0);
    if (e != NULL) {
        PositionRelative(super, e, p[0] << 16, p[1] << 16);
    }
}

void sub_0809623C(Object6AEntity* this) {
    Entity* e = CreateObject(0x6A, 0x27, 0);
    if (e != NULL) {
        PositionRelative(super, e, 0, -0x100000);
    }
}

void sub_08096260(Object6AEntity* this) {
    Entity* e = CreateObject(0x6A, 0x28, 0);
    if (e != NULL) {
        PositionRelative(super, e, 0, -0x100000);
    }
}

void sub_08096284(Object6AEntity* this) {
    sub_0809629C(this, 0xd);
}

void sub_08096290(Object6AEntity* this) {
    sub_0809629C(this, 0xe);
}

void sub_0809629C(Object6AEntity* this, u32 type) {
    u32 tmp;

    if (super->action == 0) {
        super->action = 1;
        sub_0807DD64(super);
    }
    ExecuteScriptForEntity(super, 0);
    HandleEntity0x82Actions(super);
    sub_08003FC4(super, 0x1000);
    tmp = super->type;
    super->type = type;
    sub_08080CB4(super);
    super->type = tmp;
}

void sub_080962D8(Object6AEntity* this) {
    DoFade(6, 0x100);
}

void sub_080962E8(Object6AEntity* this) {
    DoFade(7, 0x100);
}

void sub_080962F8(Object6AEntity* this, ScriptExecutionContext* ctx) {
    HitboxCfg* cfg = &gUnk_08122B3C[ctx->intVariable];
    sub_08078850(super, 1, cfg->_c, cfg->_8);
    super->hitbox = &cfg->hit;
}
