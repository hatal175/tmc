#include "entity.h"
#include "script.h"
#include "functions.h"
#include "fileScreen.h"
#include "screen.h"

extern void sub_08057044(u32, struct_020227E8*, u32);
extern bool32 sub_0802B234(Entity*);
extern u32 gUnk_081146B8;

void Phonograph(Entity* this) {
    if (this->action == 0) {
        this->action += 1;
        this->spriteSettings.draw = 1;
        this->field_0x68.HWORD = 1;
        this->field_0x6a.HWORD = 0xffff;
        sub_0807DD64(this);
        this->frameIndex = 0;
    }
    ExecuteScriptForEntity(this, NULL);
    HandleEntity0x82Actions(this);
}

ASM_FUNC("asm/non_matching/phonograph/sub_0806E964.inc",
         void sub_0806E964(Entity* this, ScriptExecutionContext* context))

void sub_0806EABC(Entity* this, u32 param) {
    sub_08050384();

#ifdef EU
    sub_08057044((s16)this->field_0x68.HWORD, &gUnk_020227E8[0], 0x202020);
#else
    sub_08057044(param, &gUnk_020227E8[0], 0x202020);
#endif

    sub_0805F46C(0x3302, &gUnk_081146B8);
    gScreen.bg0.updated = 1;
}
