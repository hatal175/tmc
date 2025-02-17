#include "entity.h"
#include "functions.h"
#include "room.h"
#include "save.h"
#include "utils.h"
#include "audio.h"
#include "flags.h"
#include "textbox.h"
#include "object.h"

Entity* GiveItemWithCutscene(u32, u32, u32);
Entity* sub_080A276C(Entity*, u32, u32);
void sub_08078AF0(Entity*, u32, u32);
Entity* sub_0805E744(void);
void sub_080A7D44(u32, u32);

void CreateItemEntity(u32 type, u32 type2, u32 delay) {
    Entity* e = GiveItemWithCutscene(type, type2, delay);
    if (e != NULL) {
        e->parent = sub_080A276C(e, e->type, 0);
    }
}

void sub_080A7C18(u32 type, u32 type2, u32 delay) {
    Entity* e = GiveItemWithCutscene(type, type2, delay);
    if (e != NULL) {
        e->parent = &gPlayerEntity;
        sub_08078AF0(e, e->type, 0);
    }
}

Entity* GiveItemWithCutscene(u32 type, u32 type2, u32 delay) {
    Entity* e;
    if (type == 63 && gSave.stats.filler3[0]) {
        type = 87;
        type2 = 0;
    }
    e = sub_0805E744();
    if (e != NULL) {
        e->type = type;
        e->type2 = type2;
        e->actionDelay = delay;
        e->id = OBJECT_B;
        e->kind = OBJECT;
        AppendEntityToList(e, 6);
    }
    return e;
}

void ClearSmallChests(void) {
    MemClear(gSmallChests, sizeof(gSmallChests));
}

void sub_080A7C8C(u32 pos, u32 layer) {
    TileEntity* t = gSmallChests;
    u32 found = 0;
    u32 i;
    for (i = 0; i < 8; ++i, ++t) {
        if (*(u16*)&t->_4 == pos) {
            found = 1;
            break;
        }
    }
    if ((layer >> 1) == ((u32)(t->_6 << 31) >> 31)) {
        if (found) {
            SetLocalFlag(t->_1);
            CreateItemEntity(t->_2, t->_3, 0);
        } else {
            CreateItemEntity(0x60, 0, 0);
        }
        sub_0807B7D8(0x74, pos, layer);
        RequestPriorityDuration(NULL, 120);
        SoundReq(SFX_CHEST_OPEN);
    }
}

u32 sub_080A7CFC(u32 a1) {
    u32 msg = 0x600;
    u32 isTileEntity6 = 0;
    TileEntity* t = GetCurrentRoomProperty(3);
    if (t != 0) {
        do {
            if (t->_4 == a1) {
                switch (t->type) {
                    case SIGN:
                        isTileEntity6 = 0;
                        msg = *(u16*)&t->_6;
                        break;
                    case TILE_ENTITY_6:
                        isTileEntity6 = 1;
                        msg = *(u16*)&t->_6;
                        break;
                }
                break;
            }
            t++;
        } while (t->_4 != 0);
    }
    sub_080A7D44(msg, isTileEntity6);
}

void sub_080A7D44(u32 msg, u32 isTileEntity6) {
    if (isTileEntity6)
        CreateEzloHint(msg, 0);
    else
        // Read sign text
        MessageFromTarget(msg);
}
