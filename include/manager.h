#ifndef MANAGER_H
#define MANAGER_H

#include "global.h"
#include "entity.h"

union SplitSHWord {
    s16 SHWORD;
    struct {
        u8 LO, HI;
    } PACKED HALF;
} PACKED;

typedef struct Manager {
    /*0x00*/ struct Manager* prev;
    /*0x00*/ struct Manager* next;
    /*0x08*/ u8 type;
    /*0x09*/ u8 subtype;
    /*0x0a*/ u8 unk_0a;
    /*0x0b*/ u8 unk_0b;
    /*0x0c*/ u8 action;
    /*0x0d*/ u8 unk_0d;
    /*0x0e*/ u8 unk_0e;
    /*0x0f*/ u8 unk_0f;
    /*0x10*/ u8 unk_10;
    /*0x11*/ u8 unk_11[3];
    /*0x14*/ struct Manager* parent;
    /*0x18*/ u8 unk_18[0x8];
    // union SplitHWord y;
    // u16 unk_22;
    // u16 unk_24;
    // u16 unk_26;
    // u8 unk_28[0x0D];
    // u8 unk_35;
    // u16 unk_36;
    // union SplitSHWord unk_38;
    // union SplitSHWord unk_3a;
    // u16 unk_3c;
    // u16 unk_3e;
} Manager;

typedef struct {
    u16 posX;
    u16 posY;
    u8 width;
    u8 height;
    u8 unk_06;
    union {
        u8 all;
        struct {
            u8 layer : 2;
            u8 unk1 : 2;
            u8 unk2 : 1;
            u8 unk3 : 3;
        } PACKED b;
    } PACKED unk_07;
} Manager6WarpData;

typedef struct {
    Manager manager;
    Manager6WarpData* warpList;
} Manager6;

typedef struct {
    Manager manager;
    u16 x;
    u16 y;
    u16 rx;
    u16 ry;
    u8 unk_28[13];
    u8 msg_height;
    u16 msg_idx;
    u8 x_raw;
    u8 y_raw;
    u8 rx_raw;
    u8 ry_raw;
    u16 flag1;
    u16 flag2;
} ManagerA;

typedef struct {
    Manager manager;
    u8 unk_20;
    u8 unk_21[0x14];
    u8 unk_35;
    u8 unk_36[0x4];
    u16 unk_3a;
    u16 unk_3c;
    u16 unk_3e;
} ManagerB;

typedef struct {
    Manager manager;
    Entity* enemies[8];
} ManagerBHelper;

typedef struct {
    Manager manager;
    u8 unk_20[0x18];
    s16 unk_38;
    s16 unk_3a;
    u16 unk_3c;
    u16 unk_3e;
} ManagerE;

typedef struct {
    Manager manager;
    u8 unk_20[0x18];
    s16 unk_38;
    s16 unk_3a;
    u16 unk_3c;
    u16 unk_3e;
} ManagerF;

typedef struct {
    Manager manager;
    u8 unk_20;
    u8 unk_21;
    u8 unk_22;
    u8 unk_23;
    u8 filler_0x24[0x1C];
} Manager10;

typedef struct Manager11 {
    Manager manager;
    u8 unk_20[0x1C];
    u16 unk_3c;
    u16 unk_3e;
} Manager11;

typedef struct {
    u16 unk_00;
    u8 source_roomID;
    u8 unk_03;
    u8 target_areaID;
    u8 target_roomID;
    u16 unk_06;
} DiggingCaveEntrance;

extern struct {
    DiggingCaveEntrance* unk_00;
    u16 unk_04;
    u16 unk_06;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0a;
    u8 unk_0b;
} gUnk_03004030;

extern DiggingCaveEntrance* diggingCaveEntrances[];

typedef struct {
    Manager manager;
    u8 field_0x20[0x15];
    u8 field_0x35;
    u8 field_0x36;
    u8 field_0x37;
    s16 x;
    u16 y;
    u16 tile;
    u16 field_0x3e;
} Manager24;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 unk_04;
    u16 unk_06;
} UnkManager26HelperStruct;

extern void Manager1_Main();
extern void Manager2_Main();
extern void Manager3_Main();
extern void Manager4_Main();
extern void Manager5_Main();
extern void Manager6_Main();
extern void Manager7_Main();
extern void Manager8_Main();
extern void Manager9_Main();
extern void ManagerA_Main();
extern void ManagerB_Main();
extern void ManagerC_Main();
extern void ManagerD_Main();
extern void ManagerE_Main();
extern void sub_08058ECC(ManagerF*);
extern void Manager10_Main(Manager10*);
extern void Manager11_Main(Manager11*);
extern void Manager12_Main();
extern void Manager13_Main();
extern void Manager14_Main();
extern void Manager15_Main();
extern void Manager16_Main();
extern void Manager17_Main();
extern void Manager18_Main();
extern void Manager19_Main();
extern void Manager1A_Main();
extern void Manager1B_Main();
extern void Manager1C_Main(Manager*);
extern void Manager1D_Main();
extern void Manager1E_Main();
extern void Manager1F_Main();
extern void Manager20_Main();
extern void Manager21_Main();
extern void Manager22_Main();
extern void Manager23_Main();
extern void Manager24_Main();
extern void Manager25_Main();
extern void Manager26_Main();
extern void Manager27_Main();
extern void Manager28_Main();
extern void Manager29_Main();
extern void Manager2A_Main(Manager*);
extern void Manager2B_Main();
extern void Manager2C_Main();
extern void Manager2D_Main(Entity*);
extern void Manager2E_Main();
extern void Manager2F_Main();
extern void Manager30_Main();
extern void Manager31_Main();
extern void Manager32_Main();
extern void Manager33_Main();
extern void Manager34_Main();
extern void Manager35_Main();
extern void Manager36_Main(Manager*);
extern void Manager37_Main();
extern void Manager38_Main(Entity*);
extern void Manager39_Main();

extern void (*const gManagerFunctions[58])();

Manager* GetEmptyManager(void);

/**
 * @brief Set manager responsible for handling room changes
 */
extern void RegisterTransitionManager(void* mgr, void (*onEnter)(), void (*onExit)());

extern u32 sub_0805ACC0(Entity*);
extern void sub_0801855C(void);
extern void sub_080186C0(u32);

#endif
