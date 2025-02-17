#include "global.h"
#include "functions.h"
#include "menu.h"
#include "structures.h"
#include "screen.h"

extern void (*const gUnk_081280C4[])();

void DrawKinstoneMenu(void) {
#if !(defined(DEMO_USA) || defined(DEMO_JP))
    gScreenTransition.player_status.field_0x24[8] = 2;
    FlushSprites();
    gUnk_081280C4[gMenu.menuType]();
    sub_080A3B74();
    sub_080A4054();
    sub_0801C1D4();
    sub_0801C208();
    UpdateEntities();
    sub_080AD9B0();
    sub_080AD918();
    gScreenTransition.player_status.field_0x24[8] = 0;
#endif
}

extern void gUnk_081280DC;

void sub_080A3BD0(void) {
    s32 iVar1;
    s32 iVar2;

    gMenu.column_idx = 1;
    gMenu.unk2a = 0;
    sub_080A4D34();
    LoadPaletteGroup(0xcb);
    LoadGfxGroup(0x75);

    iVar1 = sub_080A4494();
    iVar2 = iVar1 + 7;
    if (iVar2 < 0) {
        iVar2 += 0x7;
    }

    iVar1 = (iVar2 >> 3) - 6;
    iVar1 = max(iVar1, 0);
    iVar1 = min(iVar1, 6);

    LoadGfxGroup(iVar1 + 0x76);
    gScreen.lcd.displayControl |= 0x1e00;
    gScreen.bg1.control = 0x1c01;
    gScreen.bg2.control = 0x1d02;
    gScreen.bg3.control = 0x1e0b;
    gScreen.bg1.updated = 1;
    gScreen.bg2.updated = 1;
    gScreen.bg3.updated = 1;
    sub_080A4528();
    sub_080A4398();
    sub_0801E738(0);
    sub_080A70AC(&gUnk_081280DC);
    sub_080A7114(1);
    DoFade(6, 8);
}
