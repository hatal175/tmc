@ Outro MinishEzlo after fixing everything
SCRIPT_START script_MinishEzloGoodbye
	BeginBlock
	SetEntitySpeed 0x0080
	DoPostScriptAction 0x0007
	DoPostScriptAction 0x000b
	_0807EB44 0x0004
	CallWithArg sub_0807F3D8, 0x00000000
	EndBlock
	WaitForSyncFlagAndClear 0x00000002
	DoPostScriptAction 0x0004
	Wait 0x001e
	_0807EB44 0x0002
	CallWithArg sub_0807F3D8, 0x00000000
	Wait 0x0006
	_0807EB44 0x0000
	CallWithArg sub_0807F3D8, 0x00000000
	SetSyncFlag 0x00000004
	WaitForSyncFlagAndClear 0x00000002
	_0807EB44 0x0002
	CallWithArg sub_0807F3D8, 0x00000000
	Wait 0x0014
	_0807EB44 0x0004
	CallWithArg sub_0807F3D8, 0x00000000
	SetSyncFlag 0x00000004
	WaitForSyncFlagAndClear 0x00000002
	_0807E930 0x000c
	Call sub_0807F2D4
	Call sub_08094B94
	SetSyncFlag 0x00000004
	WaitForSyncFlagAndClear 0x00000002
	_0807E930 0x000f
	Call sub_0807F2D4
	SetSyncFlag 0x00000004
	WaitForSyncFlagAndClear 0x00000002
	CallWithArg sub_080960C4, script_Object6AEzloFinalMagic
	_0807E930 0x0012
	Call sub_0807F2D4
	Wait 0x001e
	SetSyncFlag 0x00000020
	StopBgm
	Call CreateDust
	Call sub_0806305C
	Call sub_080630A4
	_0807EF3C 0x0000, 0x0020
	Wait 0x001e
	SetSyncFlag 0x00000004
	WaitForSyncFlagAndClear 0x00000002
	SetEntitySpeed 0x0080
	_0807EEF4 0x0000, 0xfff0
	Wait 0x003c
	_0807EEF4 0x0000, 0xfff0
	SetSyncFlag 0x00000004
	WaitForSyncFlagAndClear 0x00000002
	_0807EDD4 0x0088, 0x0040
	SetSyncFlag 0x00000004
	DoPostScriptAction 0x0006
SCRIPT_END
