@ Veil Falls BigGoron 3
SCRIPT_START script_BigGoron3
	BeginBlock
	_0807E9D4
	EndBlock
script_0800934E:
	CheckEntityInteractType
	JumpIfNot script_0800934E
	_0807E864
	Call sub_0807DF28
	Call sub_0806D638
	_0807F0B4 0x0001
	CameraTargetEntity
	CheckGlobalFlag 0x0055
	JumpIf script_BigGoronTalk
	MessageNoOverlap 0x1d01
	WaitUntilTextboxCloses
script_08009376:
	WaitUntilTextboxCloses
	Call sub_0806D640
	_0807F0B4 0x0001
	CameraTargetPlayer
	Wait 0x002d
	_0807F0B4 0x0004
	_0807E878
	Call sub_0807DF50
	Jump script_0800934E
SCRIPT_END
