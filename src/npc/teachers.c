#include "global.h"
#include "entity.h"
#include "player.h"
#include "save.h"
#include "script.h"
#include "npc.h"
#include "functions.h"

extern SpriteLoadData gUnk_08113910[];

extern Dialog gUnk_08113930[];

void Teachers(Entity* this) {
    switch (this->action) {
        case 0:
            if (LoadExtraSpriteData(this, &gUnk_08113910[this->type * 4])) {
                this->action = 1;
                this->spriteSettings.draw = TRUE;
                this->animationState = this->actionDelay;
                this->field_0x68.HALF.HI = 0;
                SetDefaultPriority(this, PRIO_MESSAGE);
                sub_0807DD50(this);
            }
            break;
        case 1:
            if (this->interactType == 2) {
                this->action = 2;
                this->interactType = 0;
                this->field_0x68.HALF.HI = this->animIndex;
                InitializeAnimation(this,
                                    (this->animIndex & -4) + sub_0806F5A4(GetFacingDirection(this, &gPlayerEntity)));
                sub_0806F118(this);
            } else {
                sub_0807DD94(this, NULL);
            }
            break;
        case 2:
            if (UpdateFuseInteraction(this)) {
                this->action = 1;
                InitializeAnimation(this, this->field_0x68.HALF.HI);
            }
    }
}

void sub_0806C674(Entity* this) {
    this->field_0x68.HALF.LO = sub_0801E99C(this);
    sub_08078784(this, this->field_0x68.HALF.LO);
}

void Teachers_Head(Entity* this) {
    u8 bVar1;
    u8 bVar2;
    u32 uVar3;

    uVar3 = this->frame & -0x81;
    bVar1 = this->frameIndex;
    bVar2 = this->frameSpriteSettings & 0x3f;
    if (this->type == 0) {
        SetExtraSpriteFrame(this, 0, (uVar3 + 3));
        SetExtraSpriteFrame(this, 1, bVar1);
        SetSpriteSubEntryOffsetData1(this, 1, 0);
        sub_0807000C(this);
    } else {
        SetExtraSpriteFrame(this, 0, (uVar3 + 6));
        SetExtraSpriteFrame(this, 1, ((bVar2) + 3));
        SetExtraSpriteFrame(this, 2, bVar1);
        SetSpriteSubEntryOffsetData1(this, 2, 1);
        SetSpriteSubEntryOffsetData2(this, 2, 0);
        sub_0807000C(this);
    }
}

void sub_0806C70C(Entity* this) {
    int offset;

    offset = gSave.global_progress - 2;
    if (offset < 0)
        offset = 0;

    ShowNPCDialogue(this, gUnk_08113930 + this->type * 8 + offset);
}

void Teachers_Fusion(Entity* this) {
    if (this->action == 0) {
        if (LoadExtraSpriteData(this, &gUnk_08113910[this->type * 4])) {
            this->action++;
            this->spriteSettings.draw = TRUE;
            InitializeAnimation(this, 2);
        }
    } else {
        GetNextFrame(this);
    }
}
