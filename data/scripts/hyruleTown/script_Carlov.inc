@ Hyrule Town Carlov
SCRIPT_START script_Carlov
	BeginBlock
	_0807E9D4
	_0807EB44 0x0000
	SetEntitySpeed 0x01c0
	DoPostScriptAction 0x000a
	EndBlock
script_08014462:
	_0807E30C
	JumpIfNot script_08014462
	_0807E864
	_0807E930 0x0008
	Wait 0x0020
	_0807E930 0x0002
	MessageFromTarget 0x4202
	MessageFromTarget 0x4203
	WaitUntilTextboxCloses
	CheckTextboxResult 
	JumpIfNot script_080144F0
	DoPostScriptAction 0x0001
	Wait 0x008c
	DoPostScriptAction 0x0000
	HasRupees 0x000a
	JumpIf script_080144A2
	MessageFromTarget 0x4204
	Jump script_080144FC
script_080144A2:
	Call sub_0806E250
	JumpIfNot script_080144B8
	MessageFromTarget 0x420b
	_0807EB38 
	JumpTable script_080144B8, script_080144C0
script_080144B8:
	ClearLocalFlag 0x0093
	Jump script_080144C8
script_080144C0:
	SetLocalFlag 0x0093
.ifdef USA
	SetLocalFlag 0x00d3
.else
.ifdef DEMO_USA
	SetLocalFlag 0x00d3
.endif
.endif
script_080144C8:
	ModRupees 0xfff6
	MessageFromTarget 0x420c
	PlaySound SFX_10C
	Wait 0x0018
	SetRoomFlag 0x0000
	SetLocalFlag 0x0092
	_0807EEF4 0x0000, 0xffa0
	Call sub_0807DF38
	Jump script_080144FC
script_080144F0:
	_0807E930 0x0009
	Wait 0x003c
	_0807E930 0x0002
script_080144FC:
	_0807E878
	CheckRoomFlag 0x0000
	JumpIfNot script_08014462
.ifdef USA
	_0807E9DC
.else
.ifdef DEMO_USA
	_0807E9DC
.else
.ifdef DEMO_JP
	_0807E9DC
.endif
.endif
.endif
SCRIPT_END
	.align 2, 0

