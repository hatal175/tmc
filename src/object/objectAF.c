#include "global.h"
#include "entity.h"
#include "coord.h"

extern void sub_080A0640(Entity*);

extern void (*const gUnk_081248C4[])(Entity*);

void ObjectAF(Entity* this) {
    gUnk_081248C4[this->action](this);
}

void sub_080A05A4(Entity* this) {
    if (this->type != 2) {
        this->action = 1;
        this->spritePriority.b0 = 6;
        sub_080A0640(this);
        InitializeAnimation(this, 1);
    } else {
        this->action = 2;
        this->y.HALF.HI++;
        this->z.HALF.HI = 0;
        this->spriteOffsetY--;
        InitializeAnimation(this, 3);
    }
}

void sub_080A05F4(Entity* this) {
    if (this->parent == NULL) {
        this->action = 2;
        InitializeAnimation(this, 2);
    } else {
        if (this->parent->next == NULL) {
            DeleteThisEntity();
        }
        sub_080A0640(this);
        GetNextFrame(this);
    }
}

void sub_080A0624(Entity* this) {
    GetNextFrame(this);
    if (this->frame & 0x80) {
        DeleteThisEntity();
    }
}

void sub_080A0640(Entity* this) {
    if (this->type == 0) {
        PositionRelative(*(Entity**)(this->parent->myHeap + 0x4), this, 0, 0x80000);
    } else {
        CopyPosition(this->parent, this);
    }
    this->z.HALF.HI = 0;
}
