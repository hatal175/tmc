@ Intro Assembly Guard
SCRIPT_START script_GuardAtAssembly
	BeginBlock
	_0807EB44 0x0000
	_0807E930 0x0000
	EndBlock
	WaitForSyncFlag 0x00000010
	PlaySound SFX_11C
	_0807E930 0x0001
	Wait 0x0010
	PlaySound SFX_11C
	_0807EB44 0x0004
	_0807E930 0x0006
	Wait 0x0010
	DoPostScriptAction 0x000f
	SetEntitySpeed 0x0200
	_0807ECC4 0x1c20
	DoPostScriptAction 0x0006
SCRIPT_END
