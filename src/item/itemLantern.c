#include "item.h"
#include "functions.h"
#include "audio.h"

extern void (*const gUnk_0811BD68[])(ItemBehavior*, u32);

extern s8 gUnk_08126EEC[];
extern Entity* sub_08077BD4(ItemBehavior*);

extern bool32 sub_08077F10(ItemBehavior*);

extern void sub_0807AB44(Entity*, s32, s32);

void ItemLantern(ItemBehavior* this, u32 arg1) {
    gUnk_0811BD68[this->stateID](this, arg1);
}

void sub_08075A0C(ItemBehavior* this, u32 arg1) {
    Entity* object;
    u32 itemSlot;
    s8* tmp;
    itemSlot = IsItemEquipped(this->behaviorID);
    if (gPlayerState.heldObject != 0 || gPlayerState.playerAction == 0x18 || gPlayerState.jumpStatus != 0 ||
        gPlayerState.item != NULL || (gPlayerState.flags & PL_MINISH) != 0) {
        ForceEquipItem(0xf, itemSlot);
        gPlayerState.flags &= 0xff7fffff;
        ForceEquipItem(0xf, itemSlot);
        sub_08077E78(this, arg1);
    } else {

        this->field_0x5[4] |= 0x80;
        sub_08077D38(this, arg1);
        sub_08077BD4(this);
        sub_0806F948(&gPlayerEntity);
        this->behaviorID = 0x10;
        ForceEquipItem(0x10, itemSlot);
        tmp = &gUnk_08126EEC[gPlayerEntity.animationState & 6];
        object = CreateObjectWithParent(&gPlayerEntity, 0x45, 1, 0);
        if (object != NULL) {
            object->spriteVramOffset = gPlayerEntity.spriteVramOffset;
            object->x.HALF.HI = tmp[0] + object->x.HALF.HI;
            object->y.HALF.HI = tmp[1] + object->y.HALF.HI;
        }
    }
}

#ifdef EU
ASM_FUNC("asm/non_matching/eu/sub_08075ADC.inc", void sub_08075ADC(ItemBehavior* this, u32 arg1))
#else
void sub_08075ADC(ItemBehavior* this, u32 arg1) {
    u32 bVar1;

    if (gPlayerState.item != NULL || (this->field_0x5[9] & 1) == 0 || (gPlayerState.flags & 0x110) != 0 ||
        sub_08079D48() == 0) {
        this->field_0xf = 0;
        this->stateID += 1;
        gPlayerState.flags |= 0x800000;
        bVar1 = 8 >> arg1;
        gPlayerState.field_0x3[1] = gPlayerState.field_0x3[1] & ~((bVar1 << 4) | bVar1);
        bVar1 = ~bVar1;
        gPlayerState.field_0xa = bVar1 & gPlayerState.field_0xa;
        gPlayerState.keepFacing = bVar1 & gPlayerState.keepFacing;
        SoundReq(SFX_ITEM_LANTERN_ON);
    } else {
        UpdateItemAnim(this);
    }
}
#endif

void sub_08075B54(ItemBehavior* this, u32 arg1) {
    u32 bVar1;
    u32 itemSlot;
    Entity* object;
    s8* tmp;

    if ((gPlayerState.flags & 0x110) == 0) {
        itemSlot = IsItemEquipped(this->behaviorID);
        if (!(((sub_08077F10(this) == 0) && (itemSlot < 2)) || (gPlayerState.jumpStatus != 0))) {
            ForceEquipItem(0xf, itemSlot);
            gPlayerState.flags &= 0xff7fffff;
            sub_08077E78(this, arg1);
            SoundReq(SFX_ITEM_LANTERN_OFF);
        } else {
            if (((gPlayerState.playerAction != 0x18) && (gPlayerEntity.frameIndex < 0x37)) &&
                ((u16)gPlayerEntity.spriteIndex == 6)) {
                tmp = &gUnk_08126EEC[gPlayerEntity.animationState & 6];

                if ((gPlayerState.jumpStatus == 0) &&
                    (sub_080002F0(TILE(gPlayerEntity.x.HALF.HI + tmp[0], gPlayerEntity.y.HALF.HI + tmp[1]),
                                  gPlayerEntity.collisionLayer, 0x40) != 0)) {
                    this->field_0xf = 0xf;
                    this->stateID += 1;
                    gPlayerEntity.field_0x7a.HWORD = 2;
                    object = CreateObjectWithParent(&gPlayerEntity, 0x45, 1, 0);
                    if (object != NULL) {
                        object->spriteVramOffset = gPlayerEntity.spriteVramOffset;
                        object->x.HALF.HI = tmp[0] + object->x.HALF.HI;
                        object->y.HALF.HI = tmp[1] + object->y.HALF.HI;
                    }
                    sub_08077DF4(this, 0x60c);
                    bVar1 = (8 >> (arg1));
                    gPlayerState.field_0xa = bVar1 | gPlayerState.field_0xa;
                    gPlayerState.keepFacing = bVar1 | gPlayerState.keepFacing;
                }
            }
        }
    }
}

void sub_08075C9C(ItemBehavior* this, u32 arg1) {
    s8* tmp;

    UpdateItemAnim(this);
    if ((this->field_0x5[9] & 0x10) != 0) {
        tmp = &gUnk_08126EEC[gPlayerEntity.animationState & 6];
        sub_0807AB44(&gPlayerEntity, tmp[0], tmp[1]);
    }
    if ((this->field_0x5[9] & 0x80) != 0) {
        this->field_0xf = 0;
        this->stateID -= 1;
        gPlayerState.field_0xa = (~(8 >> arg1)) & gPlayerState.field_0xa;
        gPlayerState.keepFacing = (~(8 >> arg1)) & gPlayerState.keepFacing;
    } else {
        gPlayerEntity.field_0x7a.HWORD += 1;
    }
}
