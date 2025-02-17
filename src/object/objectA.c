#include "global.h"
#include "entity.h"
#include "room.h"
#include "flags.h"
#include "object.h"
#include "functions.h"
#include "overworld.h"

extern Hitbox gHitbox_2;

extern u8 gUpdateVisibleTiles;

void ObjectA(Entity* this) {
    u32 uVar2;

    if (this->action == 0) {
        this->action = 1;
        this->hitbox = &gHitbox_2;
        if (this->collisionLayer == 1) {
            uVar2 = 0x26;
        } else {
            uVar2 = 0x34;
        }
        this->field_0x70.HALF.LO = uVar2;
        if (CheckFlags(this->field_0x86.HWORD) != 0) {
            SetTileType(*(u16*)&this->field_0x70.HALF.LO, COORD_TO_TILE(this), this->collisionLayer);
            if ((gRoomControls.unk2 & 1) != 0) {
                gUpdateVisibleTiles = 0;
            }
            DeleteThisEntity();
        } else {
            sub_080787CC(this);
        }
    } else if (this->interactType != 0) {
        SetTileType(*(u16*)&this->field_0x70.HALF.LO, COORD_TO_TILE(this), this->collisionLayer);
        SetFlag(this->field_0x86.HWORD);
        CreateDust(this);
        sub_080526F8(-1);
        DeleteThisEntity();
    }
}
