@ Intro Assembly Player
SCRIPT_START script_PlayerEnters
	BeginBlock
	SetEntitySpeed 0x0100
	EndBlock
	DoPostScriptAction 0x0001
	_0807EDD4 0x00b8, 0x0090
	_0807EB44 0x0006
	DoPostScriptAction 0x0000
	SetSyncFlag 0x00000020
	WaitForSyncFlagAndClear 0x00000040
	DoPostScriptAction 0x0001
	_0807EDD4 0x0088, 0x0078
	_0807EB44 0x0000
	DoPostScriptAction 0x0000
	Wait 0x000f
	SetSyncFlag 0x00000020
	Call sub_080791BC
SCRIPT_END
	.2byte 0x0000
