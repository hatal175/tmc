@ Ezlo talk after Wind Ruins
SCRIPT_START script_EzloTalkFoW
	_0807E864
	Call sub_0807DF28
	_0807EB28 0x1c03
	WaitUntilTextboxCloses
	SetLocalFlagByBank 0x0100, 0x0003
	Call sub_0807DF50
	_0807E878
	DoPostScriptAction 0x0006
SCRIPT_END
	.2byte 0x0000
