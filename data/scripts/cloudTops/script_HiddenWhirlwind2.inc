@ Cloud Tops Whirlwind hidden in clouds
SCRIPT_START script_HiddenWhirlwind2
	BeginBlock
.ifdef JP
	CheckLocalFlag 0x00f2
.else
.ifdef EU
	CheckLocalFlag 0x00f2
.else
.ifdef DEMO_JP
	CheckLocalFlag 0x00f2 @ TODO deduplicate
.else
	CheckLocalFlag 0x00f5
.endif
.endif
.endif
	JumpIf script_0800D6E8
	DoPostScriptAction 0x0008
	EndBlock
script_0800D700:
.ifdef JP
	CheckLocalFlag 0x00f2
.else
.ifdef EU
	CheckLocalFlag 0x00f2
.else
.ifdef DEMO_JP
	CheckLocalFlag 0x00f2 @ TODO deduplicate
.else
	CheckLocalFlag 0x00f5
.endif
.endif
.endif
	JumpIfNot script_0800D700
	DoPostScriptAction 0x0007
SCRIPT_END
	.2byte 0x0000
