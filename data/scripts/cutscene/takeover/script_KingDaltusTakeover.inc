@ Western Wood Cutscene King Daltus
SCRIPT_START script_KingDaltusTakeover
	BeginBlock
	_0807EB44 0x0004
	DoPostScriptAction 0x0000
	EndBlock
	WaitForSyncFlagAndClear 0x00000004
	DoPostScriptAction 0x0004
	Wait 0x003c
	MessageNoOverlap 0x1319
	WaitUntilTextboxCloses
	SetSyncFlag 0x00000008
	WaitForSyncFlagAndClear 0x00000004
	MessageNoOverlap 0x131a
	WaitUntilTextboxCloses
	SetSyncFlag 0x00000008
	WaitForSyncFlagAndClear 0x00000004
	MessageNoOverlap 0x131d
	WaitUntilTextboxCloses
	SetSyncFlag 0x00000008
	WaitForSyncFlagAndClear 0x00000004
	MessageNoOverlap 0x131e
	WaitUntilTextboxCloses
	SetSyncFlag 0x00000008
	WaitForSyncFlag 0x00000400
	DoPostScriptAction 0x0006
SCRIPT_END
