@ Player at Librari move on trap
SCRIPT_START script_PlayerStepOnTrap
	BeginBlock
	_0807EB44 0x0004
	SetEntitySpeed 0x0100
	EndBlock
	DoPostScriptAction 0x0001
	_0807EDD4 0x0078, 0x0080
	DoPostScriptAction 0x0000
	SetSyncFlag 0x00000001
	Call sub_080791BC
SCRIPT_END
