@ Bomb Forest Minish during Kinstone cutscene
SCRIPT_START script_BombMinishKinstone
	BeginBlock
	_0807EB44 0x0004
	DoPostScriptAction 0x0000
	Call sub_0807F348
	EndBlock
script_0800BB42:
	CheckRoomFlag 0x00ff
	JumpIfNot script_0800BB42
	DoPostScriptAction 0x0004
	Wait 0x003c
	MessageNoOverlap 0x0e05
	WaitUntilTextboxCloses
	Wait 0x0078
	Call sub_08054968
SCRIPT_END
