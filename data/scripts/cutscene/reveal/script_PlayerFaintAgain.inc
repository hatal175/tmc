@ Sanctuary Player faint from Vaati attack
SCRIPT_START script_PlayerFaintAgain
	Call sub_0807F1C4
	Call sub_0807F2D4
	Call sub_0807F1E8
	Call sub_0807F2D4
	SetSyncFlag 0x00000002
	WaitForSyncFlagAndClear 0x00000004
	PlaySound SFX_PLY_JUMP
	_0807EB44 0x0004
	Call sub_0807F210
	_0807EF3C 0x0200, 0x0020
	DoPostScriptAction 0x0000
	SetSyncFlag 0x00000002
	Call sub_080791BC
SCRIPT_END
	.2byte 0x0000
