@ Ezlo Cutscene Vaati
SCRIPT_START script_Vaati
	BeginBlock
	DoPostScriptAction 0x0007
	DoPostScriptAction 0x000b
	_0807EB44 0x0000
	DoPostScriptAction 0x0017
	Call sub_0807F180
	EndBlock
	WaitForSyncFlagAndClear 0x00000800
	_0807EB44 0x0002
	DoPostScriptAction 0x0017
	Wait 0x000a
	_0807EB44 0x0004
	DoPostScriptAction 0x0017
	_0807EB44 0x0004
	DoPostScriptAction 0x001b
	SetSyncFlag 0x00001000
	WaitForSyncFlagAndClear 0x00000800
	Wait 0x0078
	DoPostScriptAction 0x0004
	Wait 0x0014
	SetSyncFlag 0x00001000
	WaitForSyncFlagAndClear 0x00000800
	DoPostScriptAction 0x0018
	Call sub_0807F2D4
	_0807EB44 0x0004
	DoPostScriptAction 0x0000
	SetSyncFlag 0x00001000
	WaitForSyncFlagAndClear 0x00000800
	_0807EB44 0x0004
	DoPostScriptAction 0x0014
	CallWithArg sub_0809545C, script_Object6ADarkMagic
	PlaySound SFX_1C4
	Wait 0x0078
	DoPostScriptAction 0x0016
	WaitForSyncFlagAndClear 0x00020000
	_0807EB44 0x0004
	DoPostScriptAction 0x0000
	SetSyncFlag 0x00001000
	WaitForSyncFlagAndClear 0x00000800
	Call sub_08066CA4
	DoPostScriptAction 0x0008
	Wait 0x0078
	SetSyncFlag 0x00001000
	DoPostScriptAction 0x0006
SCRIPT_END
