#include "enemy.h"
#include "functions.h"

extern s32 sub_080012DC(Entity*);
bool32 PlayerInRange(Entity*, u32, u32);

void sub_08023E10(Entity*);
void sub_08023E54(Entity*);
void sub_08023E9C(Entity*);
void sub_0804A4E4(Entity*, Entity*);

extern void (*const gUnk_080012C8[])(Entity*);

extern void (*const gUnk_080CBDBC[])(Entity*);
extern void (*const gUnk_080CBDD4[])(Entity*);
extern void (*const gUnk_080CBDEC[])(Entity*);

extern const s8 gUnk_080CBDF4[];
extern const s8 gUnk_080CBDF7[];
extern const s8 gUnk_080CBDFF[];

void Sluggula(Entity* this) {
    if (this->type == 1) {
        EnemyFunctionHandler(this, gUnk_080CBDBC);

        SetChildOffset(this, 0, 1, -0x10);
    } else if (this->type == 0) {
        if (this->z.HALF.HI == 0) {
            u32 idx = sub_080012DC(this);
            if (idx != 0) {
                gUnk_080012C8[idx](this);
                return;
            }
        }
        gUnk_080CBDD4[GetNextFunction(this)](this);

        SetChildOffset(this, 0, 1, -0x10);
    } else {
        sub_08023E10(this);
    }
}

void sub_08023C08(Entity* this) {
    gUnk_080CBDEC[this->action](this);
}

void sub_08023C20(Entity* this) {
    if (this->field_0x43)
        sub_0804A9FC(this, 0x1c);

    if (this->type == 1) {
        sub_0804AA30(this, gUnk_080CBDBC);
    } else {
        sub_0804AA30(this, gUnk_080CBDD4);
    }
}

void nullsub_137(Entity* this) {
    /* ... */
}

void sub_08023C5C(Entity* this) {
    sub_0804A720(this);
    this->action = 1;
    this->actionDelay = (Random() & 0x30) + 0xb4;
    this->direction = DirectionRound(Random());
    this->animationState = this->direction >> 3;
    InitializeAnimation(this, this->animationState);
}

void sub_08023C8C(Entity* this) {
    ProcessMovement(this);
    GetNextFrame(this);
    sub_08023E54(this);
    if (--this->actionDelay == 0) {
        if (this->frame != 1) {
            this->actionDelay = 8;
        } else {
            this->actionDelay = (Random() & 0x30) + 0xb4;
            sub_08023E9C(this);
            this->animationState = this->direction >> 3;
            InitializeAnimation(this, this->animationState);
        }
    }
}

void sub_08023CE0(Entity* this) {
    switch (this->action) {
        case 0:
            sub_0804A720(this);
            if (this->type2 == 1) {
                this->action = 2;
                if (this->actionDelay == 0) {
                    this->actionDelay = 1;
                }
                this->spriteSettings.draw = 3;
            } else {
                this->action = 1;
            }
            this->z.HALF.HI = -0x80;
            this->spriteRendering.b3 = 1;
            this->spriteOrientation.flipY = 1;
            InitializeAnimation(this, 6);
            break;
        case 1:
            if (PlayerInRange(this, 1, 0x20)) {
                this->action = 2;
                if (this->actionDelay == 0) {
                    this->actionDelay = 8;
                }
                this->spriteSettings.draw = 3;
            }
            break;
        case 2:
            if (this->actionDelay != 0) {
                if (--this->actionDelay == 0) {
                    EnqueueSFX(0x12d);
                    InitializeAnimation(this, 4);
                }
            } else if (!sub_08003FC4(this, 0x1800)) {
                this->action = 3;
                this->spriteSettings.draw = 1;
                EnqueueSFX(0x84);
                UpdateSpriteForCollisionLayer(this);
            }
            break;
        default:
            GetNextFrame(this);
            if (this->frame) {
                if (this->frame & 0x80) {
                    Entity* ent = CreateEnemy(SLUGGULA, 1);
                    if (ent) {
                        sub_0804A4E4(this, ent);
                        DeleteThisEntity();
                    }
                } else {
                    this->y.HALF.HI += gUnk_080CBDF4[this->frame - 1];
                    this->frame = 0;
                }
            }
            break;
    }
}

void sub_08023E10(Entity* this) {
    if (this->action == 0) {
        this->action = 1;
        this->spritePriority.b0 = 6;
        InitializeAnimation(this, 5);
    }

    GetNextFrame(this);
    if (this->frame & 0x80)
        DeleteEntity(this);
}

void sub_08023E54(Entity* this) {
    Entity* ent;

    if (this->field_0xf++ > 27) {
        this->field_0xf = 0;
        ent = CreateEnemy(SLUGGULA, 2);
        if (ent) {
            const s8* ptr = &gUnk_080CBDF7[this->animationState * 2];
            PositionRelative(this, ent, ptr[0] << 0x10, ptr[1] << 0x10);
        }
    }
}

extern Entity* gUnk_020000B0;

void sub_08023E9C(Entity* this) {
    u32 uVar3 = Random();
    if (sub_08049FA0(this) == 0 && (uVar3 & 1)) {
        this->direction = DirectionRoundUp(sub_08049EE4(this));
    } else if (sub_08049FDC(this, 1) && (uVar3 & 6)) {
        u32 uVar3 = GetFacingDirection(this, gUnk_020000B0) - this->direction;
        if (uVar3 != 0 && ((uVar3 + 4) & 0x1f) > 8) {
            if ((uVar3 & 0x1f) < 0x10) {
                this->direction = DirectionRound(this->direction + 8);
            } else {
                this->direction = DirectionRound(this->direction - 8);
            }
        }
    } else {
        this->direction = DirectionRound(this->direction + gUnk_080CBDFF[(s32)(uVar3 >> 4) % 3]);
    }
}

// clang-format off
void (*const gUnk_080CBDBC[])(Entity*) = {
    sub_08023C08,
    sub_08023C20,
    sub_08001324,
    sub_0804A7D4,
    sub_08001242,
    nullsub_137,
};

void (*const gUnk_080CBDD4[])(Entity*) = {
    sub_08023CE0,
    sub_08023C20,
    sub_08001324,
    sub_0804A7D4,
    sub_08001242,
    nullsub_137,
};

void (*const gUnk_080CBDEC[])(Entity*) = {
    sub_08023C5C,
    sub_08023C8C,
};

const s8 gUnk_080CBDF4[] = {
    1, 2, 6,
};

const s8 gUnk_080CBDF7[] = {
    0, 2, -2, 2, 0, -2, 2, 2
};

const s8 gUnk_080CBDFF[] = {
    0, -8, 8,
};
// clang-format on
