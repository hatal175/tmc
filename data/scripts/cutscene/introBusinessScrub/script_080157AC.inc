@ Intro Outside Castle OBJECT_69 1?
SCRIPT_START script_080157AC
	CheckPlayerInRegion 0x01f8, 0x0310, 0x2020
	JumpIfNot script_080157AC
	_0807E864
	Call sub_0807F9A4
	Call sub_0807DF28
	SetSyncFlag 0x00000001
	WaitForSyncFlagAndClear 0x00000002
	Call sub_0807DF50
	_0807E878
script_080157DA:
	CheckPlayerInRegion 0x0250, 0x0230, 0x3040
	JumpIfNot script_080157DA
	_0807E864
	Call sub_0807F9A4
	Call sub_0807DF28
	Call sub_0807F3F8
	Wait 0x003c
	SetSyncFlag 0x00000001
	WaitForSyncFlagAndClear 0x00000002
	StartPlayerScript script_PlayerIntroBusinessScrub1
	_0807F0B4 0x0001
	SetEntityPositionRelative 0x0248, 0x0218
	CameraTargetEntity
	Call sub_0807F5C0
	WaitForSyncFlagAndClear 0x00000010
	SetSyncFlag 0x00000008
	WaitForSyncFlagAndClear 0x00000020
	SetSyncFlag 0x00000001
	WaitForSyncFlagAndClear 0x00000002
	StartPlayerScript script_PlayerIntroBusinessScrub2
	WaitForSyncFlagAndClear 0x00000010
	SetSyncFlag 0x00000001
	WaitForSyncFlagAndClear 0x00000002
	MessageFromTargetPos 0x1066, 0x0002
	WaitUntilTextboxCloses
	SetSyncFlag 0x00000001
	WaitForSyncFlagAndClear 0x00000002
	Call sub_0807DF50
	_0807E878
	Call sub_08066F94
	SetSyncFlag 0x00000008
script_08015880:
	CheckRoomFlag 0x0000
	JumpIfNot script_08015880
script_08015888:
	WaitUntilTextboxCloses
	ComparePlayerAction 0x001c
	JumpIf script_08015888
	_0807E864
	Call sub_0807DF28
	_0807F0B4 0x0002
	SetEntityPositionRelative 0x0248, 0x0208
	CameraTargetEntity
	StartPlayerScript script_PlayerIntroBusinessScrub3
	WaitForSyncFlagAndClear 0x00000010
	MessageFromTargetPos 0x106a, 0x000c
	WaitUntilTextboxCloses
	SetSyncFlag 0x00000008
	Wait 0x0078
	_0807E8E4_2 
	MessageFromTargetPos 0x1068, 0x0002
	WaitUntilTextboxCloses
	SetSyncFlag 0x00000001
	WaitForSyncFlagAndClear 0x00000002
.ifdef JP
	SetLocalFlag 0x0089
.else
.ifdef EU
	SetLocalFlag 0x0089
.else
.ifdef DEMO_JP
	SetLocalFlag 0x0089 @ TODO deduplicate
.else
	SetLocalFlag 0x008b
.endif
.endif
.endif
	Call sub_08066FB8
	Call sub_0807DF50
	_0807E878
	_0807F0B4 0x0004
	CameraTargetPlayer
	DoPostScriptAction 0x0006
SCRIPT_END
