@ Intro Ceremony Chest carrying Guard
@ and guard bottom left?
SCRIPT_START script_GuardCarryingChest
	BeginBlock
	DoPostScriptAction 0x0008
	SetEntitySpeed 0x0100
	Call sub_08095244
	Call sub_0807F338
	EndBlock
	WaitForSyncFlag 0x0002a800
	DoPostScriptAction 0x0007
	_0807E930 0x0006
	_0807ECC4 0x0010
	Wait 0x003c
	_0807ECC4 0x0010
	Wait 0x003c
	_0807ECC4 0x0010
	_0807E930 0x0002
	Call sub_08064050
	JumpTable script_08011312, script_GuardBottomRight, script_GuardTopLeft, script_GuardTopRight
@ Guard bottom left:
script_08011312:
	ClearSyncFlag 0x00000800
	SetSyncFlag 0x00001000
	WaitForSyncFlagAndClear 0x00000800
	_0807E930 0x0007
	_0807EB44 0x0006
	_0807ECF4 0x0010
	_0807EB44 0x0004
	_0807E930 0x0002
	SetSyncFlag 0x00001000
	WaitForSyncFlagAndClear 0x00000800
	DoPostScriptAction 0x0004
	Wait 0x003c
	_0807E930 0x0012
	PlaySound SFX_EM_MOBLIN_SPEAR
	Wait 0x003c
	_0807E930 0x0014
	SetEntitySpeed 0x0100
	_0807EDD4 0x01f0, 0x0098
	_0807EDD4 0x01f0, 0x00c8
	_0807E930 0x0013
	SetSyncFlag 0x00001000
	WaitForSyncFlagAndClear 0x00000800
	DoPostScriptAction 0x0010
	Wait 0x000a
	DoPostScriptAction 0x0010
	Call sub_0807F3C8
	_0807E930 0x0014
	SetEntitySpeed 0x0400
	SetEntityDirection 0x001e
	_0807EC1C 0x003c
	SetSyncFlag 0x00001000
	DoPostScriptAction 0x0006
SCRIPT_END
