@ Sanctuary NPC4E Intro Cutscene
SCRIPT_START script_Npc4ESanctuaryIntro
	EndBlock
script_08013CA6:
	CheckPlayerInRegion 0x00e8, 0x01e8, 0x4080
	JumpIfNot script_08013CA6
	_0807E864
	Call sub_0807F9A4
	Call sub_0807DF28
	Call sub_0807F3F8
	Wait 0x003c
	_0807F0B4 0x0001
	SetEntityPositionRelative 0x00e8, 0x0138
	CameraTargetEntity
	Call sub_0807F5C0
	Wait 0x0078
	_0807F0B4 0x0004
	CameraTargetPlayer
	Call sub_0807F5C0
	_0807EB28 0x1504
	WaitUntilTextboxCloses
	SetLocalFlag 0x0079
	Call sub_0807DF50
	_0807E878
	DoPostScriptAction 0x0006
SCRIPT_END
