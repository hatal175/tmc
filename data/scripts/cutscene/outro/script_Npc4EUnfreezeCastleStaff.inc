@ Outro NPC4E Unfreeze castle staff
SCRIPT_START script_Npc4EUnfreezeCastleStaff
	BeginBlock
	_0807E864
	Call sub_0807DF28
	SetEntityPositionRelative 0x00f8, 0x01b8
	Call sub_0807F844
	EndBlock
	Wait 0x003c
	PlaySound SFX_EVAPORATE
	_0807E778 0x0004
	DoFade7
	WaitForFadeFinish
	SetSyncFlag 0x00000001
	PlaySound SFX_APPARATE
	_0807E778 0x0002
	DoFade6
	WaitForFadeFinish
	Wait 0x001e
	SetSyncFlag 0x00000002
	Wait 0x0014
	SetSyncFlag 0x00000004
	Wait 0x000a
	SetSyncFlag 0x00000008
	Wait 0x0005
	SetSyncFlag 0x00000010
	Wait 0x0002
	SetSyncFlag 0x00000020
	Wait 0x0078
	CallWithArg sub_0806DA1C, 0x0000000c
	DoPostScriptAction 0x0006
SCRIPT_END
