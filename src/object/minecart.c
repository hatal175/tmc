#include "object.h"
#include "functions.h"

extern u32 sub_08091DDC(Entity*);
extern u32 sub_080002B4(Entity*, u32, u32);
extern u32 sub_08007DD6(u32, u32);
extern void sub_08017744(Entity*);
extern void sub_08091C0C(Entity*);

typedef struct {
    u16 field_0x0;
    u16 field_0x2;
    u8 field_0x4;
    u8 field_0x5;
    u8 field_0x6;
    u8 field_0x7;
} struct_030010EC;

extern void (*const gUnk_081223A8[])(Entity*);

extern struct_030010EC gUnk_030010EC[];
extern Hitbox gUnk_080FD310;

extern const s8 gUnk_081223C8[];
extern const u32 gUnk_081223D8[];

void Minecart(Entity* this) {
    gUnk_081223A8[this->action](this);
    this->bitfield = 0;
}

void sub_080916EC(Entity* this) {
    struct_030010EC* unk = &gUnk_030010EC[this->actionDelay];

    *(struct_030010EC**)&this->cutsceneBeh.HWORD = unk;
    if ((gRoomControls.roomID != unk->field_0x4) || (gPlayerState.flags & 0x1000) != 0) {
        DeleteThisEntity();
    }
    this->x.HALF.HI = gRoomControls.roomOriginX + ((unk->field_0x0 & 0x3f) << 4) + 8;
    this->y.HALF.HI = gRoomControls.roomOriginY + ((unk->field_0x0 & 0xfc << 4) >> 2) + 8;
    this->animationState = unk->field_0x5;
    this->type2 = unk->field_0x6;
    this->action = 1;
    this->hitbox = &gUnk_080FD310;
    COLLISION_ON(this);
    this->hitType = 1;
    this->field_0x3c = 0x47;
    this->hurtType = 0x44;
    this->flags2 = 0x80;
    this->direction = DirectionFromAnimationState(this->animationState);
    this->speed = 0x700;
    this->spritePriority.b1 = 3;
    InitAnimationForceUpdate(this, this->type2 + 4 + this->animationState);
    SetTile(0x4022, COORD_TO_TILE(this), this->collisionLayer);
}

void sub_080917DC(Entity* this) {

    if ((this->bitfield & 0x7f) == 0x1d) {
        this->zVelocity = 0x2a000;
        this->action = 7;
        InitAnimationForceUpdate(this, this->type2 + 4 + this->animationState);
        SoundReq(SFX_13B);
    } else {
        if (sub_0800445C(this) != 0) {
            if (((gPlayerState.flags & 0x40080) == 0) && (gPlayerState.field_0x1c == 0) &&
                (gPlayerState.heldObject == 0) && (gPlayerState.jumpStatus == 0)) {
                this->actionDelay++;
            } else {
                this->actionDelay = 0;
            }
        } else {
            this->actionDelay = 0;
        }
        if (this->type2 == 0) {
            if (8 < this->actionDelay) {
                this->action = this->action + 1;
                gPlayerState.jumpStatus = 0x81;
                gPlayerState.flags |= 0x4000000;
                gPlayerEntity.zVelocity = 0x20000;
                gPlayerEntity.speed = 0x100;
                gPlayerEntity.flags &= 0x7f;
                ResetPlayer();
                sub_0807A108();
                SoundReq(SFX_PLY_JUMP);
            }
        } else {
            this->actionDelay = 0;
        }
    }
}

void sub_080918A4(Entity* this) {
    if (EntityInRectRadius(this, &gPlayerEntity, 2, 2) != 0) {
        gPlayerEntity.x.HALF.HI = this->x.HALF.HI;
        gPlayerEntity.y.HALF.HI = this->y.HALF.HI;
        if (gPlayerEntity.z.HALF.HI > -0x10) {
            if ((s32)gPlayerEntity.zVelocity > -1) {
                return;
            }
            gPlayerEntity.animationState = this->animationState << 1;
            gPlayerState.flags = (gPlayerState.flags ^ 0x4000000) | 0x1000;
            this->action++;
            this->field_0xf = 1;
            this->flags |= ENT_20;
            this->hitType = 0x97;
            this->field_0x3c = (gPlayerEntity.field_0x3c + 1) | 0x20;
            this->flags2 = gPlayerEntity.flags2;
            this->hurtType = 0x18;
            this->damage = 8;
            sub_0801766C(this);
            sub_0807BA8C(COORD_TO_TILE(this), this->collisionLayer);
            SoundReq(SFX_137);
        }
    } else {
        gPlayerEntity.direction = GetFacingDirection(&gPlayerEntity, this);
    }
    if (gPlayerEntity.zVelocity < 0) {
        gPlayerEntity.spritePriority.b0 = this->spritePriority.b0 - 1;
    }
}

void sub_080919AC(Entity* this) {
    u32 iVar2;
    u32 uVar3;

    gRoomControls.unk5 = 7;
    if ((gPlayerState.flags & 0x1000) == 0) {
        this->action = 1;
        return;
    }

    if ((gPlayerEntity.frame & 0xf) == 0) {
        COLLISION_OFF(this);
        CopyPosition(this, &gPlayerEntity);
        if ((gPlayerEntity.frame & 0xf0) == 0x10) {
            this->spriteOffsetY = 1;
        } else {
            this->spriteOffsetY = 0;
        }
    } else {
        COLLISION_ON(this);
        gPlayerEntity.speed = 0;
        sub_0806F69C(this);
        CopyPosition(this, &gPlayerEntity);
        gPlayerEntity.spritePriority.b0 = this->spritePriority.b0 - 1;
        if (!sub_08091DDC(this)) {
            if ((gScreenTransition.frameCount & 0xf) == 0) {
                SoundReq(SFX_138);
            }

            if (--this->field_0xf == 0xff) {
                SoundReq(SFX_PLY_VO7);
                this->field_0xf = 0x3c;
            }

            uVar3 = sub_080002B4(this, gUnk_081223C8[this->animationState * 2],
                                 gUnk_081223C8[this->animationState * 2 + 1]);
            iVar2 = sub_08007DD6(uVar3, gUnk_081223D8[this->animationState]);
            if (iVar2 == 0) {
                this->direction = this->direction ^ 0x10;
                this->animationState = this->animationState ^ 2;
            } else {
                switch (uVar3) {
                    case 0x64:
                        this->flags &= ~ENT_20;
                        this->hitType = 1;
                        this->field_0x3c = 0x47;
                        this->hurtType = 0x44;
                        this->flags2 = 0x80;
                        this->action = 6;
                        sub_08017744(this);
                        gPlayerState.jumpStatus = 0x41;
                        gPlayerState.flags = (gPlayerState.flags ^ 0x1000) | 0x4000000;
                        gPlayerEntity.zVelocity = 0x20000;
                        gPlayerEntity.speed = 0x200;
                        gPlayerEntity.animationState = this->animationState << 1;
                        gPlayerEntity.direction = this->direction;
                        gPlayerEntity.flags |= 0x80;
                        sub_08004168(this);
                        InitAnimationForceUpdate(this, this->animationState + 0xc);
                        SoundReq(SFX_PLY_VO4);
                        SoundReq(SFX_139);
                        return;
                    case 0x67:
                    case 0x68:
                    case 0x69:
                    case 0x6a:
                    case 0x6c:
                    case 0x6d:
                    case 0x6e:
                    case 0x6f:
                        if (uVar3 == sub_080002B8(this)) {
                            sub_08091C0C(this);
                            gPlayerEntity.animationState = this->animationState << 1;
                            return;
                        }
                        break;
                }
            }

            gPlayerEntity.animationState = this->animationState << 1;
            if (this->animIndex == this->animationState) {
                UpdateAnimationSingleFrame(this);
            } else {
                InitAnimationForceUpdate(this, this->animationState);
            }
        }
    }
}
