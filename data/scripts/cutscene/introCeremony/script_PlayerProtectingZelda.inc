@ Intro ceremony Player protecting Zelda
SCRIPT_START script_PlayerProtectingZelda
	BeginBlock
	SetEntitySpeed 0x0040
	EndBlock
	SetEntitySpeed 0x0200
	DoPostScriptAction 0x0001
	_0807EDD4 0x01d8, 0x0068
	_0807EB44 0x0004
	DoPostScriptAction 0x0000
	SetSyncFlag 0x00000400
	Call sub_080791BC
SCRIPT_END
