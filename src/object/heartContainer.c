#include "global.h"
#include "audio.h"
#include "entity.h"
#include "flags.h"
#include "functions.h"

static void sub_0808E6A0(Entity*);
static void sub_0808E6E4(Entity*);
static void sub_0808E714(Entity*);
static void sub_0808E764(Entity*);

static void (*const gHeartContainerActions[])(Entity*) = {
    sub_0808E6A0,
    sub_0808E6E4,
    sub_0808E714,
    sub_0808E764,
};

extern Hitbox gUnk_08121C58;

void HeartContainer(Entity* this) {
    gHeartContainerActions[this->action](this);
}

static void sub_0808E6A0(Entity* this) {
    if (CheckFlags(this->cutsceneBeh.HWORD)) {
        DeleteThisEntity();
    }
    this->action = 1;
    this->type = 0x62;
    this->spriteSettings.draw = 0;
    this->hitbox = &gUnk_08121C58;
    this->collisionLayer = 3;
    this->updatePriority = PRIO_NO_BLOCK;
}

static void sub_0808E6E4(Entity* this) {
    if (CheckFlags(this->field_0x86.HWORD)) {
        this->action = 2;
        this->spriteSettings.draw = 1;
        this->spriteRendering.b0 = 3;
        sub_0808E714(this);
    }
}

static void sub_0808E714(Entity* this) {
    int var0 = 0x400 - this->field_0xf * 8;
    if (var0 > 0x100) {
        this->field_0xf++;
        sub_0805EC9C(this, var0, var0, 0);
    } else {
        this->action = 3;
        this->field_0x3c |= 0x10;
        sub_0805EC60(this);
        SoundReq(SFX_HEART_CONTAINER_SPAWN);
    }
    sub_08080CB4(this);
}

static void sub_0808E764(Entity* this) {
    sub_08080CB4(this);
    if (!(gPlayerState.flags & PL_MINISH) && sub_08017850(this)) {
        SetFlag(this->cutsceneBeh.HWORD);
        CreateItemEntity(0x62, 0, 0);
        DeleteThisEntity();
    }
}
