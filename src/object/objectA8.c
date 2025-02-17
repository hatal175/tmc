#include "global.h"
#include "entity.h"
#include "player.h"
#include "functions.h"

extern void (*gUnk_08124824[])(Entity*);

void ObjectA8(Entity* this) {
    if ((this->bitfield & 0x80) != 0) {
        switch (this->bitfield & 0x7f) {
            case 0:
            case 1:
            case 4:
            case 5:
            case 6:
            case 8:
            case 9:
            case 10:
            case 0xb:
            case 0xc:
            case 0x1e:
            case 0x1f:
                this->action = 5;
                this->child = &gPlayerEntity;
                CreateItemEntity(this->type, 0, 0);
                DeleteThisEntity();
        }
    }
    gUnk_08124824[this->action](this);
    sub_08080CB4(this);
}
