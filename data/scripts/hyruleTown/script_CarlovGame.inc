@ Carlov in Chest room
SCRIPT_START script_CarlovGame
	BeginBlock
	_0807E9D4
	_0807EB44 0x0000
	DoPostScriptAction 0x000a
	EndBlock
	_0807E864
	Call sub_0807DF38
	Wait 0x0010
	CheckLocalFlag 0x0093
	JumpIf script_080148B6
	MessageFromTargetPos 0x4215, 0x000c
	_0807E878 
script_0801482E:
	CheckSyncFlagAndClear 0x00000001
	JumpIf script_08014862
	CheckSyncFlagAndClear 0x00000004
	JumpIf script_08014878
	_0807E30C
	JumpIfNot script_0801482E
	_0807E864
	_0807E930 0x0008
	Wait 0x0020
	_0807E930 0x0002
	MessageFromTargetPos 0x4215, 0x000c
	_0807E878 
	Jump script_0801482E
script_08014862:
	_0807E930 0x0008
	Wait 0x0020
	_0807E930 0x0002
	SetSyncFlag 0x00000002
	Jump script_0801482E
script_08014878:
	_0807E930 0x0009
	Wait 0x003c
	_0807E930 0x0002
	SetSyncFlag 0x00000008
	Jump script_0801482E
script_0801488E:
	CheckSyncFlagAndClear 0x00000001
	JumpIf script_080148C2
	CheckSyncFlagAndClear 0x00000004
	JumpIf script_080148D8
	_0807E30C
	JumpIfNot script_0801488E
	_0807E864
	_0807E930 0x0008
	Wait 0x0020
	_0807E930 0x0002
script_080148B6:
	MessageFromTargetPos 0x4216, 0x000c
	_0807E878 
	Jump script_0801488E
script_080148C2:
	_0807E930 0x0008
	Wait 0x0020
	_0807E930 0x0002
	SetSyncFlag 0x00000002
	Jump script_0801488E
script_080148D8:
	_0807E930 0x0009
	Wait 0x003c
	_0807E930 0x0002
	SetSyncFlag 0x00000008
	Jump script_0801488E
	.2byte 0x0000
