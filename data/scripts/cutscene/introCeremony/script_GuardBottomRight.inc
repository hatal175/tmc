@ Intro Ceremony Guard bottom right
SCRIPT_START script_GuardBottomRight
	ClearSyncFlag 0x00002000
	SetSyncFlag 0x00004000
	WaitForSyncFlagAndClear 0x00002000
	_0807E930 0x0005
	_0807EB44 0x0002
	_0807EC94 0x0010
	_0807EB44 0x0004
	_0807E930 0x0002
	SetSyncFlag 0x00004000
	WaitForSyncFlagAndClear 0x00002000
	DoPostScriptAction 0x0004
	Wait 0x003c
	_0807E930 0x0012
	PlaySound SFX_EM_MOBLIN_SPEAR
	Wait 0x003c
	_0807E930 0x0014
	SetEntitySpeed 0x0100
	_0807EDD4 0x0200, 0x0098
	_0807EDD4 0x0200, 0x00c8
	_0807E930 0x0013
	SetSyncFlag 0x00004000
	WaitForSyncFlagAndClear 0x00002000
	DoPostScriptAction 0x0010
	Wait 0x000a
	DoPostScriptAction 0x0010
	Call sub_0807F3C8
	_0807E930 0x0014
	SetEntitySpeed 0x0400
	SetEntityDirection 0x0002
	_0807EC1C 0x003c
	SetSyncFlag 0x00004000
	DoPostScriptAction 0x0006
SCRIPT_END
