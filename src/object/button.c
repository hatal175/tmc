#include "object.h"
#include "functions.h"

extern void (*const gUnk_0811EE38[])(Entity*);

void Button(Entity* this) {
    gUnk_0811EE38[this->action](this);
}

extern u32 sub_08081E3C(Entity*);

void sub_08081AE0(Entity* this) {
    COLLISION_OFF(this);
    this->updatePriority = PRIO_NO_BLOCK;
    this->y.HALF.HI++;
    if (this->cutsceneBeh.HWORD != 0) {
        this->collisionLayer = this->cutsceneBeh.HWORD;
    }
    this->field_0x74.HWORD = (((this->x.HALF.HI - gRoomControls.roomOriginX) >> 4) & 0x3F) |
                             ((((this->y.HALF.HI - gRoomControls.roomOriginY) >> 4) & 0x3F) << 6);
    this->field_0x70.HALF.HI = GetTileType(this->field_0x74.HWORD, this->collisionLayer);
    if (this->type == 0 && CheckFlags(this->field_0x86.HWORD)) {
        this->action = 5;
        SetTileType(0x7A, this->field_0x74.HWORD, this->collisionLayer);
    } else {
        if (sub_08081E3C(this)) {
            this->action = 2;
        } else {
            this->action = 1;
        }
    }
}

void sub_08081B84(Entity* this) {
    if (sub_08081E3C(this)) {
        this->action = 2;
        this->field_0x70.HALF.HI = GetTileType(this->field_0x74.HWORD, this->collisionLayer);
    }
}

u32 sub_08081CB0(Entity*);
void RequestPriorityDuration(Entity*, u32);
void sub_08081FF8(Entity*);

void sub_08081BAC(Entity* this) {
    if (sub_08081CB0(this)) {
        this->subAction = 0;
        this->actionDelay = 0xA;
        RequestPriorityDuration(this, 0xA);
        sub_08081FF8(this);
        if (this->type == 1) {
            this->action = 3;
        } else {
            this->action = 5;
        }
    }
}

u32 sub_08081F7C(Entity*, u32);
u32 sub_08081D28(Entity*);
void sub_08081E6C(Entity*);

void sub_08081BE0(Entity* this) {
    if (!sub_08081F7C(this, 0x78))
        return;
    if (!sub_08081D28(this)) {
        this->action = 4;
        this->field_0xf = 1;
        if ((gPlayerState.heldObject == 2) || (!(gPlayerState.field_0x34[1] & 0x80))) {
            this->actionDelay = 0x18;
        } else {
            this->actionDelay = 0x8;
        }
    } else {
        sub_08081E6C(this);
    }
}

void sub_08081C30(Entity* this) {
    if (this->actionDelay != 0) {
        this->actionDelay--;
        if (this->field_0xf != 0) {
            this->field_0xf = 0;
            SetTile(0x4035, this->field_0x74.HWORD, this->collisionLayer);
        }
        if (sub_08081CB0(this)) {
            this->action = 3;
            this->actionDelay = 0;
        }
    } else {
        this->action = 2;
        ClearFlag(this->field_0x86.HWORD);
        SetTileType(0x77, this->field_0x74.HWORD, this->collisionLayer);
        SoundReq(SFX_10C);
    }
}

void sub_08081C98(Entity* this) {
    if (sub_08081F7C(this, 0x7a)) {
        sub_08081E6C(this);
    }
}

Entity* sub_08081D74(Entity*);
u32 sub_080001DA(u32, u32);

u32 sub_08081CB0(Entity* this) {
    u16 tmp;
    if (sub_08081D74(this)) {
        this->field_0x70.HALF.LO = -1;
        if (GetTileType(this->field_0x74.HWORD, this->collisionLayer) == 0x4035) {
            sub_0807B7D8(0x78, this->field_0x74.HWORD, this->collisionLayer);
        }
        return 1;
    } else {
        tmp = GetTileType(this->field_0x74.HWORD, this->collisionLayer);
        if (tmp != 0x77 && tmp != 0x79 && tmp != 0x4035) {
            this->field_0x70.HALF.LO = sub_080001DA(this->field_0x74.HWORD, this->collisionLayer);
            return 1;
        }
    }
    return 0;
}

u32 sub_08081D28(Entity* this) {
    if (sub_08081D74(this)) {
        this->field_0x70.HALF_U.LO = 0xFFFF;
        return 1;
    } else {
        if (this->field_0x70.HALF_U.LO == 0xFFFF) {
            return 0;
        }
        if (sub_080001DA(this->field_0x74.HWORD, this->collisionLayer) != this->field_0x70.HALF_U.LO) {
            return 0;
        }
    }
    return 1;
}

extern u32 sub_080002E0(u32, u32);
extern Entity* gUnk_03004040[3];
u32 sub_08081E0C(Entity*);

Entity* sub_08081D74(Entity* this) {
    Entity* ent;
    if (sub_080002E0(this->field_0x74.HWORD, this->collisionLayer) == 0xF) {
        return 0;
    }
    ent = 0;
    if (sub_08081E0C(this)) {
        if (!(gPlayerState.flags & 0x10) && !(gPlayerState.flags & PL_MINISH)) {
            ent = &gPlayerEntity;
        }
    } else {
        if (gPlayerState.flags & 0x400000) {
            if (EntityInRectRadius(this, gUnk_03004040[0], 5, 6)) {
                ent = gUnk_03004040[0];
            } else if (EntityInRectRadius(this, gUnk_03004040[1], 5, 6)) {
                ent = gUnk_03004040[1];
            } else if (EntityInRectRadius(this, gUnk_03004040[2], 5, 6)) {
                ent = gUnk_03004040[2];
            }
        }
    }
    this->child = ent;
    return ent;
}

u32 sub_08081E0C(Entity* this) {
    Entity* tmp = &gPlayerEntity;
    if (tmp->z.HALF.HI != 0 || !sub_08079F8C()) {
        return 0;
    } else {
        return EntityInRectRadius(this, tmp, 5, 6);
    }
}

extern u16 gUnk_0811EE50[];

u32 sub_08081E3C(Entity* this) {
    u16* tmp1;
    int tmp2;
    tmp2 = GetTileType(this->field_0x74.HWORD, this->collisionLayer);
    tmp1 = gUnk_0811EE50;
    do {
        if (*tmp1 == tmp2)
            return 1;
    } while (*++tmp1);
    return 0;
}

u32 sub_08081F00(u32*, u32*);

extern u16 gMapDataTopSpecial[0x2000];

extern u16* GetLayerByIndex(u32);
extern u16 gUnk_02019EE0[];
NONMATCH("asm/non_matching/button/sub_08081E6C.inc", void sub_08081E6C(Entity* this)) {
    u32 r4;
    u16 *tmp, *r1;
    u16* tmp2;
    u32 r6 = this->field_0x74.HWORD;
    u32 r5 = this->collisionLayer;
    u32 tile = GetTileType(r6, r5);
    if (tile < 0x4000)
        return;
    r1 = GetLayerByIndex(r5);
    r4 = (this->type == 0 ? 0x7a : 0x78);
    tmp = r1 + 0x3802;
    r1 += 0x3002 + r4;
    tmp = tmp + (*r1 << 2);
    tmp2 = (r5 == 2 ? gMapDataTopSpecial : gUnk_02019EE0);
    tmp2 += (((0x3f & r6) << 1) + ((0xfc0 & r6) << 2)) << 1;
    if (sub_08081F00((u32*)tmp2, (u32*)tmp))
        return;
    SetTileType(r4, r6, r5);
    SetTile(tile, r6, r5);
}
END_NONMATCH

u32 sub_08081F00(u32* unk1, u32* unk2) {
    if (*unk1 != *unk2)
        return 0;
    if (unk1[0x40] != unk2[1])
        return 0;
    return 1;
}

void sub_08081F24(Entity* this) {
    Entity* fx = CreateFx(this, FX_DASH, 0x40);
    if (fx) {
        fx->updatePriority = PRIO_NO_BLOCK;
        fx->x.HALF.HI += 7;
        fx->y.HALF.HI += 5;
    }
    fx = CreateFx(this, FX_DASH, 0x40);
    if (fx) {
        fx->updatePriority = PRIO_NO_BLOCK;
        fx->x.HALF.HI -= 7;
        fx->y.HALF.HI += 5;
    }
}

u32 sub_08081F7C(Entity* this, u32 r7) {
    u16 tmp;
    if (this->actionDelay == 0)
        return 1;
    if (--this->actionDelay > 6) {
        if (this->child)
            this->child->spriteOffsetY = -4;
    } else {
        if (this->actionDelay == 6) {
            SetFlag(this->field_0x86.HWORD);
            SetTileType(r7, this->field_0x74.HWORD, this->collisionLayer);
            sub_08081F24(this);
            SoundReq(SFX_10C);
            if (this->field_0x70.HALF_U.LO != 0xFFFF)
                SetTile(this->field_0x70.HALF_U.LO, this->field_0x74.HWORD, this->collisionLayer);
            return 0;
        }
    }
    return 1;
}

extern void sub_080044AE(Entity*, u32, u32);

void sub_08081FF8(Entity* this) {
    u32 direction;
    u32 i;
    if (this->child != &gPlayerEntity)
        return;
    direction = GetFacingDirection(this->child, this);
    sub_080044AE(this->child, 0x200, direction);
    for (i = 0; i < 3; i++) {
        if (gUnk_03004040[i]) {
            sub_080044AE(gUnk_03004040[i], 0x200, direction);
        }
    }
}
