@ Intro Hyrule Town Townsperson
SCRIPT_START script_TownsperonIntro
	BeginBlock
	Call sub_08061FE4
	_0807E9D4
	DoPostScriptAction 0x000a
	EndBlock
script_0800F564:
	CheckEntityInteractType
	JumpIfNot script_0800F564
	_0807E864
	_0807EB74
	Call sub_08061FE4
	Call sub_08061FF4
	WaitUntilTextboxCloses
	_0807E878
	Jump script_0800F564
	.2byte 0x0000
