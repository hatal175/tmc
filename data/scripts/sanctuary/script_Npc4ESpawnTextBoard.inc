@ Sanctuary NPC4E spawn text board
SCRIPT_START script_Npc4ESpawnTextBoard
	Call sub_0807F3F8
	Wait 0x003c
	_0807F0B4 0x0007
	SetEntityPositionRelative 0x00e8, 0x00a8
	CameraTargetEntity
	Wait 0x003c
	SetSyncFlag 0x00000004
	Wait 0x0078
	CallWithArg DeleteManager36, 0x00000001
	_0807F0C8 0x0000, 0x0000
	StartPlayerScript script_PlayerTextBoardAppears
	WaitForSyncFlagAndClear 0x00000002
	_0807EB28 0x1501
	WaitUntilTextboxCloses
	_0807F0B4 0x0004
	CameraTargetPlayer
	SetLocalFlag 0x007a
	Call sub_08053250
	Call sub_0807DF50
	_0807E878
	DoPostScriptAction 0x0006
SCRIPT_END
