@ Intro Outside Castle Business Scrub
SCRIPT_START script_BusinessScrubIntro
	BeginBlock
	DoPostScriptAction 0x0007
	DoPostScriptAction 0x000a
	_0807EB44 0x0004
	DoPostScriptAction 0x0000
	EndBlock
	WaitForSyncFlagAndClear 0x00000008
	_0807E908 0x0007
	WaitForSyncFlagAndClear 0x00000008
	_0807E908 0x0006
	SetRoomFlag 0x0000
	_0807EB44 0x0004
	DoPostScriptAction 0x0000
	WaitForSyncFlagAndClear 0x00000008
	Wait 0x003c
	PlaySound SFX_SECRET
	Call sub_08046078
	DoPostScriptAction 0x0006
SCRIPT_END
	.2byte 0x0000
