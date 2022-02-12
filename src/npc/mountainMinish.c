#include "entity.h"
#include "script.h"
#include "functions.h"
#include "message.h"
#include "flags.h"
#include "npc.h"

const u8 gUnk_08111284[][0x20];
const u8 gUnk_08111304[];
const u16 gUnk_0811130E[][4];
const SpriteLoadData gUnk_08111358[];

void sub_08067E60(Entity*);
void sub_08067E88(Entity*);
void sub_08067EE8(Entity*);

void sub_08067EF0(Entity*);
void sub_08068190(Entity*);

const u8 gUnk_08111284[][0x20] = {
    { 0x8, 0x1,  0x9, 0x1,  0xa, 0x1,  0xb, 0x83, 0xc, 0x83, 0xd, 0x83, 0xe, 0x83, 0xf, 0x80,
      0,   0x80, 0x1, 0x80, 0x2, 0x82, 0x3, 0x82, 0x4, 0x82, 0x5, 0x82, 0x6, 0x1,  0x7, 0x1 },
    { 0x8, 0x81, 0x9, 0x81, 0xa, 0x3,  0xb, 0x3,  0xc, 0x3,  0xd, 0x3,  0xe, 0x3,  0xf, 0x80,
      0,   0x80, 0x1, 0x80, 0x2, 0x80, 0x3, 0x82, 0x4, 0x82, 0x5, 0x82, 0x6, 0x81, 0x7, 0x81 },
    { 0x8, 0x81, 0x9, 0x81, 0xa, 0x83, 0xb, 0x83, 0xc, 0x83, 0xd, 0x83, 0xe, 0x0,  0xf, 0x0,
      0,   0x0,  0x1, 0x0,  0x2, 0x0,  0x3, 0x82, 0x4, 0x82, 0x5, 0x82, 0x6, 0x82, 0x7, 0x81 },
    { 0x8, 0x81, 0x9, 0x81, 0xa, 0x81, 0xb, 0x83, 0xc, 0x83, 0xd, 0x83, 0xe, 0x80, 0xf, 0x80,
      0,   0x80, 0x1, 0x80, 0x2, 0x2,  0x3, 0x2,  0x4, 0x2,  0x5, 0x2,  0x6, 0x2,  0x7, 0x81 },
};

const u8 gUnk_08111304[] = {
    10, 10, 3, 1, 0, 0, 0, 0, 0, 0,
};

const u16 gUnk_0811130E[][4] = {
    { 0x120b, 0x120b, 0x120b, 0x120b }, { 0x120c, 0x120c, 0x120c, 0x120c }, { 0x120d, 0x120e, 0x120e, 0x121f },
    { 0x120f, 0x120f, 0x120f, 0x120f }, { 0x1210, 0x1211, 0x1216, 0x1225 }, { 0x1212, 0x1212, 0x1217, 0x1217 },
    { 0x1213, 0x1213, 0x1217, 0x1217 }, { 0x122b, 0x122b, 0x122b, 0x122b }, { 0x1231, 0x1231, 0x1231, 0x1231 },
};

const SpriteLoadData gUnk_08111358[] = {
    { 0xb4, 0x1b, 0x4 },
    { 0x30b4, 0x1b, 0x4 },
    { 0x60b4, 0x1c, 0x4 },
    { 0x0, 0x0, 0x0 },
};

void MountainMinish(Entity* this) {
    static void (*const MountainMinish_Actions[])(Entity*) = {
        sub_08067E60,
        sub_08067E88,
        sub_08067EE8,
    };
    if ((this->flags & ENT_SCRIPTED) == 0) {
        MountainMinish_Actions[this->action](this);
        sub_0806ED78(this);
    } else {
        sub_08067EF0(this);
    }
}

void sub_08067E60(Entity* this) {
    if (LoadExtraSpriteData(this, gUnk_08111358) != 0) {
        this->action = 1;
        sub_08078778(this);
        InitializeAnimation(this, 2);
    }
}

void sub_08067E88(Entity* this) {
    s32 tmp;

    tmp = sub_0806ED9C(this, 0x28, 0x28);
    if (tmp < 0) {
        tmp = 2;
    } else {
        if (this->field_0xf == 0) {
            this->field_0xf = 0x10;
        } else {
            this->field_0xf = this->field_0xf - 1;
            tmp = this->animIndex;
        }
    }
    if (sub_0806F078(this, tmp) == 0) {
        GetNextFrame(this);
    }
    if (this->interactType != 0) {
        this->interactType = 0;
        this->action = 2;
        MessageFromTarget(this->actionDelay + 0x1200);
    }
}

void sub_08067EE8(Entity* this) {
    this->action = 1;
}

void sub_08067EF0(Entity* this) {
    static const u16 gUnk_08111374[] = {
        SFX_HAMMER1,
        SFX_HAMMER2,
        SFX_HAMMER3,
    };
    static const u16 gUnk_0811137A[] = {
        SFX_HAMMER4,
        SFX_HAMMER5,
        SFX_HAMMER6,
    };

    Entity* fxEnt;

    switch (this->action) {
        case 0:
            if (LoadExtraSpriteData(this, gUnk_08111358) == 0) {
                return;
            }
            this->action = 1;
            this->spriteSettings.draw = 1;
            this->animationState = this->type;
            this->field_0x68.HALF.HI = 0;
            SetDefaultPriority(this, 2);
            sub_0807DD50(this);
            InitializeAnimation(this, gUnk_08111304[this->type2]);
            break;
        case 1:
            if (this->interactType == 2) {
                this->action = 3;
                this->interactType = 0;
                this->field_0x68.HALF.HI = this->animIndex;
                InitializeAnimation(this, sub_0806F5A4(GetFacingDirection(this, &gPlayerEntity)));
                sub_0806F118(this);
            } else {
                ExecuteScriptForEntity(this, 0);
                HandleEntity0x82Actions(this);
                if ((this->type2 == 3) && (this->interactType != 0)) {
                    this->action = 2;
                    this->interactType = 0;
                    InitializeAnimation(this, sub_0806F5A4(GetFacingDirection(this, &gPlayerEntity)));
                    sub_08068190(this);
                }
            }
            break;
        case 2:
            if ((gMessage.doTextBox & 0x7f) != 0)
                break;
            this->action = 1;
            InitializeAnimation(this, (this->animationState >> 1) + 4);
            break;
        case 3:
            if (UpdateFuseInteraction(this) != 0) {
                this->action = 1;
                InitializeAnimation(this, this->field_0x68.HALF.HI);
            }
    }

    if (this->frameDuration != 0xff) {
        GetNextFrame(this);
    }
    if ((this->frameSpriteSettings & 1) != 0) {
        this->frameSpriteSettings &= 0xfe;
        if (CheckOnScreen(this) == 0) {
            SoundReq(gUnk_0811137A[((s32)Random()) % 3]);
        } else {
            EnqueueSFX(gUnk_08111374[((s32)Random()) % 3]);
        }
    }
    if ((this->frameSpriteSettings & 2) != 0) {
        this->frameSpriteSettings &= 0xfd;
        fxEnt = CreateFx(this, FX_ROCK, 0);
        if (fxEnt != NULL) {
            PositionRelative(this, fxEnt, 0, 0xffe80000);
        }
    }
    if ((this->frameSpriteSettings & 4) != 0) {
        this->frameSpriteSettings &= 0xfb;
        fxEnt = CreateFx(this, FX_STARS2, 0x20);
        if (fxEnt != NULL) {
            PositionRelative(this, fxEnt, 0xffec0000, 0xfff60000);
        }
    }
    if ((this->frameSpriteSettings & 8) != 0) {
        this->frameSpriteSettings &= 0xf7;
        this->frameDuration += Random() & 0x1f;
    }
}

void sub_08068104(Entity* this) {
    this->field_0x68.HALF.LO = sub_0801E99C(this);
    sub_08078784(this, this->field_0x68.HALF.LO);
}

void sub_0806811C(Entity* this) {
    u32 bVar1;
    u32 bVar2;
    int type;
    int iVar4;
    const u8* ptr;

    if (this->actionDelay) {
        this->actionDelay--;
    } else {
        this->actionDelay = 2;
        iVar4 = sub_0806EDD8(this, 0x20, 0x20);
        if (iVar4 < 0) {
            type = this->type;
            this->animationState = type;
            iVar4 = type << 2;
        }
        ptr = &gUnk_08111284[(this->animationState >> 1)][(iVar4 >> 1) * 2];
        bVar1 = ptr[0];
        bVar2 = ptr[1];
        if ((bVar2 & 0x80) != 0) {
            this->animationState = sub_0806F5B0(iVar4);
        }
        this->frame = bVar1 | 0x40;
        this->frameIndex = bVar2 & 0x7f;
        this->animIndex = 0;
        this->frameDuration = 0xff;
    }
}

void sub_08068190(Entity* this) {
    u32 uVar2;
    u32 uVar3;

    uVar3 = this->type2;
    if (uVar3 > 8) {
        uVar3 = 8;
    }

    uVar2 = 0;
    if (CheckLocalFlag(0x7e)) {
        uVar2 = 1;
    }
    if (GetInventoryValue(0x41) != 0) {
        uVar2 = 2;
    }
    if (GetInventoryValue(2) != 0) {
        uVar2 = 3;
    }

    MessageNoOverlap(gUnk_0811130E[uVar3][uVar2], this);
}

void sub_080681D8(Entity* this, ScriptExecutionContext* context) {
    this->type = context->intVariable;
}

void MountainMinish_Head(Entity* this) {
    u32 bVar1;

    bVar1 = this->frame & -0x81;
    SetExtraSpriteFrame(this, 1, this->frameIndex);
    if ((bVar1 & 0x40)) {
        SetExtraSpriteFrame(this, 0, (bVar1 & -0xe1) + 4);
        SetExtraSpriteFrame(this, 2, 0xff);
        SetSpriteSubEntryOffsetData1(this, 1, 0);
    } else {
        if ((bVar1 & 0x20)) {
            SetExtraSpriteFrame(this, 0, 0xff);
            SetExtraSpriteFrame(this, 2, bVar1 & -0xe1);
            SetSpriteSubEntryOffsetData1(this, 1, 2);
        } else {
            SetExtraSpriteFrame(this, 0, 0xff);
            SetExtraSpriteFrame(this, 2, 0xff);
        }
    }
    sub_0807000C(this);
}

void MountainMinish_Fusion(Entity* this) {
    if (this->action == 0) {
        if (LoadExtraSpriteData(this, gUnk_08111358) != 0) {
            this->action += 1;
            this->spriteSettings.draw = 1;
            InitializeAnimation(this, 6);
        }
    } else {
        GetNextFrame(this);
    }
}
