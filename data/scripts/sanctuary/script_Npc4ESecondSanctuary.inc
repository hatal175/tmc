@ Sanctuary second time NPC4E? Handles cutscene
SCRIPT_START script_Npc4ESecondSanctuary
	BeginBlock
	DoPostScriptAction 0x0008
	EndBlock
	BeginBlock
	Call sub_0807F92C
	CallWithArg sub_0806DA04, 0x00000003
	EndBlock
script_0801373C:
	CheckEntityInteractType
	JumpIfNot script_0801373C
	_0807E864
	Call sub_0807DF28
	StartPlayerScript script_PlayerAtPedestal
	WaitForSyncFlagAndClear 0x00000001
	CallWithArg sub_08095A1C, script_Object6ASword2
	PlaySound SFX_ELEMENT_PLACE
	Wait 0x005a
	BeginBlock
	PlaySound SFX_ELEMENT_FLOAT
	CallWithArg sub_08095D54, script_Object6AWaterElementFloating
	EndBlock
	WaitForSyncFlagAndClear 0x20000000
	BeginBlock
	PlaySound SFX_ELEMENT_CHARGE
	CallWithArg sub_08095D8C, script_Object6ASwordChange1
	CallWithArg sub_08095D8C, script_Object6ASwordCharge2
	CallWithArg sub_08095D8C, script_Object6ASwordCharge3
	EndBlock
	Wait 0x001e
	BeginBlock
	PlaySound SFX_1D0
	CallWithArg sub_08095D8C, script_Object6ASwordCharge5
	CallWithArg sub_08095D8C, script_Object6ASwordCharge6
	CallWithArg sub_08095D8C, script_Objet6ASwordCharge7
	EndBlock
	Wait 0x003c
	CallWithArg CreateManager36, 0x00000000
	SetSyncFlag 0x00000200
	WaitForSyncFlagAndClear 0x00002000
	PlaySound SFX_1D2
	CallWithArg sub_08095D8C, script_Object6ASwordCharge9
	CallWithArg sub_08095D8C, script_Object6ASwordCharge10
	SetSyncFlag 0x00000400
	WaitForSyncFlagAndClear 0x00004000
	SetSyncFlag 0x00000800
	WaitForSyncFlagAndClear 0x00008000
	Wait 0x0078
	SetSyncFlag 0x00000060
	CallWithArg DeleteManager36, 0x00000000
	Wait 0x0078
	SetSyncFlag 0x00000080
	WaitForSyncFlagAndClear 0x00000100
	Wait 0x003c
	StartPlayerScript script_PlayerPickUpSword
	SetSyncFlag 0x00000080
	_0807F078 0x0004, 0x0001
	Call sub_0806DC3C
	Call sub_0806DC58
	Call sub_0807F304
	Wait 0x003c
	_0807E778 0x0004
	DoFade7
	PlaySound SFX_EVAPORATE
	WaitForFadeFinish
	Wait 0x003c
	SetSyncFlag 0x00000010
	_0807E778 0x0002
	DoFade6
	WaitForFadeFinish
	PlaySound SFX_109
	MessageFromTargetPos 0x0504, 0x000c
	WaitUntilTextboxCloses
	SetSyncFlag 0x00040000
	SetLocalFlag 0x007b
	Call sub_08053250
	Call sub_0807DF50
	_0807E878
	DoPostScriptAction 0x0006
SCRIPT_END
	.2byte 0x0000
