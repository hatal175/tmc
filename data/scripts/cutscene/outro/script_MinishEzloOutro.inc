@ Outro Minish Ezlo
SCRIPT_START script_MinishEzloOutro
	BeginBlock
	DoPostScriptAction 0x0008
	SetEntitySpeed 0x0080
	DoPostScriptAction 0x000b
	_0807EB44 0x0004
	CallWithArg sub_0807F3D8, 0x00000000
	EndBlock
	WaitForSyncFlagAndClear 0x00000002
	_0807E930 0x000e
	DoPostScriptAction 0x0007
	Call sub_0807F2D4
	DoPostScriptAction 0x0004
	SetSyncFlag 0x00000040
	WaitForSyncFlagAndClear 0x00000002
	_0807E930 0x000c
	Call sub_0807F2D4
	SetSyncFlag 0x00000040
	WaitForSyncFlagAndClear 0x00000002
	_0807E930 0x000f
	Call sub_0807F2D4
	SetSyncFlag 0x00000040
	WaitForSyncFlagAndClear 0x00000002
	_0807E930 0x000c
	Call sub_0807F2D4
	SetSyncFlag 0x00000040
	WaitForSyncFlagAndClear 0x00000002
	CallWithArg sub_080960C4, script_EzloZeldaMagic
	SetSyncFlag 0x00000040
SCRIPT_END
	.2byte 0x0000
