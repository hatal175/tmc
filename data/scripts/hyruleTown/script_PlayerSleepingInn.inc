@ Player sleeping at Inn
SCRIPT_START script_PlayerSleepingInn
	BeginBlock
	Call sub_0807DF28
	_0807E864
	ModHealth 0x00a0
	EndBlock
	Wait 0x003c
	_0807E778 0x0004
	DoFade4
	WaitForFadeFinish
script_08010A78:
	Call sub_0807F0D8
	JumpIfNot script_08010A78
	DoPostScriptAction 0x0014
	_0807E878
	Call sub_0807DF50
	Call sub_080791D0
SCRIPT_END
	.2byte 0x0000
