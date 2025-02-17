@ Hyrule Town Carlov
SCRIPT_START script_Carlov2
	BeginBlock
	_0807E9D4
	_0807EB44 0x0004
	SetEntityDirection 0x0000
	DoPostScriptAction 0x000a
	EndBlock
script_0801463A:
	_0807E30C
.ifdef EU
	JumpIf script_080146E2
.else
	JumpIf script_080146A0
.endif
	CheckSyncFlagAndClear 0x00000004
	JumpIf script_0801477A
.ifdef EU
	CheckPlayerInRegion 0x0078, 0x0078, 0x0810
	JumpIfNot script_0801463A
	CheckRoomFlag 0x0009
	JumpIfNot script_0801463A
	_0807E864
	_0807EB28 0x431f
	WaitUntilTextboxCloses
script_0801469A:
	StartPlayerScript script_PlayerAtCarlov
	Wait 0x0010
	SetSyncFlag 0x00000002
	WaitForSyncFlagAndClear 0x00000001
	_0807E878
	Jump script_0801463A
script_080146E2:
	_0807E864
	_0807E930 0x0008
	Wait 0x0020
	_0807E930 0x0002
	CheckGlobalFlag 0x0059
	JumpIf script_0801472E_2
	CheckRoomFlag 0x0009
	JumpIf script_080146F4
	CheckLocalFlag 0x005c
	JumpIfNot script_080146FE
	CheckLocalFlag 0x005e
	JumpIfNot script_0801474A
	CheckRoomFlag 0x0006
	JumpIf script_0801472E
	CheckLocalFlag 0x005f
	JumpIf script_08014720
	Call sub_08088574
	SetRoomFlag 0x000a
	Jump script_0801473C
script_0801472E_2:
	MessageFromTargetPos 0x432f, 0x000c
	Jump script_080147CE
.else
	CheckRoomFlag 0x0004
	JumpIf script_08014672
	Call sub_0808861C
	JumpIfNot script_0801463A
	CheckLocalFlag 0x005e
	JumpIf script_080146A0
	_0807E864 
	_0807EB8C 
	MessageFromTargetPos 0x432b, 0x000c
	Jump script_080147CE
script_08014672:
.ifdef DEMO_JP
	Call sub_08088658
.else
.ifdef JP
	CheckPlayerInRegion 0x0078, 0x0078, 0x0810
.else
	Call sub_08088658
.endif
.endif
	JumpIfNot script_0801463A
	_0807E864
	_0807EB28 0x431f
	WaitUntilTextboxCloses
	StartPlayerScript script_PlayerAtCarlov
	Wait 0x0010
	SetSyncFlag 0x00000002
	WaitForSyncFlagAndClear 0x00000001
	_0807E878
	Jump script_0801463A
script_080146A0:
	_0807E864
	_0807E930 0x0008
	Wait 0x0010
	_0807EB8C
	Wait 0x0010
	_0807E930 0x0002
	CheckGlobalFlag 0x0059
	JumpIfNot script_080146C6
	MessageFromTargetPos 0x432f, 0x000c
	Jump script_080147CE
script_080146C6:
	CheckRoomFlag 0x0004
	JumpIf script_080146F4
	CheckLocalFlag 0x005e
	JumpIfNot script_080146FE
	CheckRoomFlag 0x0006
	JumpIf script_0801472E
	CheckLocalFlag 0x005f
	JumpIf script_08014720
	Call sub_08088574
	SetRoomFlag 0x0009
	Jump script_0801473C
.endif

script_080146F4:
	MessageFromTargetPos 0x431e, 0x000c
	Jump script_080147CE
script_080146FE:
.ifdef EU
	SetRoomFlag 0x000A
.else
	SetRoomFlag 0x0009
.endif
	SetLocalFlag 0x005c
.ifdef EU
script_0801474A:
	SetRoomFlag 0x000a
.endif
	MessageFromTargetPos 0x4305, 0x000c
	WaitUntilTextboxCloses
	_0807E3BC 0x0001
	JumpIfNot script_080147C4
	MessageFromTargetPos 0x4306, 0x000c
	Jump script_0801473C
script_08014720:
.ifdef EU
	SetRoomFlag 0x000A
.else
	SetRoomFlag 0x0009
.endif
	Call sub_08088504
	Jump script_0801473C
script_0801472E:
.ifdef EU
	SetRoomFlag 0x000A
.else
	SetRoomFlag 0x0009
.endif
	ClearRoomFlag 0x0006
	Call sub_08088544
script_0801473C:
	CheckTextboxResult
	JumpIfNot script_08014770
	WaitUntilTextboxCloses
	_0807E3BC 0x0001
	JumpIfNot script_080147C4
	SetRoomFlag 0x0001
	Wait 0x0014
script_08014754:
	CheckRoomFlag 0x0003
	JumpIfNot script_08014754
	ClearRoomFlag 0x0003
	WaitUntilTextboxCloses
.ifdef EU
	SetRoomFlag 0x0009
.else
	SetRoomFlag 0x0004
.endif
	MessageFromTargetPos 0x431e, 0x000c
	Jump script_080147CE
script_08014770:
.ifdef EU
	SetRoomFlag 0x000A
.else
	SetRoomFlag 0x0009
.endif
	WaitUntilTextboxCloses
	Jump script_080147CE
script_0801477A:
	CheckRoomFlag 0x0008
	JumpIf script_080147B4
	CheckRoomFlag 0x0007
	JumpIf script_080147A4
script_0801478A:
	Call sub_08088478
	WaitUntilTextboxCloses
	Call sub_080885B0
	WaitPlayerGetItem
	SetSyncFlag 0x00000008
	Jump script_080147CE
script_080147A4:
	_0807E930 0x0009
	Wait 0x003c
	_0807E930 0x0002
	Jump script_0801478A
script_080147B4:
	_0807E930 0x000a
	Wait 0x008c
	_0807E930 0x0002
	Jump script_0801478A
script_080147C4:
.ifdef EU
	SetRoomFlag 0x000A
.else
	SetRoomFlag 0x0009
.endif
	MessageFromTargetPos 0x4307, 0x000c
script_080147CE:
	WaitUntilTextboxCloses
.ifdef EU
	Wait 0x000F
.else
	Wait 0x0004
.endif
	_0807E878
	Jump script_0801463A
	.align 2, 0
