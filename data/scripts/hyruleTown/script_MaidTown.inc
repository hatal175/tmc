@ Hyrule Town Maid
SCRIPT_START script_MaidTown
	BeginBlock
	_0807E9D4
	_0807EB44 0x0004
	DoPostScriptAction 0x0000
	DoPostScriptAction 0x000a
	SetIntVariable sub_08064688
	Call sub_08064644
	EndBlock
script_08010446:
	Wait 0x003c
	Call sub_080646A4
	Jump script_08010446
