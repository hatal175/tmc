#include "global.h"
#include "structures.h"
#include "save.h"
#include "utils.h"

extern void sub_0807C960();
extern void LoadPalettes(const u8*, s32, s32);

extern u16 gMetatilesBottom[];
extern u16 gMetatilesTop[];
extern u8 gMapData;

extern const u8 gUnk_020176E0[];

void sub_0807C960(void* dest, u32 offset) {
    void* src;

    if (offset != -1) {
        src = &gMapData + (offset & 0x7fffffff);
        if ((u32)dest >> 0x18 == 6) {
            LZ77UnCompVram(src, (void*)dest);
        } else {
            LZ77UnCompWram(src, (void*)dest);
        }
    }
}

void sub_0807C998(u32* a1) {
    sub_0807C960(gMetatilesBottom, a1[0]);
    sub_0807C960(gMetatilesBottom - 0x1000, a1[1]);
    sub_0807C960(gMetatilesTop, a1[2]);
    sub_0807C960(gMetatilesTop - 0x1000, a1[3]);
}

void sub_0807C9D8(u32* a1) {
    u32* v1; // r5@1

    v1 = a1;
    sub_0807C960((u8*)0x6004000, *a1);
    sub_0807C960((u8*)0x6000000, v1[1]);
    sub_0807C960((u8*)0x6008000, v1[2]);
    sub_0807C960((u8*)gUnk_020176E0, v1[3]);
    LoadPalettes(gUnk_020176E0, 2, 13);
}

u8 sub_0807CA18() {
    if (gSave.unk_00 != 0x00 || gSave.unk_01 != 1) {
        gSave.unk_00 = 0;
        gSave.unk_01 = 1;
        gSave.global_progress = 1;
        gSave.stats.health = 24;
        gSave.stats.maxHealth = 24;
        gSave.saved_status.area_next = 0x22;
        gSave.saved_status.room_next = 0x15; // links room
        gSave.saved_status.start_anim = 0;
        gSave.saved_status.spawn_type = 0;
        gSave.saved_status.layer = 1;
        gSave.saved_status.start_pos.HALF.x = 0x90;
        gSave.saved_status.start_pos.HALF.y = 0x38;
    }
    if (gSave.playerName[0] == '\0') {
        MemCopy(gUnk_0811E470, &gSave.playerName, FILENAME_LENGTH - 1);
    }
#ifdef DEMO_USA
    {
        const u8* tmp;
        MemCopy(demoPointers[gSaveHeader->saveFileId], &gSave, 0x4B4);
        if (gSaveHeader->gameLanguage == 0) {
            gSave.playerName[0] = 0x97;
            gSave.playerName[1] = 0x7F;
            gSave.playerName[2] = 0xDD;
            gSave.playerName[3] = 0;
        }
        ModHealth(0xA0);
        ModRupees(-9999);
        tmp = demoUnknown1 + gUnk_02000010.field_0x7 * 3;
        gSave.unk48C[7] = tmp[gSaveHeader->saveFileId] * 3600;
    }
#endif
    return 1;
}
