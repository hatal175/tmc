@ Cloud Tops Windtribespeople
SCRIPT_START script_WindTribespeople7
	BeginBlock
	CheckGlobalFlag 0x0024
	JumpIf script_08014CD4
	Call sub_0806C870
	DoPostScriptAction 0x000a
	DoPostScriptAction 0x0000
	EndBlock
script_08014CAE:
	EndBlock
	BeginBlock
	CheckGlobalFlag 0x0024
	JumpIf script_08014CD4
	_0807E30C
	JumpIfNot script_08014CAE
	EndBlock
	_0807E864
	_0807EB74
	Call sub_0806C90C
	WaitUntilTextboxCloses
	_0807E878
	Jump script_08014CAE
script_08014CD4:
	DoPostScriptAction 0x0006
SCRIPT_END
	.2byte 0x0000
