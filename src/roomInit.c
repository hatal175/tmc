#include "global.h"
#include "main.h"
#include "common.h"
#include "functions.h"
#include "sound.h"
#include "effects.h"
#include "screen.h"
#include "flags.h"
#include "item.h"
#include "save.h"
#include "area.h"
#include "game.h"
#include "npc.h"
#include "kinstone.h"
#include "object.h"

extern u32 sub_08060354(void);
extern void sub_08057E64(void);
extern void sub_0809F814(u32);
extern void sub_080300E8(void);
extern void sub_08058D34(void);
extern void sub_0807BB98(u32, u32, u32, u32);
extern void sub_080AF2E4(void);
extern void sub_08059994(void);

static void sub_0804E150(void);
static void sub_0804D0B4(void);
static void sub_0804D9B0(void);
static void sub_0804ED18(void);
static void sub_0804F578(void);
extern void sub_080AF250(u32);
extern void sub_0804AFB0(void**);
extern void sub_0804AF90(void);
void sub_080AF250();
void sub_0804C290();
void sub_0804C258();

extern void** gCurrentRoomProperties;

u32 sub_unk3_ArmosInteriors_RuinsEntranceNorth(u32 arg0) {
    return 1;
}

void sub_StateChange_ArmosInteriors_RuinsEntranceNorth(void) {
    sub_08030118(0);
}

u32 sub_unk3_ArmosInteriors_RuinsEntranceSouth(void) {
    return 1;
}

void sub_StateChange_ArmosInteriors_RuinsEntranceSouth(void) {
    sub_08030118(1);
}

u32 sub_unk3_ArmosInteriors_RuinsLeft(void) {
    return 1;
}

void sub_StateChange_ArmosInteriors_RuinsLeft(void) {
    sub_08030118(2);
}

u32 sub_unk3_ArmosInteriors_RuinsMiddleLeft(void) {
    return 1;
}

void sub_StateChange_ArmosInteriors_RuinsMiddleLeft(void) {
    sub_08030118(3);
}

u32 sub_unk3_ArmosInteriors_RuinsMiddleRight(void) {
    return 1;
}

void sub_StateChange_ArmosInteriors_RuinsMiddleRight(void) {
    sub_08030118(4);
}

u32 sub_unk3_ArmosInteriors_RuinsRight(void) {
    return 1;
}

void sub_StateChange_ArmosInteriors_RuinsRight(void) {
    sub_08030118(5);
}

u32 sub_unk3_ArmosInteriors_6(void) {
    return 1;
}

void sub_StateChange_ArmosInteriors_6(void) {
    sub_08030118(6);
}

u32 sub_unk3_ArmosInteriors_RuinsGrassPath(void) {
    return 1;
}

void sub_StateChange_ArmosInteriors_RuinsGrassPath(void) {
    sub_08030118(7);
}

u32 sub_unk3_ArmosInteriors_8(void) {
    return 1;
}

void sub_StateChange_ArmosInteriors_8(void) {
    sub_08030118(8);
}

u32 sub_unk3_ArmosInteriors_FortressOfWindsLeft(void) {
    return 1;
}

void sub_StateChange_ArmosInteriors_FortressOfWindsLeft(void) {
    sub_08030118(9);
    gArea.dungeon_idx = 3;
    gArea.areaMetadata = 0x4e;
}

u32 sub_unk3_ArmosInteriors_FortressOfWindsRight(void) {
    return 1;
}

void sub_StateChange_ArmosInteriors_FortressOfWindsRight(void) {
    sub_08030118(10);
    gArea.dungeon_idx = 3;
    gArea.areaMetadata = 0x4e;
}

u32 sub_unk3_CrenelMinishPaths_CrenelBean(void) {
    return 1;
}

void sub_StateChange_CrenelMinishPaths_CrenelBean(void) {
    sub_080575C8(35);
    sub_08057688();
}

u32 sub_unk3_CrenelMinishPaths_CrenelWater(void) {
    return 1;
}

void sub_StateChange_CrenelMinishPaths_CrenelWater(void) {
    sub_080575C8(35);
}

void sub_unk1_CrenelMinishPaths_CrenelWater(void) {
    sub_080575C8(35);
}

u32 sub_unk3_CrenelMinishPaths_Rainfall(void) {
    return 1;
}

void sub_StateChange_CrenelMinishPaths_Rainfall(void) {
    sub_080580B0(34);
}

void sub_unk1_CrenelMinishPaths_Rainfall(void) {
    sub_080580B0(34);
}

u32 sub_unk3_CrenelMinishPaths_MelarisMine(void) {
    return 1;
}

void sub_StateChange_CrenelMinishPaths_MelarisMine(void) {
    sub_080580B0(0x22);
    // white sword
    if (GetInventoryValue(0x2))
        SetGlobalFlag(WHITE_SWORD_END);
}

void sub_unk1_CrenelMinishPaths_MelarisMine(void) {
    sub_080580B0(34);
}

u32 sub_unk3_MinishPaths1_ToMinishVillage(void) {
    return 1;
}

void sub_StateChange_MinishPaths1_ToMinishVillage(void) {
    sub_080575C8(30);
}

void sub_unk1_MinishPaths1_ToMinishVillage(void) {
    sub_080575C8(30);
}

u32 sub_unk3_MinishPaths1_CastorWilds(void) {
    return 1;
}

void sub_StateChange_MinishPaths1_CastorWilds(void) {
    sub_080575C8(33);
}

void sub_unk1_MinishPaths1_CastorWilds(void) {
    sub_080575C8(33);
}

u32 sub_unk3_MinishPaths1_HyruleTown(void) {
    return 1;
}

void sub_StateChange_MinishPaths1_HyruleTown(void) {
    sub_080575C8(31);
}

void sub_unk1_MinishPaths1_HyruleTown(void) {
    sub_080575C8(31);
}

u32 sub_unk3_MinishPaths1_LonLonRanch(void) {
    return 1;
}

void sub_StateChange_MinishPaths1_LonLonRanch(void) {
    sub_080575C8(32);
}

void sub_unk1_MinishPaths1_LonLonRanch(void) {
    sub_080575C8(32);
}

u32 sub_unk3_MinishPaths1_MayorsCabin(void) {
    return 1;
}

extern EntityData Entities_MinishPaths1_MayorsCabin_gUnk_080D6138;

void sub_StateChange_MinishPaths1_MayorsCabin(void) {

    sub_080575C8(0x20);

    if (gPlayerEntity.y.HALF.HI - gRoomControls.origin_y > 0x40)
        LoadRoomEntityList(&Entities_MinishPaths1_MayorsCabin_gUnk_080D6138);
}

void sub_unk1_MinishPaths1_MayorsCabin(void) {
    sub_080575C8(32);
}

u32 sub_unk3_HouseInteriors1_Mayor(void) {
    return 1;
}

extern EntityData Entities_HouseInteriors1_Mayor_080D6210;

void sub_StateChange_HouseInteriors1_Mayor(void) {

    if ((u16)gRoomTransition.player_status.start_pos_y > 0x40)
        LoadRoomEntityList(&Entities_HouseInteriors1_Mayor_080D6210);
}

u32 sub_unk3_HouseInteriors1_PostOffice(void) {
    return 1;
}

extern EntityData gUnk_080D6340;
extern EntityData gUnk_080D6360;
extern EntityData gUnk_080D6380;
extern EntityData gUnk_080D63A0;
extern EntityData gUnk_080D63C0;
extern EntityData gUnk_080D63E0;
extern EntityData gUnk_080D6400;
extern EntityData gUnk_080D6420;
extern EntityData gUnk_080D6440;

extern u16 gUnk_080D64F8;
extern u16 gUnk_080D6508;

void sub_StateChange_HouseInteriors1_PostOffice(void) {
    u16 itemID;
    s32 i;
    u16* itemArr;
    u16* flagArr;
    s32 j;

    if (CheckKinstoneFused(0x2c)) {
        LoadRoomEntityList(&gUnk_080D6340);
    }
    j = 0;
    itemArr = &gUnk_080D64F8;
    for (i = 7; i >= 0; i--) {
        itemID = *itemArr;
        itemArr++;
        if (GetInventoryValue(itemID)) {
            j++;
        }
    }
    if (CheckLocalFlag(BILL01_TESSIN_RESERVED)) {
        flagArr = &gUnk_080D6508;
        i = 0;
        while (i < j) {
            if (CheckLocalFlag(*flagArr) == 0) {
                SetLocalFlag(*flagArr);
                ClearLocalFlag(BILL01_TESSIN_RESERVED);
                SetLocalFlag(BILL01_TESSIN_BRANDNEW);
                break;
            }
            i++;
            flagArr++;
        }
    }

    if (CheckLocalFlag(BILL01_TESSIN_1))
        LoadRoomEntityList(&gUnk_080D6360);

    if (CheckLocalFlag(BILL01_TESSIN_2))
        LoadRoomEntityList(&gUnk_080D6380);

    if (CheckLocalFlag(BILL01_TESSIN_3))
        LoadRoomEntityList(&gUnk_080D63A0);

    if (CheckLocalFlag(BILL01_TESSIN_4))
        LoadRoomEntityList(&gUnk_080D63C0);

    if (CheckLocalFlag(BILL01_TESSIN_5))
        LoadRoomEntityList(&gUnk_080D63E0);

    if (CheckLocalFlag(BILL01_TESSIN_6))
        LoadRoomEntityList(&gUnk_080D6400);

    if (CheckLocalFlag(BILL01_TESSIN_7))
        LoadRoomEntityList(&gUnk_080D6420);

    if (CheckLocalFlag(BILL01_TESSIN_8))
        LoadRoomEntityList(&gUnk_080D6440);
}

u32 sub_unk3_HouseInteriors1_Library2F(void) {
    return 1;
}

extern EntityData gUnk_080D6578;
extern EntityData gUnk_080D6638;
extern EntityData gUnk_080D6558;
extern EntityData gUnk_080D6618;

void sub_StateChange_HouseInteriors1_Library2F(void) {
    // flippers
    if (GetInventoryValue(0x46) == 0) {
        LoadRoomEntityList(&gUnk_080D6578);
        if (CheckLocalFlag(MIZUKAKI_BOOK_ALLBACK) == 0) {
            LoadRoomEntityList(&gUnk_080D6638);
            return;
        }
    } else {
        LoadRoomEntityList(&gUnk_080D6558);
    }
    LoadRoomEntityList(&gUnk_080D6618);
}

u32 sub_unk3_HouseInteriors1_Library1F(void) {
    return 1;
}

extern EntityData gUnk_080D6714;
extern EntityData gUnk_additional_9_HouseInteriors1_Library1F;
extern EntityData gUnk_additional_8_HouseInteriors1_Library1F;

void sub_StateChange_HouseInteriors1_Library1F(void) {
    if (gSave.global_progress > 4) {
        LoadRoomEntityList(&gUnk_080D6714);
    }
    // flippers
    if (!GetInventoryValue(0x46) && CheckGlobalFlag(MIZUKAKI_START) && CheckLocalFlag(MIZUKAKI_KOBITO)) {
        LoadRoomEntityList(&gUnk_additional_9_HouseInteriors1_Library1F);
    } else {
        LoadRoomEntityList(&gUnk_additional_8_HouseInteriors1_Library1F);
    }
}

u32 sub_unk3_HouseInteriors1_Inn1F(void) {
    return 1;
}

extern EntityData gUnk_080D6924;

void sub_StateChange_HouseInteriors1_Inn1F(void) {
    if (gSave.global_progress > 7) {
        LoadRoomEntityList(&gUnk_080D6924);
    }
}

extern u32* gUnk_080D6A74[];

u32 sub_unk3_HouseInteriors1_InnWestRoom(void) {
    u32 index;

    if (CheckLocalFlag(YADO_CHECKIN)) {
        index = (s32)Random() % 3;
        ClearLocalFlag(BILL05_YADO1F_MATSU_T0);
    } else {
        index = 0;
        SetLocalFlag(BILL05_YADO1F_MATSU_T0);
    }
    gRoomVars.field_0x6c[3] = gUnk_080D6A74[index];
    return 1;
}

extern void* script_PlayerSleepingInn[];

void sub_StateChange_HouseInteriors1_InnWestRoom(void) {
    if (CheckLocalFlag(YADO_CHECKIN)) {
        ClearLocalFlag(YADO_CHECKIN);
        SetFade(5, 256);
        gPlayerEntity.x.HALF.HI = gRoomControls.origin_x + 0x50;
        gPlayerEntity.y.HALF.HI = gRoomControls.origin_y + 0x38;
        sub_080751E8(1, 2, &script_PlayerSleepingInn);
    }
}

extern u32* gUnk_080D6B18[];

u32 sub_unk3_HouseInteriors1_InnMiddleRoom(void) {
    u32 index;

    if (CheckLocalFlag(YADO_CHECKIN) != 0) {
        index = Random() & 1;
        ClearLocalFlag(BILL06_YADO1F_TAKE_T0);
    } else {
        index = 0;
        SetLocalFlag(BILL06_YADO1F_TAKE_T0);
    }
    gRoomVars.field_0x6c[3] = gUnk_080D6B18[index];
    return 1;
}

void sub_StateChange_HouseInteriors1_InnMiddleRoom(void) {
    if (CheckLocalFlag(YADO_CHECKIN) != 0) {
        ClearLocalFlag(YADO_CHECKIN);
        SetFade(5, 256);
        gPlayerEntity.x.HALF.HI = gRoomControls.origin_x + 0x50;
        gPlayerEntity.y.HALF.HI = gRoomControls.origin_y + 0x38;
        sub_080751E8(1, 2, &script_PlayerSleepingInn);
    }
}

extern u32* gUnk_080D6BB8[];

u32 sub_unk3_HouseInteriors1_InnEastRoom(void) {
    s32 index;

    if (CheckLocalFlag(YADO_CHECKIN) != 0) {
        index = (s32)Random() % 3;
        ClearLocalFlag(BILL07_YADO1F_UME_T0);
    } else {
        index = 0;
        SetLocalFlag(BILL07_YADO1F_UME_T0);
    }
    gRoomVars.field_0x6c[3] = gUnk_080D6BB8[index];
    return 1;
}

void sub_StateChange_HouseInteriors1_InnEastRoom(void) {
    if (CheckLocalFlag(YADO_CHECKIN)) {
        ClearLocalFlag(YADO_CHECKIN);
        SetFade(5, 256);
        gPlayerEntity.x.HALF.HI = gRoomControls.origin_x + 0x60;
        gPlayerEntity.y.HALF.HI = gRoomControls.origin_y + 0x38;
        sub_080751E8(1, 2, &script_PlayerSleepingInn);
    }
}

u32 sub_unk3_HouseInteriors1_InnWest2F(void) {
    return 1;
}

extern EntityData UpperInn_Oracles;
extern EntityData UpperInn_NoFarore;
extern EntityData UpperInn_NoNayru;
extern EntityData UpperInn_NoDin;
extern EntityData UpperInn_Farore;
extern EntityData UpperInn_Nayru;
extern EntityData UpperInn_Din;

void sub_StateChange_HouseInteriors1_InnWest2F(void) {
    if (gSave.global_progress < 4)
        return;

    if (CheckGlobalFlag(RENTED_HOUSE_DIN)) {
        if (!CheckGlobalFlag(NEW_HOUSE_NAYRU))
            if (!CheckGlobalFlag(NEW_HOUSE_FARORE))
                LoadRoomEntityList(&UpperInn_NoDin);
            else
                LoadRoomEntityList(&UpperInn_Nayru);
        else
            LoadRoomEntityList(&UpperInn_Farore);
    } else if (CheckGlobalFlag(RENTED_HOUSE_NAYRU)) {
        if (CheckGlobalFlag(NEW_HOUSE_DIN))
            LoadRoomEntityList(&UpperInn_Farore);
        else if (!CheckGlobalFlag(NEW_HOUSE_FARORE))
            LoadRoomEntityList(&UpperInn_NoNayru);
        else
            LoadRoomEntityList(&UpperInn_Din);
    } else if (CheckGlobalFlag(RENTED_HOUSE_FARORE)) {
        if (CheckGlobalFlag(NEW_HOUSE_DIN))
            LoadRoomEntityList(&UpperInn_Nayru);
        else if (CheckGlobalFlag(NEW_HOUSE_NAYRU))
            LoadRoomEntityList(&UpperInn_Din);
        else
            LoadRoomEntityList(&UpperInn_NoFarore);
    } else
        LoadRoomEntityList(&UpperInn_Oracles);
}

u32 sub_unk3_HouseInteriors1_InnEast2F(void) {
    return 1;
}

void sub_StateChange_HouseInteriors1_InnEast2F(void) {
}

u32 sub_unk3_HouseInteriors1_InnMinishHeartPiece(void) {
    return 1;
}

void sub_StateChange_HouseInteriors1_InnMinishHeartPiece(void) {
}

u32 sub_unk3_HouseInteriors1_SchoolWest(void) {
    return 1;
}

extern EntityData gUnk_080D7038;

void sub_StateChange_HouseInteriors1_SchoolWest(void) {
    if (gSave.global_progress < 8) {
        LoadRoomEntityList(&gUnk_080D7038);
    }
    if (gRoomVars.field_0x0 == 0) {
        SetWorldMapPos(2, 0, 0x2c8, 0xa8);
    }
}

u32 sub_unk3_HouseInteriors1_SchoolEast(void) {
    return 1;
}

extern EntityData gUnk_080D7140;
extern EntityData gUnk_080D7170;
extern EntityData gUnk_080D71A0;
extern EntityData gUnk_080D71D0;
extern EntityData gUnk_080D71F0;

void sub_StateChange_HouseInteriors1_SchoolEast(void) {

    if (gSave.global_progress == 6)
        LoadRoomEntityList(&gUnk_080D7140);

    if (gSave.global_progress == 7)
        LoadRoomEntityList(&gUnk_080D7170);

    if ((gSave.global_progress < 8) || (LoadRoomEntityList(&gUnk_080D71A0), gSave.global_progress < 8))
        LoadRoomEntityList(&gUnk_080D71D0);
    else
        LoadRoomEntityList(&gUnk_080D71F0);
}

extern u32 gUnk_080D7348;

u32 sub_unk3_HyruleCastle_0(void) {
    if (CheckGlobalFlag(ENDING)) {
        gRoomVars.field_0x6c[0] = &gUnk_080D7348;
        gRoomVars.field_0x6c[2] = 0;
    }
    return 1;
}

extern EntityData gUnk_080D7328;

void sub_StateChange_HyruleCastle_0(void) {
    if (!CheckGlobalFlag(LV2_CLEAR)) {
        LoadRoomEntityList(&gUnk_080D7328);
    }

#if defined(JP) || defined(DEMO_JP)
    if (CheckGlobalFlag(CASTLE_BGM) || CheckGlobalFlag(ENDING)) {
        gArea.queued_bgm = gArea.bgm;
    }
#elif defined(EU)
    if (CheckGlobalFlag(ENDING)) {
        gArea.queued_bgm = gArea.bgm;
    }
#else
    if (CheckGlobalFlag(CASTLE_BGM)) {
        gArea.queued_bgm = BGM_HYRULE_CASTLE_NOINTRO;
    } else if (CheckGlobalFlag(ENDING)) {
        gArea.queued_bgm = gArea.bgm;
    }
#endif
}

extern u32 gUnk_080D7410;

u32 sub_unk3_HyruleCastle_1(void) {
    if (CheckGlobalFlag(ENDING)) {
        gRoomVars.field_0x6c[0] = &gUnk_080D7410;
        gRoomVars.field_0x6c[2] = 0;
    }
    return 1;
}

extern EntityData gUnk_080D73B0;
extern EntityData gUnk_080D73E0;

void sub_StateChange_HyruleCastle_1(void) {
    if (CheckGlobalFlag(ENDING)) {
        gArea.queued_bgm = gArea.bgm;
    } else {
        if (!CheckGlobalFlag(LV2_CLEAR)) {
            LoadRoomEntityList(&gUnk_080D73B0);
        }
        if (!CheckGlobalFlag(LV1_CLEAR) && CheckGlobalFlag(TABIDACHI)) {
            LoadRoomEntityList(&gUnk_080D73E0);
        }
#ifndef EU
        if (CheckGlobalFlag(CASTLE_BGM)) {
            gArea.queued_bgm = gArea.bgm;
        }
#endif
    }
}

u32 sub_unk3_HyruleCastle_2(void) {
    return 1;
}

extern EntityData gUnk_080D74C8;
extern EntityData gUnk_080D7588;
extern EntityData gUnk_080D75D8;
extern EntityData gUnk_080D7618;

void sub_StateChange_HyruleCastle_2(void) {
#ifndef EU
    if (CheckGlobalFlag(CASTLE_BGM)) {
        gArea.queued_bgm = gArea.bgm;
    }
#endif

    if (CheckGlobalFlag(ENDING)) {
        LoadRoomEntityList(&gUnk_080D7618);
        gArea.queued_bgm = gArea.bgm;
    } else if (CheckGlobalFlag(TABIDACHI) == 0) {
        LoadRoomEntityList(&gUnk_080D74C8);
        gArea.queued_bgm = BGM_HYRULE_CASTLE_NOINTRO;
    } else if (CheckGlobalFlag(LV1_CLEAR) == 0) {
        LoadRoomEntityList(&gUnk_080D7588);
    } else {
        LoadRoomEntityList(&gUnk_080D75D8);
    }
}

u32 sub_unk3_HyruleCastle_3(void) {
    return 1;
}

extern EntityData gUnk_additional_8_HyruleCastle_3;

void sub_StateChange_HyruleCastle_3(void) {
    if (CheckLocalFlag(SOUGEN_08_TORITSUKI)) {
        LoadRoomEntityList(&gUnk_additional_8_HyruleCastle_3);
    }
}

u32 sub_unk3_HyruleCastle_4(void) {
    if (!CheckLocalFlag(CASTLE_04_MEZAME)) {
        gRoomTransition.player_status.spawn_type = PL_SPAWN_SPECIAL;
        ClearGlobalFlag(ZELDA_CHASE);
    }
    return 1;
}

extern u32 script_PlayerWakingUpInHyruleCastle;

void sub_StateChange_HyruleCastle_4(void) {
    if (!CheckLocalFlag(CASTLE_04_MEZAME)) {
        SetFade(5, 256);
        gPlayerEntity.x.HALF.HI = gRoomControls.origin_x + 0xb0;
        gPlayerEntity.y.HALF.HI = gRoomControls.origin_y + 0x40;
        sub_080751E8(0, 6, &script_PlayerWakingUpInHyruleCastle);
#ifdef EU
        SoundReq(SONG_STOP_ALL);
        gArea.bgm = gArea.queued_bgm;
    }
#else
    }

    if (!CheckGlobalFlag(TABIDACHI)) {
        sub_08052878();
#if !(defined(JP) || defined(DEMO_JP))
    } else {
#else
    }
#endif
        if (CheckGlobalFlag(CASTLE_BGM)) {
#if defined(JP) || defined(DEMO_JP)
            gArea.queued_bgm = gArea.bgm;
#else
        gArea.queued_bgm = BGM_HYRULE_CASTLE_NOINTRO;
#endif
        }
#if !(defined(JP) || defined(DEMO_JP))
    }
#endif
#endif
}

extern ScreenTransitionData gUnk_0813AB80;

void sub_0804BCDC(void) {
    sub_0808091C(&gUnk_0813AB80, TRANSITION_FADE_BLACK_SLOW);
}

u32 sub_unk3_HyruleCastle_5(void) {
    return 1;
}

void sub_StateChange_HyruleCastle_5(void) {
}

u32 sub_unk3_87_Main(void) {
    return 1;
}

void sub_StateChange_87_Main(void) {
}

u32 sub_unk3_45_Main(void) {
    return 1;
}

void sub_StateChange_45_Main(void) {
}

u32 sub_unk3_4D_Main(void) {
    return 1;
}

void sub_StateChange_4D_Main(void) {
}

u32 sub_unk3_57_Main(void) {
    return 1;
}

void sub_StateChange_57_Main(void) {
}

u32 sub_unk3_5F_Main(void) {
    return 1;
}

void sub_StateChange_5F_Main(void) {
}

u32 sub_unk3_67_Main(void) {
    return 1;
}

void sub_StateChange_67_Main(void) {
}

u32 sub_unk3_6F_Main(void) {
    return 1;
}

void sub_StateChange_6F_Main(void) {
}

u32 sub_unk3_77_Main(void) {
    return 1;
}

void sub_StateChange_77_Main(void) {
}

u32 sub_unk3_7F_Main(void) {
    return 1;
}

void sub_StateChange_7F_Main(void) {
}

u32 sub_unk3_8F_Main(void) {
    return 1;
}

void sub_StateChange_8F_Main(void) {
}

u32 sub_unk3_GreatFairies_Entrance(void) {
    return 1;
}

void sub_StateChange_GreatFairies_Entrance(void) {
}

u32 sub_unk3_GreatFairies_Exit(void) {
    return 1;
}

extern EntityData gUnk_080D7D34;

void sub_StateChange_GreatFairies_Exit(void) {
    // four sword
    if (GetInventoryValue(0x6)) {
        SetTile(0x4072, 0x14d, 1);
        SetTile(0x4072, 0x10c, 1);
        SetTile(0x4090, 0x14c, 1);
        SetTile(0x4090, 0x18c, 1);
        LoadRoomEntityList(&gUnk_080D7D34);
    }
}

u32 sub_unk3_Dojos_Grayblade(void) {
    return 1;
}

void sub_StateChange_Dojos_Grayblade(void) {
}

u32 sub_unk3_Dojos_Splitblade(void) {
    return 1;
}

void sub_StateChange_Dojos_Splitblade(void) {
}

u32 sub_unk3_Dojos_Greatblade(void) {
    return 1;
}

void sub_StateChange_Dojos_Greatblade(void) {
}

u32 sub_unk3_Dojos_Scarblade(void) {
    return 1;
}

void sub_StateChange_Dojos_Scarblade(void) {
}

u32 sub_unk3_Dojos_Swiftblade(void) {
    return 1;
}

void sub_StateChange_Dojos_Swiftblade(void) {
}

u32 sub_unk3_Dojos_Grimblade(void) {
    return 1;
}

extern EntityData gUnk_080D827C;

void sub_StateChange_Dojos_Grimblade(void) {
    if (!CheckLocalFlag(3)) {
        LoadRoomEntityList(&gUnk_080D827C);
    } else {
        sub_0805BC4C();
        SetTileType(0x76, 0x82, 2);
        SetTileType(0x76, 0x8c, 2);
    }
}

u32 sub_unk3_Dojos_Waveblade(void) {
    return 1;
}

void sub_StateChange_Dojos_Waveblade(void) {
}

u32 sub_unk3_Dojos_7(void) {
    return 1;
}

void sub_StateChange_Dojos_7(void) {
}

u32 sub_unk3_Dojos_8(void) {
    return 1;
}

void sub_StateChange_Dojos_8(void) {
}

u32 sub_unk3_Dojos_9(void) {
    return 1;
}

void sub_StateChange_Dojos_9(void) {
}

u32 sub_unk3_Dojos_ToGrimblade(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGrimblade(void) {
}

u32 sub_unk3_Dojos_ToSplitblade(void) {
    return 1;
}

void sub_StateChange_Dojos_ToSplitblade(void) {
}

u32 sub_unk3_Dojos_ToGreatblade(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGreatblade(void) {
}

u32 sub_unk3_Dojos_ToScarblade(void) {
    return 1;
}

void sub_StateChange_Dojos_ToScarblade(void) {
}

u32 sub_unk3_GoronCave_StairsToCave(void) {
    return 1;
}

void sub_StateChange_GoronCave_StairsToCave(void) {
}

u32 sub_unk3_GoronCave_Main(void) {
    return 1;
}

extern EntityData gUnk_080D8B24;
extern EntityData gUnk_080D8AC4;
extern EntityData gUnk_080D8A74;
extern EntityData gUnk_080D8A34;
extern EntityData gUnk_080D8A04;
extern EntityData gUnk_080D89E4;

extern u32 gUnk_080D8BBC;
extern u32 gUnk_080D8BFA;
extern u32 gUnk_080D8C68;

void sub_StateChange_GoronCave_Main(void) {
    if (!CheckLocalFlag(GORON_DOUKUTU_APPEAR))
        SetLocalFlag(GORON_DOUKUTU_APPEAR);

    if (CheckKinstoneFused(0x2f))
        LoadRoomEntityList(&gUnk_080D8B24);
    else if (CheckKinstoneFused(0x2b))
        LoadRoomEntityList(&gUnk_080D8AC4);
    else if (CheckKinstoneFused(0x26))
        LoadRoomEntityList(&gUnk_080D8A74);
    else if (CheckKinstoneFused(0x2a))
        LoadRoomEntityList(&gUnk_080D8A34);
    else if (CheckKinstoneFused(0x25))
        LoadRoomEntityList(&gUnk_080D8A04);
    else
        LoadRoomEntityList(&gUnk_080D89E4);

    if (CheckKinstoneFused(0x25))
        sub_0807BB68(&gUnk_080D8BBC, 0x7c5, 1);

    if (CheckKinstoneFused(0x26))
        sub_0807BB68(&gUnk_080D8BFA, 0x503, 1);

    if (CheckKinstoneFused(0x2f))
        sub_0807BB68(&gUnk_080D8C68, 0x281, 1);
}

typedef struct {
    u32* a;
    u16 x, y;
    u16 entCnt;
    u16 shakeTime, shakeMag, sfx;
} struct_080D8E54;

extern struct_080D8E54 gUnk_080D8E50[];

void sub_0804BF38(Entity* this, ScriptExecutionContext* context) {
    u32 numEnts;
    u32 iVar2;
    Entity* fx;
    u32 entCnt;
    u32 xOff;
    struct_080D8E54* ptr;
    u32 xtile, ytile;
    u32* a;

    iVar2 = context->intVariable;
    ptr = &gUnk_080D8E50[iVar2];
    a = ptr->a;
    xtile = (ptr->x >> 4) & 0x3f;
    ytile = ((ptr->y >> 4) & 0x3f) << 6;
    sub_0807BB68(a, xtile | ytile, 1);
    numEnts = ptr->entCnt;

    for (entCnt = 0; entCnt < numEnts; entCnt++) {
        fx = CreateObject(SPECIAL_FX, 0xf, 0);
        if (fx != NULL) {
            fx->x.HALF.HI = ptr->x + gRoomControls.origin_x + entCnt * 0x10;
            fx->y.HALF.HI = ptr->y + gRoomControls.origin_y + (entCnt & 1) * 8;
        }
        fx = CreateObject(SPECIAL_FX, 0x54, 0);
        if (fx != NULL) {
            fx->x.HALF.HI = ptr->x + gRoomControls.origin_x + entCnt * 0x10;
            fx->y.HALF.HI = ptr->y + gRoomControls.origin_y + -0xc + (entCnt & 1) * 8;
            fx->direction = 0;
            fx->speed = 0x100;
        }
    }

    InitScreenShake(ptr->shakeTime, ptr->shakeMag);
    SoundReq(ptr->sfx);
}

u32 sub_unk3_EzloAuxCutscene_Main(void) {
    return 1;
}

void sub_StateChange_EzloAuxCutscene_Main(void) {
}

u32 sub_unk3_RoyalValley_Main(void) {
    return 1;
}

extern EntityData gUnk_080D90C8;
extern EntityData gUnk_080D9108;
extern EntityData gUnk_080D9098;

void sub_StateChange_RoyalValley_Main(void) {
    if (!CheckGlobalFlag(HAKA_KEY_LOST)) {
        if (GetInventoryValue(ITEM_QST_GRAVEYARD_KEY) == 1) {
            LoadRoomEntityList(&gUnk_080D90C8);
            LoadRoomEntityList(&gUnk_080D9108);
        }
    } else if (!CheckGlobalFlag(HAKA_KEY_FOUND))
        LoadRoomEntityList(&gUnk_080D9108);

    if (GetInventoryValue(ITEM_QST_GRAVEYARD_KEY) != 2) {
        LoadRoomEntityList(&gUnk_080D9098);
        SetTileType(0x17a, 0x58e, 1);
        SetTileType(0x17b, 0x58f, 1);
        SetTileType(0x17c, 0x5ce, 1);
        SetTileType(0x17d, 0x5cf, 1);
    }

    sub_08054570();
    sub_08059278();
    SetTile(0x4072, 0xa47, 1);
    SetTile(0x4072, 0xc47, 1);

    if (CheckGlobalFlag(MAZE_CLEAR))
        if (gRoomTransition.player_status.start_pos_x == 0x78 && gRoomTransition.player_status.start_pos_y == 0x278)
            SoundReq(SFX_SECRET);

    ClearGlobalFlag(MAZE_CLEAR);
}

u32 sub_unk3_RoyalValley_ForestMaze(void) {
    return 1;
}

void sub_StateChange_RoyalValley_ForestMaze(void) {
    gArea.areaMetadata |= 0x40;
    gArea.unk_0c_0 = 1;
    sub_0804C128();
}

extern u8 gUnk_080D9338[];
extern u8 gUnk_080D9340[];
extern TileEntity gUnk_080D9328[];

void sub_0804C128() {
    sub_080AF250(0);
    if (gRoomVars.field_0x0 != 0) {
        if ((gArea.unk_0c_1) == 0) {
            if ((gArea.unk_0c_4) == 0) {
                gArea.unk_0c_1 = 1;
            }
        } else {
            if (gRoomControls.scroll_direction == gUnk_080D9338[gArea.unk_0c_1]) {
                gArea.unk_0c_1++;
            } else {
                gArea.unk_0c_1 = 0;
            }
        }

        if (gArea.unk_0c_1 == 0) {
            if (gRoomControls.scroll_direction == gUnk_080D9340[gArea.unk_0c_4]) {
                gArea.unk_0c_4++;
                gArea.unk_0c_1 = 0;
            } else {
                gArea.unk_0c_4 = 0;
            }
        }

        if (gArea.unk_0c_1 == 6) {
            sub_080AF250(1);
            SetGlobalFlag(0x62);
            sub_0804C290();
            gArea.unk_0c_1 = 0;
            return;
        }

        if (gArea.unk_0c_4 == 6) {
            sub_080AF250(1);
#if defined(EU) || defined(JP) || defined(DEMO_JP)
            if (CheckLocalFlag(0x5a) == 0) {
#else
            if (CheckLocalFlag(0x5c) == 0) {
#endif
                SetTileType(0x73, 0x107, 1);
            }
            LoadRoomTileEntities(gUnk_080D9328);
            SetGlobalFlag(0x62);
            sub_0804C290();
            gArea.unk_0c_4 = 0;
            return;
        }
    } else {
        sub_0804C258();
    }
    sub_0804C290();
}

void sub_0804C258(void) {
    gArea.unk_0c_1 = 1;
    gArea.unk_0c_4 = 0;
    if (gRoomTransition.player_status.start_anim == 4) {
        gArea.unk_0c_1 = 7;
        sub_080AF250(1);
    }
}

typedef struct {
    u16 unk0;
    u16 unk2;
} gUnk_080D9348_struct;

extern gUnk_080D9348_struct gUnk_080D9348[];

void sub_0804C290(void) {
    int iVar1;

    if (gArea.unk_0c_1) {
        iVar1 = gArea.unk_0c_1;
        SetTileType((gUnk_080D9348 + iVar1)->unk0, (gUnk_080D9348 + iVar1)->unk2, 1);
    }
}

u32 sub_unk3_RoyalValleyGraves_HeartPiece(void) {
    return 1;
}

void sub_StateChange_RoyalValleyGraves_HeartPiece(void) {
}

u32 sub_unk3_RoyalValleyGraves_Gina(void) {
    return 1;
}

void sub_StateChange_RoyalValleyGraves_Gina(void) {
}

u32 sub_unk3_MinishRafters_Cafe(void) {
    return 1;
}

void sub_StateChange_MinishRafters_Cafe(void) {
    sub_08058324(0);
}

u32 sub_unk3_MinishRafters_Stockwell(void) {
    return 1;
}

void sub_StateChange_MinishRafters_Stockwell(void) {
    sub_08058324(1);
}

u32 sub_unk3_MinishRafters_DrLeft(void) {
    return 1;
}

extern EntityData gUnk_080D9800;

void sub_StateChange_MinishRafters_DrLeft(void) {

    sub_08058324(2);

    if (CheckGlobalFlag(MIZUKAKI_START) && !CheckGlobalFlag(MIZUKAKI_HARIFALL))
        LoadRoomEntityList(&gUnk_080D9800);
}

void sub_unk1_MinishRafters_DrLeft(void) {
    sub_StateChange_MinishRafters_DrLeft();
}

u32 sub_unk3_MinishRafters_Bakery(void) {
    return 1;
}

void sub_StateChange_MinishRafters_Bakery(void) {
    sub_08058324(3);
}

u32 sub_unk3_CastorWilds_Main(void) {
    return 1;
}

extern EntityData gUnk_080D9CC8;
extern EntityData gUnk_080D9CE8;
extern EntityData gUnk_080D9C38;

void sub_StateChange_CastorWilds_Main(void) {

    SetGlobalFlag(DASHBOOTS);

    if (CheckKinstoneFused(0x5b))
        LoadRoomEntityList(&gUnk_080D9CC8);

    if ((gSave.windcrests & 0x20000000) == 0)
        LoadRoomEntityList(&gUnk_080D9CE8);

    if (!GetInventoryValue(ITEM_PEGASUS_BOOTS))
        LoadRoomEntityList(&gUnk_080D9C38);
}

void sub_unk1_CastorWilds_Main(void) {
    if ((gSave.windcrests & 0x20000000) == 0)
        LoadRoomEntityList(&gUnk_080D9CE8);
}

u32 sub_unk3_CastorCaves_South(void) {
    return 1;
}

void sub_StateChange_CastorCaves_South(void) {
}

u32 sub_unk3_CastorCaves_North(void) {
    return 1;
}

void sub_StateChange_CastorCaves_North(void) {
}

u32 sub_unk3_CastorCaves_WindRuins(void) {
    return 1;
}

void sub_StateChange_CastorCaves_WindRuins(void) {
}

u32 sub_unk3_CastorCaves_Darknut(void) {
    return 1;
}

void sub_StateChange_CastorCaves_Darknut(void) {
}

u32 sub_unk3_CastorCaves_HeartPiece(void) {
    return 1;
}

void sub_StateChange_CastorCaves_HeartPiece(void) {
}

extern u32 gUnk_080DA230;

u32 sub_unk3_CastorDarknut_Main(void) {
    if (!CheckLocalFlag(LV4_0a_TSUBO))
        gRoomVars.field_0x6c[0] = &gUnk_080DA230;

    return 1;
}

void sub_StateChange_CastorDarknut_Main(void) {
}

u32 sub_unk3_CastorDarknut_Hall(void) {
    return 1;
}

void sub_StateChange_CastorDarknut_Hall(void) {
}

u32 sub_unk3_GreatFairies_Graveyard(void) {
    return 1;
}

void sub_StateChange_GreatFairies_Graveyard(void) {
}

u32 sub_unk3_GreatFairies_MinishWoods(void) {
    return 1;
}

void sub_StateChange_GreatFairies_MinishWoods(void) {
}

u32 sub_unk3_GreatFairies_MtCrenel(void) {
    return 1;
}

void sub_StateChange_GreatFairies_MtCrenel(void) {
}

u32 sub_unk3_GardenFountains_East(void) {
    return 1;
}

void sub_StateChange_GardenFountains_East(void) {
}

u32 sub_unk3_GardenFountains_West(void) {
    return 1;
}

void sub_StateChange_GardenFountains_West(void) {
}

u32 sub_unk3_MinishHouseInteriors_GentariMain(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_GentariMain(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_GentariExit(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_GentariExit(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_Festari(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_Festari(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_Red(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_Red(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_Green(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_Green(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_Blue(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_Blue(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_SideArea(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_SideArea(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_ShoeMinish(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_ShoeMinish(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_PotMinish(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_PotMinish(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_BarrelMinish(void) {
    return 1;
}

extern EntityData gUnk_080DAB44;
extern EntityData gUnk_080DAB64;
extern EntityData gUnk_080DAB84;
extern EntityData gUnk_080DAC54;
extern EntityData gUnk_080DAD24;
extern EntityData gUnk_080DABC4;
extern EntityData gUnk_080DAC94;
extern EntityData gUnk_080DAD64;
extern EntityData gUnk_080DAC04;
extern EntityData gUnk_080DACD4;
extern EntityData gUnk_080DADA4;

void sub_StateChange_MinishHouseInteriors_BarrelMinish(void) {
    u32 uVar1;

    if (!GetInventoryValue(ITEM_JABBERNUT))
        LoadRoomEntityList(&gUnk_080DAB44);
    else
        LoadRoomEntityList(&gUnk_080DAB64);

    if (CheckGlobalFlag(DRUG_COUNT) && sub_08060354()) {
        SetRoomFlag(0);
        if (!CheckGlobalFlag(DRUG_1))
            uVar1 = 0x3200;
        else if (!CheckGlobalFlag(DRUG_2))
            uVar1 = 0x4600;
        else
            uVar1 = 0x4880;
    } else {
        if (CheckGlobalFlag(DRUG_3))
            uVar1 = 0x4900;
        else if (CheckGlobalFlag(DRUG_2))
            uVar1 = 0x4a00;
        else if (CheckGlobalFlag(DRUG_1))
            uVar1 = 0x5200;
        else
            uVar1 = 0x9200;
    }
    if (uVar1 & 0x8000)
        LoadRoomEntityList(&gUnk_080DAB84);

    if (uVar1 & 0x4000)
        LoadRoomEntityList(&gUnk_080DAC54);

    if (uVar1 & 0x2000)
        LoadRoomEntityList(&gUnk_080DAD24);

    if (uVar1 & 0x1000)
        LoadRoomEntityList(&gUnk_080DABC4);

    if (uVar1 & 0x800)
        LoadRoomEntityList(&gUnk_080DAC94);

    if (uVar1 & 0x400)
        LoadRoomEntityList(&gUnk_080DAD64);

    if (uVar1 & 0x200)
        LoadRoomEntityList(&gUnk_080DAC04);

    if (uVar1 & 0x100)
        LoadRoomEntityList(&gUnk_080DACD4);

    if (uVar1 & 0x80)
        LoadRoomEntityList(&gUnk_080DADA4);

    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_MelariMinesSouthwest(void) {
    return 1;
}

extern EntityData gUnk_080DAEE8;

void sub_StateChange_MinishHouseInteriors_MelariMinesSouthwest(void) {
    if (CheckGlobalFlag(WHITE_SWORD_END))
        LoadRoomEntityList(&gUnk_080DAEE8);

    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_MelariMinesSoutheast(void) {
    return 1;
}

extern EntityData gUnk_080DAF80;

void sub_StateChange_MinishHouseInteriors_MelariMinesSoutheast(void) {
    if (CheckGlobalFlag(WHITE_SWORD_END))
        LoadRoomEntityList(&gUnk_080DAF80);

    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_MelariMinesEast(void) {
    return 1;
}

extern EntityData gUnk_080DB018;

void sub_StateChange_MinishHouseInteriors_MelariMinesEast(void) {
    if (CheckGlobalFlag(WHITE_SWORD_END))
        LoadRoomEntityList(&gUnk_080DB018);

    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_HyruleFieldSouthwest(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_HyruleFieldSouthwest(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_HyruleFieldOutsideLinksHouse(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_HyruleFieldOutsideLinksHouse(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_NextToKnuckle(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_NextToKnuckle(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_Librari(void) {
    return 1;
}

extern EntityData gUnk_080DB238;

void sub_StateChange_MinishHouseInteriors_Librari(void) {
    if (gSave.global_progress > 8)
        LoadRoomEntityList(&gUnk_080DB238);

    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_HyruleFieldExit(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_HyruleFieldExit(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_HyruleTown(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_HyruleTown(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_MinishWoodsBomb(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_MinishWoodsBomb(void) {
    sub_0801AFE4();
}

u32 sub_unk3_MinishHouseInteriors_LakeHyliaOcarina(void) {
    return 1;
}

void sub_StateChange_MinishHouseInteriors_LakeHyliaOcarina(void) {
    sub_0801AFE4();
}

u32 sub_unk3_TownMinishHoles_MayorsHouse(void) {
    return 1;
}

extern EntityData gUnk_080DB4D0;
extern EntityData gUnk_080DB4A0;

void sub_StateChange_TownMinishHoles_MayorsHouse(void) {
    if (!GetInventoryValue(ITEM_FLIPPERS) && !GetInventoryValue(ITEM_QST_BOOK3) && CheckLocalFlag(KOBITO_DOUKUTU_04_T0))
        LoadRoomEntityList(&gUnk_080DB4D0);
    else
        LoadRoomEntityList(&gUnk_080DB4A0);

    sub_0801AFE4();
}

u32 sub_unk3_TownMinishHoles_WestOracle(void) {
    return 1;
}

void sub_StateChange_TownMinishHoles_WestOracle(void) {
    sub_0801AFE4();
}

u32 sub_unk3_TownMinishHoles_DrLeft(void) {
    return 1;
}

void sub_StateChange_TownMinishHoles_DrLeft(void) {
    sub_0801AFE4();
}

u32 sub_unk3_TownMinishHoles_Carpenter(void) {
    return 1;
}

void sub_StateChange_TownMinishHoles_Carpenter(void) {
    sub_0801AFE4();
}

u32 sub_unk3_TownMinishHoles_Cafe(void) {
    return 1;
}

void sub_StateChange_TownMinishHoles_Cafe(void) {
    sub_0801AFE4();
}

u32 sub_unk3_TownMinishHoles_5(void) {
    return 1;
}

void sub_StateChange_TownMinishHoles_5(void) {
    sub_0801AFE4();
}

extern u32 gUnk_080DB910;

u32 sub_unk3_TownMinishHoles_LibraryBookshelf(void) {
    if (CheckGlobalFlag(MIZUKAKI_START) && !CheckLocalFlag(KOBITO_DOUKUTU_09_T0)) {
        gRoomVars.field_0x6c[1] = &gUnk_080DB910;
    }
    return 1;
}

extern EntityData gUnk_080DB8F0;
extern EntityData gUnk_additional_a_TownMinishHoles_LibraryBookshelf;

void sub_StateChange_TownMinishHoles_LibraryBookshelf(void) {
    LoadRoomEntityList(&gUnk_080DB8F0);
    if (!GetInventoryValue(ITEM_FLIPPERS) && CheckGlobalFlag(MIZUKAKI_START)) {
        LoadRoomEntityList(&gUnk_additional_a_TownMinishHoles_LibraryBookshelf);
    }
    sub_0801AFE4();
}

u32 sub_unk3_TownMinishHoles_LibrariBookHouse(void) {
    return 1;
}

extern EntityData gUnk_080DBA08;

void sub_StateChange_TownMinishHoles_LibrariBookHouse(void) {
    if (GetInventoryValue(ITEM_FLIPPERS) || !CheckLocalFlag(KOBITO_DOUKUTU_09_T0)) {
        LoadRoomEntityList(&gUnk_080DBA08);
    }
    sub_0801AFE4();
}

u32 sub_unk3_TownMinishHoles_RemShoeShop(void) {
    return 1;
}

extern EntityData gUnk_080DBB50;
extern EntityData gUnk_080DBB70;
extern EntityData gUnk_080DBB10;
extern EntityData gUnk_080DBAD0;
extern EntityData gUnk_080DBB90;

void sub_StateChange_TownMinishHoles_RemShoeShop(void) {
    u32 tilePos;
    u32 i;

    if (!CheckLocalFlag(KOBITO_DOUKUTU_00_T0)) {
        LoadRoomEntityList(&gUnk_080DBB50);
    }

    if (GetInventoryValue(ITEM_PEGASUS_BOOTS) == 1) {
        LoadRoomEntityList(&gUnk_080DBB70);
        LoadRoomEntityList(&gUnk_080DBB10);
    } else {
        LoadRoomEntityList(&gUnk_080DBAD0);
    }
    if (!CheckLocalFlag(KOBITO_DOUKUTU_05_T0)) {
        tilePos = 0x140;
        for (i = 0; i < 0x13; i++, tilePos++) {
            SetTileType(0x4072, tilePos, 1);
        }
    }
    LoadRoomEntityList(&gUnk_080DBB90);
    sub_0801AFE4();
}

u32 sub_unk3_MinishCaves_BeanPesto(void) {
    return 1;
}

void sub_StateChange_MinishCaves_BeanPesto(void) {
}

u32 sub_unk3_MinishCaves_SoutheastWater1(void) {
    return 1;
}

void sub_StateChange_MinishCaves_SoutheastWater1(void) {
}

u32 sub_unk3_MinishCaves_SoutheastWater2(void) {
    return 1;
}

void sub_StateChange_MinishCaves_SoutheastWater2(void) {
}

u32 sub_unk3_MinishCaves_Ruins(void) {
    return 1;
}

void sub_StateChange_MinishCaves_Ruins(void) {
}

u32 sub_unk3_MinishCaves_OutsideLinksHouse(void) {
    return 1;
}

void sub_StateChange_MinishCaves_OutsideLinksHouse(void) {
}

u32 sub_unk3_MinishCaves_MinishWoodsNorth1(void) {
    return 1;
}

void sub_StateChange_MinishCaves_MinishWoodsNorth1(void) {
}

u32 sub_unk3_MinishCaves_MinishWoodsNorth2(void) {
    return 1;
}

void sub_StateChange_MinishCaves_MinishWoodsNorth2(void) {
}

u32 sub_unk3_MinishCaves_LakeHyliaNorth(void) {
    return 1;
}

void sub_StateChange_MinishCaves_LakeHyliaNorth(void) {
}

u32 sub_unk3_MinishCaves_LakeHyliaLibrari(void) {
    return 1;
}

void sub_StateChange_MinishCaves_LakeHyliaLibrari(void) {
}

u32 sub_unk3_MinishCaves_MinishWoodsSouthwest(void) {
    return 1;
}

void sub_StateChange_MinishCaves_MinishWoodsSouthwest(void) {
}

u32 sub_unk3_MinishVillage_Main(void) {
    return 1;
}

extern EntityData gUnk_080DC390;
extern EntityData gUnk_080DC3F0;
extern EntityData gUnk_080DC430;
extern EntityData gUnk_080DC530;
extern EntityData gUnk_080DC470;
extern EntityData gUnk_080DC4C0;

void sub_StateChange_MinishVillage_Main(void) {
    if (!GetInventoryValue(ITEM_JABBERNUT)) {
        LoadRoomEntityList(&gUnk_080DC390);
        if (!CheckLocalFlagByBank(0x200, 0x80)) {
            LoadRoomEntityList(&gUnk_080DC3F0);
        }
    } else {
        LoadRoomEntityList(&gUnk_080DC430);
        if (!GetInventoryValue(ITEM_GUST_JAR)) {
            LoadRoomEntityList(&gUnk_080DC530);
        }
    }
    if ((!CheckLocalFlagByBank(FLAG_BANK_2, M_ELDER_TALK2ND)) && GetInventoryValue(ITEM_GUST_JAR)) {
        LoadRoomEntityList(&gUnk_080DC470);
    }
    if (!CheckLocalFlag(0x8d)) {
        LoadRoomEntityList(&gUnk_080DC4C0);
    }
    sub_08057E64();
}

u32 sub_unk3_MinishVillage_SideHouse(void) {
    return 1;
}

void sub_StateChange_MinishVillage_SideHouse(void) {
}

typedef struct {
    u8 LO[0x4000];
    u8 HI[0x4000];
} struct_086D4460;

extern struct_086D4460 gUnk_086D4460;

void sub_unk2_MinishVillage_SideHouse(void) {
    LoadResourceAsync(&gUnk_086D4460.LO, 0x6000000, 0x4000);
    LoadResourceAsync(&gUnk_086D4460.HI, 0x6008000, 0x4000);
    LoadPaletteGroup(0x19);
}

u32 sub_unk3_CastleGardenMinishHoles_East(void) {
    return 1;
}

void sub_StateChange_CastleGardenMinishHoles_East(void) {
}

u32 sub_unk3_CastleGardenMinishHoles_West(void) {
    return 1;
}

void sub_StateChange_CastleGardenMinishHoles_West(void) {
}

u32 sub_unk3_37_0(void) {
    return 1;
}

void sub_StateChange_37_0(void) {
}

u32 sub_unk3_37_1(void) {
    return 1;
}

void sub_StateChange_37_1(void) {
}

u32 sub_unk3_MinishCracks_LonLonRanchNorth(void) {
    return 1;
}

void sub_StateChange_MinishCracks_LonLonRanchNorth(void) {
}

u32 sub_unk3_MinishCracks_LakeHyliaEast(void) {
    return 1;
}

void sub_StateChange_MinishCracks_LakeHyliaEast(void) {
}

u32 sub_unk3_MinishCracks_HyruleCastleGarden(void) {
    return 1;
}

void sub_StateChange_MinishCracks_HyruleCastleGarden(void) {
}

u32 sub_unk3_MinishCracks_MtCrenel(void) {
    return 1;
}

void sub_StateChange_MinishCracks_MtCrenel(void) {
}

u32 sub_unk3_MinishCracks_EastHyruleCastle(void) {
    return 1;
}

void sub_StateChange_MinishCracks_EastHyruleCastle(void) {
}

u32 sub_unk3_MinishCracks_5(void) {
    return 1;
}

void sub_StateChange_MinishCracks_5(void) {
}

u32 sub_unk3_MinishCracks_CastleWildsBowHole(void) {
    return 1;
}

extern EntityData gUnk_080DCB10;

void sub_StateChange_MinishCracks_CastleWildsBowHole(void) {
    if (!GetInventoryValue(ITEM_BOW)) {
        LoadRoomEntityList(&gUnk_080DCB10);
    }
}

u32 sub_unk3_MinishCracks_RuinsEntrance(void) {
    return 1;
}

void sub_StateChange_MinishCracks_RuinsEntrance(void) {
}

u32 sub_unk3_MinishCracks_MinishWoodsSouth(void) {
    return 1;
}

void sub_StateChange_MinishCracks_MinishWoodsSouth(void) {
}

u32 sub_unk3_MinishCracks_CastorWildsNorth(void) {
    return 1;
}

void sub_StateChange_MinishCracks_CastorWildsNorth(void) {
}

u32 sub_unk3_MinishCracks_CastorWildsWest(void) {
    return 1;
}

void sub_StateChange_MinishCracks_CastorWildsWest(void) {
}

u32 sub_unk3_MinishCracks_CastorWildsMiddle(void) {
    return 1;
}

void sub_StateChange_MinishCracks_CastorWildsMiddle(void) {
}

u32 sub_unk3_MinishCracks_RuinsTektite(void) {
    return 1;
}

void sub_StateChange_MinishCracks_RuinsTektite(void) {
}

u32 sub_unk3_MinishCracks_CastorWildsNextToBow(void) {
    return 1;
}

void sub_StateChange_MinishCracks_CastorWildsNextToBow(void) {
}

u32 sub_unk3_MinishCracks_E(void) {
    return 1;
}

void sub_StateChange_MinishCracks_E(void) {
}

u32 sub_unk3_MinishCracks_F(void) {
    return 1;
}

void sub_StateChange_MinishCracks_F(void) {
}

u32 sub_unk3_MinishCracks_10(void) {
    return 1;
}

void sub_StateChange_MinishCracks_10(void) {
}

u32 sub_unk3_MinishCracks_11(void) {
    return 1;
}

void sub_StateChange_MinishCracks_11(void) {
}

u32 sub_unk3_MelarisMine_Main(void) {
    return 1;
}

extern EntityData gUnk_additional_8_MelarisMine_Main;
extern EntityData gUnk_additional_9_MelarisMine_Main;
extern EntityData gUnk_080DD294;

void sub_StateChange_MelarisMine_Main(void) {
    if (!CheckGlobalFlag(WHITE_SWORD_END)) {
        LoadRoomEntityList(&gUnk_additional_8_MelarisMine_Main);
    }
    if (!CheckLocalFlag(0x7f)) {
        LoadRoomEntityList(&gUnk_additional_9_MelarisMine_Main);
    } else {
        LoadRoomEntityList(&gUnk_080DD294);
    }
    SetLocalFlag(0x8e);
}

u32 sub_unk3_CloudTops_House(void) {
    return 1;
}

extern EntityData gUnk_080DD364;

void sub_StateChange_CloudTops_House(void) {
    if (!(gSave.windcrests & 0x4000000)) {
        LoadRoomEntityList(&gUnk_080DD364);
    }
}

void sub_unk1_CloudTops_House(void) {
    if (!(gSave.windcrests & 0x4000000)) {
        LoadRoomEntityList(&gUnk_080DD364);
    }
}

u32 sub_unk3_CloudTops_Middle(void) {
    return 1;
}

void sub_StateChange_CloudTops_Middle(void) {
}

u32 sub_unk3_CloudTops_Bottom(void) {
    return 1;
}

extern EntityData gUnk_080DD7E0;
extern EntityData gUnk_080DD840;

void sub_StateChange_CloudTops_Bottom(void) {

    if (CheckGlobalFlag(KUMOTATSUMAKI)) {
        sub_0809F814(0x6de);
    }
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (CheckLocalFlag(0xf0)) {
#else
    if (CheckLocalFlag(0xf3)) {
#endif
        sub_0809F814(0xe0);
    } else {
        LoadRoomEntityList(&gUnk_080DD7E0);
    }
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (CheckLocalFlag(0xf2)) {
#else
    if (CheckLocalFlag(0xf5)) {
#endif
        sub_0809F814(0xba3);
    } else {
        LoadRoomEntityList(&gUnk_080DD840);
    }
}

u32 sub_unk3_Ruins_Entrance(void) {
    return 1;
}

void sub_StateChange_Ruins_Entrance(void) {
    sub_080300E8();
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    SetLocalFlag(0x25);
#else
    SetLocalFlag(0x24);
#endif
}

u32 sub_unk3_Ruins_Beanstalk(void) {
    return 1;
}

void sub_StateChange_Ruins_Beanstalk(void) {
}

u32 sub_unk3_Ruins_TripleTektites(void) {
    return 1;
}

extern EntityData gUnk_080DDE88;

void sub_StateChange_Ruins_TripleTektites(void) {

    if (CheckKinstoneFused(0x41)) {
        LoadRoomEntityList(&gUnk_080DDE88);
    }
}

void sub_unk1_Ruins_TripleTektites(void) {
    if (CheckLocalFlagByBank(FLAG_BANK_1, LOST_02_00)) {
        SetDirtTile(0x85);
    }
}

u32 sub_unk3_Ruins_LadderToTektites(void) {
    return 1;
}

void sub_StateChange_Ruins_LadderToTektites(void) {
}

u32 sub_unk3_Ruins_FortressEntrance(void) {
    return 1;
}

extern EntityData gUnk_080DE008;

void sub_StateChange_Ruins_FortressEntrance(void) {
    sub_080300E8();
    if (CheckGlobalFlag(LV3_CLEAR) && !CheckLocalFlag(3)) {
        LoadRoomEntityList(&gUnk_080DE008);
    }
}

u32 sub_unk3_Ruins_Armos(void) {
    return 1;
}

extern EntityData gUnk_080DE1E0;
extern EntityData gUnk_080DE200;

void sub_StateChange_Ruins_Armos(void) {
    sub_080300E8();
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (!CheckLocalFlag(0x31)) {
#else
    if (!CheckLocalFlag(0x30)) {
#endif
        LoadRoomEntityList(&gUnk_080DE1E0);
    }
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (!CheckLocalFlag(0x32)) {
#else
    if (!CheckLocalFlag(0x31)) {
#endif
        LoadRoomEntityList(&gUnk_080DE200);
    }
}

u32 sub_unk3_DeepwoodShrine_Madderpillar(void) {
    return 1;
}

extern EntityData gUnk_080DE4C8;

void sub_StateChange_DeepwoodShrine_Madderpillar(void) {
    if ((gPlayerEntity.y.HALF.HI - gRoomControls.origin_y) < (gRoomControls.height >> 1)) {
        if (!CheckLocalFlag(0x17)) {
            LoadRoomEntityList(&gUnk_080DE4C8);
        }
    }
}

u32 sub_unk3_DeepwoodShrine_BluePortal(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_BluePortal(void) {
}

u32 sub_unk3_DeepwoodShrine_StairsToB1(void) {
    return 1;
}

extern EntityData gUnk_080DE814;
extern EntityData gUnk_additional_8_DeepwoodShrine_StairsToB1;

void sub_StateChange_DeepwoodShrine_StairsToB1(void) {
    if (!CheckLocalFlag(0x4b)) {
        LoadRoomEntityList(&gUnk_080DE814);
    } else {
        if (!CheckLocalFlag(0x4c)) {
            LoadRoomEntityList(&gUnk_additional_8_DeepwoodShrine_StairsToB1);
            SetTileType(0x79, 0x285, 1);
        } else {
            SetTileType(0x7a, 0x285, 1);
            if (!CheckLocalFlag(0x24)) {
                SetTileType(0x73, 0x205, 1);
            }
        }
    }
}

u32 sub_unk3_DeepwoodShrine_PotBridge(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_PotBridge(void) {
}

u32 sub_unk3_DeepwoodShrine_DoubleStatue(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_DoubleStatue(void) {
}

u32 sub_unk3_DeepwoodShrine_Map(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_Map(void) {
}

u32 sub_unk3_DeepwoodShrine_Barrel(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_Barrel(void) {
    if (gSave.unk7 == 0) {
        goto a;
    }
    if (gSave.unk7 != 2) {
    a:
        SetTileType(0x90, 0x20b, 1);
        SetTileType(0x90, 0x411, 1);
    } else {
        SetTileType(0x90, 0x211, 1);
        SetTileType(0x90, 0x40b, 1);
    }
    if (CheckLocalFlag(0x15)) {
        SetTileType(0x76, 0x304, 2);
    }
    if (CheckLocalFlag(0x16)) {
        SetTileType(0x76, 0x318, 2);
    }
}

u32 sub_unk3_DeepwoodShrine_Button(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_Button(void) {
}

u32 sub_unk3_DeepwoodShrine_Mulldozer(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_Mulldozer(void) {
}

u32 sub_unk3_DeepwoodShrine_Pillars(void) {
    return 1;
}
void sub_StateChange_DeepwoodShrine_Pillars(void) {
}

u32 sub_unk3_DeepwoodShrine_Lever(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_Lever(void) {
}

u32 sub_unk3_DeepwoodShrine_Entrance(void) {
    return 1;
}

#if defined(DEMO_USA) || defined(DEMO_JP)
void sub_StateChange_DeepwoodShrine_Entrance(void) {
#ifdef DEMO_USA
    if (gSaveHeader->saveFileId != 0 && GetInventoryValue(ITEM_EARTH_ELEMENT) == 0) {
#else
#ifdef DEMO_JP
    if (GetInventoryValue(ITEM_EARTH_ELEMENT) == 0) {
#endif
#endif
        SetTileType(0x365, 0x349, 1);
        SetTileType(0x365, 0x34a, 1);
        SetTileType(0x365, 0x34b, 1);
    }
}
#else
void sub_StateChange_DeepwoodShrine_Entrance(void) {
}
#endif

u32 sub_unk3_DeepwoodShrine_Torch(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_Torch(void) {
}

u32 sub_unk3_DeepwoodShrine_BossKey(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_BossKey(void) {
}

u32 sub_unk3_DeepwoodShrine_Compass(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_Compass(void) {
}

u32 sub_unk3_DeepwoodShrine_13(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_13(void) {
}

u32 sub_unk3_DeepwoodShrine_LilyPadWest(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_LilyPadWest(void) {
}

u32 sub_unk3_DeepwoodShrine_LilyPadEast(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_LilyPadEast(void) {
}

u32 sub_unk3_DeepwoodShrineBoss_Main(void) {
    return 1;
}

extern EntityData gUnk_additional_a_DeepwoodShrineBoss_Main;

extern u8 gUpdateVisibleTiles;
extern u32 gUsedPalettes;

void sub_StateChange_DeepwoodShrineBoss_Main(void) {

    if (!CheckLocalFlag(0x48)) {
        SetLocalFlag(0x48);
        MenuFadeIn(5, 0);
        gUpdateVisibleTiles = 0;
        gFadeControl.active = 0;
        gUsedPalettes = 0;
        *(u16*)0x5000000 = 0x7fff;
        DispReset(1);
    }
    if (CheckGlobalFlag(LV1_CLEAR)) {
        LoadRoomEntityList(&gUnk_additional_a_DeepwoodShrineBoss_Main);
    } else {
        SoundReq(SONG_STOP_BGM);
        gArea.bgm = gArea.queued_bgm;
    }
}

u32 sub_unk3_DeepwoodShrine_PreBoss(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_PreBoss(void) {
}

u32 sub_unk3_DeepwoodShrine_InsideBarrel(void) {
    return 1;
}

void sub_StateChange_DeepwoodShrine_InsideBarrel(void) {
    sub_08058D34();
    gArea.areaMetadata |= 0x40;
    gMain.substate = 5;
}

u32 sub_unk3_DeepwoodShrineEntry_Main(void) {
    return 1;
}

extern EntityData gUnk_080DFB78;

void sub_StateChange_DeepwoodShrineEntry_Main(void) {
    if (CheckGlobalFlag(LV1_CLEAR) && !CheckLocalFlagByBank(FLAG_BANK_1, LV1_CLEAR_MES)) {
        LoadRoomEntityList(&gUnk_080DFB78);
    }
}

u32 sub_unk3_CaveOfFlames_AfterCane(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_AfterCane(void) {
}

u32 sub_unk3_CaveOfFlames_SpinyChus(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_SpinyChus(void) {
}

u32 sub_unk3_CaveOfFlames_CartToSpinyChus(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_CartToSpinyChus(void) {
}

u32 sub_unk3_CaveOfFlames_Entrance(void) {
    return 1;
}

#ifdef DEMO_USA
void sub_StateChange_CaveOfFlames_Entrance(void) {
    if (GetInventoryValue(ITEM_FIRE_ELEMENT) == 0) {
        SetTileType(0x365, 0x287, 2);
        SetTileType(0x365, 0x288, 2);
        SetTileType(0x365, 0x289, 2);
    }
}
#else
void sub_StateChange_CaveOfFlames_Entrance(void) {
}
#endif

u32 sub_unk3_CaveOfFlames_MainCart(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_MainCart(void) {
}

u32 sub_unk3_CaveOfFlames_NorthEntrance(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_NorthEntrance(void) {
}

u32 sub_unk3_CaveOfFlames_CartWest(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_CartWest(void) {
}

u32 sub_unk3_CaveOfFlames_Helmasaur(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_Helmasaur(void) {
}

u32 sub_unk3_CaveOfFlames_Rollobite(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_Rollobite(void) {
}

u32 sub_unk3_CaveOfFlames_MinishLava(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_MinishLava(void) {
}

u32 sub_unk3_CaveOfFlames_MinishSpikes(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_MinishSpikes(void) {
}

u32 sub_unk3_CaveOfFlames_RollobiteSwitch(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_RollobiteSwitch(void) {
}

extern u32 gUnk_080E103C;

u32 sub_unk3_CaveOfFlames_BeforeGleerok(void) {
    if (CheckGlobalFlag(LV2_CLEAR)) {
        gRoomVars.field_0x6c[1] = &gUnk_080E103C;
    }
    return 1;
}

void sub_StateChange_CaveOfFlames_BeforeGleerok(void) {
}

u32 sub_unk3_CaveOfFlames_PathBossKey(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_PathBossKey(void) {
}

u32 sub_unk3_CaveOfFlames_PathBossKey2(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_PathBossKey2(void) {
}

u32 sub_unk3_CaveOfFlames_Compass(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_Compass(void) {
}

u32 sub_unk3_CaveOfFlames_Bobomb(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_Bobomb(void) {
}

u32 sub_unk3_CaveOfFlames_BossDoor(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_BossDoor(void) {
}

u32 sub_unk3_CaveOfFlames_18(void) {
    return 1;
}

void sub_StateChange_CaveOfFlames_18(void) {
}

u32 sub_unk3_CaveOfFlamesBoss_Main(void) {
    return 1;
}

extern EntityData gUnk_additional_a_CaveOfFlamesBoss_Main;

extern u32 gUnk_0200B650;

void sub_StateChange_CaveOfFlamesBoss_Main(void) {

    if (CheckGlobalFlag(LV2_CLEAR)) {
        gUnk_0200B650 = 0;
        gScreen.lcd.displayControl &= ~DISPCNT_BG1_ON;
        sub_0807AABC(&gPlayerEntity);
        LoadRoomEntityList(&gUnk_additional_a_CaveOfFlamesBoss_Main);
    } else {
        SoundReq(SONG_STOP_BGM);
        gArea.bgm = gArea.queued_bgm;
    }
}

u32 sub_unk3_FortressOfWinds_Eyegore(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_Eyegore(void) {
}

u32 sub_unk3_FortressOfWinds_BeforeMazaal(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_BeforeMazaal(void) {
    gRoomTransition.field_0x38 = 0;
    gRoomTransition.field_0x39 = 0x5a;
}

u32 sub_unk3_FortressOfWinds_EastKeyLever(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_EastKeyLever(void) {
    sub_080300E8();
}

u32 sub_unk3_FortressOfWinds_PitPlatforms(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_PitPlatforms(void) {
}

u32 sub_unk3_FortressOfWinds_WestKeyLever(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_WestKeyLever(void) {
    sub_080300E8();
}

u32 sub_unk3_FortressOfWinds_Darknut(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_Darknut(void) {
}

u32 sub_unk3_FortressOfWinds_EyeBridge(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_EyeBridge(void) {
}

u32 sub_unk3_FortressOfWinds_Pit(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_Pit(void) {
}

u32 sub_unk3_FortressOfWinds_Wallmaster(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_Wallmaster(void) {
}

u32 sub_unk3_FortressOfWinds_Clone(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_Clone(void) {
}

u32 sub_unk3_FortressOfWinds_SpikeTraps(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_SpikeTraps(void) {
}

u32 sub_unk3_FortressOfWinds_Mazaal(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_Mazaal(void) {

    if (!CheckFlags(0x31)) {
        if (gRoomTransition.field_0x38 == 0) {
            SoundReq(SONG_STOP_BGM);
        } else {
            if (gRoomTransition.field_0x39 == 0) {
                SoundReq(SONG_STOP);
                SetPlayerControl(3);
            }
        }
        gArea.bgm = gArea.queued_bgm;
    }
}

u32 sub_unk3_FortressOfWinds_Stalfos(void) {
    return 1;
}

void sub_StateChange_FortressOfWinds_Stalfos(void) {
}

u32 sub_unk3_FortressOfWinds_EntranceMoleMitts(void) {
    return 1;
}

void sub_StateChange_Dojos_Waveblade0(void) {
}

u32 sub_unk3_FortressOfWinds_Main2F(void) {
    return 1;
}

void sub_StateChange_Dojos_Waveblade1(void) {
}

u32 sub_unk3_FortressOfWinds_MinishHole(void) {
    return 1;
}

void sub_StateChange_Dojos_Waveblade2(void) {
}

u32 sub_unk3_FortressOfWinds_BossKey(void) {
    return 1;
}

void sub_StateChange_Dojos_Waveblade3(void) {
}

u32 sub_unk3_FortressOfWinds_WestStairs2F(void) {
    return 1;
}

void sub_StateChange_Dojos_Waveblade4(void) {
}

u32 sub_unk3_FortressOfWinds_EastStairs2F(void) {
    return 1;
}

void sub_StateChange_Dojos_Waveblade5(void) {
}

u32 sub_unk3_FortressOfWinds_WestStairs1F(void) {
    return 1;
}

void sub_StateChange_Dojos_Waveblade6(void) {
}

u32 sub_unk3_FortressOfWinds_CenterStairs1F(void) {
    return 1;
}

void sub_StateChange_Dojos_Waveblade7(void) {
}

u32 sub_unk3_FortressOfWinds_EastStairs1F(void) {
    return 1;
}

void sub_StateChange_Dojos_Waveblade8(void) {
}

u32 sub_unk3_FortressOfWinds_Wizzrobe(void) {
    return 1;
}

void sub_StateChange_Dojos_Waveblade9(void) {
}

u32 sub_unk3_FortressOfWinds_HeartPiece(void) {
    return 1;
}

void sub_StateChange_Dojos_70(void) {
}

u32 sub_unk3_InnerMazaal_Main(void) {
    return 1;
}

void sub_StateChange_Dojos_71(void) {
}

u32 sub_unk3_FortressOfWindsTop_Main(void) {
    return 1;
}

extern EntityData gUnk_080E3850;

void sub_StateChange_FortressOfWindsTop_Main(void) {
    SetGlobalFlag(LV3_CLEAR);
    UpdateGlobalProgress();
    sub_0805B4D0(3);
    if (!GetInventoryValue(ITEM_OCARINA) && CheckLocalFlag(0x45)) {
        LoadRoomEntityList(&gUnk_080E3850);
    }
}

u32 sub_unk3_TempleOfDroplets_WestHole(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_WestHole(void) {
    sub_0804D0B4();
}

static void sub_0804D0B4(void) {
    if (!CheckLocalFlag(0x29)) {
        SetLocalFlag(0x29);
        SetLocalFlag(0x4b);
        SetLocalFlag(0x4e);
    }
}

u32 sub_unk3_TempleOfDroplets_NorthSplit(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_NorthSplit(void) {
}

u32 sub_unk3_TempleOfDroplets_EastHole(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_EastHole(void) {
}

u32 sub_unk3_TempleOfDroplets_Entrance(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_Entrance(void) {
}

u32 sub_unk3_TempleOfDroplets_NorthwestStairs(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_NorthwestStairs(void) {
}

u32 sub_unk3_TempleOfDroplets_ScissorsMiniboss(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_ScissorsMiniboss(void) {
}

u32 sub_unk3_TempleOfDroplets_WaterfallNorthwest(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_WaterfallNorthwest(void) {
}

u32 sub_unk3_TempleOfDroplets_WaterfallNortheast(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_WaterfallNortheast(void) {
}

u32 sub_unk3_TempleOfDroplets_Element(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_Element(void) {
}

u32 sub_unk3_TempleOfDroplets_IceCorner(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_IceCorner(void) {
}

u32 sub_unk3_TempleOfDroplets_IcePitMaze(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_IcePitMaze(void) {
}

u32 sub_unk3_TempleOfDroplets_HoleToBlueChuchu(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_HoleToBlueChuchu(void) {
}

u32 sub_unk3_TempleOfDroplets_WaterfallSoutheast(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_WaterfallSoutheast(void) {
}

u32 sub_unk3_TempleOfDroplets_WaterfallSouthwest(void) {
    return 1;
}

void sub_StateChange_TempleOfDroplets_WaterfallSouthwest(void) {
}

u32 sub_unk3_TempleOfDroplets_BigOcto(void) {
    return 1;
}

extern EntityData gUnk_additional_a_TempleOfDroplets_BigOcto;

void sub_StateChange_TempleOfDroplets_BigOcto(void) {
    ChangeLightLevel(0x100);
    if (CheckGlobalFlag(LV4_CLEAR)) {
        LoadRoomEntityList(&gUnk_additional_a_TempleOfDroplets_BigOcto);
    } else {
        SoundReq(SONG_STOP_BGM);
        gArea.bgm = gArea.queued_bgm;
    }
}

u32 sub_unk3_TempleOfDroplets_ToBigBlueChuchu(void) {
    return 1;
}

void sub_StateChange_Dojos_72(void) {
}

u32 sub_unk3_TempleOfDroplets_BigBlueChuchu(void) {
    return 1;
}

extern EntityData gUnk_080E4BD8;

void sub_StateChange_TempleOfDroplets_BigBlueChuchu(void) {
    if (!CheckLocalFlag(0x48)) {
        ClearLocalFlag(0x46);
        LoadRoomEntityList(&gUnk_080E4BD8);
    }
}

u32 sub_unk3_TempleOfDroplets_BigBlueChuchuKey(void) {
    return 1;
}

extern EntityData gUnk_080E4CF8;
extern EntityData gUnk_080E4CD8;

void sub_StateChange_TempleOfDroplets_BigBlueChuchuKey(void) {
    sub_0804D0B4();
    if (CheckLocalFlag(0x6c)) {
        LoadRoomEntityList(&gUnk_080E4CD8);
    } else {
        LoadRoomEntityList(&gUnk_080E4CF8);
    }
    if (!CheckLocalFlag(0x4b)) {
        ClearLocalFlag(0x49);
    }
}

u32 sub_unk3_TempleOfDroplets_BossKey(void) {
    return 1;
}

void sub_StateChange_Dojos_73(void) {
}

u32 sub_unk3_TempleOfDroplets_NorthSmallKey(void) {
    return 1;
}

void sub_StateChange_Dojos_74(void) {
}

u32 sub_unk3_TempleOfDroplets_BlockCloneButtonPuzzle(void) {
    return 1;
}

void sub_StateChange_Dojos_75(void) {
}

u32 sub_unk3_TempleOfDroplets_BlockClonePuzzle(void) {
    return 1;
}

void sub_StateChange_Dojos_76(void) {
}

u32 sub_unk3_TempleOfDroplets_BlockCloneIceBridge(void) {
    return 1;
}

void sub_StateChange_Dojos_77(void) {
}

u32 sub_unk3_TempleOfDroplets_StairsToScissorsMiniboss(void) {
    return 1;
}

void sub_StateChange_Dojos_78(void) {
}

u32 sub_unk3_TempleOfDroplets_SpikeBar(void) {
    return 1;
}

void sub_StateChange_Dojos_79(void) {
}

u32 sub_unk3_TempleOfDroplets_Lanterns(void) {
    return 1;
}

void sub_StateChange_Dojos_80(void) {
}

u32 sub_unk3_TempleOfDroplets_LilypadIceBlocks(void) {
    return 1;
}

extern EntityData gUnk_080E5660;
extern EntityData gUnk_080E5680;

void sub_StateChange_TempleOfDroplets_LilypadIceBlocks(void) {
    if (!CheckLocalFlag(0x59)) {
        LoadRoomEntityList(&gUnk_080E5660);
    } else {
        LoadRoomEntityList(&gUnk_080E5680);
    }
}

u32 sub_unk3_TempleOfDroplets_Pit(void) {
    return 1;
}

void sub_StateChange_Dojos_81(void) {
}

u32 sub_unk3_TempleOfDroplets_FireBars(void) {
    return 1;
}

void sub_StateChange_Dojos_82(void) {
}

u32 sub_unk3_TempleOfDroplets_LanternMaze(void) {
    return 1;
}

void sub_StateChange_Dojos_83(void) {
}

u32 sub_unk3_TempleOfDroplets_Madderpillars(void) {
    return 1;
}

void sub_StateChange_Dojos_84(void) {
}

u32 sub_unk3_TempleOfDroplets_AfterMadderpillars(void) {
    return 1;
}

void sub_StateChange_Dojos_85(void) {
}

u32 sub_unk3_TempleOfDroplets_BlueChuchuKeyLever(void) {
    return 1;
}

extern EntityData gUnk_080E5E3C;
extern EntityData gUnk_080E5E5C;

void sub_StateChange_TempleOfDroplets_BlueChuchuKeyLever(void) {
    sub_0804D0B4();
    if (!CheckLocalFlag(0x4b)) {
        LoadRoomEntityList(&gUnk_080E5E3C);
    } else {
        LoadRoomEntityList(&gUnk_080E5E5C);
    }
}

u32 sub_unk3_TempleOfDroplets_MulldozerKey(void) {
    return 1;
}

void sub_StateChange_Dojos_86(void) {
}

u32 sub_unk3_TempleOfDroplets_BombWall(void) {
    return 1;
}

void sub_StateChange_Dojos_87(void) {
}

u32 sub_unk3_TempleOfDroplets_LilypadWestB2(void) {
    return 1;
}

void sub_StateChange_Dojos_88(void) {
}

u32 sub_unk3_TempleOfDroplets_CompassRoom(void) {
    return 1;
}

void sub_StateChange_Dojos_89(void) {
}

u32 sub_unk3_TempleOfDroplets_LanternScissors(void) {
    return 1;
}

void sub_StateChange_Dojos_90(void) {
}

u32 sub_unk3_TempleOfDroplets_LilypadMiddleB2(void) {
    return 1;
}

void sub_StateChange_Dojos_91(void) {
}

u32 sub_unk3_TempleOfDroplets_LilypadEastB2(void) {
    return 1;
}

void sub_StateChange_Dojos_92(void) {
}

u32 sub_unk3_TempleOfDroplets_FlameBarBlockPuzzle(void) {
    return 1;
}

void sub_StateChange_Dojos_93(void) {
}

u32 sub_unk3_RoyalCrypt_KingGustaf(void) {
    return 1;
}

extern EntityData gUnk_080E693C;

void sub_StateChange_RoyalCrypt_KingGustaf(void) {
    if (!CheckLocalFlag(0x32)) {
        LoadRoomEntityList(&gUnk_080E693C);
    }
}

u32 sub_unk3_RoyalCrypt_WaterRope(void) {
    return 1;
}

void sub_StateChange_Dojos_94(void) {
}

u32 sub_unk3_RoyalCrypt_Gibdo(void) {
    return 1;
}

void sub_StateChange_Dojos_95(void) {
}

u32 sub_unk3_RoyalCrypt_3(void) {
    return 1;
}

void sub_StateChange_Dojos_96(void) {
}

u32 sub_unk3_RoyalCrypt_KeyBlock(void) {
    return 1;
}

void sub_StateChange_Dojos_97(void) {
}

u32 sub_unk3_RoyalCrypt_5(void) {
    return 1;
}

void sub_StateChange_Dojos_98(void) {
}

u32 sub_unk3_RoyalCrypt_6(void) {
    return 1;
}

void sub_StateChange_Dojos_99(void) {
}

u32 sub_unk3_RoyalCrypt_MushroomPit(void) {
    return 1;
}

void sub_StateChange_RoyalCrypt_MushroomPit(void) {
    sub_08054570();
}

u32 sub_unk3_RoyalCrypt_Entrance(void) {
    return 1;
}

extern EntityData gUnk_080E718C;
extern EntityData gUnk_080E71AC;

void sub_StateChange_RoyalCrypt_Entrance(void) {
    SetTileType(0x312, 0x108, 1);
    sub_08054570();
    if (!CheckLocalFlag(0xc4)) {
        LoadRoomEntityList(&gUnk_080E718C);
    }
    if (!CheckLocalFlag(0xc5)) {
        LoadRoomEntityList(&gUnk_080E71AC);
    }
}

u32 sub_unk3_PalaceOfWinds_0(void) {
    return 1;
}

extern EntityData gUnk_additional_9_PalaceOfWinds_0;
extern EntityData gUnk_080E72C4;
extern EntityData gUnk_additional_8_PalaceOfWinds_0;

void sub_StateChange_PalaceOfWinds_0(void) {
    Manager19_Main(NULL);
    if (CheckGlobalFlag(LV5_CLEAR)) {
        LoadRoomEntityList(&gUnk_additional_9_PalaceOfWinds_0);
    }
    if (!CheckLocalFlag(0x7b)) {
        LoadRoomEntityList(&gUnk_080E72C4);
    } else {
        SetGlobalFlag(LV5_CLEAR);
        if (!GetInventoryValue(ITEM_WIND_ELEMENT)) {
            SetPlayerControl(3);
            LoadRoomEntityList(&gUnk_additional_8_PalaceOfWinds_0);
            gArea.bgm = gArea.queued_bgm;
            SoundReq(SONG_STOP_BGM);
        }
    }
}

u32 sub_unk3_PalaceOfWinds_1(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_1(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_2(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_2(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_3(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_3(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_4(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_4(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_5(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_5(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_6(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_6(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_7(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_7(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_8(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_8(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_9(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_9(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_10(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_10(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_11(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_11(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_12(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_12(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_13(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_13(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_14(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_14(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_15(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_15(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_16(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_16(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_17(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_17(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_18(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_18(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_19(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_19(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_20(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_20(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_21(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_21(void) {
}

u32 sub_unk3_PalaceOfWinds_22(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_22(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_23(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_23(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_24(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_24(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_25(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_25(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_26(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_26(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_27(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_27(void) {
}

u32 sub_unk3_PalaceOfWinds_28(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_28(void) {
}

u32 sub_unk3_PalaceOfWinds_29(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_29(void) {
}

u32 sub_unk3_PalaceOfWinds_30(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_30(void) {
}

u32 sub_unk3_PalaceOfWinds_31(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_31(void) {
}

u32 sub_unk3_PalaceOfWinds_32(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_32(void) {
}

u32 sub_unk3_PalaceOfWinds_33(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_33(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_34(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_34(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_35(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_35(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_36(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_36(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_37(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_37(void) {
}

u32 sub_unk3_PalaceOfWinds_38(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_38(void) {
}

u32 sub_unk3_PalaceOfWinds_39(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_39(void) {
}

u32 sub_unk3_PalaceOfWinds_40(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_40(void) {
}

u32 sub_unk3_PalaceOfWinds_41(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_41(void) {
}

u32 sub_unk3_PalaceOfWinds_42(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_42(void) {
}

u32 sub_unk3_PalaceOfWinds_43(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_43(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_44(void) {
    return 1;
}

extern EntityData gUnk_080EA09C;

void sub_StateChange_PalaceOfWinds_44(void) {
    Manager19_Main(NULL);
    if (!CheckLocalFlag(0x70)) {
        LoadRoomEntityList(&gUnk_080EA09C);
    }
}

u32 sub_unk3_PalaceOfWinds_45(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_45(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_46(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_46(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_47(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_47(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_48(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_48(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_49(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_49(void) {
    Manager19_Main(NULL);
}

u32 sub_unk3_PalaceOfWinds_50(void) {
    return 1;
}

void sub_StateChange_PalaceOfWinds_50(void) {
}

u32 sub_unk3_PalaceOfWindsBoss_Main(void) {
    return 1;
}

void sub_StateChange_PalaceOfWindsBoss_Main(void) {
}

u32 sub_unk3_Vaati2_Main(void) {
    return 1;
}

void sub_StateChange_Vaati2_Main(void) {
    SoundReq(SONG_STOP_BGM);
    gArea.bgm = gArea.queued_bgm;
}

u32 sub_unk3_Vaati3_Main(void) {
    return 1;
}

void sub_StateChange_Vaati3_Main(void) {
    Manager2F_Main(NULL);

    if ((gRoomTransition.field_0x38 & 1) && gRoomTransition.field_0x39) {
        if (gRoomTransition.field_0x3c == 1) {
            gPlayerEntity.x.HALF.HI = gRoomTransition.field_0x48;
            gPlayerEntity.y.HALF.HI = gRoomTransition.field_0x4a + 8;
        } else {
            if (gRoomTransition.field_0x3c) {
                return;
            }
            gPlayerEntity.x.HALF.HI = gRoomTransition.field_0x44;
            gPlayerEntity.y.HALF.HI = gRoomTransition.field_0x46 + 8;
        }
    }
}

u32 sub_unk3_DarkHyruleCastleBridge_Main(void) {
    return 1;
}

void sub_StateChange_DarkHyruleCastleBridge_Main(void) {
    sub_0805B4D0(6);
}

u32 sub_unk3_VaatisArms_First(void) {
    return 1;
}

void sub_StateChange_VaatisArms_First(void) {
}

u32 sub_unk3_VaatisArms_Second(void) {
    return 1;
}

void sub_StateChange_VaatisArms_Second(void) {
}

u32 sub_unk3_DarkHyruleCastleOutside_ZeldaStatuePlatform(void) {
    sub_080534AC();
    return 1;
}

extern EntityData gUnk_080EAD68;
extern EntityData gUnk_080EADB8;

void sub_StateChange_DarkHyruleCastleOutside_ZeldaStatuePlatform(void) {
    sub_0805B4D0(4);
    if (!CheckLocalFlag(0x77)) {
        LoadRoomEntityList(&gUnk_080EAD68);
    } else if (!CheckLocalFlag(0x79)) {
        LoadRoomEntityList(&gUnk_080EADB8);
        SetTileType(0x4072, 0x145, 1);
        SetTileType(0x4072, 0x149, 1);
        gArea.queued_bgm = 0;
    }
}

extern u16 gUnk_080EAE00;

void sub_0804D7EC(void) {
    u16 temp;
    u16* tilePos;

    tilePos = &gUnk_080EAE00;
    while (*tilePos != 0) {
        temp = *tilePos;
        tilePos++;
        SetTileType(0x4072, temp, 1);
    }
}

void sub_0804D810(void) {
    u16 uVar1;
    u16* puVar2;

    puVar2 = &gUnk_080EAE00;
    while (*puVar2 != 0) {
        uVar1 = *puVar2;
        puVar2++;
        sub_0807BA8C(uVar1, 1);
    }
}

u32 sub_unk3_DarkHyruleCastleOutside_Garden(void) {
    return 1;
}

extern EntityData gUnk_080EAE60;
extern EntityData gUnk_080EAEC0;
extern EntityData gUnk_080EAF20;

void sub_StateChange_DarkHyruleCastleOutside_Garden(void) {
    gArea.areaMetadata = 0x40;
    gArea.locationIndex = 0;
    if (CheckGlobalFlag(ENDING)) {
        if (!CheckLocalFlag(0x7f)) {
            LoadRoomEntityList(&gUnk_080EAEC0);
            SetLocalFlag(0x7f);
            gArea.queued_bgm = 0x11;
        } else {
            LoadRoomEntityList(&gUnk_080EAF20);
            gArea.queued_bgm = gArea.bgm;
        }
    } else {
        if (CheckLocalFlag(0x79)) {
            gArea.queued_bgm = gArea.bgm;
        }
        if (!CheckLocalFlag(1)) {
            LoadRoomEntityList(&gUnk_080EAE60);
        }
    }
    ClearGlobalFlag(0x5d);
}

u32 sub_unk3_DarkHyruleCastleOutside_OutsideNorthwest(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGrimblade0(void) {
}

u32 sub_unk3_DarkHyruleCastleOutside_OutsideNortheast(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGrimblade1(void) {
}

u32 sub_unk3_DarkHyruleCastleOutside_OutsideEast(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGrimblade2(void) {
}

u32 sub_unk3_DarkHyruleCastleOutside_OutsideSouthwest(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGrimblade3(void) {
}

u32 sub_unk3_DarkHyruleCastleOutside_OutsideSouth(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGrimblade4(void) {
}

u32 sub_unk3_DarkHyruleCastleOutside_OutsideSoutheast(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGrimblade5(void) {
}

u32 sub_unk3_DarkHyruleCastleOutside_8(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGrimblade6(void) {
}

extern u32 gUnk_080EB604;
extern u32 gUnk_080EB5D4;

u32 sub_unk3_DarkHyruleCastle_0(void) {
    if (CheckGlobalFlag(ENDING)) {
        gRoomVars.field_0x6c[0] = &gUnk_080EB604;
        gRoomVars.field_0x6c[2] = 0;
        gArea.bgm = gArea.queued_bgm = BGM_BEAT_VAATI;
    } else if (CheckLocalFlag(0x79)) {
        gRoomVars.field_0x6c[0] = NULL;
        if (!CheckLocalFlag(0x7a)) {
            SetGlobalFlag(ZELDA_CHASE);
            gRoomVars.field_0x6c[0] = &gUnk_080EB5D4;
            gRoomVars.field_0x6c[7] = sub_0804D9B0;
            gRoomVars.field_0x6c[2] = 0;
        }
    }
    return 1;
}

void sub_StateChange_DarkHyruleCastle_0(void) {
    if (CheckGlobalFlag(ENDING)) {
        gArea.queued_bgm = gArea.bgm;
    }

    if (CheckLocalFlag(0x79)) {
        sub_0804D9B0();
    }
}

extern EntityData gUnk_080EB684;

static void sub_0804D9B0(void) {
    sub_0807BB98(0x797, 1, 5, 1);
    sub_0807BB98(0x357, 1, 5, 1);
    sub_0807BB98(0x55f, 1, 2, 1);
    LoadRoomEntityList(&gUnk_080EB684);
    gArea.queued_bgm = gArea.bgm;
}

u32 sub_unk3_DarkHyruleCastle_1(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGrimblade7(void) {
}

u32 sub_unk3_DarkHyruleCastle_2(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGrimblade8(void) {
}

u32 sub_unk3_DarkHyruleCastle_3(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGrimblade9(void) {
}

u32 sub_unk3_DarkHyruleCastle_4(void) {
    return 1;
}

void sub_StateChange_Dojos_ToSplitblade0(void) {
}

u32 sub_unk3_DarkHyruleCastle_5(void) {
    return 1;
}

void sub_StateChange_Dojos_ToSplitblade1(void) {
}

u32 sub_unk3_DarkHyruleCastle_6(void) {
    if (!CheckLocalFlag(0x77)) {
        gRoomVars.field_0x6c[0] = 0;
        gRoomVars.field_0x6c[2] = 0;
    }
    return 1;
}

extern EntityData gUnk_080EB9F4;
extern EntityData gUnk_080EBAA4;
extern EntityData gUnk_080EBAF4;

void sub_StateChange_DarkHyruleCastle_6(void) {
    if (!CheckLocalFlag(0x77)) {
        LoadRoomEntityList(&gUnk_080EB9F4);
    } else {
        if (!CheckLocalFlag(0x78)) {
            LoadRoomEntityList(&gUnk_080EBAA4);
            SetLocalFlag(0x75);
        }
        if (CheckLocalFlag(0x7b)) {
            LoadRoomEntityList(&gUnk_080EBAF4);
            SetLocalFlag(0x76);
        }
    }
}

u32 sub_unk3_DarkHyruleCastle_7(void) {
    return 1;
}

void sub_StateChange_Dojos_ToSplitblade2(void) {
}

u32 sub_unk3_DarkHyruleCastle_8(void) {
    return 1;
}

void sub_StateChange_Dojos_ToSplitblade3(void) {
}

u32 sub_unk3_DarkHyruleCastle_9(void) {
    return 1;
}

void sub_StateChange_Dojos_ToSplitblade4(void) {
}

u32 sub_unk3_DarkHyruleCastle_10(void) {
    return 1;
}

void sub_StateChange_Dojos_ToSplitblade5(void) {
}

u32 sub_unk3_DarkHyruleCastle_11(void) {
    return 1;
}

void sub_StateChange_Dojos_ToSplitblade6(void) {
}

u32 sub_unk3_DarkHyruleCastle_12(void) {
    return 1;
}
void sub_StateChange_Dojos_ToSplitblade7(void) {
}

u32 sub_unk3_DarkHyruleCastle_13(void) {
    return 1;
}

void sub_StateChange_Dojos_ToSplitblade8(void) {
}

u32 sub_unk3_DarkHyruleCastle_14(void) {
    return 1;
}

extern EntityData gUnk_080EC2CC;

void sub_StateChange_DarkHyruleCastle_14(void) {
    if (CheckLocalFlag(0x86) && !CheckLocalFlag(0x4c)) {
        LoadRoomEntityList(&gUnk_080EC2CC);
    }
}

u32 sub_unk3_DarkHyruleCastle_15(void) {
    return 1;
}

void sub_StateChange_Dojos_ToSplitblade9(void) {
}

u32 sub_unk3_DarkHyruleCastle_16(void) {
    return 1;
}

extern EntityData gUnk_080EC4E8;

void sub_StateChange_DarkHyruleCastle_16(void) {
    if (CheckLocalFlag(0x86) && !CheckLocalFlag(0x4d)) {
        LoadRoomEntityList(&gUnk_080EC4E8);
    }
}

u32 sub_unk3_DarkHyruleCastle_17(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGreatblade0(void) {
}

u32 sub_unk3_DarkHyruleCastle_18(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGreatblade1(void) {
}

u32 sub_unk3_DarkHyruleCastle_19(void) {
    return 1;
}

extern EntityData gUnk_080EC820;

void sub_StateChange_DarkHyruleCastle_19(void) {
    if (CheckLocalFlag(0x86) && !CheckLocalFlag(0x53)) {
        LoadRoomEntityList(&gUnk_080EC820);
    }
}

u32 sub_unk3_DarkHyruleCastle_20(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGreatblade2(void) {
}

u32 sub_unk3_DarkHyruleCastle_21(void) {
    return 1;
}

extern EntityData gUnk_080ECA60;

void sub_StateChange_DarkHyruleCastle_21(void) {
    if (CheckLocalFlag(0x86) && !CheckLocalFlag(0x56)) {
        LoadRoomEntityList(&gUnk_080ECA60);
    }
}

u32 sub_unk3_DarkHyruleCastle_22(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGreatblade3(void) {
}

u32 sub_unk3_DarkHyruleCastle_23(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGreatblade4(void) {
}

u32 sub_unk3_DarkHyruleCastle_24(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGreatblade5(void) {
}

u32 sub_unk3_DarkHyruleCastle_25(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGreatblade6(void) {
}

u32 sub_unk3_DarkHyruleCastle_26(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGreatblade7(void) {
}

u32 sub_unk3_DarkHyruleCastle_27(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGreatblade8(void) {
}

u32 sub_unk3_DarkHyruleCastle_28(void) {
    if (CheckLocalFlag(0x79)) {
        gRoomVars.field_0x6c[2] = 0;
    }
    return 1;
}

extern EntityData gUnk_080ECFCC;

void sub_StateChange_DarkHyruleCastle_28(void) {
    if (CheckLocalFlag(0x79)) {
        sub_0807BB98(0x90, 1, 1, 5);
        LoadRoomEntityList(&gUnk_080ECFCC);
        gArea.queued_bgm = gArea.bgm;
    }
}

u32 sub_unk3_DarkHyruleCastle_29(void) {
    return 1;
}

void sub_StateChange_Dojos_ToGreatblade9(void) {
}

u32 sub_unk3_DarkHyruleCastle_30(void) {
    return 1;
}

void sub_StateChange_Dojos_ToScarblade0(void) {
}

extern u32 gUnk_080ED1E4;

u32 sub_unk3_DarkHyruleCastle_31(void) {
    if (CheckGlobalFlag(ENDING)) {
        gRoomVars.field_0x6c[0] = &gUnk_080ED1E4;
        gRoomVars.field_0x6c[2] = 0;
    }
    return 1;
}

void sub_StateChange_DarkHyruleCastle_31(void) {
    if (CheckGlobalFlag(ENDING)) {
        gArea.queued_bgm = gArea.bgm;
    }
}

u32 sub_unk3_DarkHyruleCastle_32(void) {
    return 1;
}

void sub_StateChange_Dojos_ToScarblade1(void) {
}

u32 sub_unk3_DarkHyruleCastle_33(void) {
    return 1;
}

void sub_StateChange_Dojos_ToScarblade2(void) {
}

u32 sub_unk3_DarkHyruleCastle_34(void) {
    return 1;
}

void sub_StateChange_Dojos_ToScarblade3(void) {
}

u32 sub_unk3_DarkHyruleCastle_35(void) {
    return 1;
}

void sub_StateChange_Dojos_ToScarblade4(void) {
}

u32 sub_unk3_DarkHyruleCastle_36(void) {
    return 1;
}

void sub_StateChange_Dojos_ToScarblade5(void) {
}

u32 sub_unk3_DarkHyruleCastle_37(void) {
    return 1;
}

void sub_StateChange_Dojos_ToScarblade6(void) {
}

u32 sub_unk3_DarkHyruleCastle_38(void) {
    return 1;
}

void sub_StateChange_Dojos_ToScarblade7(void) {
}

u32 sub_unk3_DarkHyruleCastle_39(void) {
    return 1;
}

void sub_StateChange_Dojos_ToScarblade8(void) {
}

u32 sub_unk3_DarkHyruleCastle_40(void) {
    return 1;
}

void sub_StateChange_Dojos_ToScarblade9(void) {
}

u32 sub_unk3_DarkHyruleCastle_41(void) {
    return 1;
}

void sub_StateChange_GoronCave_StairsToCave0(void) {
}

u32 sub_unk3_DarkHyruleCastle_42(void) {
    return 1;
}

void sub_StateChange_GoronCave_StairsToCave1(void) {
}

u32 sub_unk3_DarkHyruleCastle_43(void) {
    return 1;
}

void sub_StateChange_GoronCave_StairsToCave2(void) {
}

u32 sub_unk3_DarkHyruleCastle_44(void) {
    return 1;
}

void sub_StateChange_GoronCave_StairsToCave3(void) {
}

u32 sub_unk3_DarkHyruleCastle_45(void) {
    return 1;
}

void sub_StateChange_GoronCave_StairsToCave4(void) {
}

u32 sub_unk3_DarkHyruleCastle_46(void) {
    return 1;
}

void sub_StateChange_GoronCave_StairsToCave5(void) {
}

u32 sub_unk3_DarkHyruleCastle_47(void) {
    return 1;
}

void sub_StateChange_GoronCave_StairsToCave6(void) {
}

u32 sub_unk3_DarkHyruleCastle_48(void) {
    return 1;
}

void sub_StateChange_GoronCave_StairsToCave7(void) {
}

u32 sub_unk3_DarkHyruleCastle_49(void) {
    return 1;
}

void sub_StateChange_GoronCave_StairsToCave8(void) {
}

u32 sub_unk3_DarkHyruleCastle_50(void) {
    return 1;
}

void sub_StateChange_GoronCave_StairsToCave9(void) {
}

u32 sub_unk3_DarkHyruleCastle_51(void) {
    return 1;
}

void sub_StateChange_Ruins_Beanstalk0(void) {
}

u32 sub_unk3_DarkHyruleCastle_52(void) {
    return 1;
}

void sub_StateChange_Ruins_Beanstalk1(void) {
}

u32 sub_unk3_DarkHyruleCastle_53(void) {
    if (CheckLocalFlag(0x79)) {
        gRoomVars.field_0x6c[2] = 0;
        gRoomVars.field_0x6c[0] = 0;
    }
    return 1;
}

extern EntityData gUnk_080EE314;

void sub_StateChange_DarkHyruleCastle_53(void) {
    if (CheckLocalFlag(0x79)) {
        sub_0807BB98(3, 2, 5, 1);
        LoadRoomEntityList(&gUnk_080EE314);
        gArea.queued_bgm = gArea.bgm;
    }
}

u32 sub_unk3_DarkHyruleCastle_54(void) {
    return 1;
}

void sub_StateChange_Ruins_Beanstalk2(void) {
}

u32 sub_unk3_DarkHyruleCastle_55(void) {
    if (CheckLocalFlag(0x79)) {
        gRoomVars.field_0x6c[2] = 0;
    }
    return 1;
}

extern EntityData gUnk_080EE5DC;

void sub_StateChange_DarkHyruleCastle_55(void) {
    if (CheckLocalFlag(0x79)) {
        sub_0807BB98(0x392, 2, 2, 5);
        LoadRoomEntityList(&gUnk_080EE5DC);
        gArea.queued_bgm = gArea.bgm;
    }
}

u32 sub_unk3_DarkHyruleCastle_56(void) {
    return 1;
}

void sub_StateChange_Ruins_Beanstalk3(void) {
}

u32 sub_unk3_DarkHyruleCastle_57(void) {
    return 1;
}

extern EntityData gUnk_080EE71C;

void sub_StateChange_DarkHyruleCastle_57(void) {
    if (CheckLocalFlag(1)) {
        LoadRoomEntityList(&gUnk_080EE71C);
    }
}

u32 sub_unk3_DarkHyruleCastle_58(void) {
    return 1;
}

void sub_StateChange_Ruins_Beanstalk4(void) {
}

extern u32 Area_HyruleTown[];

u32 sub_unk3_HyruleTown_0(void) {
    u32 uVar1;
    u32 uVar2;

    UpdateGlobalProgress();
    if (CheckKinstoneFused(0xb)) {
        if (CheckGlobalFlag(0x19) == 0) {
            SetGlobalFlag(0x19);
        } else if (CheckGlobalFlag(0x18) == 0) {
            SetGlobalFlag(0x18);
        }
    }

    sub_0804AFB0((void**)(Area_HyruleTown[gSave.global_progress]));
    if (gSave.global_progress != 1) {
        gCurrentRoomProperties = (void**)*Area_HyruleTown;
    } else {
        SetGlobalFlag(0x1c);
        uVar1 = gArea.pCurrentRoomInfo->map_x;
        uVar2 = gArea.pCurrentRoomInfo->map_y;
        gRoomControls.area = 0x15;
        gRoomControls.room = 0;
        InitRoom();
        gArea.pCurrentRoomInfo->map_x = uVar1 + 0x130;
        gArea.pCurrentRoomInfo->map_y = uVar2;
        gRoomTransition.player_status.start_pos_x = (gArea.pCurrentRoomInfo->pixel_width) >> 1;
        sub_08052EA0();
        sub_0804AF90();

#if defined(JP) || defined(EU) || defined(DEMO_JP)
        if (CheckLocalFlag(0xca) == 0) {
#else
        if (CheckLocalFlag(0xcd) == 0) {
#endif
            SetFade(7, 0x100);
        } else {
            SetFade(6, 0x10);
        }
    }
    return 1;
}

extern EntityData gUnk_080EEB6C;
extern EntityData gUnk_080EEB8C;
extern EntityData gUnk_080EE88C;
extern EntityData gUnk_080EE8FC;
extern EntityData gUnk_080EE91C;
extern EntityData gUnk_080EECBC;
extern EntityData gUnk_080EE93C;
extern EntityData gUnk_080EE95C;
extern EntityData gUnk_080EE97C;
extern EntityData gUnk_080EE9BC;
extern EntityData gUnk_080EE99C;
extern EntityData gUnk_080EE9DC;
extern EntityData gUnk_080EEA3C;
extern EntityData gUnk_080EEA1C;
extern EntityData gUnk_080EE9FC;
extern EntityData gUnk_080EEA5C;
extern EntityData gUnk_080EEABC;
extern EntityData gUnk_080EEA7C;
extern EntityData gUnk_080EEA9C;
extern EntityData gUnk_080EEBAC;

void sub_StateChange_HyruleTown_0(void) {
    sub_08054570();
    TryLoadPrologueHyruleTown();
#if defined(USA) || defined(DEMO_USA) || defined(DEMO_JP)
    SetTileType(0x176, 0x66b, 1);
#endif
    if (gSave.global_progress == 1) {
        sub_0801D000(0);
    } else {
        sub_08018C58(0xdb4);
        if (!CheckLocalFlagByBank(FLAG_BANK_2, MHOUSE04_DANRO)) {
            LoadRoomEntityList(&gUnk_080EEB6C);
        }
        if (!CheckLocalFlagByBank(FLAG_BANK_2, MHOUSE06_DANRO)) {
            LoadRoomEntityList(&gUnk_080EEB8C);
        }

        if ((!GetInventoryValue(ITEM_KINSTONE_BAG)) && CheckGlobalFlag(LV1_CLEAR)) {
            LoadRoomEntityList(&gUnk_080EE88C);
        }
        if (!CheckKinstoneFused(0x28)) {
            LoadRoomEntityList(&gUnk_080EE8FC);
        }
        if (CheckKinstoneFused(0x33)) {
            LoadRoomEntityList(&gUnk_080EE91C);
        }
        if (CheckGlobalFlag(MACHI_MACHIHOKORI)) {
            LoadRoomEntityList(&gUnk_080EE93C);
        } else {
            LoadRoomEntityList(&gUnk_080EECBC);
        }
        if (CheckKinstoneFused(0x1b) && (gSave.global_progress > 3)) {
            if (!(CheckGlobalFlag(NEW_HOUSE_DIN) || CheckGlobalFlag(NEW_HOUSE_NAYRU) ||
                  CheckGlobalFlag(NEW_HOUSE_FARORE))) {
                if (!(CheckGlobalFlag(RENTED_HOUSE_DIN) || CheckGlobalFlag(RENTED_HOUSE_NAYRU) ||
                      CheckGlobalFlag(RENTED_HOUSE_FARORE))) {
                    LoadRoomEntityList(&gUnk_080EE95C);
                } else {
                    if (!CheckGlobalFlag(TATEKAKE_HOUSE)) {
                        LoadRoomEntityList(&gUnk_080EE97C);
                    } else {
                        LoadRoomEntityList(&gUnk_080EE9BC);
                    }
                }
            } else {
                LoadRoomEntityList(&gUnk_080EE99C);
            }
        }
        if (CheckGlobalFlag(RENTED_HOUSE_DIN)) {
            LoadRoomEntityList(&gUnk_080EE9FC);
        } else if (CheckGlobalFlag(RENTED_HOUSE_NAYRU)) {
            LoadRoomEntityList(&gUnk_080EEA1C);
        } else if (CheckGlobalFlag(RENTED_HOUSE_FARORE)) {
            LoadRoomEntityList(&gUnk_080EEA3C);
        } else {
            LoadRoomEntityList(&gUnk_080EE9DC);
        }
        if ((gSave.global_progress > 4) && !CheckKinstoneFused(0xb) &&
            (CheckGlobalFlag(RENTED_HOUSE_DIN) || CheckGlobalFlag(RENTED_HOUSE_NAYRU) ||
             CheckGlobalFlag(RENTED_HOUSE_FARORE))) {
            LoadRoomEntityList(&gUnk_080EEA5C);
        }
        // rocs cape
#if defined(JP) || defined(EU) || defined(DEMO_JP)
        if (!CheckLocalFlag(0xcd) && GetInventoryValue(ITEM_ROCS_CAPE)) {
#else
        if (!CheckLocalFlag(0xd0) && GetInventoryValue(ITEM_ROCS_CAPE)) {
#endif
            LoadRoomEntityList(&gUnk_080EEABC);
        }
        if ((gSave.global_progress > 3) && CheckGlobalFlag(INLOCK)) {
            LoadRoomEntityList(&gUnk_080EEA7C);
        }
        if ((gSave.global_progress < 6) && !CheckGlobalFlag(MIZUKAKI_START)) {
            LoadRoomEntityList(&gUnk_080EEA9C);
        }
        if ((gSave.windcrests & 0x8000000) == 0) {
            LoadRoomEntityList(&gUnk_080EEBAC);
        }
        sub_0804E150();
    }
}

void sub_unk1_HyruleTown_8(void) {
    if ((gSave.windcrests & 0x8000000) == 0) {
        LoadRoomEntityList(&gUnk_080EEBAC);
    }
}

extern u16 gUnk_080EED2C[];
extern u16 gUnk_080EED7A[];
extern u16 gUnk_080EED8C[];

void sub_0804E150(void) {
    u16* pTileData;
    u32 uVar3;

    pTileData = gUnk_080EED2C;
    uVar3 = 1 << gSave.global_progress;
    for (; pTileData[1] != 0; pTileData += 3) {
        if ((pTileData[0] & uVar3) != 0) {
            SetTile(pTileData[2], pTileData[1], 1);
        }
    }
#if defined(JP) || defined(DEMO_JP) || defined(EU)
    if (CheckLocalFlag(0xce) == 0) {
#else
    if (CheckLocalFlag(0xd1) == 0) {
#endif
        pTileData = gUnk_080EED7A;
        uVar3 = 1 << gSave.global_progress;
        for (; pTileData[0] != 0; pTileData += 3) {
            if ((pTileData[0] & uVar3) != 0) {
                SetTile(pTileData[2], pTileData[1], 1);
            }
        }
    }
    if (CheckGlobalFlag(0x29) == 0) {
        pTileData = gUnk_080EED8C;
        uVar3 = 1 << gSave.global_progress;
        for (; pTileData[0] != 0; pTileData += 3) {
            if ((pTileData[0] & uVar3) != 0) {
                SetTile(pTileData[2], pTileData[1], 1);
            }
        }
    }
}

u32 sub_unk3_HyruleTownMinishCaves_Entrance(void) {
    return 1;
}

void sub_StateChange_HyruleTownMinishCaves_Entrance(void) {
}

u32 sub_unk3_HyruleTownMinishCaves_NorthRoom(void) {
    return 1;
}

void sub_StateChange_HyruleTownMinishCaves_NorthRoom(void) {
}

u32 sub_unk3_HyruleTownMinishCaves_PacciJump(void) {
    return 1;
}

void sub_StateChange_HyruleTownMinishCaves_PacciJump(void) {
}

u32 sub_unk3_HyruleTownMinishCaves_MulldozerFight(void) {
    return 1;
}

void sub_StateChange_HyruleTownMinishCaves_MulldozerFight(void) {
}

u32 sub_unk3_HyruleTownMinishCaves_WestChest(void) {
    return 1;
}

void sub_StateChange_HyruleTownMinishCaves_WestChest(void) {
}

u32 sub_unk3_HyruleTownMinishCaves_Flippers(void) {
    return 1;
}

void sub_StateChange_HyruleTownMinishCaves_Flippers(void) {
}

u32 sub_unk3_HyruleTownMinishCaves_Librari(void) {
    return 1;
}

void sub_StateChange_HyruleTownMinishCaves_Librari(void) {
}

u32 sub_unk3_HyruleTownMinishCaves_WestFrozenChest(void) {
    return 1;
}

void sub_StateChange_HyruleTownMinishCaves_WestFrozenChest(void) {
}

u32 sub_unk3_HyruleTownMinishCaves_CrossIntersection(void) {
    return 1;
}

void sub_StateChange_HyruleTownMinishCaves_CrossIntersection(void) {
}

u32 sub_unk3_HyruleTownMinishCaves_SoutheastCorner(void) {
    return 1;
}

void sub_StateChange_HyruleTownMinishCaves_SoutheastCorner(void) {
}

u32 sub_unk3_HyruleTownMinishCaves_Entrance2(void) {
    return 1;
}

void sub_StateChange_HyruleTownMinishCaves_Entrance2(void) {
}

u32 sub_unk3_HyruleTownUnderground_Main(void) {
    return 1;
}

void sub_StateChange_HyruleTownUnderground_Main(void) {
}

u32 sub_unk3_HyruleTownUnderground_Well(void) {
    return 1;
}

void sub_StateChange_HyruleTownUnderground_Well(void) {
}

extern u32 gUnk_080F09A0;

u32 sub_unk3_CastleGarden_Main(void) {
    if (GetInventoryValue(ITEM_FOURSWORD)) {
        gRoomVars.field_0x6c[1] = &gUnk_080F09A0;
    }
    return 1;
}

extern EntityData gUnk_080F0650;
extern EntityData gUnk_080F0800;
extern EntityData gUnk_080F08F0;
extern EntityData gUnk_080F0850;
extern EntityData gUnk_080F0870;
extern EntityData gUnk_080F0890;
extern EntityData gUnk_080F0920;

void sub_StateChange_CastleGarden_Main(void) {
    if (!CheckGlobalFlag(TABIDACHI)) {
        LoadRoomEntityList(&gUnk_080F0650);
#ifdef EU
        gArea.queued_bgm = BGM_FESTIVAL_APPROACH;
#else
        gArea.queued_bgm = BGM_BEANSTALK;
        SetGlobalFlag(CASTLE_BGM);
    } else {
        if (CheckGlobalFlag(CASTLE_BGM)) {
#if defined(JP) || defined(DEMO_JP)
            gArea.queued_bgm = gArea.bgm;
#else
            gArea.queued_bgm = BGM_HYRULE_CASTLE_NOINTRO;
#endif
        }
#endif
    }
#if defined(JP) || defined(DEMO_JP) || defined(EU)
    if (!CheckLocalFlag(0x9b)) {
#else
    if (!CheckLocalFlag(0x9c)) {
#endif
        LoadRoomEntityList(&gUnk_080F0800);
        SetTileType(0x4072, 600, 1);
        SetTileType(0x4072, 0x298, 1);
        SetTileType(0x4072, 0x266, 1);
        SetTileType(0x4072, 0x2a6, 1);
    } else {
        if (!GetInventoryValue(ITEM_FOURSWORD)) {
            LoadRoomEntityList(&gUnk_080F08F0);
            SetTileType(0x4072, 0x9e, 1);
            SetTileType(0x4072, 0x9f, 1);
            SetTileType(0x4072, 0xa0, 1);
        }
        LoadRoomEntityList(&gUnk_080F0850);
        if (!GetInventoryValue(ITEM_WATER_ELEMENT)) {
            LoadRoomEntityList(&gUnk_080F0870);
        } else {
            LoadRoomEntityList(&gUnk_080F0890);
        }
        SetTileType(0x4072, 600, 1);
        SetTileType(0x4072, 0x298, 1);
#if defined(JP) || defined(DEMO_JP) || defined(EU)
        if (CheckLocalFlag(0x11)) {
#else
        if (CheckLocalFlag(0x10)) {
#endif
            LoadRoomEntityList(&gUnk_080F0920);
#if defined(JP) || defined(DEMO_JP) || defined(EU)
            ClearLocalFlag(0x11);
#else
            ClearLocalFlag(0x10);
#endif
        }
    }
    sub_080AF284();
}

u32 sub_unk3_SimonsSimulation_Main(void) {
    ClearLocalFlag(1);
    return 1;
}

extern u8* gUnk_080F0D58[4];
extern Entity* gUnk_080F0CB8[15];
extern u8* gUnk_080F0E08[];
extern struct {
    u32 unk_00;
    u32 unk_04;
} gUnk_080F0E1C[];

void sub_StateChange_SimonsSimulation_Main(void) {
    u32 r;
    u32 index;
    u32 tmp;
    tmp = CheckGlobalFlag(LV4_CLEAR);
    index = BOOLCAST(tmp);
    if (CheckGlobalFlag(LV5_CLEAR)) {
        index = 2;
    }
    if (CheckGlobalFlag(GAMECLEAR)) {
        index = 3;
    }
    r = Random();
    index = gUnk_080F0D58[index][r & 0x1f];
    LoadRoomEntityList((EntityData*)gUnk_080F0CB8[index & 0xF]);
    index >>= 4;
    r >>= 8;
    index = gUnk_080F0E08[index][r & 0x1F];
    if (!CheckLocalFlag(0xC6)) {
        SetLocalFlag(0xC6);
        index = 0xE;
    }
    sub_0804B3C4(&gUnk_080F0E1C[index]);
    SoundReq(SONG_STOP_BGM);
}

u32 sub_unk3_HouseInteriors2_Stranger(void) {
    return 1;
}

extern EntityData gUnk_080F1C68;
extern EntityData gUnk_080F1C88;

void sub_StateChange_HouseInteriors2_Stranger(void) {
    if (!CheckGlobalFlag(POWERGLOVE_HINT)) {
        LoadRoomEntityList(&gUnk_080F1C68);
    } else {
        LoadRoomEntityList(&gUnk_080F1C88);
    }
}

u32 sub_unk3_HouseInteriors2_WestOracle(void) {
    return 1;
}

extern EntityData gUnk_080F1D90;
extern EntityData gUnk_080F1DB0;
extern EntityData gUnk_080F1DD0;

void sub_StateChange_HouseInteriors2_WestOracle(void) {
    if (CheckGlobalFlag(NEW_HOUSE_DIN)) {
        LoadRoomEntityList(&gUnk_080F1D90);
    } else if (CheckGlobalFlag(NEW_HOUSE_NAYRU)) {
        LoadRoomEntityList(&gUnk_080F1DB0);
    } else if (CheckGlobalFlag(NEW_HOUSE_FARORE)) {
        LoadRoomEntityList(&gUnk_080F1DD0);
    }
}

u32 sub_unk3_HouseInteriors2_2(void) {
    return 1;
}

void sub_StateChange_Ruins_Beanstalk5(void) {
}

u32 sub_unk3_HouseInteriors2_3(void) {
    return 1;
}

void sub_StateChange_Ruins_Beanstalk6(void) {
}

u32 sub_unk3_HouseInteriors2_DrLeft(void) {
    return 1;
}

extern EntityData gUnk_080F2174;
extern EntityData gUnk_080F2194;
extern EntityData gUnk_080F21B4;

void sub_StateChange_HouseInteriors2_DrLeft(void) {
    LoadRoomEntityList(&gUnk_080F2174);
    if (!GetInventoryValue(ITEM_QST_BOOK2) && CheckGlobalFlag(MIZUKAKI_HARIFALL)) {
        LoadRoomEntityList(&gUnk_080F2194);
    }
    if (gRoomTransition.player_status.spawn_type == PL_SPAWN_MINISH) {
        LoadRoomEntityList(&gUnk_080F21B4);
    }
}

u32 sub_unk3_HouseInteriors2_Romio(void) {
    return 1;
}

extern EntityData gUnk_080F23BC;
extern EntityData gUnk_080F238C;
extern EntityData gUnk_additional_c_HouseInteriors2_Romio;

void sub_StateChange_HouseInteriors2_Romio(void) {
    if (gSave.global_progress > 7) {
        LoadRoomEntityList(&gUnk_080F23BC);
    }
    if (!GetInventoryValue(ITEM_FLIPPERS) && CheckGlobalFlag(MIZUKAKI_START)) {
        LoadRoomEntityList(&gUnk_080F238C);
    } else {
        LoadRoomEntityList(&gUnk_additional_c_HouseInteriors2_Romio);
    }
}

u32 sub_unk3_HouseInteriors2_Julietta(void) {
    return 1;
}

extern EntityData gUnk_080F2570;
extern EntityData gUnk_080F2590;
extern EntityData gUnk_080F25C0;
extern EntityData gUnk_080F2600;

void sub_StateChange_HouseInteriors2_Julietta(void) {
    switch (gSave.global_progress) {
        case 0:
        case 2:
        case 4:
            LoadRoomEntityList(&gUnk_080F2570);
            break;
        case 1:
        case 3:
            break;
        case 5:
            if (!GetInventoryValue(ITEM_FLIPPERS)) {
                if (!CheckGlobalFlag(MIZUKAKI_START)) {
                    LoadRoomEntityList(&gUnk_080F2570);
                    break;
                }
                if (!GetInventoryValue(0x39)) {
                    LoadRoomEntityList(&gUnk_080F25C0);
                }
            } else {
                LoadRoomEntityList(&gUnk_080F2590);
            }
            break;
        case 8:
        case 9:
            LoadRoomEntityList(&gUnk_080F2600);
        case 6:
        case 7:
            LoadRoomEntityList(&gUnk_080F2590);
    }
}

u32 sub_unk3_HouseInteriors2_Percy(void) {
    return 1;
}

extern EntityData gUnk_additional_9_HouseInteriors2_Percy;
extern EntityData gUnk_080F2860;
extern EntityData gUnk_additional_a_HouseInteriors2_Percy;
extern EntityData gUnk_080F27D8;
extern EntityData gUnk_080F2798;

void sub_StateChange_HouseInteriors2_Percy(void) {
    if (CheckKinstoneFused(0x21)) {
        if (!CheckLocalFlag(0x42)) {
            if (!CheckLocalFlag(0x43)) {
                LoadRoomEntityList(&gUnk_additional_9_HouseInteriors2_Percy);
                LoadRoomTileEntities(&gUnk_080F2860);
            } else {
                LoadRoomEntityList(&gUnk_additional_a_HouseInteriors2_Percy);
            }
        } else if (!CheckLocalFlag(0x3f)) {
            LoadRoomEntityList(&gUnk_080F27D8);
        } else {
            LoadRoomEntityList(&gUnk_080F2798);
        }
    }
}

u32 sub_unk3_HouseInteriors2_EastOracle(void) {
    return 1;
}

extern EntityData gUnk_080F28D4;
extern EntityData gUnk_080F28F4;
extern EntityData gUnk_080F2914;

void sub_StateChange_HouseInteriors2_EastOracle(void) {
    if (CheckGlobalFlag(RENTED_HOUSE_DIN)) {
        LoadRoomEntityList(&gUnk_080F28D4);
    } else if (CheckGlobalFlag(RENTED_HOUSE_NAYRU)) {
        LoadRoomEntityList(&gUnk_080F28F4);
    } else if (CheckGlobalFlag(RENTED_HOUSE_FARORE)) {
        LoadRoomEntityList(&gUnk_080F2914);
    }
}

u32 sub_unk3_HouseInteriors2_A(void) {
    return 1;
}

void sub_StateChange_Ruins_Beanstalk7(void) {
}

u32 sub_unk3_HouseInteriors2_B(void) {
    return 1;
}

void sub_StateChange_Ruins_Beanstalk8(void) {
}

u32 sub_unk3_HouseInteriors2_Cucco(void) {
    return 1;
}

void sub_StateChange_Ruins_Beanstalk9(void) {
}

u32 sub_unk3_HouseInteriors2_LinksHouseEntrance(void) {
    return 1;
}

extern EntityData gUnk_080F2E2C;

void sub_StateChange_HouseInteriors2_LinksHouseEntrance(void) {
    if (!CheckGlobalFlag(OUTDOOR)) {
        gArea.bgm = gArea.queued_bgm;
        SoundReq(SONG_PLAY_VOL_RESET | BGM_MINISH_CAP);
    }
    if (!CheckGlobalFlag(START)) {
        LoadRoomEntityList(&gUnk_080F2E2C);
    }
}

u32 sub_unk3_HouseInteriors2_LinksHouseSmith(void) {
    return 1;
}

extern EntityData gUnk_080F2E94;
extern EntityData gUnk_080F2EC4;

void sub_StateChange_HouseInteriors2_LinksHouseSmith(void) {
    if (!CheckGlobalFlag(OUTDOOR)) {
        gArea.bgm = gArea.queued_bgm;
        SoundReq(SONG_PLAY_VOL_RESET | BGM_MINISH_CAP);
    }
    if (!CheckGlobalFlag(START)) {
        LoadRoomEntityList(&gUnk_080F2E94);
    } else {
        LoadRoomEntityList(&gUnk_080F2EC4);
    }
}

u32 sub_unk3_HouseInteriors2_Dampe(void) {
    return 1;
}

extern EntityData gUnk_080F2FD4;

void sub_StateChange_HouseInteriors2_Dampe(void) {
    if (!CheckLocalFlag(0x69) || GetInventoryValue(ITEM_QST_GRAVEYARD_KEY) > 1) {
        LoadRoomEntityList(&gUnk_080F2FD4);
    }
}

u32 sub_unk3_HouseInteriors2_Stockwell(void) {
    return 1;
}

extern EntityData gUnk_080F30CC;

void sub_StateChange_HouseInteriors2_Stockwell(void) {
    if ((GetInventoryValue(ITEM_QST_DOGFOOD) == 1) && !CheckGlobalFlag(BIN_DOGFOOD) &&
        (gPlayerState.flags & PL_MINISH) == 0) {
        LoadRoomEntityList(&gUnk_080F30CC);
    }
}

u32 sub_unk3_HouseInteriors2_LinksHouseBedroom(void) {
    return 1;
}

extern EntityData gUnk_080F31D8;
extern u32 script_PlayerIntro;

void sub_StateChange_HouseInteriors2_LinksHouseBedroom(void) {
    if (!CheckGlobalFlag(START) && !CheckLocalFlag(0x46)) {
        sub_080A71C4(5, 1, 4, 4);
        gUpdateVisibleTiles = 0;
        SetFade(5, 256);
        sub_080751E8(0, 6, &script_PlayerIntro);
    }
    if (!CheckGlobalFlag(OUTDOOR)) {
        gArea.bgm = gArea.queued_bgm;
        SoundReq(SONG_PLAY_VOL_RESET | BGM_MINISH_CAP);
    }
    if ((gPlayerState.flags & PL_NO_CAP) == 0) {
        LoadRoomEntityList(&gUnk_080F31D8);
    }
}

extern u32 script_PlayerWakeAfterRest;

void sub_0804E864(void) {
    gPlayerEntity.x.HALF.HI = gRoomControls.origin_x + 0x90;
    gPlayerEntity.y.HALF.HI = gRoomControls.origin_y + 0x38;
    sub_080751E8(1, 6, &script_PlayerWakeAfterRest);
    ModHealth(0xa0);
}

u32 sub_unk3_HouseInteriors4_Carpenter(void) {
    return 1;
}

extern EntityData gUnk_080F3260;

void sub_StateChange_HouseInteriors4_Carpenter(void) {
    if (GetInventoryValue(ITEM_PACCI_CANE)) {
        LoadRoomEntityList(&gUnk_080F3260);
        SetTileType(0x4072, 0x202, 1);
        SetTileType(0x4072, 0x242, 1);
        SetTileType(0x4072, 0x204, 1);
        SetTileType(0x4072, 0x244, 1);
    }
}

u32 sub_unk3_HouseInteriors4_Swiftblade(void) {
    return 1;
}

void sub_StateChange_HouseInteriors4_Swiftblade(void) {
    sub_08054564();
}

u32 sub_unk3_HouseInteriors4_RanchHouseWest(void) {
    return 1;
}

extern EntityData gUnk_080F36FC;
extern EntityData gUnk_080F3604;

void sub_StateChange_HouseInteriors4_RanchHouseWest(void) {
    if (!CheckGlobalFlag(INLOCK)) {
        LoadRoomEntityList(&gUnk_080F36FC);
    } else if (gSave.global_progress < 4) {
        LoadRoomEntityList(&gUnk_080F3604);
    }
}

u32 sub_unk3_HouseInteriors4_RanchHouseEast(void) {
    return 1;
}

extern EntityData gUnk_080F37D0;

void sub_StateChange_HouseInteriors4_RanchHouseEast(void) {
    if (CheckGlobalFlag(INLOCK)) {
        LoadRoomEntityList(&gUnk_080F37D0);
    }
}

u32 sub_unk3_HouseInteriors4_FarmHouse(void) {
    return 1;
}

void sub_StateChange_Ruins_LadderToTektites0(void) {
}

u32 sub_unk3_HouseInteriors4_Mayor(void) {
    return 1;
}

extern EntityData gUnk_080F3A48;

void sub_StateChange_HouseInteriors4_Mayor(void) {
    if (!GetInventoryValue(ITEM_FLIPPERS) && CheckGlobalFlag(MIZUKAKI_START) && !GetInventoryValue(ITEM_QST_BOOK3)) {
        LoadRoomEntityList(&gUnk_080F3A48);
    }
    gRoomTransition.player_status.overworld_map_x = 0xf28;
    gRoomTransition.player_status.overworld_map_y = 0x82d;
}

extern u32 Enemies_LakeHylia_Main;
extern u32 gUnk_080F3EA4;

u32 sub_unk3_LakeHylia_Main(void) {
    if (CheckGlobalFlag(LV4_CLEAR) && !CheckLocalFlag(4)) {
        gRoomVars.field_0x6c[2] = &gUnk_080F3EA4;
    } else {
        gRoomVars.field_0x6c[2] = &Enemies_LakeHylia_Main;
    }
    return 1;
}

extern EntityData gUnk_080F3C64;
extern EntityData gUnk_080F3C94;
extern EntityData gUnk_080F3C44;

void sub_StateChange_LakeHylia_Main(void) {
    if (CheckGlobalFlag(LV4_CLEAR) && !CheckLocalFlag(4)) {
        LoadRoomEntityList(&gUnk_080F3C64);
    }
    if (CheckKinstoneFused(0x12)) {
        LoadRoomEntityList(&gUnk_080F3C94);
    }
    if ((gSave.global_progress > 3) && CheckGlobalFlag(TINGLE_TALK1ST)) {
        LoadRoomEntityList(&gUnk_080F3C44);
    }
    SetTile(0x4091, 0x590, 1);
    SetTile(0x4091, 0x591, 1);
    SetTile(0x4091, 0x592, 1);
    SetTile(0x4091, 0x593, 1);
    SetTile(0x4091, 0x594, 1);
    SetTile(0x4091, 0x5d0, 1);
    SetTile(0x4091, 0x610, 1);
    SetTile(0x4091, 0x650, 1);
    SetTile(0x4091, 0x5d4, 1);
    SetTile(0x4091, 0x614, 1);
    SetTile(0x4091, 0x654, 1);
    SetTile(0x4091, 0x690, 1);
    SetTile(0x4091, 0x691, 1);
    SetTile(0x4091, 0x692, 1);
    SetTile(0x4091, 0x693, 1);
    SetTile(0x4091, 0x694, 1);
}

u32 sub_unk3_LakeHylia_Beanstalk(void) {
    return 1;
}

void sub_StateChange_Ruins_LadderToTektites1(void) {
}

u32 sub_unk3_LakeWoodsCave_Main(void) {
    return 1;
}

void sub_StateChange_Ruins_LadderToTektites2(void) {
}

u32 sub_unk3_HyliaDigCaves_Middle(void) {
    return 1;
}

void sub_StateChange_Ruins_LadderToTektites3(void) {
}

u32 sub_unk3_HyliaDigCaves_North(void) {
    return 1;
}

void sub_StateChange_Ruins_LadderToTektites4(void) {
}

u32 sub_unk3_CastorWildsDigCave_Main(void) {
    return 1;
}

void sub_StateChange_Ruins_LadderToTektites5(void) {
}

u32 sub_unk3_HyruleDigCaves_Main(void) {
    return 1;
}

void sub_StateChange_Ruins_LadderToTektites6(void) {
}

u32 sub_unk3_CrenelDigCave_Main(void) {
    return 1;
}

void sub_StateChange_Ruins_LadderToTektites7(void) {
}

u32 sub_unk3_DigCaves1_HyruleFieldFarm(void) {
    return 1;
}

void sub_StateChange_Ruins_LadderToTektites8(void) {
}

u32 sub_unk3_DigCaves1_TrilbyHighlands(void) {
    return 1;
}

void sub_StateChange_Ruins_LadderToTektites9(void) {
}

u32 sub_unk3_VeilFallsDigCave_Main(void) {
    return 1;
}

void sub_StateChange_VeilFallsDigCave_Main(void) {
}

u32 sub_unk3_OuterFortressOfWinds_EntranceHall(void) {
    gArea.areaMetadata |= 0x48;
    return 1;
}

void sub_StateChange_OuterFortressOfWinds_EntranceHall(void) {
}

u32 sub_unk3_OuterFortressOfWinds_2F(void) {
    gArea.areaMetadata |= 0x48;
    return 1;
}

void sub_StateChange_OuterFortressOfWinds_2F(void) {
}

u32 sub_unk3_OuterFortressOfWinds_3F(void) {
    gArea.areaMetadata |= 0x48;
    return 1;
}

void sub_StateChange_OuterFortressOfWinds_3F(void) {
}

u32 sub_unk3_OuterFortressOfWinds_MoleMitts(void) {
    sub_0801DD58(0x58, 5);
    gArea.areaMetadata |= 0x48;
    return 1;
}

void sub_StateChange_OuterFortressOfWinds_MoleMitts(void) {
}

u32 sub_unk3_OuterFortressOfWinds_SmallKey(void) {
    sub_0801DD58(0x58, 6);
    gArea.areaMetadata |= 0x48;
    return 1;
}

void sub_StateChange_OuterFortressOfWinds_SmallKey(void) {
}

extern u32 gUnk_080F4EB0;

u32 sub_unk3_MinishWoods_Main(void) {
    if (CheckGlobalFlag(ENDING)) {
        gRoomVars.field_0x6c[0] = &gUnk_080F4EB0;
        gRoomVars.field_0x6c[2] = NULL;
    }
    return 1;
}

extern EntityData gUnk_080F4D50;
extern EntityData gUnk_080F4DB0;
extern EntityData gUnk_080F4DD0;
extern EntityData gUnk_080F4DF0;
extern EntityData gUnk_080F4F10;
extern EntityData gUnk_080F4E10;

void sub_StateChange_MinishWoods_Main(void) {
    if (CheckGlobalFlag(ENDING)) {
        gArea.queued_bgm = gArea.bgm;
    }
    if (!CheckGlobalFlag(EZERO_1ST)) {
        LoadRoomEntityList(&gUnk_080F4D50);
    }
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (!CheckLocalFlag(0x3d)) {
        if (!CheckLocalFlag(0x3a)) {
#else
    if (!CheckLocalFlag(0x3e)) {
        if (!CheckLocalFlag(0x3b)) {
#endif
            LoadRoomEntityList(&gUnk_080F4DB0);
        } else {
            LoadRoomEntityList(&gUnk_080F4DD0);
        }
        LoadRoomEntityList(&gUnk_080F4DF0);
    }
    if (CheckKinstoneFused(0x4e)) {
        LoadRoomEntityList(&gUnk_080F4F10);
    }
    if ((s32)gSave.windcrests > -1) {
        LoadRoomEntityList(&gUnk_080F4E10);
    }
#ifdef DEMO_USA
    SetTileType(0x177, 0x5b4, 1);
    SetTileType(0x177, 0x5f4, 1);
#endif
}

void sub_unk1_MinishWoods_Main(void) {
    if ((s32)gSave.windcrests > -1) {
        LoadRoomEntityList(&gUnk_080F4E10);
    }
}

u32 sub_unk3_Empty_Main(void) {
    return 1;
}

void sub_StateChange_Empty_Main(void) {
}

extern u32 gUnk_080F5348;

u32 sub_unk3_SanctuaryEntrance_Main(void) {
    if (CheckGlobalFlag(ENDING)) {
        gRoomVars.field_0x6c[0] = &gUnk_080F5348;
        gRoomVars.field_0x6c[7] = sub_0804ED18;
        gRoomVars.field_0x6c[2] = NULL;
    }
    return 1;
}

extern EntityData gUnk_080F5328;
extern EntityData gUnk_080F5308;

void sub_StateChange_SanctuaryEntrance_Main(void) {
    if (GetInventoryValue(ITEM_GREEN_SWORD)) {
        LoadRoomEntityList(&gUnk_080F5328);
#if defined(JP) || defined(EU) || defined(DEMO_JP)
        if (!CheckLocalFlag(0x15)) {
#else
        if (!CheckLocalFlag(0x14)) {
#endif
            LoadRoomEntityList(&gUnk_080F5308);
        }
    }
}

static void sub_0804ED18(void) {
    gArea.queued_bgm = gArea.bgm;
}

u32 sub_unk3_Sanctuary_Hall(void) {
    return 1;
}

void sub_StateChange_Sanctuary_Hall(void) {
    sub_080AF2E4();
    if (CheckGlobalFlag(SEIIKI_BGM)) {
        gArea.queued_bgm = BGM_CASTLE_COLLAPSE;
    }
}

u32 sub_unk3_Sanctuary_Main(void) {
    return 1;
}

extern EntityData gUnk_080F54E8;
extern EntityData gUnk_080F5508;
extern EntityData gUnk_080F5558;
extern EntityData gUnk_080F5598;
extern EntityData gUnk_080F55D8;
extern EntityData gUnk_080F5528;
extern EntityData gUnk_080F5578;
extern EntityData gUnk_080F55B8;

void sub_StateChange_Sanctuary_Main(void) {
    if (!CheckLocalFlag(0x79)) {
        LoadRoomEntityList(&gUnk_080F54E8);
    }
    if (!CheckLocalFlag(0x7a)) {
        if (GetInventoryValue(ITEM_GREEN_SWORD) && !GetInventoryValue(ITEM_RED_SWORD) &&
            GetInventoryValue(ITEM_EARTH_ELEMENT) && GetInventoryValue(ITEM_FIRE_ELEMENT)) {
            LoadRoomEntityList(&gUnk_080F5508);
        }
    } else {
        if (!CheckLocalFlag(0x7b)) {
            if (GetInventoryValue(ITEM_RED_SWORD) && !GetInventoryValue(ITEM_BLUE_SWORD) &&
                GetInventoryValue(ITEM_WATER_ELEMENT)) {
                LoadRoomEntityList(&gUnk_080F5558);
            }
        } else {
            if (!CheckLocalFlag(0x7c)) {
                if (!GetInventoryValue(ITEM_FOURSWORD) && GetInventoryValue(ITEM_WIND_ELEMENT)) {
                    LoadRoomEntityList(&gUnk_080F5598);
                }
            } else {
                LoadRoomEntityList(&gUnk_080F55D8);
            }
        }
    }
    if (CheckLocalFlag(0x7a)) {
        LoadRoomEntityList(&gUnk_080F5528);
    }
    if (CheckLocalFlag(0x7b)) {
        LoadRoomEntityList(&gUnk_080F5578);
    }
    if (CheckLocalFlag(0x7c)) {
        LoadRoomEntityList(&gUnk_080F55B8);
    }
    if (CheckGlobalFlag(SEIIKI_BGM)) {
        gArea.queued_bgm = BGM_CASTLE_COLLAPSE;
    }
}

u32 sub_unk3_Sanctuary_StainedGlass(void) {
    return 1;
}

extern EntityData gUnk_080F5660;

void sub_StateChange_Sanctuary_StainedGlass(void) {
    if (!CheckLocalFlag(0x78) && CheckLocalFlag(0x7c)) {
        LoadRoomEntityList(&gUnk_080F5660);
    }
    if (CheckGlobalFlag(SEIIKI_BGM)) {
        gArea.queued_bgm = BGM_CASTLE_COLLAPSE;
    }
}

u32 sub_unk3_HouseInteriors3_StockwellShop(void) {
    return 1;
}

extern EntityData gUnk_080F5758;
extern EntityData gUnk_080F57E8;
extern EntityData gUnk_080F57A8;
extern EntityData gUnk_080F57C8;
extern EntityData gUnk_080F5888;
extern EntityData gUnk_080F58A8;
extern EntityData gUnk_080F5868;
extern EntityData gUnk_080F5828;
extern EntityData gUnk_080F5848;
extern EntityData gUnk_080F5788;

void sub_StateChange_HouseInteriors3_StockwellShop(void) {
    LoadRoomEntityList(&gUnk_080F5758);
    if (!GetInventoryValue(0x36) && CheckLocalFlagByBank(0x200, 0x8f)) {
        LoadRoomEntityList(&gUnk_080F57E8);
    }
    if (!CheckLocalFlag(0x55)) {
        LoadRoomEntityList(&gUnk_080F57A8);
    } else {
        if (gBombBagSizes[gSave.stats.bombBagType] >= 30) {
            LoadRoomEntityList(&gUnk_080F57C8);
        }
        if (!GetInventoryValue(ITEM_BOOMERANG) && !GetInventoryValue(ITEM_MAGIC_BOOMERANG)) {
            LoadRoomEntityList(&gUnk_080F5888);
#ifndef EU
        } else {
            if (!CheckLocalFlag(0xcd)) {
                LoadRoomEntityList(&gUnk_080F58A8);
            }
#endif
        }
    }
    if (GetInventoryValue(ITEM_BOW) || CheckGlobalFlag(LV3_CLEAR)) {
        LoadRoomEntityList(&gUnk_080F5868);
        if (!CheckLocalFlag(0x56)) {
            LoadRoomEntityList(&gUnk_080F5828);
        } else {
            LoadRoomEntityList(&gUnk_080F5848);
        }
    }
    if (gSave.stats.hasAllFigurines == 0) {
        LoadRoomEntityList(&gUnk_080F5788);
    }
}

u32 sub_unk3_HouseInteriors3_Cafe(void) {
    return 1;
}

void sub_StateChange_HouseInteriors3_Cafe(void) {
}

u32 sub_unk3_HouseInteriors3_RemShoeShop(void) {
    return 1;
}

extern EntityData gUnk_080F5B3C;

void sub_StateChange_HouseInteriors3_RemShoeShop(void) {
#ifndef EU
    if (GetInventoryValue(0x38) == 1) {
        LoadRoomEntityList(&gUnk_080F5B3C);
    }
#endif
}

u32 sub_unk3_HouseInteriors3_Bakery(void) {
    return 1;
}
void sub_StateChange_HouseInteriors3_Bakery(void) {
}

u32 sub_unk3_HouseInteriors3_Simon(void) {
    if (CheckGlobalFlag(MAROYA_WAKEUP)) {
        gRoomTransition.player_status.spawn_type = PL_SPAWN_SPECIAL;
    }
    return 1;
}

extern EntityData gUnk_080F5DD0;
extern u32 script_PlayerWakingUpAtSimons;

void sub_StateChange_HouseInteriors3_Simon(void) {
    if (gSave.global_progress > 7) {
        LoadRoomEntityList(&gUnk_080F5DD0);
    }
    if (CheckGlobalFlag(MAROYA_WAKEUP)) {
        sub_080751E8(1, 2, &script_PlayerWakingUpAtSimons);
    }
}

u32 sub_unk3_HouseInteriors3_FigurineHouse(void) {
    return 1;
}

extern EntityData gUnk_080F5E68;

void sub_StateChange_HouseInteriors3_FigurineHouse(void) {
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (!CheckLocalFlagByBank(0x100, 0xce)) {
#else
    if (!CheckLocalFlagByBank(0x100, 0xd1)) {
#endif
        LoadRoomEntityList(&gUnk_080F5E68);
    }
}

u32 sub_unk3_HouseInteriors3_BorlovEntrance(void) {
    return 1;
}

extern EntityData gUnk_additional_8_HouseInteriors3_BorlovEntrance;
extern EntityData gUnk_additional_9_HouseInteriors3_BorlovEntrance;
extern EntityData gUnk_additional_a_HouseInteriors3_BorlovEntrance;

void sub_StateChange_HouseInteriors3_BorlovEntrance(void) {
    if (gSave.global_progress > 4) {
        LoadRoomEntityList(&gUnk_additional_8_HouseInteriors3_BorlovEntrance);
    }
    if (!CheckLocalFlag(0x92)) {
        LoadRoomEntityList(&gUnk_additional_9_HouseInteriors3_BorlovEntrance);
    } else {
        LoadRoomEntityList(&gUnk_additional_a_HouseInteriors3_BorlovEntrance);
    }
}

u32 sub_unk3_HouseInteriors3_Carlov(void) {
    return 1;
}

void sub_StateChange_HouseInteriors3_Carlov(void) {
}

u32 sub_unk3_HouseInteriors3_Borlov(void) {
    return 1;
}

void sub_StateChange_HouseInteriors3_Borlov(void) {
}

u32 sub_unk3_WindTribeTower_Entrance(void) {
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (CheckGlobalFlag(KUMOTATSUMAKI) && CheckLocalFlagByBank(0x100, 0xd9)) {
#else
    if (CheckGlobalFlag(KUMOTATSUMAKI) && CheckLocalFlagByBank(0x100, 0xdc)) {
#endif
        SetGlobalFlag(WARP_EVENT_END);
    }
    return 1;
}

extern EntityData gUnk_080F61BC;

void sub_StateChange_WindTribeTower_Entrance(void) {
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (CheckLocalFlagByBank(0x100, 0xd9)) {
#else
    if (CheckLocalFlagByBank(0x100, 0xdc)) {
#endif
        SetLocalFlag(0x90);
    }
    if (CheckKinstoneFused(0xf)) {
        LoadRoomEntityList(&gUnk_080F61BC);
    }
    if (!CheckGlobalFlag(WARP_EVENT_END)) {
        SetTileType(0x4072, 0x4c7, 1);
        SetTileType(0x4072, 0x507, 1);
    }
    SetWorldMapPos(8, 0, 0x1e8, 0x158);
}

u32 sub_unk3_WindTribeTower_Floor2(void) {
    return 1;
}

extern EntityData gUnk_080F62E4;
extern EntityData gUnk_080F6324;

void sub_StateChange_WindTribeTower_Floor2(void) {
    if (!CheckGlobalFlag(WARP_EVENT_END)) {
        LoadRoomEntityList(&gUnk_080F62E4);
    } else {
        if (CheckLocalFlag(99)) {
            LoadRoomEntityList(&gUnk_080F6324);
        }
    }
}

u32 sub_unk3_WindTribeTower_Floor3(void) {
    return 1;
}

void sub_StateChange_WindTribeTower_Floor3(void) {
}

u32 sub_unk3_WindTribeTower_Floor4(void) {
    return 1;
}

extern EntityData gUnk_080F6564;
extern EntityData gUnk_080F6584;

void sub_StateChange_WindTribeTower_Floor4(void) {
    if (!CheckLocalFlag(0xb1)) {
        LoadRoomEntityList(&gUnk_080F6564);
    } else {
        LoadRoomEntityList(&gUnk_080F6584);
    }
}

u32 sub_unk3_WindTribeTowerRoof_Main(void) {
    return 1;
}

extern EntityData gUnk_080F66AC;

void sub_StateChange_WindTribeTowerRoof_Main(void) {
    sub_0805B4D0(5);
    if (CheckGlobalFlag(LV5_CLEAR) && !CheckLocalFlagByBank(0x100, 5)) {
        LoadRoomEntityList(&gUnk_080F66AC);
    }
    SetWorldMapPos(8, 0, 0x1e8, 0x158);
#ifndef EU
    gArea.areaMetadata |= 0x80;
#endif
}

u32 sub_unk3_Beanstalks_MountCrenel(void) {
    return 1;
}

void sub_StateChange_Beanstalks_MountCrenel(void) {
}

u32 sub_unk3_Beanstalks_LakeHylia(void) {
    return 1;
}

void sub_StateChange_Beanstalks_LakeHylia(void) {
}

u32 sub_unk3_Beanstalks_Ruins(void) {
    return 1;
}

void sub_StateChange_Beanstalks_Ruins(void) {
}

u32 sub_unk3_Beanstalks_EasternHills(void) {
    return 1;
}

void sub_StateChange_Beanstalks_EasternHills(void) {
}

u32 sub_unk3_Beanstalks_WesternWoods(void) {
    return 1;
}

void sub_StateChange_Beanstalks_WesternWoods(void) {
}

u32 sub_unk3_Beanstalks_MountCrenelClimb(void) {
    return 1;
}

void sub_StateChange_Beanstalks_MountCrenelClimb(void) {
}

u32 sub_unk3_Beanstalks_LakeHyliaClimb(void) {
    return 1;
}

void sub_StateChange_Beanstalks_LakeHyliaClimb(void) {
}

u32 sub_unk3_Beanstalks_RuinsClimb(void) {
    return 1;
}

void sub_StateChange_Beanstalks_RuinsClimb(void) {
}

u32 sub_unk3_Beanstalks_EasternHillsClimb(void) {
    return 1;
}

void sub_StateChange_Beanstalks_EasternHillsClimb(void) {
}

u32 sub_unk3_Beanstalks_WesternWoodsClimb(void) {
    return 1;
}

void sub_StateChange_Beanstalks_WesternWoodsClimb(void) {
}

u32 sub_unk3_HyruleField_WesternWoodSouth(void) {
    return 1;
}

void sub_StateChange_HyruleField_WesternWoodSouth(void) {
    Manager18_Main(0);
}

u32 sub_unk3_HyruleField_LinksHouseExterior(void) {
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (!CheckLocalFlag(0x6b)) {
#else
    if (!CheckLocalFlag(0x6d)) {
#endif
        SetFade(7, 256);
    }
    SetGlobalFlag(OUTDOOR);
    return 1;
}

extern EntityData gUnk_080F70A8;
extern EntityData gUnk_080F70D8;
extern EntityData gUnk_080F7088;

void sub_StateChange_HyruleField_LinksHouseExterior(void) {
    Manager18_Main(NULL);
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (!CheckLocalFlag(0x6b)) {
#else
    if (!CheckLocalFlag(0x6d)) {
#endif
        LoadRoomEntityList(&gUnk_080F70A8);
        ClearGlobalFlag(ZELDA_CHASE);
    }
    if (!CheckGlobalFlag(TABIDACHI)) {
        gArea.queued_bgm = BGM_FESTIVAL_APPROACH;
    }
    if ((gSave.windcrests & 0x40000000) == 0) {
        LoadRoomEntityList(&gUnk_080F70D8);
    }
    if (gSave.global_progress > 3) {
        LoadRoomEntityList(&gUnk_080F7088);
    }
}

void sub_unk1_HyruleField_LinksHouseExterior(void) {
    if ((gSave.windcrests & 0x40000000) == 0) {
        LoadRoomEntityList(&gUnk_080F70D8);
    }
}

u32 sub_unk3_HyruleField_FromMinishWoods(void) {
    return 1;
}

void sub_StateChange_HyruleField_FromMinishWoods(void) {
    Manager18_Main(NULL);
}

u32 sub_unk3_HyruleField_FromMinishWoodsNorth(void) {
    return 1;
}

void sub_StateChange_HyruleField_FromMinishWoodsNorth(void) {
    Manager18_Main(NULL);
}

extern u32 gUnk_080F7680;

u32 sub_unk3_HyruleField_Farmers(void) {
    if (GetInventoryValue(ITEM_GUST_JAR) && !GetInventoryValue(ITEM_PACCI_CANE)) {
        gRoomVars.field_0x6c[2] = &gUnk_080F7680;
    }
    return 1;
}

extern EntityData gUnk_080F7500;
extern EntityData gUnk_080F7550;

void sub_StateChange_HyruleField_Farmers(void) {
    Manager18_Main(NULL);
    if (gSave.global_progress > 3) {
        LoadRoomEntityList(&gUnk_080F7500);
    }
    if (GetInventoryValue(ITEM_GUST_JAR) && !GetInventoryValue(ITEM_PACCI_CANE)) {
        LoadRoomEntityList(&gUnk_080F7550);
        SetTileType(0x4072, 0x311, 1);
        SetTileType(0x4072, 0x351, 1);
        SetTileType(0x4072, 0x3d9, 1);
        SetTileType(0x4072, 0x419, 1);
    }
}

u32 sub_unk3_HyruleField_LonLonRanch(void) {
    return 1;
}

extern EntityData gUnk_080F77F0;
extern EntityData gUnk_080F77C0;
extern EntityData gUnk_080F7810;
extern EntityData gUnk_080F7860;
extern EntityData gUnk_080F78A0;

void sub_StateChange_HyruleField_LonLonRanch(void) {

    Manager18_Main(0);
    if (CheckLocalFlagByBank(0x200, 0x8f)) {
        if (!CheckGlobalFlag(INLOCK)) {
            LoadRoomEntityList(&gUnk_080F77C0);
        }
    } else if (GetInventoryValue(ITEM_EARTH_ELEMENT)) {
        LoadRoomEntityList(&gUnk_080F77F0);
    }
    if (CheckGlobalFlag(TABIDACHI) && !GetInventoryValue(ITEM_EARTH_ELEMENT)) {
        LoadRoomEntityList(&gUnk_080F7810);
    }
    if (!CheckKinstoneFused(0x29)) {
        LoadRoomEntityList(&gUnk_080F7860);
        SetTile(0x4072, 0xd88, 1);
        SetTile(0x4096, 0xdc8, 1);
    }
    if ((gSave.global_progress > 3) && CheckGlobalFlag(TINGLE_TALK1ST)) {
        LoadRoomEntityList(&gUnk_080F78A0);
    }
}

extern u32 gUnk_080F7CD0;
extern void sub_0804F5E8(void);
extern u32 gUnk_080F7C80;
extern void sub_0804F4E4(void);

u32 sub_unk3_HyruleField_OutsideCastle(void) {
    if (CheckGlobalFlag(TABIDACHI) && !GetInventoryValue(0x11)) {
        gRoomVars.field_0x6c[0] = &gUnk_080F7CD0;
        gRoomVars.field_0x6c[7] = sub_0804F5E8;
    }
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (CheckGlobalFlag(LV2_CLEAR) && GetInventoryValue(0x3) && !CheckLocalFlag(0x8a)) {
#else
    if (CheckGlobalFlag(LV2_CLEAR) && GetInventoryValue(0x3) && !CheckLocalFlag(0x8c)) {
#endif
        gRoomVars.field_0x6c[0] = &gUnk_080F7C80;
        gRoomVars.field_0x6c[7] = sub_0804F4E4;
        gRoomVars.field_0x6c[2] = NULL;
    }
#ifndef EU
    if (CheckGlobalFlag(TABIDACHI)) {
        ClearGlobalFlag(CASTLE_BGM);
    }
#endif
    return 1;
}

void sub_0804F4E4(void) {
    Manager18_Main(NULL);
    sub_0804F578();
}

extern EntityData gUnk_080F7D70;

void sub_StateChange_HyruleField_OutsideCastle(void) {
    sub_0804F4E4();
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (!CheckLocalFlag(0x89)) {
#else
    if (!CheckLocalFlag(0x8b)) {
#endif
        LoadRoomEntityList(&gUnk_080F7D70);
        SetTileType(0x174, 0x7a2, 1);
        SetTileType(0x174, 0x7a3, 1);
        SetTileType(0x174, 0x7a5, 1);
        SetTileType(0x174, 0x7a6, 1);
        SetTileType(0x174, 0x7a7, 1);
    }
    if (!CheckGlobalFlag(TABIDACHI)) {
#ifdef EU
        gArea.queued_bgm = 0x10;
#else
        gArea.queued_bgm = 0x13;
#endif
    }
}

extern EntityData gUnk_080F7DC0;

static void sub_0804F578(void) {
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (!CheckLocalFlag(0x8c)) {
#else
    if (!CheckLocalFlag(0x8e)) {
#endif
        LoadRoomEntityList(&gUnk_080F7DC0);
    } else {
        SetTileType(0x37, 0x94a, 1);
        SetTileType(0x37, 0x94b, 1);
        SetTileType(0x37, 0x94c, 1);
        SetTileType(0x37, 0x98a, 1);
        SetTileType(0x37, 0x98b, 1);
        SetTileType(0x37, 0x98c, 1);
    }
}

void sub_0804F5E8(void) {
    sub_0804F4E4();
    SetTileType(0x1d3, 0xbde, 1);
    SetTileType(0x1d6, 0xbe2, 1);
    SetTileType(0x1d4, 0xc1f, 1);
    SetTileType(0x1d5, 0xc20, 1);
    SetTileType(0x1d6, 0xc5e, 1);
    SetTileType(0x4072, 0xb9b, 1);
    SetTileType(0x4072, 0xbdb, 1);
    SetTileType(0x4072, 0xaa4, 1);
    SetTileType(0x4072, 0xae4, 1);
}

void sub_0804F680(Entity* parent, s32 x, s32 y) {
    Entity* fx;

    fx = CreateFx(parent, FX_DEATH, 0);
    if (fx != NULL) {
        fx->x.HALF.HI = gRoomControls.origin_x + x;
        fx->y.HALF.HI = gRoomControls.origin_y + y;
    }
}

void sub_0804F6A8(Entity* this) {
    sub_0804F680(this, 0x1d8, 0x108);
    sub_0804F680(this, 0x218, 0x188);
}

void sub_0804F6C8(Entity* this) {
    sub_0804F680(this, 0x1e8, 0x108);
    sub_0804F680(this, 0x208, 0x188);
}

void sub_0804F6E8(Entity* this) {
    sub_0804F680(this, 0x1f8, 0x108);
    sub_0804F680(this, 0x258, 0x138);
    sub_0804F680(this, 0x1f8, 0x188);
    sub_0804F680(this, 0x198, 0x158);
}

void sub_0804F724(Entity* this) {
    sub_0804F680(this, 0x208, 0x108);
    sub_0804F680(this, 0x258, 0x148);
    sub_0804F680(this, 0x1e8, 0x188);
    sub_0804F680(this, 0x198, 0x148);
}

void sub_0804F760(Entity* this) {
    sub_0804F680(this, 0x218, 0x108);
    sub_0804F680(this, 0x258, 0x158);
    sub_0804F680(this, 0x1d8, 0x188);
    sub_0804F680(this, 0x198, 0x138);
}

void sub_0804F79C(Entity* parent) {
    Entity* fx;

    fx = CreateFx(parent, FX_BIG_EXPLOSION, 0);
    if (fx != NULL) {
        fx->spriteRendering.b3 = 0;
        fx->x.HALF.HI = gRoomControls.origin_x + Q_8_8(1.72);
        fx->y.HALF.HI = gRoomControls.origin_y + Q_8_8(1.285);
    }
    fx = CreateFx(parent, FX_BIG_EXPLOSION, 0);
    if (fx != NULL) {
        fx->spriteRendering.b3 = 0;
        fx->x.HALF.HI = gRoomControls.origin_x + Q_8_8(2.22);
        fx->y.HALF.HI = gRoomControls.origin_y + Q_8_8(1.285);
    }
}

void sub_0804F808(void) {
    SetTileType(0x1d3, 0x41d, 1);
    SetTileType(0x1d3, 0x621, 1);
}

void sub_0804F830(void) {
    SetTileType(0x1d4, 0x41e, 1);
    SetTileType(0x1d4, 0x620, 1);
}

void sub_0804F854(void) {
    SetTileType(0x1d5, 0x41f, 1);
    SetTileType(0x1d4, 0x4e5, 1);
    SetTileType(0x1d5, 0x61f, 1);
    SetTileType(0x1d4, 0x559, 1);
}

void sub_0804F89C(void) {
    SetTileType(0x1d6, 0x420, 1);
    SetTileType(0x1d5, 0x525, 1);
    SetTileType(0x1d6, 0x61e, 1);
    SetTileType(0x1d5, 0x519, 1);
}

void sub_0804F8E0(void) {
    SetTileType(0x1d3, 0x421, 1);
    SetTileType(0x1d6, 0x565, 1);
    SetTileType(0x1d3, 0x61d, 1);
    SetTileType(0x1d6, 0x4d9, 1);
}

void sub_0804F928(void) {
    sub_0807BA8C(0x41d, 1);
    sub_0807BA8C(0x621, 1);
}

void sub_0804F944(void) {
    sub_0807BA8C(0x41e, 1);
    sub_0807BA8C(0x620, 1);
}

void sub_0804F960(void) {
    sub_0807BA8C(0x41f, 1);
    sub_0807BA8C(0x4e5, 1);
    sub_0807BA8C(0x61f, 1);
    sub_0807BA8C(0x559, 1);
}

void sub_0804F994(void) {
    sub_0807BA8C(0x420, 1);
    sub_0807BA8C(0x525, 1);
    sub_0807BA8C(0x61e, 1);
    sub_0807BA8C(0x519, 1);
}

void sub_0804F9C8(void) {
    sub_0807BA8C(0x421, 1);
    sub_0807BA8C(0x565, 1);
    sub_0807BA8C(0x61d, 1);
    sub_0807BA8C(0x4d9, 1);
}

u32 sub_unk3_HyruleField_OutsideCastleWest(void) {
    return 1;
}

extern EntityData gUnk_080F806C;

void sub_StateChange_HyruleField_OutsideCastleWest(void) {
    Manager18_Main(NULL);
    if ((gSave.global_progress > 3) && CheckGlobalFlag(TINGLE_TALK1ST)) {
        LoadRoomEntityList(&gUnk_080F806C);
    }
}

u32 sub_unk3_HyruleField_TrilbyHighlands(void) {
    return 1;
}

extern EntityData gUnk_080F82E0;

void sub_StateChange_HyruleField_TrilbyHighlands(void) {
    Manager18_Main(NULL);
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    if (CheckGlobalFlag(LV2_CLEAR) && GetInventoryValue(ITEM_RED_SWORD) && !CheckLocalFlag(0x9b)) {
#else
    if (CheckGlobalFlag(LV2_CLEAR) && GetInventoryValue(ITEM_RED_SWORD) && !CheckLocalFlag(0x9c)) {
#endif
        LoadRoomEntityList(&gUnk_080F82E0);
    }
}

u32 sub_unk3_HyruleField_PercysHouse(void) {
    return 1;
}

extern EntityData gUnk_080F8430;

void sub_StateChange_HyruleField_PercysHouse(void) {
    Manager18_Main(NULL);
    if (CheckKinstoneFused(0x21) && !CheckLocalFlagByBank(0x200, 0x42)) {
        LoadRoomEntityList(&gUnk_080F8430);
    }
}

u32 sub_unk3_Caves_Boomerang(void) {
    return 1;
}

extern EntityData gUnk_080F85F8;
extern EntityData gUnk_080F85D8;

void sub_StateChange_Caves_Boomerang(void) {
    if (CheckGlobalFlag(SOUGEN_06_HASHIGO)) {
        LoadRoomEntityList(&gUnk_080F85D8);
    } else {
        LoadRoomEntityList(&gUnk_080F85F8);
    }
    if (!GetInventoryValue(0xc)) {
        ClearLocalFlag(8);
    }
}

u32 sub_unk3_Caves_ToGraveyard(void) {
    return 1;
}

void sub_StateChange_Caves_ToGraveyard(void) {
}

u32 sub_unk3_Caves_2(void) {
    return 1;
}

void sub_StateChange_Caves_2(void) {
}

u32 sub_unk3_Caves_3(void) {
    return 1;
}

void sub_StateChange_Caves_3(void) {
}

u32 sub_unk3_Caves_4(void) {
    return 1;
}

void sub_StateChange_Caves_4(void) {
}

u32 sub_unk3_Caves_5(void) {
    return 1;
}

void sub_StateChange_Caves_5(void) {
}

u32 sub_unk3_Caves_6(void) {
    return 1;
}

void sub_StateChange_Caves_6(void) {
}

u32 sub_unk3_Caves_KeeseChest(void) {
    return 1;
}

void sub_StateChange_Caves_KeeseChest(void) {
}

u32 sub_unk3_Caves_FairyFountainTrilbyHighlands(void) {
    return 1;
}

void sub_StateChange_Caves_FairyFountainTrilbyHighlands(void) {
}

u32 sub_unk3_Caves_FairyFountainLinksHouse(void) {
    return 1;
}

void sub_StateChange_Caves_FairyFountainLinksHouse(void) {
}

u32 sub_unk3_Caves_A(void) {
    return 1;
}

void sub_StateChange_Caves_A(void) {
}

u32 sub_unk3_Caves_HyruleTownWaterfall(void) {
    return 1;
}

void sub_StateChange_Caves_HyruleTownWaterfall(void) {
}

u32 sub_unk3_Caves_LonLonRanch(void) {
    return 1;
}

void sub_StateChange_Caves_LonLonRanch(void) {
}

u32 sub_unk3_Caves_LonLonRanchSecret(void) {
    return 1;
}

void sub_StateChange_Caves_LonLonRanchSecret(void) {
    if (CheckLocalFlag(0x11)) {
        SetRoomFlag(0);
        SetRoomFlag(1);
        ChangeLightLevel(0x100);
        if (!CheckLocalFlag(0x12)) {
            SetTileType(0x73, 0xcb, 1);
        }
    }
}

u32 sub_unk3_Caves_TrilbyHighlands(void) {
    return 1;
}

void sub_StateChange_Caves_TrilbyHighlands(void) {
}

u32 sub_unk3_Caves_LonLonRanchWallet(void) {
    return 1;
}

void sub_StateChange_Caves_LonLonRanchWallet(void) {
}

u32 sub_unk3_Caves_RupeeLinksHouse(void) {
    return 1;
}

void sub_StateChange_Caves_RupeeLinksHouse(void) {
}

u32 sub_unk3_Caves_RupeeTrilbyHighlands(void) {
    return 1;
}

void sub_StateChange_Caves_RupeeTrilbyHighlands(void) {
}

u32 sub_unk3_Caves_FairyFountainMoleMitts(void) {
    return 1;
}

void sub_StateChange_Caves_FairyFountainMoleMitts(void) {
}

u32 sub_unk3_Caves_KeeseChestSoutheastHyrule(void) {
    return 1;
}
void sub_StateChange_Caves_KeeseChestSoutheastHyrule(void) {
}

u32 sub_unk3_Caves_BottleBusinessScrub(void) {
    return 1;
}

void sub_StateChange_Caves_BottleBusinessScrub(void) {
}

u32 sub_unk3_Caves_HeartPieceHallway(void) {
    return 1;
}

void sub_StateChange_Caves_HeartPieceHallway(void) {
}

u32 sub_unk3_Caves_FairyFountainBoomerang(void) {
    return 1;
}

void sub_StateChange_Caves_FairyFountainBoomerang(void) {
}

u32 sub_unk3_Caves_KinstoneBusinessScrub(void) {
    return 1;
}

void sub_StateChange_Caves_KinstoneBusinessScrub(void) {
}

u32 sub_unk3_VeilFalls_Main(void) {
    return 1;
}

extern EntityData gUnk_080F9304;

void sub_StateChange_VeilFalls_Main(void) {
    if ((gSave.windcrests & 0x2000000) == 0) {
        LoadRoomEntityList(&gUnk_080F9304);
    }
}

void sub_unk1_VeilFalls_Main(void) {
    if ((gSave.windcrests & 0x2000000) == 0) {
        LoadRoomEntityList(&gUnk_080F9304);
    }
}

u32 sub_unk3_VeilFallsCaves_Hallway2F(void) {
    return 1;
}

void sub_StateChange_VeilFallsCaves_Hallway2F(void) {
}

u32 sub_unk3_VeilFallsCaves_Hallway1F(void) {
    return 1;
}

void sub_StateChange_VeilFallsCaves_Hallway1F(void) {
}

u32 sub_unk3_VeilFallsCaves_SecretRoom(void) {
    return 1;
}

void sub_StateChange_VeilFallsCaves_SecretRoom(void) {
}

u32 sub_unk3_VeilFallsCaves_Entrance(void) {
    return 1;
}

void sub_StateChange_VeilFallsCaves_Entrance(void) {
}

u32 sub_unk3_VeilFallsCaves_Exit(void) {
    return 1;
}

void sub_StateChange_VeilFallsCaves_Exit(void) {
}

u32 sub_unk3_VeilFallsCaves_SecretChest(void) {
    return 1;
}

void sub_StateChange_VeilFallsCaves_SecretChest(void) {
}

u32 sub_unk3_VeilFallsCaves_SecretStaircases(void) {
    return 1;
}

void sub_StateChange_VeilFallsCaves_SecretStaircases(void) {
}

u32 sub_unk3_VeilFallsCaves_BlockPuzzle(void) {
    return 1;
}

void sub_StateChange_VeilFallsCaves_BlockPuzzle(void) {
}

u32 sub_unk3_VeilFallsCaves_RupeePath(void) {
    return 1;
}

void sub_StateChange_VeilFallsCaves_RupeePath(void) {
}

u32 sub_unk3_VeilFallsCaves_HeartPiece(void) {
    return 1;
}

void sub_StateChange_VeilFallsCaves_HeartPiece(void) {
}

extern u32 gUnk_080F9BF8;

u32 sub_unk3_VeilFallsTop_Main(void) {
    if (!CheckKinstoneFused(0xe)) {
        gRoomVars.field_0x6c[0] = &gUnk_080F9BF8;
    }
    return 1;
}

void sub_StateChange_VeilFallsTop_Main(void) {
    sub_0805B4D0(2);
    sub_0806D0B0(0);
}

u32 sub_unk3_47_0(void) {
    return 1;
}

void sub_StateChange_47_0(void) {
}

u32 sub_unk3_47_1(void) {
    return 1;
}

void sub_StateChange_47_1(void) {
}

u32 sub_unk3_47_2(void) {
    return 1;
}

void sub_StateChange_47_2(void) {
}

u32 sub_unk3_47_3(void) {
    return 1;
}

void sub_StateChange_47_3(void) {
}

u32 sub_unk3_47_4(void) {
    return 1;
}

void sub_StateChange_47_4(void) {
}

u32 sub_unk3_TreeInteriors_WitchHut(void) {
    return 1;
}

extern EntityData gUnk_080F9FA8;
extern EntityData gUnk_080F9F88;

void sub_StateChange_TreeInteriors_WitchHut(void) {
    if (CheckKinstoneFused(0x14)) {
        LoadRoomEntityList(&gUnk_080F9FA8);
    }
    if (!GetInventoryValue(ITEM_QST_MUSHROOM)) {
        LoadRoomEntityList(&gUnk_080F9F88);
    }
}

u32 sub_0804FCD4(void) {
    return 1;
}

void nullsub_434(void) {
}

u32 sub_0804FCDC(void) {
    return 1;
}

void nullsub_435(void) {
}

u32 sub_0804FCE4(void) {
    return 1;
}

void nullsub_436(void) {
}

u32 sub_0804FCEC(void) {
    return 1;
}

void nullsub_437(void) {
}

u32 sub_0804FCF4(void) {
    return 1;
}

void nullsub_438(void) {
}

u32 sub_0804FCFC(void) {
    return 1;
}

void nullsub_439(void) {
}

u32 sub_0804FD04(void) {
    return 1;
}

void nullsub_440(void) {
}

u32 sub_0804FD0C(void) {
    return 1;
}

void nullsub_441(void) {
}

u32 sub_0804FD14(void) {
    return 1;
}

void nullsub_442(void) {
}

u32 sub_0804FD1C(void) {
    return 1;
}

void nullsub_443(void) {
}

u32 sub_0804FD24(void) {
    return 1;
}

void nullsub_444(void) {
}

u32 sub_0804FD2C(void) {
    return 1;
}

void nullsub_445(void) {
}

u32 sub_0804FD34(void) {
    return 1;
}

void nullsub_446(void) {
}

u32 sub_0804FD3C(void) {
    return 1;
}

void nullsub_447(void) {
}

u32 sub_0804FD44(void) {
    return 1;
}

void nullsub_448(void) {
}

u32 sub_unk3_TreeInteriors_StairsToCarlov(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_StairsToCarlov(void) {
}

u32 sub_unk3_TreeInteriors_PercysTreehouse(void) {
    return 1;
}

extern EntityData gUnk_080FA5D0;

void sub_StateChange_TreeInteriors_PercysTreehouse(void) {
    if (!CheckKinstoneFused(0x21)) {
        LoadRoomEntityList(&gUnk_080FA5D0);
    }
}

u32 sub_unk3_TreeInteriors_HeartPiece(void) {
    return 1;
}
void sub_StateChange_TreeInteriors_HeartPiece(void) {
}

u32 sub_unk3_TreeInteriors_StairsToBladeBrother(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_StairsToBladeBrother(void) {
}

u32 sub_unk3_TreeInteriors_14(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_14(void) {
}

u32 sub_unk3_TreeInteriors_BoomerangNorthwest(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_BoomerangNorthwest(void) {
}

u32 sub_unk3_TreeInteriors_BoomerangNortheast(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_BoomerangNortheast(void) {
}

u32 sub_unk3_TreeInteriors_BoomerangSouthwest(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_BoomerangSouthwest(void) {
}

u32 sub_unk3_TreeInteriors_BoomerangSoutheast(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_BoomerangSoutheast(void) {
}

u32 sub_unk3_TreeInteriors_HeartPieceSouthwestField(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_HeartPieceSouthwestField(void) {
}

u32 sub_unk3_TreeInteriors_StairsToFairyFountain(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_StairsToFairyFountain(void) {
}

u32 sub_unk3_TreeInteriors_StairsToWalletFairy(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_StairsToWalletFairy(void) {
}

u32 sub_unk3_TreeInteriors_1C(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_1C(void) {
}

u32 sub_unk3_TreeInteriors_StairsToBusinessScrub(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_StairsToBusinessScrub(void) {
}

u32 sub_unk3_TreeInteriors_1E(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_1E(void) {
}

u32 sub_unk3_TreeInteriors_1F(void) {
    return 1;
}

void sub_StateChange_TreeInteriors_1F(void) {
}

extern u32 gUnk_080FAD48;

u32 sub_unk3_MtCrenel_MountainTop(void) {
    if (CheckGlobalFlag(ENDING)) {
        gRoomVars.field_0x6c[0] = &gUnk_080FAD48;
        gRoomVars.field_0x6c[2] = NULL;
    }
    return 1;
}

extern EntityData gUnk_080FACB8;

void sub_StateChange_MtCrenel_MountainTop(void) {
    if (CheckGlobalFlag(ENDING)) {
        gArea.queued_bgm = gArea.bgm;
    } else {
        LoadRoomEntityList(&gUnk_080FACB8);
    }
    sub_0805B4D0(0);
    sub_08059994();
}

void sub_unk1_MtCrenel_MountainTop(void) {
    sub_0805B4D0(0);
}

u32 sub_unk3_MtCrenel_WallClimb(void) {
    return 1;
}

void sub_StateChange_MtCrenel_WallClimb(void) {
}

u32 sub_unk3_MtCrenel_CaveOfFlamesEntrance(void) {
    return 1;
}

extern EntityData gUnk_080FAFE4;
extern EntityData gUnk_080FB004;

void sub_StateChange_MtCrenel_CaveOfFlamesEntrance(void) {
    sub_0805B4D0(1);
    if (CheckGlobalFlag(LV2_CLEAR) && !CheckLocalFlag(LV1_CLEAR)) {
        LoadRoomEntityList(&gUnk_080FAFE4);
    }
    if ((gSave.windcrests & 0x1000000) == 0) {
        LoadRoomEntityList(&gUnk_080FB004);
    }
    if (GetInventoryValue(0x2)) {
        SetGlobalFlag(WHITE_SWORD_END);
    }
}

void sub_unk1_MtCrenel_CaveOfFlamesEntrance(void) {
    if ((gSave.windcrests & 0x1000000) == 0) {
        LoadRoomEntityList(&gUnk_080FB004);
    }
}

u32 sub_unk3_MtCrenel_GustJarShortcut(void) {
    return 1;
}

void sub_StateChange_MtCrenel_GustJarShortcut(void) {
}

u32 sub_unk3_MtCrenel_Entrance(void) {
    return 1;
}

void sub_StateChange_MtCrenel_Entrance(void) {
#if defined(USA) || defined(DEMO_USA) || defined(DEMO_JP)
    SetTileType(0x176, 0x66f, 1);
#endif
}

u32 sub_unk3_CrenelCaves_BlockPushing(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_BlockPushing(void) {
}

u32 sub_unk3_CrenelCaves_PillarCave(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_PillarCave(void) {
}

u32 sub_unk3_CrenelCaves_BridgeSwitch(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_BridgeSwitch(void) {
}

u32 sub_unk3_CrenelCaves_ExitToMines(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_ExitToMines(void) {
}

u32 sub_unk3_CrenelCaves_GripRing(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_GripRing(void) {
}

u32 sub_unk3_CrenelCaves_FairyFountain(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_FairyFountain(void) {
}

u32 sub_unk3_CrenelCaves_SpinyChuPuzzle(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_SpinyChuPuzzle(void) {
}

u32 sub_unk3_CrenelCaves_ChuchuPotChest(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_ChuchuPotChest(void) {
}

u32 sub_unk3_CrenelCaves_WaterHeartPiece(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_WaterHeartPiece(void) {
}

u32 sub_unk3_CrenelCaves_RupeeFairyFountain(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_RupeeFairyFountain(void) {
}

u32 sub_unk3_CrenelCaves_HelmasaurHallway(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_HelmasaurHallway(void) {
}

u32 sub_unk3_CrenelCaves_MushroomKeese(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_MushroomKeese(void) {
}

u32 sub_unk3_CrenelCaves_LadderToGreenWater(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_LadderToGreenWater(void) {
}

u32 sub_unk3_CrenelCaves_BombBusinessScrub(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_BombBusinessScrub(void) {
}

u32 sub_unk3_CrenelCaves_Hermit(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_Hermit(void) {
    if (!CheckLocalFlag(0x70)) {
        SetLocalFlag(0x70);
    }
}

u32 sub_unk3_CrenelCaves_HintScrub(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_HintScrub(void) {
}

u32 sub_unk3_CrenelCaves_ToGrayblade(void) {
    return 1;
}

void sub_StateChange_CrenelCaves_ToGrayblade(void) {
}
