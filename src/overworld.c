#include "global.h"
#include "audio.h"
#include "screen.h"
#include "entity.h"
#include "player.h"
#include "room.h"
#include "main.h"
#include "flags.h"
#include "save.h"
#include "utils.h"
#include "fileScreen.h"
#include "menu.h"
#include "functions.h"
#include "structures.h"
#include "area.h"
#include "textbox.h"
#include "overworld.h"

extern u32 gUnk_03003FC0;

extern u8 gUnk_080FCA84[];
extern u8 gUnk_080FCAC8[];
extern u32 gUsedPalettes;
extern u8 gUnk_02024090[];
extern u16 gUnk_080FCAD6[];

extern void** gAreaTilesets[];
extern void** gAreaRoomMaps[];
extern void* gAreaMetatiles[];
extern void* gUnk_080B755C[];
extern void** gExitLists[];
extern void** gAreaTable[];

extern u8 gUnk_080FCAF8[];
extern u16 gUnk_020178E0[];

void sub_080520C4();
void SetPopupState();
u32 sub_08052724();
void CleanUpGFXSlots();
void sub_080ADE24();
void sub_0801C370(u32);
void sub_0801AE44(u32);
void sub_0801862C(void);
void sub_08078160(u32);
void SetPlayerEventPriority(void);
RoomResInfo* GetCurrentRoomInfo(void);
void sub_08049D30(void);
void InitScriptData(void);
void sub_08054524(void);
void sub_080186D4(void);
void sub_0806F364(void);
void sub_08052FF4(u32 area, u32 room);
void sub_0807C860(void);
void sub_0807C740(void);
void sub_080197AC(void);
void sub_08053390(void);

static u32 StairsAreValid();
static void ClearFlagArray(const u16*);
static void DummyHandler(u32* a1);
static void sub_08053434(u32* a1);
static void sub_080534E4(u32* a1);
static void InitAllRoomResInfo(void);
static void InitRoomResInfo(RoomResInfo* info, RoomHeader* hdr, u32 area, u32 room);
static void sub_080532E4(void);
static void sub_08053460(void);

typedef struct {
    u16* dest;
    void* gfx_dest;
    void* buffer_loc;
    u32 _c;
    u16 gfx_src;
    u8 width;
    u8 right_align : 1;
    u8 sm_border : 1;
    u8 unused : 1;
    u8 draw_border : 1;
    u8 border_type : 4;
    u8 fill_type;
    u8 _15;
    u8 _16;
    u8 stylized;
} Font;

typedef struct {
    u8 dest_off[8];
    u8 _8;
    u8 right_align;
    u16 _a;
} PopupOption;

extern void CreateDialogBox();

void sub_0805212C(void) {
    if (gFadeControl.active)
        return;

    if (gMain.field_0x5 == 0) {
        if (gMenu.focusCoords[0] >= 38) {
            gMenu.focusCoords[0]--;
        } else {
            gMenu.transitionTimer--;
            if (gMenu.transitionTimer == 0) {
                sub_080520C4(2);
#if defined(DEMO_USA) || defined(DEMO_JP)
                SoundReq(SONG_VOL_FADE_OUT);
                DoFade(7, 4);
#else
                SetPopupState(0, 0);
                gScreen.lcd.displayControl |= DISPCNT_BG1_ON | DISPCNT_BG2_ON;
                gFadeControl.mask = 0x0000ffff;
                DoFade(4, 16);
#endif
            }
        }
    } else {
        gMain.field_0x5--;
    }
}

#if defined(DEMO_USA) || defined(DEMO_JP)
void sub_080521A0(void) {
    if (gFadeControl.active == 0) {
        DoSoftReset();
    }
}
#else
void sub_080521A0(void) {
    s32 temp3;
    u32 temp2;

    if (gFadeControl.active)
        return;

    switch (gMenu.menuType) {
        case 0:
            gMenu.transitionTimer = 30;
            gMenu.field_0x3 = 0;
            sub_080A7114(1);
            SetPopupState(0, 0);
            gFadeControl.mask = 0xffffffff;
            return;
        case 1:
            if (gMenu.transitionTimer == 0) {
                u32 temp = gMenu.field_0x3;
                switch (gInput.newKeys) {
                    case DPAD_UP:
                        temp = 0;
                        break;
                    case DPAD_DOWN:
                        temp = 1;
                        break;
                    case A_BUTTON:
                        if (gMenu.field_0x3 != 0) {
                            temp2 = 4;
                        } else {
                            CreateDialogBox(8, 0);
                            temp2 = 2;
                        }
                        gMenu.transitionTimer = 60;
                        sub_080A7114(temp2);
                        SoundReq(SFX_TEXTBOX_SELECT);
                        break;
                }
                if (gMenu.field_0x3 != temp) {
                    gMenu.field_0x3 = temp;
                    SetPopupState(0, temp);
                    SoundReq(SFX_TEXTBOX_CHOICE);
                }
                return;
            }
            gMenu.transitionTimer--;
            return;
        case 2:
            temp3 = HandleSave(0);
            gMenu.field_0x0 = temp3;
            switch (temp3) {
                case 1:
                    sub_080A7114(4);
                    break;
                case -1:
                    gMenu.transitionTimer = 60;
                    CreateDialogBox(9, 0);
                    sub_080A7114(3);
                    break;
            }
            return;
        case 3:
            if (gMenu.transitionTimer != 0) {
                gMenu.transitionTimer--;
            } else if (gInput.newKeys & (A_BUTTON | B_BUTTON | START_BUTTON)) {
                sub_080A7114(0);
            }
            return;
        case 4:
        default:
            gScreen.lcd.displayControl &= ~DISPCNT_BG1_ON;
            sub_08050384();
            sub_080520C4(3);
            return;
    }
}
#endif

void sub_080522F4(void) {
    switch (gMenu.menuType) {
        case 0x0:
            gMenu.transitionTimer = 0x1e;
            gMenu.field_0x3 = 0;
            sub_080A7114(1);
            SetPopupState(1, 0);
            return;
        case 0x1:
            gScreen.lcd.displayControl |= DISPCNT_BG1_ON;
            if (gMenu.transitionTimer != 0) {
                gMenu.transitionTimer--;
                return;
            } else {
                u32 temp = gMenu.field_0x3;
                switch (gInput.newKeys) {
                    case DPAD_UP:
                        temp = 0;
                        break;
                    case DPAD_DOWN:
                        temp = 1;
                        break;
                    case A_BUTTON:
                        sub_080A7114(2);
                        SoundReq(SFX_TEXTBOX_SELECT);
                        if (temp == 0) {
                            DoFade(5, 8);
                        } else {
                            DoFade(7, 8);
                        }
                        break;
                }
                if (gMenu.field_0x3 != temp) {
                    gMenu.field_0x3 = temp;
                    SetPopupState(1, temp);
                    SoundReq(SFX_TEXTBOX_CHOICE);
                }
            }
            return;
        case 0x2:
        default:
            if (gFadeControl.active == 0) {
                if (gMenu.field_0x3 == 0) {
                    InitScreen(2);
                } else {
                    DoSoftReset();
                }
            }
            return;
    }
}

void nullsub_107(void) {
}

void DrawGameOverText(void) {
    static const u8 sOffsets[] = {
        48, 68, 88, 108, 137, 156, 174, 192,
    };

    u32 i;

    gOamCmd._4 = 0;
    gOamCmd._6 = 0;
    gOamCmd._8 = 0x8600;
    gOamCmd.y = gMenu.focusCoords[0];
    for (i = 0; i < 8; ++i) {
        gOamCmd.x = sOffsets[i];
#ifdef EU
        sub_080ADA14(0x1fc, i);
#else
        sub_080ADA14(0x1fd, i);
#endif
    }
}

void SetPopupState(u32 type, u32 choice_idx) {
    static const Font sDefaultFont = {
        .dest = gBG1Buffer,
        .gfx_dest = (u16*)0x06006000,
        .buffer_loc = gTextGfxBuffer,
        ._c = 0,
        .gfx_src = 0xD300,
        .width = 0xE0,
        .right_align = 0,
        .sm_border = 0,
        .unused = 0,
        .draw_border = 0,
        .border_type = 0,
        .fill_type = 6,
        ._15 = 4,
        ._16 = 1,
        .stylized = 0,
    };
    static const PopupOption sPopupOptions[] = {
        { { 11, 11, 11, 10, 11, 10, 10, 0 }, 8, 0, 16 },
        { { 10, 11, 11, 9, 11, 9, 9, 0 }, 8, 0, 17 },
        { { 15, 15, 15, 15, 15, 15, 15, 0 }, 5, 1, 13 },
    };

    Font font;
    const PopupOption* opt;
    u32 fakematch;

    MemClear(gBG1Buffer, sizeof gBG1Buffer);
    gUnk_020227E8[0]._0.WORD = 0xf;
    gUnk_020227E8[1]._0.WORD = 0xf;
    gUnk_020227E8[2]._0.WORD = 0xf;
    gUnk_020227E8[3]._0.WORD = 0xf;
    *(&gUnk_020227E8[choice_idx]._0.BYTES.byte0 + 1) = fakematch = 1;

    MemCopy(&sDefaultFont, &font, sizeof font);
    opt = &sPopupOptions[type];
    font.dest = sDefaultFont.dest + (opt->dest_off[gSaveHeader->gameLanguage] + opt->_8 * 32);
    font.right_align = opt->right_align;
    sub_0805F46C(opt->_a, &font);
    gScreen.bg1.updated = fakematch;
}

void InitializePlayer(void) {
    static const u8 sPlayerSpawnStates[] = {
        [PL_SPAWN_DEFAULT] = PLAYER_INIT,
        [PL_SPAWN_MINISH] = PLAYER_MINISH,
        [PL_SPAWN_DROP] = PLAYER_INIT,
        [PL_SPAWN_WALKING] = PLAYER_ROOMTRANSITION,
        [PL_SPAWN_STEP_IN] = PLAYER_080720DC,
        [PL_SPAWN_SPECIAL] = PLAYER_08074C44,
        [PL_SPAWN_DROP_MINISH] = PLAYER_MINISH,
        [PL_SPAWN_STAIRS_ASCEND] = PLAYER_USEENTRANCE,
        [PL_SPAWN_STAIRS_DESCEND] = PLAYER_USEENTRANCE,
        [PL_SPAWN_9] = PLAYER_MINISH,
        [PL_SPAWN_PARACHUTE_FORWARD] = PLAYER_WARP,
        [PL_SPAWN_PARACHUTE_UP] = PLAYER_WARP,
        [PL_SPAWN_FAST_TRAVEL] = PLAYER_WARP,
    };

    Entity* pl;

    sub_080784C8();
    MemClear(&gUnk_03000B80, sizeof gUnk_03000B80);
    MemClear(&gPlayerState, sizeof gPlayerState);
    MemFill32(0xffffffff, &gPlayerState.hurtType, sizeof gPlayerState.hurtType);
    MemClear(&gPlayerEntity, sizeof gPlayerEntity);

    pl = &gPlayerEntity;

    gRoomControls.cameraTarget = pl;
    gPlayerState.playerAction = sPlayerSpawnStates[gScreenTransition.player_status.spawn_type];
    if (!CheckGlobalFlag(EZERO_1ST)) {
        gPlayerState.flags |= PL_NO_CAP;
    }
    switch (gScreenTransition.player_status.spawn_type) {
        case PL_SPAWN_DROP:
        case PL_SPAWN_DROP_MINISH:
            pl->z.HALF.HI = -0xc0;
            break;
        case PL_SPAWN_STEP_IN:
            gPlayerState.field_0x34[4] = 16;
            pl->direction = Direction8FromAnimationState(gScreenTransition.player_status.start_anim);
        case PL_SPAWN_WALKING:
            pl->speed = 224;
            break;
        case PL_SPAWN_STAIRS_ASCEND:
        case PL_SPAWN_STAIRS_DESCEND:
            gPlayerState.field_0x34[4] = 1;
            gPlayerState.field_0x34[5] = gScreenTransition.player_status.spawn_type;
            break;
        case PL_SPAWN_PARACHUTE_FORWARD:
            gPlayerState.field_0x34[4] = 1;
            break;
        case PL_SPAWN_PARACHUTE_UP:
            gPlayerState.field_0x34[4] = 3;
            break;
        case PL_SPAWN_FAST_TRAVEL:
            gPlayerState.field_0x34[4] = 4;
    }

    pl->kind = PLAYER;
    pl->flags |= ENT_COLLIDE | ENT_20;
    pl->spritePriority.b0 = 4;
    pl->health = gSave.stats.health;
    pl->x.HALF.HI = gScreenTransition.player_status.start_pos.HALF.x;
    pl->y.HALF.HI = gScreenTransition.player_status.start_pos.HALF.y;
    pl->animationState = gScreenTransition.player_status.start_anim;
    pl->collisionLayer = gScreenTransition.player_status.layer;
    UpdateSpriteForCollisionLayer(pl);
    AppendEntityToList(pl, 1);
    RegisterPlayerHitbox();
}

bool32 CheckIsOverworld(void) {
#ifdef EU
    return gArea.areaMetadata == 0x01;
#else
    return gArea.areaMetadata == 0x81;
#endif
}

bool32 sub_08052638(u32 r0) {
#if EU
    return gAreaMetadata[r0].flags == 0x01;
#else
    return gAreaMetadata[r0].flags == 0x81;
#endif
}

#ifndef EU
u32 sub_08052654(void) {
    return (gArea.areaMetadata >> 7) & 1;
}
#endif

u32 CheckIsDungeon(void) {
    return (gArea.areaMetadata >> 2) & 1;
}

u32 CheckIsInteriorWithEnemies(void) {
    return (gArea.areaMetadata >> 4) & 1;
}

u32 CheckIsInteriorNoEnemies(void) {
    return (gArea.areaMetadata >> 6) & 1;
}

u32 CheckHasMap(void) {
    return (gArea.areaMetadata >> 3) & 1;
}

s32 ModHealth(s32 deltaHealth) {
    s32 newHealth;

    newHealth = gStats.health + deltaHealth;
    if (newHealth < 0) {
        newHealth = 0;
    }
    if (gStats.maxHealth < newHealth) {
        newHealth = (u32)gStats.maxHealth;
    }
    gStats.health = newHealth;
    gPlayerEntity.health = newHealth;
    return newHealth;
}

void ModRupees(s32 rupeeDelta) {
    s32 newRupeeCount;
    Stats* s = &gStats;

    newRupeeCount = s->rupees + rupeeDelta;
    if (newRupeeCount < 0) {
        newRupeeCount = 0;
    } else {
        if (newRupeeCount > gWalletSizes[s->walletType * 2]) {
            newRupeeCount = gWalletSizes[s->walletType * 2];
        }
    }
    s->rupees = newRupeeCount;
}

void sub_080526F8(s32 a1) {
    if (sub_08052724()) {
        u8* p = &gSave.unk45C[gArea.dungeon_idx];
        if (*p + a1 < 0)
            *p = 0;
        else
            *p += a1;
    }
}

u32 sub_08052724(void) {
    return (gArea.areaMetadata >> 1) & 1;
}

u32 HasDungeonMap(void) {
    u32 tmp;

    if (sub_08052724())
        tmp = gSave.unk45C[gArea.dungeon_idx];
    return tmp ? 1 : 0;
}

u32 HasDungeonCompass(void) {
    u32 tmp;

    if (sub_08052724())
        tmp = gSave.unk46C[gArea.dungeon_idx] & 4;
    return tmp ? 1 : 0;
}

u32 HasDungeonBigKey(void) {
    if (!sub_08052724())
        return 0;
    return (gSave.unk46C[gArea.dungeon_idx] >> 1) & 1;
}

u32 HasDungeonSmallKey(void) {
    u32 tmp;

    if (!sub_08052724())
        return 0;
    return gSave.unk46C[gArea.dungeon_idx] & 1;
}

void sub_080527FC(u32 a1, u32 a2) {
    sub_08053320();
#ifndef EU
    CleanUpGFXSlots();
#endif
    sub_080ADE24();
    sub_0801C370(1);
    sub_0801AE44(a1);
    MemCopy(gUnk_02024090, gPaletteBuffer, 1024);
    gUsedPalettes = -1;
}

void sub_0805283C(void) {
    gArea.pMusicIndex = gAreaMetadata[gRoomControls.areaID]._3;
    if (CheckLocalFlagByBank(FLAG_BANK_10, LV6_KANE_START)) {
        gArea.pMusicIndex = BGM_FIGHT_THEME2;
    }
}

#ifndef EU
void sub_08052878(void) {
    gArea.musicIndex = gArea.pMusicIndex;
    SoundReq(SONG_STOP_ALL);
}

static void sub_0805289C(void) {
    gArea.pMusicIndex = gArea.musicIndex;
}
#endif

u32 sub_080528B4(void) {
    if (gScreenTransition.field_0x4[1]) {
        InitFade();
        gMain.funcIndex = 3;
        gMain.transition = 0;
        DoFade(5, 8);
        SoundReq(SONG_STOP_BGM);
        return 1;
    }
    return 0;
}

void RoomExitCallback(void) {
    if (gArea.transitionManager != NULL && gArea.onExit != NULL)
        gArea.onExit(gArea.transitionManager);
}

u32 HandleRoomExit(void) {
    if (gScreenTransition.transitioningOut && gSave.stats.health != 0 && gPlayerState.framestate != PL_STATE_DIE) {
        if (StairsAreValid()) {
            gScreenTransition.transitioningOut = 0;
            return 0;
        }

        switch (gScreenTransition.transitionType) {
            case TRANSITION_CUT:
                DoFade(13, 8);
                break;
            case TRANSITION_CUT_FAST:
                DoFade(13, 3);
                break;
            case TRANSITION_FADE_WHITE_SLOW:
                DoFade(7, 4);
                break;
            case TRANSITION_FADE_BLACK_SLOW:
                DoFade(5, 4);
                break;
            case TRANSITION_FADE_BLACK:
                DoFade(5, 16);
                break;
            case TRANSITION_FADE_BLACK_FAST:
                DoFade(5, 256);
                break;
            case TRANSITION_7:
            case TRANSITION_FADE_WHITE_FAST:
                DoFade(7, 256);
                break;
            default:
                DoFade(7, 16);
                break;
        }
        RoomExitCallback();
        gMain.transition = 3;
        *(&gMain.pauseInterval + 1) = 1;
        return 1;
    }
    return 0;
}

static u32 StairsAreValid(void) {
    static const u16 sStairTypes[] = { 0x91, PL_SPAWN_STAIRS_ASCEND, 0x92, PL_SPAWN_STAIRS_DESCEND,
                                       0x93, PL_SPAWN_STAIRS_ASCEND, 0x94, PL_SPAWN_STAIRS_DESCEND,
                                       0x95, PL_SPAWN_STAIRS_ASCEND, 0x96, PL_SPAWN_STAIRS_DESCEND,
                                       0x97, PL_SPAWN_STAIRS_ASCEND, 0x98, PL_SPAWN_STAIRS_DESCEND,
                                       0 };

    const u16* i;
    u32 tgt = gScreenTransition.stairs_idx;

    for (i = sStairTypes; i[0] != 0; i += 2) {
        if (tgt == i[0]) {
            gPlayerState.playerAction = 30;
            gPlayerState.field_0x38 = 0;
            gPlayerState.field_0x39 = i[1];
            if (!gScreenTransition.player_status.spawn_type)
                gScreenTransition.player_status.spawn_type = i[1];
            return 1;
        }
    }
    return 0;
}

void InitParachuteRoom(void) {
    gScreenTransition.transitioningOut = 1;
    gScreenTransition.player_status.start_pos.HALF.x = (gPlayerEntity.x.HALF.HI - gRoomControls.roomOriginX) & 0x3F8;
    gScreenTransition.player_status.start_pos.HALF.y = (gPlayerEntity.y.HALF.HI - gRoomControls.roomOriginY) & 0x3F8;
    gScreenTransition.player_status.start_anim = 4;
    gScreenTransition.player_status.spawn_type = PL_SPAWN_PARACHUTE_FORWARD;
    gScreenTransition.player_status.area_next = gRoomControls.areaID;
    gScreenTransition.player_status.room_next = gRoomControls.roomID - 1;
}

static void HandleRoomEnter(void) {
    switch (gScreenTransition.transitionType) {
        case TRANSITION_CUT:
            DoFade(12, 8);
            break;
        case TRANSITION_CUT_FAST:
            DoFade(12, 3);
            break;
        case TRANSITION_FADE_WHITE_SLOW:
            DoFade(6, 4);
            break;
        case TRANSITION_3:
            break;
        case TRANSITION_FADE_BLACK_FAST:
            DoFade(5, 256);
            break;
        case TRANSITION_7:
            DoFade(7, 256);
            break;
        case TRANSITION_FADE_BLACK:
            DoFade(4, 16);
            break;
        case TRANSITION_FADE_WHITE_FAST:
            DoFade(6, 8);
            break;
        default:
            sub_080500F4(16);
            break;
    }
}

u32 sub_08052B24(void) {
    s32 tmp = PL_STATE_WALK;

    if (!(gInput.heldKeys & SELECT_BUTTON) || gPlayerState.controlMode != CONTROL_ENABLED || gUnk_02034490[0] ||
        gUnk_0200AF00.filler0[1])
        return 0;

    if ((gPlayerState.flags & 0x118) || (gPlayerState.framestate_last > tmp) || gPlayerState.item ||
        gPlayerEntity.field_0x7a.HWORD)
        return 0;

    if ((gPlayerEntity.z.HALF.HI & 0x8000) && !gPlayerState.field_0xa)
        return 0;

    sub_0801862C();
    sub_08078160(19);
    SetPlayerEventPriority();
    return 1;
}

void DisplayEzloMessage(void) {
    u32 height;
    u32 idx;
#if defined(JP) || defined(EU)
    idx = 0x10;
#else
    idx = 0x11;
#endif

    if (gScreenTransition.player_status.field_0x24[idx] == 0) {
        height = gPlayerEntity.y.HALF.HI - gRoomControls.roomScrollY > 96 ? 1 : 13;
    } else {
        height = gScreenTransition.player_status.field_0x24[idx];
    }
    MessageAtHeight(gScreenTransition.hint_idx, height);
}

#if defined(USA) || defined(DEMO_USA) || defined(DEMO_JP)
void sub_08052BF8(void) {
    Entity* e = NULL;

    if (gScreenTransition.player_status.field_0x24[13])
        return;
    gScreenTransition.player_status.field_0x24[13] = 1;
#ifndef DEMO_JP
    gScreenTransition.player_status.field_0x24[10] = gArea.locationIndex;
#endif
    e = (Entity*)GetEmptyManager();
    if (e == NULL)
        return;
    e->kind = MANAGER;
    e->id = 15;
    e->type = 15;
    AppendEntityToList(e, 0);
}
#endif

void sub_08052C3C(void) {
    if (gArea.field_0x18 == 0)
        gArea.unk1A = gArea.field_0x18;
    if (gArea.unk1A) {
        gArea.unk1A--;
        gArea.field_0x18 = 0;
    }
}

void sub_08052C5C(void) {
    if (!CheckIsInteriorNoEnemies()) {
        if (CheckIsOverworld()) {
            gScreenTransition.player_status.field_0x20 = gPlayerEntity.x.HALF_U.HI;
            gScreenTransition.player_status.field_0x22 = gPlayerEntity.y.HALF_U.HI;
        } else if (CheckIsDungeon()) {
            gScreenTransition.player_status.field_0x1c = gPlayerEntity.x.HALF.HI;
            gScreenTransition.player_status.field_0x1e = gPlayerEntity.y.HALF.HI;
        }
    }
}

void sub_08052CA4(u32 area, u32 room, u32 x, u32 y) {
    RoomHeader* hdr = gAreaRoomHeaders[area] + room;
    gScreenTransition.player_status.field_0x20 = hdr->map_x + x;
    gScreenTransition.player_status.field_0x22 = hdr->map_y + y;
}

void sub_08052CD0(u32 area, u32 room, u32 x, u32 y) {
    RoomHeader* hdr = gAreaRoomHeaders[area] + room;
    gScreenTransition.player_status.field_0x1c = hdr->map_x + x;
    gScreenTransition.player_status.field_0x1e = hdr->map_y + y;
}

void sub_08052CFC(void) {
    AreaHeader* a_hdr = NULL;

    MemClear(&gArea, sizeof gArea);
    a_hdr = &gAreaMetadata[gRoomControls.areaID];
    gArea.areaMetadata = a_hdr->flags;
    gArea.locationIndex = a_hdr->location;
    gArea.dungeon_idx = a_hdr->location - 23;
    gArea.localFlagOffset = gLocalFlagBanks[a_hdr->flag_bank];
    gArea.filler[0] = a_hdr->flag_bank;
    gArea.unk1A = 180;
    gArea.unk_0a = 256;
    HandleRoomEnter();
    InitAllRoomResInfo();
}

u32 GetFlagBankOffset(u32 idx) {
    AreaHeader* a_hdr = &gAreaMetadata[idx];
    return gLocalFlagBanks[a_hdr->flag_bank];
}

void RegisterTransitionManager(void* mgr, void (*onEnter)(), void (*onExit)()) {
    if (gMain.transition != 7) {
        gArea.transitionManager = mgr;
        gArea.onEnter = onEnter;
        gArea.onExit = onExit;
    }
}

static void InitAllRoomResInfo(void) {
    RoomHeader* r_hdr = gAreaRoomHeaders[gRoomControls.areaID];
    RoomResInfo* info = gArea.roomResInfos;
    u32 i;
    for (i = 0; i < MAX_ROOMS && *(u16*)r_hdr != 0xFFFF; i++, r_hdr++) {
        if (r_hdr->tileset_id != 0xFFFF)
            InitRoomResInfo(info, r_hdr, gRoomControls.areaID, i);
        info++;
    }
    gArea.pCurrentRoomInfo = GetCurrentRoomInfo();
}

static void InitRoomResInfo(RoomResInfo* info, RoomHeader* r_hdr, u32 area, u32 room) {
    info->map_x = r_hdr->map_x;
    info->map_y = r_hdr->map_y;
    info->pixel_width = r_hdr->pixel_width;
    info->pixel_height = r_hdr->pixel_height;
    info->tileset = *(gAreaTilesets[area] + r_hdr->tileset_id);
    info->map = *(gAreaRoomMaps[area] + room);
    info->metatiles = gAreaMetatiles[area];
    info->bg_anim = gUnk_080B755C[area];
    info->exits = *(gExitLists[area] + room);
    if (gAreaTable[area] != NULL) {
        info->properties = *(gAreaTable[area] + room);
    }
}

RoomResInfo* GetCurrentRoomInfo(void) {
    return &gArea.roomResInfos[gRoomControls.roomID];
}

void sub_08052EA0(void) {
    MemClear(&gRoomVars, sizeof gRoomVars);
    gRoomVars.unk_10[0] = -1;
    gRoomVars.unk_10[1] = gRoomVars.unk_10[0];
    gRoomVars.unk_10[2] = gRoomVars.unk_10[0];
    gRoomVars.unk_10[3] = gRoomVars.unk_10[0];
    gRoomVars.lightLevel = 256;
    gArea.locationIndex = gAreaMetadata[gRoomControls.areaID].location;
    sub_08049D30();
    InitScriptData();
    sub_08054524();
    sub_080186D4();
    sub_0806F364();
    UpdateGlobalProgress();
}

static u32 sub_08052EF4(s32 idx) {
    AreaHeader* a_hdr = NULL;
    u32 i = idx < 0 ? gRoomControls.areaID : idx;
    a_hdr = &gAreaMetadata[i];
    return gLocalFlagBanks[a_hdr->flag_bank];
}

void sub_08052F1C(void) {
    u32 x, y;
    LinkedList* ll;
    Entity* e;

    if ((gArea.filler3[1] & 1) == 0 || !gRoomVars.field_0x0)
        return;

    y = 0;
    x = 0;

    // WTF?
    switch (gRoomControls.unk_10) {
        case 0:
            y = gArea.pCurrentRoomInfo->pixel_height;
        case 1:
            y = gArea.pCurrentRoomInfo->pixel_height;
        case 2:
            y = gArea.pCurrentRoomInfo->pixel_height;
        case 3:
            x = gArea.pCurrentRoomInfo->pixel_width;
    }

    gArea.pCurrentRoomInfo->map_x += x;
    gArea.pCurrentRoomInfo->map_y += y;
    gRoomControls.roomOriginX += x;
    gRoomControls.roomOriginY += y;
    gRoomControls.roomScrollX += x;
    gRoomControls.roomScrollY += y;

    ll = gEntityLists;
    do {
        for (e = ll->first; e != (Entity*)ll; e = e->next) {
            if (e->kind != MANAGER) {
                e->x.HALF.HI += x;
                e->y.HALF.HI += y;
            }
        }
    } while (++ll < gEntityLists + 9);
}

void sub_08052FD8(u32 area, u32 room) {
    sub_08052FF4(area, room);
    gRoomControls.cameraTarget = NULL;
    sub_0807C860();
    sub_0807C740();
}

void sub_08052FF4(u32 area, u32 room) {
    RoomHeader* r_hdr = NULL;

    sub_08080668();
    sub_080197AC();
    gRoomControls.areaID = area;
    gRoomControls.roomID = room;
    gScreen.lcd.displayControl = 0x1740;
    MemClear(&gArea.currentRoomInfo, sizeof gArea.currentRoomInfo);
    gArea.pCurrentRoomInfo = &gArea.currentRoomInfo;
    r_hdr = gAreaRoomHeaders[area] + room;
    gArea.currentRoomInfo.map_x = r_hdr->map_x;
    gArea.currentRoomInfo.map_y = r_hdr->map_y;
    gArea.currentRoomInfo.pixel_width = r_hdr->pixel_width;
    gArea.currentRoomInfo.pixel_height = r_hdr->pixel_height;
    gArea.currentRoomInfo.tileset = *(gAreaTilesets[area] + r_hdr->tileset_id);
    gArea.currentRoomInfo.map = *(gAreaRoomMaps[area] + room);
    gArea.currentRoomInfo.metatiles = gAreaMetatiles[area];
    gArea.currentRoomInfo.bg_anim = gUnk_080B755C[area];
}

void ChangeLightLevel(s32 lightLevel) {
    lightLevel += gRoomVars.lightLevel;
    if (lightLevel < 0)
        lightLevel = 0;
    if (lightLevel > 256)
        lightLevel = 256;
    gRoomVars.lightLevel = lightLevel;
}

static void sub_080530B0(void) {
    static const u16 sMinecartData[] = { 0x189, 0x0, 0x102, 0x4, 0x1af, 0x0, 0x204, 0x0,
                                         0x1cf, 0x0, 0x10,  0x4, 0x0,   0x0, 0x0,   0x0 };

    MemCopy(sMinecartData, gScreenTransition.minecart_data, sizeof sMinecartData);
}

void UpdateGlobalProgress(void) {
    u8 pcnt = 1;
    if (CheckLocalFlagByBank(FLAG_BANK_3, SEIIKI_STAINED_GLASS)) {
        pcnt = 9;
    } else if (CheckGlobalFlag(LV5_CLEAR)) {
        pcnt = 8;
    } else if (CheckLocalFlagByBank(FLAG_BANK_3, OUBO_KAKERA)) {
        pcnt = 7;
    } else if (CheckGlobalFlag(LV4_CLEAR)) {
        pcnt = 6;
    } else if (CheckGlobalFlag(LV3_CLEAR)) {
        pcnt = 5;
    } else if (CheckLocalFlagByBank(FLAG_BANK_1, SOUGEN_08_TORITSUKI)) {
        pcnt = 4;
    } else if (CheckGlobalFlag(LV1_CLEAR)) {
        pcnt = 2;
    }
    gSave.global_progress = pcnt;
}

static u32 sub_08053144(void) {
    u32 ret;

    if (CheckGlobalFlag(ENDING))
        return 0;
    ret = 0;
    if (gArea.locationIndex != 0)
        ret = !!(gScreenTransition.player_status.field_0x24[10] ^ gArea.locationIndex);
    return ret;
}

void sub_08053178(void) {
    if (!sub_08053144())
        return;

    gScreenTransition.player_status.field_0x24[10] = gArea.locationIndex;

    if (!CheckGlobalFlag(TABIDACHI))
        return;

    if (!CheckGlobalFlag(ENDING)) {
        Entity* e = (Entity*)GetEmptyManager();
        if (e != NULL) {
            e->kind = MANAGER;
            e->id = 0x39;
            AppendEntityToList(e, 8);
            if (!gRoomVars.field_0x0 && !ReadBit(gSave.areaVisitFlags, gArea.locationIndex)) {
                e->type2 = 1;
                SetPlayerControl(3);
                SetInitializationPriority();
            }
        }
    }
    WriteBit(gSave.areaVisitFlags, gArea.locationIndex);
}

void sub_080531F8(void) {
    gPlayerState.startPosX = gPlayerEntity.x.HALF.HI;
    gPlayerState.startPosY = gPlayerEntity.y.HALF.HI;
    if (sub_08053144()) {
        MemCopy(&gScreenTransition.player_status, &gSave.saved_status, sizeof gScreenTransition.player_status);
        if (CheckIsDungeon()) {
            gScreenTransition.player_status.field_0x16 = gRoomControls.areaID;
            gScreenTransition.player_status.field_0x17 = gRoomControls.roomID;
            gScreenTransition.player_status.field_0x18 = gPlayerEntity.x.HALF.HI;
            gScreenTransition.player_status.field_0x1a = gPlayerEntity.y.HALF.HI;
        }
    }
}

void sub_08053250(void) {
    gScreenTransition.player_status.spawn_type = PL_SPAWN_DEFAULT;
    gScreenTransition.player_status.start_pos.HALF.x = gPlayerEntity.x.HALF.HI - gRoomControls.roomOriginX;
    gScreenTransition.player_status.start_pos.HALF.y = gPlayerEntity.y.HALF.HI - gRoomControls.roomOriginY;
    gScreenTransition.player_status.start_anim = gPlayerEntity.animationState;
    gScreenTransition.player_status.layer = gPlayerEntity.collisionLayer;
    gScreenTransition.player_status.area_next = gRoomControls.areaID;
    gScreenTransition.player_status.room_next = gRoomControls.roomID;
    MemCopy(&gScreenTransition.player_status, &gSave.saved_status, sizeof gScreenTransition.player_status);
}

void sub_0805329C(void) {
    if (sub_08053144()) {
        switch (gRoomControls.areaID) {
            case AREA_DEEPWOOD_SHRINE:
                gSave.unk7 = 0;
                break;
            case AREA_CAVE_OF_FLAMES:
                sub_080530B0();
                break;
            case AREA_OUTER_FORTRESS_OF_WINDS:
                sub_080532E4();
                break;
            default:
                sub_08053460();
                break;
        }
    }
}

static void sub_080532E4(void) {
    s32 x, y;

    RoomHeader* r_hdr = gAreaRoomHeaders[AREA_FORTRESS_OF_WINDS] + 33;

    gScreenTransition.player_status.field_0x16 = AREA_FORTRESS_OF_WINDS;
    gScreenTransition.player_status.field_0x17 = 33;

    gScreenTransition.player_status.field_0x18 = r_hdr->map_x + r_hdr->pixel_width / 2;
    gScreenTransition.player_status.field_0x1c = gScreenTransition.player_status.field_0x18;
    gScreenTransition.player_status.field_0x1a = r_hdr->map_y + r_hdr->pixel_height + 0xa0;
    gScreenTransition.player_status.field_0x1e = gScreenTransition.player_status.field_0x1a;
}

void sub_08053320(void) {
    MemClear(&gBG0Buffer, sizeof gBG0Buffer);
    MemClear(&gBG1Buffer, sizeof gBG1Buffer);
    MemClear(&gBG2Buffer, sizeof gBG2Buffer);
    MemClear(&gBG3Buffer, sizeof gBG3Buffer);
    LoadGfxGroup(16);
    LoadGfxGroup(23);
    if (gRoomControls.areaID == AREA_CASTOR_WILDS)
        LoadGfxGroup(26);
    sub_08053390();
    LoadPaletteGroup(11);
    LoadPaletteGroup(12);
    SetColor(0, 0);
}

void sub_08053390(void) {
    LoadGfxGroup(GetInventoryValue(8) ? 24 : 25);
    if (GetInventoryValue(0xAu))
        LoadGfxGroup(29);
    LoadGfxGroup(GetInventoryValue(12) ? 28 : 27);
}

void sub_080533CC(void) {
    u16* p1 = gUnk_020178E0;
    u16* p2 = gUnk_020178E0 - 0x100;
    *p2++ = *p1++;
    *p2++ = *p1++;
    *p2++ = *p1++;
    *p2++ = *p1++;
    *p2++ = *p1++;
    gUsedPalettes |= 8;
}

void sub_0805340C(void) {
    static void (*const sHandlers[])(u32*) = {
        sub_08053434, DummyHandler, sub_080534E4, DummyHandler, DummyHandler, DummyHandler, DummyHandler, DummyHandler,
    };

    u32* p;
    u32 i;

    p = gSave.unk48C;
    for (i = 0; i < 8; i++, p++) {
        (sHandlers[i])(p);
    }
}

static void DummyHandler(u32* a1) {
}

static void sub_08053434(u32* a1) {
    if (gArea.locationIndex == 29 && *a1) {
        if (!--*a1) {
            sub_08053460();
            MenuFadeIn(5, 6);
        }
    }
}

static void sub_08053460(void) {
    static const u16 sClearFlags[] = { FLAG_BANK_10, LV6_GUFUU1_GISHIKI, FLAG_BANK_10, LV6_GUFUU1_DEMO,
                                       FLAG_BANK_10, LV6_ZELDA_DISCURSE, FLAG_BANK_10, LV6_00_ESCAPE,
                                       FLAG_BANK_10, LV6_GUFUU2_DEAD,    FLAG_BANK_G,  ENDING,
                                       FLAG_BANK_10, LV6_KANE_START,     FLAG_BANK_10, LV6_KANE_1ST,
                                       FLAG_BANK_10, LV6_KANE_2ND,       FLAG_BANK_10, LV6_SOTO_ENDING,
                                       0xFFFF };

    gSave.unk48C[0] = 0;
    if (CheckLocalFlagByBank(FLAG_BANK_10, LV6_ZELDA_DISCURSE))
        ClearGlobalFlag(ZELDA_CHASE);
    ClearFlagArray(sClearFlags);
}

void sub_08053494(void) {
    gSave.unk48C[0] = 10800;
}

void sub_080534AC(void) {
    if (CheckLocalFlagByBank(FLAG_BANK_10, LV6_KANE_START)) {
        ClearLocalFlagByBank(FLAG_BANK_10, LV6_KANE_START);
        gSave.unk48C[0] = 0;
        SoundReq(SONG_STOP_BGM);
    }
}

static void sub_080534E4(u32* a1) {
    if (gRoomControls.areaID != AREA_VEIL_FALLS_TOP) {
        if (*a1)
            --*a1;
    }
}

void sub_08053500(void) {
    gSave.unk48C[2] = 36000;
}

void sub_08053518(void) {
    static const u16 sClearFlags[] = { FLAG_BANK_2, BILL00_SHICHOU_00, FLAG_BANK_2, BILL0A_YADO_TAKARA_00,
                                       FLAG_BANK_2, BILL0C_SCHOOLR_00, FLAG_BANK_1, MACHI00_00,
                                       FLAG_BANK_1, MACHI00_02,        FLAG_BANK_2, MHOUSE06_00,
                                       FLAG_BANK_2, MHOUSE14_00,       FLAG_BANK_2, MHOUSE2_00_02,
                                       FLAG_BANK_2, MHOUSE2_01_T0,     FLAG_BANK_2, MHOUSE2_02_KAME,
                                       FLAG_BANK_2, SHOP00_ITEM_01,    FLAG_BANK_2, SHOP01_CAFE_01,
                                       0xFFFF };

    sub_08053460();
    ClearFlagArray(sClearFlags);

    if (!CheckGlobalFlag(WATERBEAN_PUT))
        ClearGlobalFlag(WATERBEAN_OUT);
    if (!GetInventoryValue(0x40u))
        ClearGlobalFlag(LV1_CLEAR);
    if (!GetInventoryValue(0x41u))
        ClearGlobalFlag(LV2_CLEAR);
    if (!GetInventoryValue(0x42u))
        ClearGlobalFlag(LV4_CLEAR);
}

static void ClearFlagArray(const u16* p) {
    const u16* i;

    for (i = p; i[0] != 0xFFFF; i += 2)
        ClearLocalFlagByBank(i[0], i[1]);
}
