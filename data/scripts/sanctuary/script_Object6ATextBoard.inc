@ Sanctuary OBJECT_6A text board
SCRIPT_START script_Object6ATextBoard
	BeginBlock
	CheckLocalFlag 0x007a
	JumpIf script_08013C2A
	CheckInventory1 0x0003
	JumpIf script_08013C2A
	CheckInventory1 0x0002
	JumpIfNot script_08013C98
	CheckInventory1 0x0040
	JumpIfNot script_08013C98
	CheckInventory1 0x0041
	JumpIfNot script_08013C98
	EndBlock
	DoPostScriptAction 0x0008
	WaitForSyncFlagAndClear 0x00000004
	_0807E908 0x0002
	PlaySound SFX_134
	Jump script_08013C32
script_08013C2A:
	CheckLocalFlag 0x007c
	JumpIf script_08013C98
script_08013C32:
	BeginBlock
	DoPostScriptAction 0x0007
	Call sub_0807F934
	DoPostScriptAction 0x000a
	CallWithArg sub_080962F8, 0x00000000
.ifndef EU
	CallWithArg sub_0807F8E8, 0x00000004
.endif
	EndBlock
script_08013C58:
	EndBlock
	BeginBlock
	CheckSyncFlagAndClear 0x00000008
	JumpIf script_08013C92
	CheckEntityInteractType
	JumpIfNot script_08013C58
	EndBlock
	_0807E864
	_0807EB74
	CheckLocalFlag 0x007d
	JumpIf script_08013C82
	_0807EB28 0x1501
	Jump script_08013C86
script_08013C82:
	_0807EB28 0x1506
script_08013C86:
	WaitUntilTextboxCloses
	Wait 0x000f
	_0807E878
	Jump script_08013C58
script_08013C92:
	EndBlock
	_0807E908 0x0004
script_08013C98:
	DoPostScriptAction 0x0008
	DoPostScriptAction 0x0006
SCRIPT_END
	.align 2, 0
