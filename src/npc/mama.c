#include "entity.h"
#include "script.h"
#include "functions.h"
#include "save.h"
#include "npc.h"

extern Dialog gUnk_08113760[];

extern SpriteLoadData gUnk_08113754;

bool32 sub_0806C454(Entity* this);

void Mama(Entity* this) {
    switch (this->action) {
        case 0:
            if (sub_0806C454(this) != 0) {
                this->action = 1;
                this->spriteSettings.draw = 1;
                this->animationState = this->actionDelay;
                this->field_0x68.HALF.HI = 0;
                sub_0807DD50(this);
            }
            break;
        case 1:
            if (this->interactType == 2) {
                this->action = 2;
                this->interactType = 0;
                this->field_0x68.HALF.HI = this->animIndex;
                InitializeAnimation(this, sub_0806F5A4(GetFacingDirection(this, &gPlayerEntity)));
                sub_0806F118(this);
            } else {
                ExecuteScriptForEntity(this, NULL);
                HandleEntity0x82Actions(this);
                GetNextFrame(this);
            }
            break;

        case 2:
            if (UpdateFuseInteraction(this) != 0) {
                this->action = 1;
                InitializeAnimation(this, this->field_0x68.HALF.HI);
            }
            break;
    }
}

bool32 sub_0806C454(Entity* this) {
    if (LoadExtraSpriteData(this, &gUnk_08113754) == 0) {
        return FALSE;
    } else {
        SetDefaultPriority(this, PRIO_MESSAGE);
        return TRUE;
    }
}

void Mama_Head(Entity* this) {
    SetExtraSpriteFrame(this, 0, this->frame & 0x7f);
    SetExtraSpriteFrame(this, 1, this->frameIndex);
    SetSpriteSubEntryOffsetData1(this, 1, 0);
    sub_0807000C(this);
}

void sub_0806C4A8(Entity* this, ScriptExecutionContext* context) {
    s32 tmp;
    if ((this->frame & 0x80) != 0) {
        tmp = GetAnimationState(this);
        if (tmp < 0) {
            tmp = 3;
        }
        this->animationState = tmp * 2;
        InitAnimationForceUpdate(this, tmp);
        context->condition = 1;
    } else {
        context->condition = 0;
    }
}

void sub_0806C4DC(Entity* this) {
    ShowNPCDialogue(this, &gUnk_08113760[gSave.global_progress]);
}

void sub_0806C4F8(Entity* this) {
    this->field_0x68.HALF.LO = sub_0801E99C(this);
    sub_08078784(this, this->field_0x68.HALF.LO);
}

void Mama_Fusion(Entity* this) {
    if (this->action == 0) {
        if (sub_0806C454(this) != 0) {
            this->action += 1;
            this->spriteSettings.draw = 1;
            this->y.HALF.HI -= 4;
            InitializeAnimation(this, 2);
        }
    } else {
        GetNextFrame(this);
    }
}
