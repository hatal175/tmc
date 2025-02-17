#include "object.h"

extern void (*const gUnk_08121060[])(Entity*);
extern void (*const gUnk_08121070[])(Entity*);

extern s8 gUnk_08121068[];

void Smoke(Entity* this) {
    gUnk_08121060[this->type](this);
}

void sub_0808A40C(Entity* this) {
    Entity* ent;

    if (this->action == 0) {
        this->action = 1;
        this->actionDelay = 0x28;
    }
    if (--this->actionDelay == 0) {
        this->actionDelay = 0x40 - (Random() & 0x1f);
        ent = CreateObject(SMOKE, 1, 0);
        if (ent != NULL) {
            CopyPosition(this, ent);
            ent->x.HALF.HI += gUnk_08121068[(Random() & 7)];
        }
    }
}

void sub_0808A46C(Entity* this) {
    gUnk_08121070[this->action](this);
}

void sub_0808A484(Entity* this) {
    this->action = 1;
    this->spriteSettings.draw = TRUE;
    this->speed = 0x40;
    this->direction = 6;
    this->spriteRendering.b3 = 1;
    this->spritePriority.b0 = 0;
    this->spriteOrientation.flipY = 1;
    InitializeAnimation(this, 0x28);
}

void sub_0808A4D0(Entity* this) {
    GetNextFrame(this);
    sub_0806F69C(this);
    if (this->frame & 0x80) {
        DeleteEntity(this);
    }
}
