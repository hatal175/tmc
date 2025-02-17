#include "item.h"
#include "functions.h"
#include "save.h"

extern void (*const gUnk_0811BD80[])(ItemBehavior*, u32);

extern void sub_08077E3C(ItemBehavior*, u32);

void ItemBow(ItemBehavior* this, u32 arg1) {
    gUnk_0811BD80[this->stateID](this, arg1);
}

void sub_08075DF4(ItemBehavior* this, u32 arg1) {
    if ((gPlayerState.field_0x3[1] & 8) == 0) {
        this->field_0x5[4] |= 0x80;
        sub_0806F948(&gPlayerEntity);
        sub_08077BB8(this);
        sub_08077D38(this, arg1);
        gPlayerState.field_0x1f[2] = 1;
    } else {
        sub_08077E78(this, arg1);
    }
}

void sub_08075E40(ItemBehavior* this, u32 arg1) {
    u8 bVar1;

    if (gPlayerState.field_0x1f[2] != 0) {
        bVar1 = gPlayerState.field_0x3[1] & 0x80;
        if (bVar1 == 0) {
            UpdateItemAnim(this);
            if ((this->field_0x5[9] & 0x80) != 0) {
                this->stateID = 2;
                this->field_0x5[4] &= 0x7f;
                if (gSave.stats.arrowCount != 0) {
                    this->field_0xf = bVar1;
                    gPlayerState.field_0xa &= ~(8 >> arg1);
                }
            }
            return;
        }
    }
    gPlayerState.field_0x1f[2] = 0;
    sub_08077E78(this, arg1);
}

void sub_08075EC0(ItemBehavior* this, u32 arg1) {
    u8 arrowCount;
    s32 iVar2;

    arrowCount = gSave.stats.arrowCount;
    iVar2 = sub_08077EFC(this);
    if (iVar2 != 0 && arrowCount != 0) {
        if (((gPlayerState.field_0x3[1] & 0x80) != 0) || (gPlayerState.field_0x1f[2] == 0)) {
            gPlayerState.field_0x1f[2] = 0;
            sub_08077E78(this, arg1);
        }
    } else {
        gPlayerState.field_0xa = (8 >> arg1) | gPlayerState.field_0xa;
        sub_08077DF4(this, 0x27c);
        this->field_0xf = 0xf;
        this->field_0x5[4] |= 0xf;
        this->stateID = 3;
    }
}

void sub_08075F38(ItemBehavior* this, u32 arg1) {
    if (((gPlayerState.field_0x3[1] & 0x80) == 0) && (gPlayerState.field_0x1f[2] != 0)) {
        UpdateItemAnim(this);
        if ((this->field_0x5[9] & 1) != 0) {
            this->stateID = 4;
        }
    } else {
        gPlayerState.field_0x1f[2] = 0;
        sub_08077E78(this, arg1);
    }
}

void sub_08075F84(ItemBehavior* this, u32 arg1) {
    if (((gPlayerState.field_0x3[1] & 0x80) == 0) && (gPlayerState.field_0x1f[2] != 0)) {
        if (GetInventoryValue(0x70) == 1) {
            sub_08077E3C(this, 5);
        } else {
            UpdateItemAnim(this);
        }
        if ((this->field_0x5[9] & 0x80) == 0) {
            return;
        }
    }
    gPlayerState.field_0x1f[2] = 0;
    sub_08077E78(this, arg1);
}
