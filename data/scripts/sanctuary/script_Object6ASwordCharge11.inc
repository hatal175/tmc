@ Sanctuary third time OBJECT_6A ?
SCRIPT_START script_Object6ASwordCharge11
	CheckSyncFlagAndClear 0x00020000
	JumpIf script_08014264
	Wait 0x0008
	CallWithArg sub_08095EAC, 0x00000000
	Jump script_Object6ASwordCharge11
script_08014264:
	CallWithArg sub_08095EAC, 0x00000001
	Jump script_08014264
	.align 2, 0
