@ Some Forest Minish?
SCRIPT_START script_ForestMinish19
	SetEntitySpeed 0x0100
script_0801679C:
	WaitForSyncFlag 0x00000002
	ClearSyncFlag 0x00000002
	_0807EC94 0x0030
	SetSyncFlag 0x00000004
	Wait 0x000f
	DoPostScriptAction 0x0000
	_0807EB44 0x0004
	WaitForSyncFlag 0x00000002
	ClearSyncFlag 0x00000002
	DoPostScriptAction 0x0003
	Wait 0x0002
	_0807EB44 0x0006
	Wait 0x0002
	_0807EB44 0x0000
	Wait 0x0002
	_0807EB44 0x0002
	Wait 0x0002
	_0807EB44 0x0004
	WaitForSyncFlag 0x00000002
	ClearSyncFlag 0x00000002
	_0807ECF4 0x0030
	SetSyncFlag 0x00000001
	Wait 0x000f
	DoPostScriptAction 0x0000
	_0807EB44 0x0004
	WaitForSyncFlag 0x00000002
	ClearSyncFlag 0x00000002
	DoPostScriptAction 0x0003
	Wait 0x0002
	_0807EB44 0x0006
	Wait 0x0002
	_0807EB44 0x0000
	Wait 0x0002
	_0807EB44 0x0002
	Wait 0x0002
	_0807EB44 0x0004
	Jump script_0801679C
