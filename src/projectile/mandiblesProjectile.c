#include "entity.h"
#include "enemy.h"
#include "coord.h"
#include "functions.h"
#include "game.h"

extern Entity* sub_08049DF4(u32);
extern u32 sub_08049F1C(Entity*, Entity*, u32);
extern s32 sub_080AF090(Entity*);
extern u32 sub_0806F824(Entity*, Entity*, u32, u32);
extern Hitbox gHitbox_0;

extern void (*const MandiblesProjectile_Functions[])(Entity*);
extern void (*const MandiblesProjectile_Actions[])(Entity*);
extern const u8 gUnk_08129CA4[];
extern const Hitbox* const gUnk_08129CF4[];
extern const u8 gUnk_08129CAC[];
extern const s8 gUnk_08129D14[];

void sub_080AA1D8(Entity*);
void sub_080AA270(Entity*);
bool32 sub_080AA2E0(Entity*);
void sub_080AA320(Entity*);
void sub_080AA3E0(Entity*, u32);
bool32 sub_080AA374(Entity*);

void MandiblesProjectile(Entity* this) {
    Entity* entity = this->child;
    if (entity == NULL) {
        entity = this->parent;
    }
    if ((entity->field_0x43 == 0) && ((this->flags & ENT_COLLIDE) == 0)) {
        COLLISION_ON(this);
    }
    MandiblesProjectile_Functions[GetNextFunction(this)](this);
}

void MandiblesProjectile_OnTick(Entity* this) {
    if (this->action < 3) {
        sub_080AA1D8(this);
    }
    MandiblesProjectile_Actions[this->action](this);
}

void sub_080A9EBC(Entity* this) {
    Entity* parent;

    if ((this->bitfield & 0x80) != 0) {
        switch (this->action) {
            case 4:
                this->field_0xf = 0;
                ModHealth(-2);
                sub_080AF090(this);
                UpdateAnimationSingleFrame(this);
                break;
            case 3:
                if (this->field_0x43 != 0) {
                    this->field_0x82.HALF.LO = 2;
                    this->animationState = 0xff;
                    sub_080AA270(this);
                    this->field_0xf = 0x20;
                }
                break;
            default:
                parent = this->parent;
                parent->iframes = this->iframes;
                parent->knockbackDirection = this->knockbackDirection;
                parent->knockbackDuration = this->knockbackDuration;
                if (this->action == 1) {
                    sub_080AA320(this);
                }
                break;
        }
        this->knockbackDuration = 0;
    }
}

void MandiblesProjectile_Init(Entity* this) {
    this->action = 1;
    this->field_0x80.HWORD = 0;
    this->animationState = 0xff;
    this->field_0x82.HALF.LO = 0;
    this->spritePriority.b0 = 4;
    ResolveEntityBelow(this, this->parent);
    sub_080AA270(this);
}

void MandiblesProjectile_Action1(Entity* this) {
    if (this->field_0x80.HWORD != 0) {
        this->field_0x80.HWORD -= 1;
    } else {
        if (--this->field_0xf == 0) {
            sub_080AA270(this);
        } else {
            if (sub_080AA2E0(this) != 0) {
                sub_080AA320(this);
            }
        }
    }
    UpdateAnimationSingleFrame(this);
}

void MandiblesProjectile_Action2(Entity* this) {
    UpdateAnimationSingleFrame(this);
    if ((this->frame & 0x40) != 0) {
        this->frame &= 0xbf;
        EnqueueSFX(SFX_15D);
    }
    this->field_0x78.HWORD = TILE(this->x.HALF.HI, this->y.HALF.HI);
    if (GetTileType(this->field_0x78.HWORD, this->collisionLayer) == 0x4000) {
        SetTile(0x4005, this->field_0x78.HWORD, this->collisionLayer);
    }
}

void MandiblesProjectile_Action3(Entity* this) {
    u32 uVar1;
    s8* tmp;
    Entity* entity;

    entity = this->child;
    if (entity == NULL) {
        DeleteThisEntity();
    }
    if (entity->next == NULL) {
        DeleteThisEntity();
    } else {
        tmp = GetSpriteSubEntryOffsetDataPointer((u16)entity->spriteIndex, entity->frameIndex);
        if ((entity->animationState & 4) != 0) {
            PositionRelative(entity, this, -tmp[0] * 0x10000, tmp[1] << 0x10);
        } else {
            PositionRelative(entity, this, tmp[0] << 0x10, tmp[1] << 0x10);
        }
    }
    if (entity->field_0x43 == 0) {
        if (this->field_0xf != 0) {
            this->field_0xf -= 1;
        } else {
            UpdateAnimationSingleFrame(this);
            if ((this->frame & 0x80) != 0) {
                this->action = 4;
                this->field_0x82.HALF.LO = 3;
                this->field_0xf = 0x40;
                uVar1 = entity->animationState;
                this->direction = uVar1 << 2;
                this->animationState = uVar1 << 0x1a >> 0x1a;

#ifdef EU
                this->spriteOrientation.flipY = 1;
#endif

                this->hitbox = &gHitbox_0;
#ifndef EU
                if (CheckIsDungeon() != 0) {
                    this->spriteOrientation.flipY = 1;
                }
#endif
                sub_080AA3E0(this, 0);
            }
        }
    }
}

void MandiblesProjectile_Action4(Entity* this) {
    s32 iVar1;
    u32 uVar2;
    Entity* entity;

    entity = this->child;
    if (entity != NULL) {
        if (entity->next == NULL) {
            this->child = NULL;
        }
        if (this->field_0xf != 0) {
            this->field_0xf -= 1;
        } else {
            if (sub_080AA374(this) != 0) {
                if (entity->health == 0) {
                    DeleteThisEntity();
                }
                EnqueueSFX(0xf2);
                this->action = 1;
                this->animationState = 0xff;
                this->field_0x82.HALF.LO = 0;
                this->actionDelay = 0;
                this->field_0x80.HWORD = 0x20;
                this->spriteOrientation.flipY = 2;
                this->parent = this->child;
                this->child = NULL;
                sub_080AA270(this);
                entity = this->parent;
                entity->action = 1;
                entity->direction = entity->animationState << 2;
                entity->speed = 0;
                entity->field_0x82.HALF.LO = 1;
                entity->actionDelay = 0;
                entity->field_0xf = 0x78;
                entity->field_0x80.HWORD = 0x20;
                sub_080AA3E0(entity, 1);
            }
        }
    } else {
        if (CheckOnScreen(this) == 0) {
            DeleteThisEntity();
        }
    }
    LinearMoveUpdate(this);
    UpdateAnimationSingleFrame(this);
}

void sub_080AA1D8(Entity* this) {
    s8* tmp;
    Entity* parent;

    parent = this->parent;
    if (parent != NULL) {
        if (parent->next == NULL) {
            DeleteThisEntity();
        }
        if ((parent->frameIndex & 0x20) == 0) {
            tmp = GetSpriteSubEntryOffsetDataPointer((u16)parent->spriteIndex, parent->frameIndex);
            if ((parent->animationState & 4) != 0) {
                PositionRelative(parent, this, -tmp[0] * 0x10000, tmp[1] << 0x10);
            } else {
                PositionRelative(parent, this, tmp[0] << 0x10, tmp[1] << 0x10);
            }
            if (parent->field_0x43 != 0) {
                if ((this->flags & ENT_COLLIDE) != 0) {
                    COLLISION_OFF(this);
                }
            } else {
                if ((this->flags & ENT_COLLIDE) == 0) {
                    COLLISION_ON(this);
                }
            }
        }
    } else {
        DeleteThisEntity();
    }
}

void sub_080AA270(Entity* this) {
    u32 animationState;
    Entity* parent;
    parent = this->parent;
    this->field_0xf = gUnk_08129CA4[Random() & 7];
    animationState = parent->animationState;
    if (this->animationState == 0xff) {
        this->animationState = animationState;
        this->hitbox = (Hitbox*)gUnk_08129CF4[animationState];
        sub_080AA3E0(this, 0);
    } else {
        animationState = (gUnk_08129CAC[Random() & 7] + animationState) & 7;
        if (animationState != this->animationState) {
            this->animationState = animationState;
            this->hitbox = (Hitbox*)gUnk_08129CF4[animationState];
            sub_080AA3E0(this, 0);
        }
    }
}

bool32 sub_080AA2E0(Entity* this) {
    Entity* entity;
    u32 a;
    u32 b;

    entity = sub_08049DF4(0);
    if (entity == NULL) {
        return FALSE;
    }
    a = GetFacingDirection(this, entity);
    b = this->animationState * 4;
    if (Direction8Round(a + 4) != Direction8Round(b + 4)) {
        return FALSE;
    }
    if (sub_08049F1C(this, entity, 0x40) == 0) {
        return FALSE;
    }
    return TRUE;
}

NONMATCH("asm/non_matching/mandiblesProjectile/sub_080AA320.inc", void sub_080AA320(Entity* this)) {
    u32 uVar2;
    Entity* parent;

    parent = this->parent;
    this->action = 2;
    this->field_0x82.HALF.LO = 1;
    this->field_0xf = 0;
    parent->action = 2;
    parent->field_0xf = 0x30;
    parent->field_0x80.HWORD = 0x50;
    parent->speed = 0;
    parent->direction = sub_08049F84(parent, 0);
    // TODO regalloc
    uVar2 = parent->direction + 4;
    this->animationState = Direction8Round(uVar2) >> 2;
    parent->animationState = DirectionRound(uVar2) >> 2;
    sub_080AA3E0(parent, 1);
    sub_080AA1D8(this);
}
END_NONMATCH

NONMATCH("asm/non_matching/mandiblesProjectile/sub_080AA374.inc", bool32 sub_080AA374(Entity* this)) {
    u32 uVar1;
    u32 animationState;
    Entity* entity;
    bool32 result;

    result = FALSE;
    if ((this->child != NULL) && (this->child->next != NULL)) {
        // TODO regalloc
        animationState = this->child->animationState;
        uVar1 = sub_0806F824(this, this->child, gUnk_08129D14[animationState], gUnk_08129D14[animationState + 1]);
        if (sub_0806FCB8(this, this->child->x.HALF.HI + gUnk_08129D14[animationState],
                         this->child->y.HALF.HI + gUnk_08129D14[animationState + 1], 8) != 0) {
            result = TRUE;
        } else {
            sub_08004596(this, uVar1);
        }
    }
    return result;
}
END_NONMATCH

void sub_080AA3E0(Entity* this, u32 param) {
    u32 tmp;

    tmp = this->animationState | this->field_0x82.HALF.LO << 3;
    if (param != 0) {
        tmp >>= 1;
    }
    InitAnimationForceUpdate(this, tmp);
}

void (*const MandiblesProjectile_Functions[])(Entity*) = {
    MandiblesProjectile_OnTick, sub_080A9EBC, DeleteEntity, DeleteEntity, DeleteEntity,
};
void (*const MandiblesProjectile_Actions[])(Entity*) = {
    MandiblesProjectile_Init,    MandiblesProjectile_Action1, MandiblesProjectile_Action2,
    MandiblesProjectile_Action3, MandiblesProjectile_Action4,
};
const u8 gUnk_08129CA4[] = { 24, 36, 52, 32, 60, 28, 44, 40 };
const u8 gUnk_08129CAC[] = {
    1, 0, 7, 1, 0, 7, 0, 0,
};
const Hitbox gUnk_08129CB4 = { 0, -4, { 5, 5, 3, 7 }, 6, 8 };
const Hitbox gUnk_08129CBC = { 3, -3, { 5, 3, 3, 5 }, 6, 6 };
const Hitbox gUnk_08129CC4 = { 4, 0, { 7, 3, 5, 5 }, 8, 6 };
const Hitbox gUnk_08129CCC = { 3, 3, { 5, 3, 3, 5 }, 6, 6 };
const Hitbox gUnk_08129CD4 = { 0, 4, { 5, 5, 3, 7 }, 6, 8 };
const Hitbox gUnk_08129CDC = { -3, 3, { 5, 3, 3, 5 }, 6, 6 };
const Hitbox gUnk_08129CE4 = { -4, 0, { 7, 3, 5, 5 }, 8, 6 };
const Hitbox gUnk_08129CEC = { -3, -3, { 5, 3, 3, 5 }, 6, 6 };
const Hitbox* const gUnk_08129CF4[] = {
    &gUnk_08129CB4, &gUnk_08129CBC, &gUnk_08129CC4, &gUnk_08129CCC,
    &gUnk_08129CD4, &gUnk_08129CDC, &gUnk_08129CE4, &gUnk_08129CEC,
};
const s8 gUnk_08129D14[] = { 0, -16, 6, -10, 0, 4, -6, -10 };
