@ Western Wood Cutscene Vaati
SCRIPT_START script_VaatiTakeover
	BeginBlock
	DoPostScriptAction 0x0008
	_0807EB44 0x0004
	DoPostScriptAction 0x0000
	DoPostScriptAction 0x001d
	EndBlock
	WaitForSyncFlagAndClear 0x00000010
	Call sub_08066C94
	Wait 0x00e9
	DoPostScriptAction 0x0007
	DoPostScriptAction 0x001e
	Wait 0x0014
	_0807EB44 0x0000
	DoPostScriptAction 0x001c
	Call sub_0807F2D4
	DoPostScriptAction 0x0000
	SetSyncFlag 0x00000020
	WaitForSyncFlagAndClear 0x00000010
	Call sub_08066CA4
	DoPostScriptAction 0x0008
	Wait 0x00bc
	SetSyncFlag 0x00000020
	WaitForSyncFlagAndClear 0x00000010
	SetEntityPositionRelative 0x0088, 0x0068
	Call sub_08066C94
	Wait 0x00e8
	DoPostScriptAction 0x0007
	DoPostScriptAction 0x001e
	Wait 0x0014
	SetSyncFlag 0x00000020
	WaitForSyncFlagAndClear 0x00000010
	DoPostScriptAction 0x0014
	Wait 0x001e
	MessageNoOverlap 0x131b
	WaitUntilTextboxCloses
	SetSyncFlag 0x00000020
	WaitForSyncFlagAndClear 0x00000010
	DoPostScriptAction 0x0006
SCRIPT_END
