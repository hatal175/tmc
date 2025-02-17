#include "enemy.h"
#include "object.h"
#include "textbox.h"
#include "structures.h"
#include "functions.h"
#include "save.h"
#include "screen.h"

extern u8 gEntCount;

void VaatiWrathType0PreAction(Entity*);
u32 sub_08041FCC(Entity*);
void sub_08042004(Entity*);
u32 sub_08041ED4(Entity*);
u32 sub_08041F74(Entity*, u32);
u32 sub_08041F1C(Entity*);
void sub_08042028(Entity*);
u32 sub_0804207C(Entity*);
void sub_0804212C(Entity*);
void sub_080421AC(Entity*);
void sub_08042120(Entity*);
void sub_0804235C(Entity*);
void sub_08042214(Entity*);
void sub_08042050(Entity*);
void sub_08041E78(Entity*);
void sub_08042264(Entity*);
u32 sub_080422C0(Entity*, u32);
void sub_0804228C(Entity*);

void VaatiWrathType0(Entity*);
void VaatiWrathType1(Entity*);
void VaatiWrathType2(Entity*);
void VaatiWrathType3(Entity*);
void VaatiWrathType0Action0(Entity*);
void VaatiWrathType0Action1(Entity*);
void VaatiWrathType0Action2(Entity*);
void VaatiWrathType0Action3(Entity*);
void VaatiWrathType0Action4(Entity*);
void VaatiWrathType0Action5(Entity*);
void VaatiWrathType0Action6(Entity*);
void VaatiWrathType0Action7(Entity*);
void VaatiWrathType0Action8(Entity*);
void VaatiWrathType0Action9(Entity*);
void VaatiWrathType0ActionA(Entity*);
void VaatiWrathType0ActionB(Entity*);
void VaatiWrathType0ActionC(Entity*);
void VaatiWrathType0ActionD(Entity*);
void sub_08041BE8(Entity*);
void sub_08041CD0(Entity*);
void sub_08041D14(Entity*);
void sub_08041D84(Entity*);
void sub_08041E20(Entity*);
void sub_08041E50(Entity*);

typedef struct {
    Entity* type0;
    Entity* type1;
    Entity* type2;
    Entity* type3;
    Entity* object5b;
    Entity* arms[2];
    Entity* eyes[4];
} VaatiWrathHeapStruct;

void (*const vaatiWrathTypes[])(Entity*) = {
    VaatiWrathType0,
    VaatiWrathType1,
    VaatiWrathType2,
    VaatiWrathType3,
};
void (*const vaatiWrathType0Actions[])(Entity*) = {
    VaatiWrathType0Action0, VaatiWrathType0Action1, VaatiWrathType0Action2, VaatiWrathType0Action3,
    VaatiWrathType0Action4, VaatiWrathType0Action5, VaatiWrathType0Action6, VaatiWrathType0Action7,
    VaatiWrathType0Action8, VaatiWrathType0Action9, VaatiWrathType0ActionA, VaatiWrathType0ActionB,
    VaatiWrathType0ActionC, VaatiWrathType0ActionD,
};

const u8 gUnk_080D0E64[] = { 0, -1, 0, 1 };

void (*const gUnk_080D0E68[])(Entity*) = {
    sub_08041BE8, sub_08041CD0, sub_08041D14, sub_08041D84, sub_08041E20, sub_08041E50,
};

const u16 gUnk_080D0E80[] = { 0x16c, 0x16d, 0x16e, 0x16f, 0x170, 0x171, 0x172, 0x173 };

const s8 gUnk_080D0E90[] = { 0x00, 0xf0, 0xf8, 0xe6, 0xff, 0x00, 0x0e, 0xe1,
                             0x02, 0xf4, 0xf1, 0x02, 0x04, 0xec, 0xf6, 0xf8 };

const s8 gUnk_080D0EA0[] = { 0xfc, 0xfb, 0xfa, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd };

const u8 gUnk_080D0EA8[] = { 0x78, 0xa0, 0xc8, 0xf0 };

const u8 gUnk_080D0EAC[] = { 0x3c, 0x50, 0x64, 0x78 };

const s8 gUnk_080D0EB0[] = { 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
                             0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xfe, 0xfe,
                             0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd };

void VaatiWrath(Entity* this) {
    if (((this->type == 0) && ((this->bitfield & 0x80) != 0)) && (this->health == 0)) {
        COLLISION_ON(this);
        this->health = 0xff;
        if (--this->cutsceneBeh.HALF.LO == 0) {
            this->action = 0xd;
            this->subAction = 0;
            SoundReq(SONG_STOP_ALL);
            SoundReq(SFX_BOSS_DIE);
        }
    }
    vaatiWrathTypes[this->type](this);
}

void VaatiWrathType0(Entity* this) {
#if !(defined EU || defined JP)
    VaatiWrathType0PreAction(this);
#endif
    vaatiWrathType0Actions[this->action](this);
}

void VaatiWrathType0Action0(Entity* this) {
    u32 bVar1;

    bVar1 = gScreenTransition.field_0x38 & 1;
    if (bVar1 != 0) {
        if (sub_08041FCC(this) == 0) {
            return;
        }
        if ((gScreenTransition.field_0x39 & 0xc) == 0) {
            this->action = 5;
            this->subAction = 1;
        } else {
            this->action = 2;
            this->actionDelay = 0x3c;
        }
        this->x.HALF.HI = gScreenTransition.hurtType;
        this->y.HALF.HI = gScreenTransition.field_0x42;
        sub_08042004(this);
    } else {
        if (sub_08041ED4(this) == 0) {
            return;
        }
        this->action = 1;
        this->subAction = bVar1;
        this->actionDelay = 120;
        this->spritePriority.b1 = 0;
        this->z.HALF.HI = 0xffb0;
        gRoomControls.cameraTarget = this;
        sub_080809D4();
    }
    this->spriteSettings.draw = 1;
    this->field_0x6c.HALF.HI |= 1;
    this->field_0x78.HALF.HI = 0;
    this->field_0x7c.HALF.LO = 0x3c;
    this->field_0x7c.HALF.HI = 0x78;
    this->cutsceneBeh.HALF.LO = 3;
    InitAnimationForceUpdate(this, 0);
}

void VaatiWrathType0Action1(Entity* this) {
    UpdateAnimationSingleFrame(this);
    switch (this->subAction) {
        case 0:
            break;
        case 1:
            this->spritePriority.b1 = 1;
            this->z.WORD += 0x8000;
            if ((this->z.HALF.HI & 0x3f) == 0) {
                SoundReq(SFX_1A9);
            }
            if (-6 < this->z.HALF.HI) {
                this->subAction = 2;
                SoundReq(SFX_1A9);
            }
            break;
        case 2:
            sub_08042004(this);
            if (this->actionDelay != 0) {
                this->actionDelay--;
            } else {
                if (sub_08041F74(this, 0) == 0) {
                    return;
                }
                this->subAction = 3;
                this->actionDelay = 0x3c;
            }
            break;
        case 3:
            sub_08042004(this);
            if (this->actionDelay != 0) {
                this->actionDelay--;
            } else {
                if (sub_08041F74(this, 1) != 0) {
                    this->subAction = 4;
                    this->actionDelay = 120;
                    this->field_0xf = 0;
                }
            }
            break;
        case 4:
            sub_08042004(this);
            if (--this->actionDelay == 0) {
                this->subAction = 5;
            } else {
                if ((this->actionDelay < 0x3d) && (this->field_0xf == 0)) {
                    if (sub_08041F1C(this) != 0) {
                        this->field_0xf = 1;
                    }
                }
            }
            break;
        case 5:
            sub_08042004(this);
            this->subAction = 6;
            this->actionDelay = 0x1e;
            gScreenTransition.field_0x38 |= 1;
            gRoomControls.cameraTarget = &gPlayerEntity;
            gPlayerState.controlMode = 1;
            break;
        default:
            sub_08042004(this);
            if (--this->actionDelay != 0) {
                return;
            }
            this->action = 2;
            this->actionDelay = 0x3c;
            break;
    }
}

void VaatiWrathType0Action2(Entity* this) {
    sub_08042004(this);
    UpdateAnimationSingleFrame(this);
    if (--this->actionDelay == 0) {
        this->field_0xf = (Random() & 1) + 1;
        sub_08042028(this);
    }
}

void VaatiWrathType0Action3(Entity* this) {
    s32 bound;
    s32 thisY;

    u32 roomY;

    sub_08042004(this);
    UpdateAnimationSingleFrame(this);
    ProcessMovement(this);

    roomY = gRoomControls.roomOriginY;
    bound = roomY + 0x90;
    thisY = this->y.HALF.HI;
    if ((bound < thisY)) {
        this->y.HALF.HI = bound;
    } else {
        bound = roomY + 0x40;
        if ((bound > thisY)) {
            this->y.HALF.HI = bound;
        }
    }

    if (--this->actionDelay == 0) {
        this->action = 4;
        this->actionDelay = 8;
    } else {
        if (this->actionDelay < 0x1e) {
            this->speed -= 8;
        } else {
            if (this->speed < 0x100) {
                this->speed += 6;
            }
        }
        if ((this->actionDelay & 3) == 0) {
            sub_08004596(this, sub_0804207C(this));
        }
    }
    sub_0804212C(this);
    sub_080421AC(this);
}

void VaatiWrathType0Action4(Entity* this) {
    sub_08042004(this);
    UpdateAnimationSingleFrame(this);
    if (--this->actionDelay == 0) {
        if (--this->field_0xf == 0) {
            sub_08042120(this);
        } else {
            sub_08042028(this);
        }
    }
}

void VaatiWrathType0Action5(Entity* this) {
    Entity* object;
    u32 subAction;
    Entity* arm;

    sub_08042004(this);
    UpdateAnimationSingleFrame(this);
    sub_0804212C(this);
    sub_080421AC(this);
    subAction = this->subAction;
    if (subAction == 0) {
        this->subAction = 1;
        if ((Random() & 1) != 0) {
            arm = ((VaatiWrathHeapStruct*)this->myHeap)->arms[0];
            if (arm == NULL) {
                arm = ((VaatiWrathHeapStruct*)this->myHeap)->arms[1];
            }
        } else {
            arm = ((VaatiWrathHeapStruct*)this->myHeap)->arms[1];
            if (arm == NULL) {
                arm = ((VaatiWrathHeapStruct*)this->myHeap)->arms[0];
            }
        }
        if (arm != NULL && arm->action == 2) {
            arm->action = 4;
            arm->subAction = 0;
        } else {
            this->field_0xf = (Random() & 1) + 1;
            sub_08042028(this);
        }
    } else {
        if (this->field_0x78.HALF.HI == 0) {
            if (this->subAction == 2) {
                if ((gScreenTransition.field_0x39 & 3) == 0) {
                    object = CreateObject(OBJECT_B5, 0, 0);
                    if (object != NULL) {
                        object->parent = this;
                        ((VaatiWrathHeapStruct*)this->myHeap)->object5b = object;
                        gRoomControls.cameraTarget = object;
                        this->action = 6;
                        this->actionDelay = 0x1e;
                        ((VaatiWrathHeapStruct*)this->myHeap)->type1->subAction = 1;
                        InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type1, 0xe);
                    }
                } else {
                    this->action = 2;
                    this->actionDelay = 0x3c;
                }
            }
        }
    }
}

void VaatiWrathType0Action6(Entity* this) {
    Entity* type1;

    if (this->actionDelay == 0) {
        type1 = ((VaatiWrathHeapStruct*)this->myHeap)->type1;
        GetNextFrame(type1);
        if (type1->frame == 1) {
            type1->frame &= 0xfe;
            InitAnimationForceUpdate(this, 4);
        } else {
            if (type1->frame == 2) {
                Entity* type3 = CreateEnemy(VAATI_WRATH, 3);
                if (type3 != NULL) {
                    type3->myHeap = this->myHeap;
                    ((VaatiWrathHeapStruct*)this->myHeap)->type3 = type3;
                    InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type2, 0x14);
                    type1->frame &= 0xfd;
                }
            } else {
                if ((type1->frame & 0x80) != 0) {
                    sub_0804235C(this);
                }
            }
        }
    } else {
        this->actionDelay--;
    }
    sub_08042004(this);
    UpdateAnimationSingleFrame(this);
}

void VaatiWrathType0Action7(Entity* this) {
    sub_08042214(this);
    sub_08042004(this);
    UpdateAnimationSingleFrame(this);
    if (gRoomControls.roomOriginY + 0x48 != this->y.HALF.HI) {
        this->speed = 0x100;
        this->direction = ((gRoomControls.roomOriginY + 0x48) >= this->y.HALF.HI) ? 0x10 : 0;
        sub_0806F69C(this);
    } else {
        if (--this->actionDelay == 0) {
            sub_08042050(this);
        }
    }
}

void VaatiWrathType0Action8(Entity* this) {
    sub_08042004(this);
    UpdateAnimationSingleFrame(this);
    sub_0806F69C(this);
    if (((gRoomControls.roomOriginX + 0x20) > this->x.HALF.HI) ||
        ((gRoomControls.roomOriginX + 0x140) < this->x.HALF.HI)) {
        if (0x3f < this->speed) {
            this->direction ^= 0x10;
        }
    }
    if (--this->actionDelay == 0) {
        this->action = 9;
        this->actionDelay = 0x3c;
    } else {
        if (this->actionDelay < 0x1e) {
            this->speed -= 0xc;
        } else {
            if (0x1ff >= this->speed)
                this->speed += 0x10;
        }
    }
    sub_08042214(this);
}

void VaatiWrathType0Action9(Entity* this) {
    sub_08042004(this);
    UpdateAnimationSingleFrame(this);
    if (this->field_0x78.HALF.HI != 0) {
        sub_08042214(this);
    } else {
        if (--this->actionDelay == 0) {
            if ((gPlayerEntity.x.HALF.HI - this->x.HALF.HI) + 0x40u < 0x81) {
                this->action = 10;
                this->field_0x7a.HALF.HI = 0;
                ((VaatiWrathHeapStruct*)this->myHeap)->eyes[0]->actionDelay = 1;
                ((VaatiWrathHeapStruct*)this->myHeap)->eyes[1]->actionDelay = 1;
                ((VaatiWrathHeapStruct*)this->myHeap)->eyes[2]->actionDelay = 1;
                ((VaatiWrathHeapStruct*)this->myHeap)->eyes[3]->actionDelay = 1;
            } else {
                this->action = 7;
                this->actionDelay = 0x1e;
                this->field_0x78.HALF.HI = 0;
            }
        }
    }
}

void VaatiWrathType0ActionA(Entity* this) {
    Entity* type1;

    sub_08042004(this);
    UpdateAnimationSingleFrame(this);
    if (this->field_0x7a.HALF.HI == 0x0f) {
        this->action = 7;
        this->actionDelay = 120;
        this->field_0x78.HALF.HI = 0;
    } else {
        if (this->field_0x7a.HALF.HI == 0xf0) {
            this->action = 0xb;
            this->subAction = 0;
            this->direction = 0;
            this->speed = 0x100;
            this->zVelocity = 0x12000;
            ChangeObjPalette(this, 0x16b);
            InitAnimationForceUpdate(this, 5);
            type1 = ((VaatiWrathHeapStruct*)this->myHeap)->type1;
            type1->subAction = 1;
            InitializeAnimation(type1, 0xf);
            InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type2, 0x15);
            InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type3, 0x1e);
            SoundReq(SFX_BOSS_HIT);
        }
    }
}

void VaatiWrathType0ActionB(Entity* this) {
    switch (this->subAction) {
        case 0:
            sub_0806F69C(this);
            UpdateAnimationSingleFrame(this);
            GetNextFrame(((VaatiWrathHeapStruct*)this->myHeap)->type1);
            GetNextFrame(((VaatiWrathHeapStruct*)this->myHeap)->type2);
            if (sub_08003FC4(this, 0x2000) == 0) {
                this->subAction = 1;
                this->actionDelay = 0xf0;
                this->health = 8;
                this->hitType = 0x38;
                sub_08080964(0x14, 0);
                InitAnimationForceUpdate(this, 6);
                InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type2, 0x16);
            }
            break;
        case 1:
            UpdateAnimationSingleFrame(this);
            GetNextFrame(((VaatiWrathHeapStruct*)this->myHeap)->type2);
            if (--this->actionDelay == 0) {
                this->subAction = 2;
                this->actionDelay = 0x3c;
                this->hitType = 0x39;
                this->health = 0xff;
            }
            break;
        default:
            this->spriteOffsetX = gUnk_080D0E64[--this->actionDelay & 3];
            if (this->actionDelay == 0) {
                this->action = 0xc;
                this->subAction = 0;
                ChangeObjPalette(this, 0x140);
                InitAnimationForceUpdate(this, 8);
                InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type1, 0x10);
                InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type2, 0x18);
            }
            break;
    }
}

void VaatiWrathType0ActionC(Entity* this) {
    Entity* entity;

    UpdateAnimationSingleFrame(this);
    GetNextFrame(((VaatiWrathHeapStruct*)this->myHeap)->type2);
    if (this->subAction != 0) {
        GetNextFrame(((VaatiWrathHeapStruct*)this->myHeap)->type1);
    }
    switch (this->subAction) {
        case 0:
            this->z.WORD -= 0x8000;
            if (this->z.HALF.HI < -4) {
                this->subAction = 1;
                this->actionDelay = 120;
                this->direction = 0x10;
                this->speed = 0x80;
            }
            break;
        case 1:
            sub_08042004(this);
            if (this->actionDelay) {
                this->actionDelay--;
            } else {
                sub_0806F69C(this);
                if (gRoomControls.roomOriginY + 0x48 == this->y.HALF.HI) {
                    this->subAction = 2;
                    InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type1, 0x11);
                    InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type2, 0x19);
                    InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type3, 0x1f);
                }
            }
            break;
        default:
            sub_08042004(this);
            entity = ((VaatiWrathHeapStruct*)this->myHeap)->type1;
            if (entity->frame & 1) {
                entity->frame &= 0xfe;
                InitAnimationForceUpdate(this, 9);
            } else {
                if (entity->frame & 0x80) {
                    sub_0804235C(this);
                }
            }
            break;
    }
}

void VaatiWrathType0ActionD(Entity* this) {
    gUnk_080D0E68[this->subAction](this);
}

void sub_08041BE8(Entity* this) {
    Entity* entity;

    if (sub_08079F8C() != 0) {
        this->subAction = 1;
        this->actionDelay = 120;
        this->updatePriority = PRIO_NO_BLOCK;
        InitAnimationForceUpdate(this, 10);

        entity = ((VaatiWrathHeapStruct*)this->myHeap)->type1;
        entity->myHeap = NULL;
        DeleteEntity(entity);
        ((VaatiWrathHeapStruct*)this->myHeap)->type1 = NULL;

        entity = ((VaatiWrathHeapStruct*)this->myHeap)->type2;
        entity->updatePriority = PRIO_NO_BLOCK;
        sub_080AE068(entity);
        LoadFixedGFX(entity, 0x1f5);
        ChangeObjPalette(entity, 0x16b);
        InitializeAnimation(entity, 0x1a);

        entity = ((VaatiWrathHeapStruct*)this->myHeap)->type3;
        entity->myHeap = NULL;
        DeleteEntity(entity);
        ((VaatiWrathHeapStruct*)this->myHeap)->type3 = NULL;
#ifndef EU
        entity = ((VaatiWrathHeapStruct*)this->myHeap)->object5b;
        entity->myHeap = NULL;
        DeleteEntity(entity);
        ((VaatiWrathHeapStruct*)this->myHeap)->object5b = NULL;

        gRoomControls.cameraTarget = &gPlayerEntity;
#endif
        entity = ((VaatiWrathHeapStruct*)this->myHeap)->eyes[0];
        entity->myHeap = NULL;
        DeleteEntity(entity);
        ((VaatiWrathHeapStruct*)this->myHeap)->eyes[0] = NULL;

        entity = ((VaatiWrathHeapStruct*)this->myHeap)->eyes[1];
        entity->myHeap = NULL;
        DeleteEntity(entity);
        ((VaatiWrathHeapStruct*)this->myHeap)->eyes[1] = NULL;

        entity = ((VaatiWrathHeapStruct*)this->myHeap)->eyes[2];
        entity->myHeap = NULL;
        DeleteEntity(entity);
        ((VaatiWrathHeapStruct*)this->myHeap)->eyes[2] = NULL;

        entity = ((VaatiWrathHeapStruct*)this->myHeap)->eyes[3];
        entity->myHeap = NULL;
        DeleteEntity(entity);
        ((VaatiWrathHeapStruct*)this->myHeap)->eyes[3] = NULL;

        SetPlayerControl(2);
    }
}

void sub_08041CD0(Entity* this) {
    GetNextFrame(((VaatiWrathHeapStruct*)this->myHeap)->type2);
    if (this->frame & 0x80) {
        if (this->actionDelay != 0) {
            this->actionDelay--;
        } else {
            this->subAction = 2;
            this->actionDelay = 0x3c;
            MessageFromTarget(0x1651);
        }
    } else {
        UpdateAnimationSingleFrame(this);
    }
}

void sub_08041D14(Entity* this) {
    Entity* pEVar1;

    GetNextFrame(((VaatiWrathHeapStruct*)this->myHeap)->type2);
    if ((gMessage.doTextBox & 0x7f) == 0) {
        if (this->actionDelay != 0) {
            this->actionDelay--;
        } else {
            if (gEntCount < 0x46) {
                pEVar1 = CreateObject(OBJECT_B6, 0, 0);
                pEVar1->parent = this;
                this->child = pEVar1;
                pEVar1 = CreateObject(OBJECT_B6, 1, 0);
                pEVar1->parent = this;
                this->subAction = 3;
                this->actionDelay = 0x96;
                this->field_0xf = 0;
                this->spriteSettings.draw = 0;
                SoundReq(SFX_1C4);
            }
        }
    }
}

void sub_08041D84(Entity* this) {
    GetNextFrame(((VaatiWrathHeapStruct*)this->myHeap)->type2);
    if (this->actionDelay != 0) {
        this->actionDelay--;
    } else {
        if (this->field_0xf < 0xf0) {
            if ((0xb7 < this->field_0xf) && ((this->field_0xf & 7) == 0)) {
                ChangeObjPalette(((VaatiWrathHeapStruct*)this->myHeap)->type2,
                                 gUnk_080D0E80[(this->field_0xf - 0xb8) >> 3]);
                ChangeObjPalette(this->child, gUnk_080D0E80[(this->field_0xf - 0xb8) >> 3]);
            }
            if (this->field_0xf == 0xe6) {
                DoFade(7, 4);
            }
        } else {
            this->subAction = 4;
            this->spriteSettings.draw = 1;
            ChangeObjPalette(this, 0x173);
            InitAnimationForceUpdate(this, 0xb);
        }
        this->field_0xf++;
        sub_08041E78(this);
    }
}

void sub_08041E20(Entity* this) {
    this->field_0xf += 1;
    sub_08041E78(this);
    GetNextFrame(((VaatiWrathHeapStruct*)this->myHeap)->type2);
    if (gFadeControl.active == 0) {
        this->subAction = 5;
        this->actionDelay = 0x5a;
    }
}

void sub_08041E50(Entity* this) {
    Entity* type2;

    if (--this->actionDelay == 0) {
        SetGlobalFlag(ENDING);
        type2 = ((VaatiWrathHeapStruct*)this->myHeap)->type2;
        type2->myHeap = NULL;
        DeleteEntity(type2);
        DeleteThisEntity();
    }
}

void sub_08041E78(Entity* this) {
    Entity* fx;
    const s8* temp;

    if ((this->field_0xf & 0xf) == 0) {
        fx = CreateFx(this, FX_GIANT_EXPLOSION4, 0);
        if (fx != NULL) {
            temp = &gUnk_080D0E90[this->field_0xf >> 3 & 0xe];
            fx->x.HALF.HI += *temp++;
            fx->y.HALF.HI += *temp;
            fx->spritePriority.b0 = 3;
            sub_08080964(4, 0);
        }
    }
}

u32 sub_08041ED4(Entity* this) {
    VaatiWrathHeapStruct* heap;
    Entity* entity;

    if (gEntCount < 0x46) {
        heap = zMalloc(sizeof(VaatiWrathHeapStruct));
        if (heap != NULL) {
            this->myHeap = (void*)heap;
            heap->type0 = this;
            heap->type3 = NULL;
            heap->arms[0] = NULL;
            heap->arms[1] = NULL;
            entity = CreateEnemy(VAATI_WRATH, 1);
            entity->myHeap = (void*)heap;
            heap->type1 = entity;
            entity = CreateEnemy(VAATI_WRATH, 2);
            entity->myHeap = (void*)heap;
            heap->type2 = entity;
            return 1;
        }
    }
    return 0;
}

u32 sub_08041F1C(Entity* this) {
    Entity* eye;

    if (!(gEntCount < 0x44)) {
        return 0;
    }

    eye = CreateEnemy(VAATI_WRATH_EYE, 0);
    eye->parent = this;
    ((VaatiWrathHeapStruct*)this->myHeap)->eyes[0] = eye;
    eye = CreateEnemy(VAATI_WRATH_EYE, 1);
    eye->parent = this;
    ((VaatiWrathHeapStruct*)this->myHeap)->eyes[1] = eye;
    eye = CreateEnemy(VAATI_WRATH_EYE, 2);
    eye->parent = this;
    ((VaatiWrathHeapStruct*)this->myHeap)->eyes[2] = eye;
    eye = CreateEnemy(VAATI_WRATH_EYE, 3);
    eye->parent = this;
    ((VaatiWrathHeapStruct*)this->myHeap)->eyes[3] = eye;
    return 1;
}

u32 sub_08041F74(Entity* this, u32 unk1) {
    Entity* arm;
    VaatiWrathHeapStruct* heap;

    if (!(gEntCount < 0x47)) {
        return 0;
    }
    heap = ((VaatiWrathHeapStruct*)this->myHeap);
    arm = NULL;
    if ((gScreenTransition.field_0x39 >> unk1 & 1U) != 0) {
        arm = CreateEnemy(VAATI_ARM, 0);
        arm->type2 = unk1;
        arm->parent = this;
        CopyPosition(this, arm);
    }
    if (unk1 == 0) {
        heap->arms[0] = arm;
    } else {
        heap->arms[1] = arm;
    }
    return 1;
}

u32 sub_08041FCC(Entity* this) {
    if (gEntCount < 0x4d) {
        if (sub_08041ED4(this)) {
            sub_08041F74(this, 0);
            sub_08041F74(this, 1);
            sub_08041F1C(this);
            return 1;
        }
    }
    return 0;
}

void sub_08042004(Entity* this) {
    this->z.HALF.HI = gUnk_080D0EA0[(++this->field_0x78.HALF.LO >> 4) & 7];
}

void sub_08042028(Entity* this) {
    this->action = 3;
    this->actionDelay = gUnk_080D0EA8[Random() & 3];
    this->speed = 0x40;
    this->direction = sub_0804207C(this);
}

void sub_08042050(Entity* this) {
    u32 uVar1;

    this->action = 8;
    uVar1 = Random();
    this->actionDelay = gUnk_080D0EAC[uVar1 & 3];
    this->speed = 0x20;
    this->direction = ((uVar1 >> 8) & 0x10) + 8;
}

u32 sub_0804207C(Entity* this) {
    Entity* arm;
    u32 x;
    u32 y;
    u32 tmp;

    x = this->x.HALF.HI;
    y = this->y.HALF.HI - 0x10;
    arm = ((VaatiWrathHeapStruct*)this->myHeap)->arms[0];
    if ((arm != NULL) && (arm->action >= 5) && sub_0806FCB8(arm, x, y, 0x30)) {
        return sub_080045D4(arm->x.HALF.HI, arm->y.HALF.HI, x, y);
    } else {
        arm = ((VaatiWrathHeapStruct*)this->myHeap)->arms[1];
        if (((arm != NULL) && (arm->action >= 5)) && sub_0806FCB8(arm, x, y, 0x30)) {
            return sub_080045D4(arm->x.HALF.HI, arm->y.HALF.HI, x, y);
        } else {
            if (gPlayerEntity.y.HALF.HI < 0x40) {
                tmp = gRoomControls.roomOriginY + 0x18;

            } else {
                tmp = gPlayerEntity.y.HALF.HI - 0x28;
            }
            return sub_080045D4(this->x.HALF.HI, this->y.HALF.HI, gPlayerEntity.x.HALF.HI, tmp);
        }
    }
}

void sub_08042120(Entity* this) {
    this->action = 5;
    this->subAction = 0;
}

void sub_0804212C(Entity* this) {
    Entity* arm;
    u32 y, x;

    if (this->field_0x7c.HALF.LO != 0u) {
        this->field_0x7c.HALF.LO--;
        return;
    }
    arm = NULL;
    y = this->y.HALF.HI - 0x44;
    if (gPlayerEntity.y.HALF.HI - y < 0x61u) {
        x = this->x.HALF.HI - 0x38;
        if (gPlayerEntity.x.HALF.HI - x < 0x39u) {
            arm = ((VaatiWrathHeapStruct*)this->myHeap)->arms[1];
        } else {
            if ((gPlayerEntity.x.HALF.HI - this->x.HALF.HI) < 0x39u) {
                arm = ((VaatiWrathHeapStruct*)this->myHeap)->arms[0];
            }
        }
    }
    if (arm != NULL) {
        if (arm->action != 2) {
            return;
        }
        if ((Random() & 1) == 0) {
            return;
        }
        arm->action = 3;
        arm->subAction = 0;
        this->field_0x7c.HALF.LO = 0x2d0;
    } else {
        this->field_0x7c.HALF.LO = 0x3c;
    }
}

void sub_080421AC(Entity* this) {
    if (this->field_0x7c.HALF_U.HI != 0) {
        this->field_0x7c.HALF_U.HI--;
    } else {
        if (this->field_0x78.HALF.HI == 0) {
            if (((Random() & 1) != 0) && ((gScreenTransition.field_0x39 & 0xc) != 0)) {
                sub_08042264(this);
                this->field_0x78.HALF.HI = 1;
                return;
            }
            this->field_0x7c.HALF_U.HI = 0x1e;
            return;
        }
        if (sub_080422C0(this, 0) == 0) {
            return;
        }
        this->field_0x78.HALF.HI = 0;
        this->field_0x7c.HALF_U.HI = 0x168;
    }
}

void sub_08042214(Entity* this) {
    if (this->field_0x7c.HALF_U.HI != 0) {
        this->field_0x7c.HALF_U.HI--;
    } else {
        if (this->field_0x78.HALF.HI == 0) {
            if ((Random() & 3) != 0) {
                sub_0804228C(this);
                this->field_0x78.HALF.HI = 1;
                return;
            }
            this->field_0x7c.HALF_U.HI = 0x1e;
        } else {
            if (sub_080422C0(this, 1) == 0) {
                return;
            }
            this->field_0x78.HALF.HI = 0;
            this->field_0x7c.HALF_U.HI = 0xb4;
        }
    }
}

void sub_08042264(Entity* this) {
    InitAnimationForceUpdate(this, 1);
    ((VaatiWrathHeapStruct*)this->myHeap)->type1->subAction = 1;
    InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type1, 0xd);
    InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type2, 0x13);
}

void sub_0804228C(Entity* this) {
    InitAnimationForceUpdate(this, 2);
    ((VaatiWrathHeapStruct*)this->myHeap)->type1->subAction = 1;
    InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type1, 0xd);
    InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type2, 0x13);
    InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type3, 0x1d);
}

u32 sub_080422C0(Entity* this, u32 unk1) {
    Entity* type1;
    Entity* child;
    u32 tmp;

    UpdateAnimationSingleFrame(this);
    GetNextFrame(((VaatiWrathHeapStruct*)this->myHeap)->type2);
    type1 = ((VaatiWrathHeapStruct*)this->myHeap)->type1;
    GetNextFrame(type1);
    if (unk1 + 1 == (tmp = type1->frame)) {
        child = CreateProjectile(0x21);
        if (child != NULL) {
            child->type = unk1;
            child->parent = this;
            type1->frame &= ~tmp;
        }
    } else {
        if (type1->frame == 4) {
            type1->frame &= 0xfb;
            InitAnimationForceUpdate(this, 3);
        } else {
            if (type1->frame & 0x80) {
                InitAnimationForceUpdate(this, 0);
                type1->subAction = 0;
                InitializeAnimation(type1, 0xc);
                InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type2, 0x12);
                if (unk1 == 1) {
                    InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type3, 0x1b);
                }
                return 1;
            }
        }
    }
    return 0;
}

void sub_0804235C(Entity* this) {
    Entity* type1;

    this->action = 7;
    this->actionDelay = 120;
    this->field_0x78.HALF.HI = 0;
    this->field_0x7c.HALF.HI = 0xf0;
    InitAnimationForceUpdate(this, 0);
    type1 = ((VaatiWrathHeapStruct*)this->myHeap)->type1;
    type1->subAction = 0;
    InitializeAnimation(type1, 0xc);
    InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type2, 0x12);
    InitializeAnimation(((VaatiWrathHeapStruct*)this->myHeap)->type3, 0x1b);
}

#if defined USA || defined DEMO_USA || defined DEMO_JP
void VaatiWrathType0PreAction(Entity* this) {
    int temp;
    if ((gScreenTransition.field_0x38 & 2) == 0) {
        if (gSave.unk48C[3] != 0) {
            gSave.unk48C[3]--;
        } else {
            temp = gPlayerState.framestate_last;
            if (temp < 2) {
                if (temp >= 0) {
                    if (gPlayerState.item == NULL) {
                        if (gPlayerEntity.field_0x7a.HWORD == 0) {
                            if ((gPlayerEntity.z.HALF.HI & 0x8000U) == 0 || (gPlayerState.field_0xa != 0)) {
                                CreateEzloHint(0xb70, 0);
                                gScreenTransition.field_0x38 |= 2;
                            }
                        }
                    }
                }
            }
        }
    }
}
#endif

void VaatiWrathType1(Entity* this) {
    if (((VaatiWrathHeapStruct*)this->myHeap)->type0->next == NULL) {
        this->myHeap = NULL;
        DeleteThisEntity();
    }
    if (this->action == 0) {
        this->action = 1;
        this->subAction = 0;
        InitializeAnimation(this, 0xc);
    }
    if (this->subAction == 0) {
        GetNextFrame(this);
    }
    if ((*(u32*)&this->animIndex & 0x8000ff) == 0x80000c) {
        InitializeAnimation(this, 0xc);
        this->frameDuration = (Random() & 0x78) + 0x78;
    }
    sub_0806FA90(((VaatiWrathHeapStruct*)this->myHeap)->type0, this, 0, 1);
    this->spriteOffsetY--;
}

void VaatiWrathType2(Entity* this) {
    u32 uVar1;

    if (((VaatiWrathHeapStruct*)this->myHeap)->type0->next == NULL) {
        this->myHeap = NULL;
        DeleteThisEntity();
    }
    if (this->action == 0) {
        this->action = 1;
        InitializeAnimation(this, 0x12);
    }
    sub_0806FA90(((VaatiWrathHeapStruct*)this->myHeap)->type0, this, 0, -1);
    this->spriteOffsetY += 1;
    if (this->animIndex == 0x12) {
        uVar1 = GetFacingDirection(this, &gPlayerEntity);
        this->x.HALF.HI = gUnk_080D0EB0[uVar1] + this->x.HALF.HI;
    }
}

void VaatiWrathType3(Entity* this) {
    if (((VaatiWrathHeapStruct*)this->myHeap)->type0->next == NULL) {
        this->myHeap = NULL;
        DeleteThisEntity();
    }
    if (this->action == 0) {
        this->action = 1;
        InitializeAnimation(this, 0x1c);
    }
    sub_0806FA90(((VaatiWrathHeapStruct*)this->myHeap)->type0, this, 0, -1);
    this->spriteOffsetY += 1;
    GetNextFrame(this);
}
