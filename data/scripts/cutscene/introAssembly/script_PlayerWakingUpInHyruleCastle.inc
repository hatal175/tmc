@ Intro Hyrule Castle Player Sleeping
SCRIPT_START script_PlayerWakingUpInHyruleCastle
	BeginBlock
	Call sub_0807DF28
	_0807E864
.ifdef JP
	SetLocalFlag 0x009e
.else
.ifdef EU
	SetLocalFlag 0x009e
.else
.ifdef DEMO_JP
	SetLocalFlag 0x009e @ TODO deduplicate
.else
	SetLocalFlag 0x009f
.endif
.endif
.endif
	EndBlock
	Wait 0x003c
	_0807E778 0x0004
	DoFade4
	WaitForFadeFinish
script_08009EA4:
	Call sub_0807F0D8
	JumpIfNot script_08009EA4
	DoPostScriptAction 0x0014
	Wait 0x000a
	Call sub_08053250
	_0807E878
	Call sub_0807DF50
	Call sub_080791D0
SCRIPT_END
