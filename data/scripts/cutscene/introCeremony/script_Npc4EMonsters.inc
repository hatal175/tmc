@ Intro Ceremony NPC4E monsters
SCRIPT_START script_Npc4EMonsters
	Wait 0x001e
	PlaySound SFX_125
	CallWithArg sub_0807FB28, 0x00000003
	Wait 0x003c
	PlaySound SFX_125
	CallWithArg sub_0807FB28, 0x00000003
	Wait 0x0004
	PlaySound SFX_125
	CallWithArg sub_0807FB28, 0x00000003
	Wait 0x001e
	PlaySound SFX_12C
	SetSyncFlag 0x00800000
	WaitForSyncFlagAndClear 0x01000000
	_0807E778 0x0004
	DoFade7
	WaitForFadeFinish
	Wait 0x003c
	PlaySound SFX_SPIRITS_RELEASE
	PlaySound SFX_1C2
	LoadRoomEntityList gUnk_080F0770
	SetSyncFlag 0x00000010
	WaitForSyncFlagAndClear 0x00000020
	_0807E778 0x0002
	DoFade6
	WaitForFadeFinish
	CallWithArg DeleteManager36, 0x00000002
	_0807F0C8 0x0000, 0x0000
	Call sub_0806DC3C
	Call sub_080791BC
	CallWithArg sub_0807F244, 0x0000000d
	CallWithArg sub_0807F29C, gUnk_080049F6
	_0807F0B4 0x0001
	SetEntityPositionRelative 0x01f8, 0x0068
	SetSyncFlag 0x00000004
	Wait 0x001e
	SetSyncFlag 0x00000040
	WaitForSyncFlagAndClear 0x00000008
	WaitForSyncFlagAndClear 0x00000080
	PlaySound SFX_1C3
	SetSyncFlag 0x20000000
	Wait 0x0078
	CallWithArg sub_0807F29C, 0x00000000
	Call sub_0806DC58
	SetSyncFlag 0x40000000
	SetSyncFlag 0x00000010
	SetSyncFlag 0x00000100
	WaitForSyncFlagAndClear 0x00000020
	WaitForSyncFlagAndClear 0x00000200
	MessageFromTargetPos 0x1045, 0x000c
	WaitUntilTextboxCloses
	MessageFromTargetPos 0x1046, 0x0000
	WaitUntilTextboxCloses
	CallWithArg CreateManager36, 0x00000002
	_0807F0C8 0xffff, 0x0000
