	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	.code 16

.global RAMFUNCS_BASE
RAMFUNCS_BASE::

sub_080B197C:: @ 0x080B197C
	push {r4, r5, r6}
	ldr r2, _080B19C0 @ =gRoomControls
	ldrh r3, [r2, #0xa]
	ldrh r4, [r2, #6]
	subs r3, r3, r4
	ldrh r4, [r2, #0xc]
	ldrh r2, [r2, #8]
	subs r4, r4, r2
	adds r5, r4, #0
	lsrs r3, r3, #4
	lsrs r4, r4, #4
	lsls r4, r4, #7
	adds r3, r3, r4
	lsls r3, r3, #2
	adds r0, r0, r3
	subs r1, #0x40
	ldr r2, _080B19C4 @ =0x80000020
	ldr r3, _080B19C8 @ =0x040000D4
	movs r4, #1
	lsls r4, r4, #8
	movs r6, #0x17
	cmp r5, #8
	bhs _080B19AE
	stm r3!, {r0, r1, r2}
	b _080B19B4
_080B19AE:
	subs r0, r0, r4
_080B19B0:
	stm r3!, {r0, r1, r2}
	adds r0, r0, r4
_080B19B4:
	subs r3, #0xc
	adds r1, #0x40
	subs r6, #1
	bne _080B19B0
	pop {r4, r5, r6}
	bx lr
	.align 2, 0
_080B19C0: .4byte gRoomControls
_080B19C4: .4byte 0x80000020
_080B19C8: .4byte 0x040000D4

@ r0 = entity*
	arm_func_start _GetTileAtEntityPos
_GetTileAtEntityPos: @ 0x080B19CC
	ldrb r2, [r0, #0x38] @ obj layer
	ldrh r1, [r0, #0x32] @ obj y
	ldrh r0, [r0, #0x2e] @ obj x
	ldr ip, _080B1C10 @ =gRoomControls
	ldrh r3, [ip, #6]
	sub r0, r0, r3 @ obj x - room x
	ldrh r3, [ip, #8]
	sub r1, r1, r3 @ obj y - room y
	lsl r0, r0, #0x16
	lsr r0, r0, #0x1a
	lsl r1, r1, #0x16
	lsr r1, r1, #0x1a
	add r0, r0, r1, lsl #6
	mov r1, r2
	ldr r2, _080B1C14 @ =gUnk_08000258
	b _080B1A64

	arm_func_start sub_080B1A0C
sub_080B1A0C: @ 0x080B1A0C
	ldrh r3, [r0, #0x2e]
	add r3, r3, r1
	ldrh r1, [r0, #0x32]
	add r1, r1, r2
	ldrb r2, [r0, #0x38]
	mov r0, r3
	b _080B1A34
_080B1A28:
	ldrb r2, [r0, #0x38]
	ldrh r1, [r0, #0x32]
	ldrh r0, [r0, #0x2e]
_080B1A34:
	ldr ip, _080B1C18 @ =gRoomControls
	ldrh r3, [ip, #6]
	sub r0, r0, r3
	ldrh r3, [ip, #8]
	sub r1, r1, r3
	lsl r0, r0, #0x16
	lsr r0, r0, #0x1a
	lsl r1, r1, #0x16
	lsr r1, r1, #0x1a
	add r0, r0, r1, lsl #6
	mov r1, r2

	arm_func_start _GetTileType
_GetTileType: @ 0x080B1A60
	ldr r2, _080B1C1C @ =gUnk_08000228
_080B1A64:
	add r2, r2, r1, lsl #3
	ldr r1, [r2]
	lsl r0, r0, #1
	ldrh r0, [r1, r0]
	cmp r0, #0x4000 @ return tile index is OOB
	bxhs lr
	ldr r1, [r2, #4]
	lsl r0, r0, #1
	ldrh r0, [r1, r0]
	bx lr

	arm_func_start sub_080B1A8C
sub_080B1A8C: @ 0x080B1A8C
	ldrh r3, [r0, #0x2e]
	add r3, r3, r1
	ldrh r1, [r0, #0x32]
	add r1, r1, r2
	ldrb r2, [r0, #0x38]
	mov r0, r3
	b _080B1AB4
_080B1AA8:
	ldrb r2, [r0, #0x38]
	ldrh r1, [r0, #0x32]
	ldrh r0, [r0, #0x2e]
_080B1AB4:
	ldr ip, _080B1C20 @ =gRoomControls
	ldrh r3, [ip, #6]
	sub r0, r0, r3
	ldrh r3, [ip, #8]
	sub r1, r1, r3
	lsl r0, r0, #0x16
	lsr r0, r0, #0x1a
	lsl r1, r1, #0x16
	lsr r1, r1, #0x1a
	add r0, r0, r1, lsl #6
	mov r1, r2
	ldr r2, _080B1C24 @ =gUnk_08000278
	ldr r2, [r2, r1, lsl #2]
	ldrb r0, [r2, r0]
	bx lr

	arm_func_start sub_080B1AF0
sub_080B1AF0: @ 0x080B1AF0
	ldrh r3, [r0, #0x2e]
	add r3, r3, r1
	ldrh r1, [r0, #0x32]
	add r1, r1, r2
	ldrb r2, [r0, #0x38]
	mov r0, r3
	b _080B1B18
_080B1B0C:
	ldrb r2, [r0, #0x38]
	ldrh r1, [r0, #0x32]
	ldrh r0, [r0, #0x2e]
_080B1B18:
	ldr ip, _080B1C28 @ =gRoomControls
	ldrh r3, [ip, #6]
	sub r0, r0, r3
	ldrh r3, [ip, #8]
	sub r1, r1, r3
	lsl r0, r0, #0x16
	lsr r0, r0, #0x1a
	lsl r1, r1, #0x16
	lsr r1, r1, #0x1a
	add r0, r0, r1, lsl #6
	mov r1, r2
	ldr r2, _080B1C2C @ =gUnk_08000248
	ldr r1, [r2, r1, lsl #2]
	ldrb r0, [r1, r0]
	bx lr

	arm_func_start sub_080B1B54
sub_080B1B54: @ 0x080B1B54
	lsls r0, r0, #0x12
	ldrlo r1, _080B1C30 @ =gUnk_080B37A0
	ldrhs r1, _080B1C34 @ =gUnk_080B7910
	ldrb r0, [r1, r0, lsr #18]
	bx lr

	arm_func_start sub_080B1B68
sub_080B1B68: @ 0x080B1B68
	lsrs r2, r0, #0xe
	bxne lr
	ldr r2, _080B1C38 @ =gUnk_0800022C
	ldr r1, [r2, r1, lsl #3]
	lsl r0, r0, #1
	ldrh r0, [r1, r0]
	bx lr

	arm_func_start sub_080B1B84
sub_080B1B84: @ 0x080B1B84
	mov ip, lr
	bl _GetTileType
	lsls r0, r0, #0x12
	ldrlo r1, _080B1C3C @ =gUnk_08000360
	ldrhs r1, _080B1C40 @ =gUnk_080B7A3E
	lsr r0, r0, #0x11
	ldrh r0, [r1, r0]
	bx ip

	arm_func_start sub_080B1BA4
sub_080B1BA4: @ 0x080B1BA4
	mov ip, lr
	mov r3, r2
	bl _GetTileType
	lsls r0, r0, #0x12
	ldrlo r1, _080B1C44 @ =gUnk_08000360
	ldrhs r1, _080B1C48 @ =gUnk_080B7A3E
	lsr r0, r0, #0x11
	ldrh r0, [r1, r0]
	and r0, r0, r3
	bx ip

	arm_func_start sub_080B1BCC
sub_080B1BCC: @ 0x080B1BCC
	ldrh r3, [r0, #0x2e]
	add r1, r1, r3
	ldrh r3, [r0, #0x32]
	add r2, r2, r3
	ldr ip, _080B1C4C @ =gRoomControls
	ldrh r3, [ip, #6]
	sub r1, r1, r3
	ldrh r3, [ip, #8]
	sub r2, r2, r3
	and r1, r1, #0x3f0
	and r2, r2, #0x3f0
	add r1, r1, r2, lsl #6
	ldr r2, _080B1C50 @ =gUnk_08000278
	ldrb r3, [r0, #0x38]
	ldr r2, [r2, r3, lsl #2]
	ldrb r0, [r2, r1, lsr #4]
	bx lr
	.align 2, 0
_080B1C10: .4byte gRoomControls
_080B1C14: .4byte gUnk_08000258
_080B1C18: .4byte gRoomControls
_080B1C1C: .4byte gUnk_08000228
_080B1C20: .4byte gRoomControls
_080B1C24: .4byte gUnk_08000278
_080B1C28: .4byte gRoomControls
_080B1C2C: .4byte gUnk_08000248
_080B1C30: .4byte gUnk_080B37A0
_080B1C34: .4byte gUnk_080B7910
_080B1C38: .4byte gUnk_0800022C
_080B1C3C: .4byte gUnk_08000360
_080B1C40: .4byte gUnk_080B7A3E
_080B1C44: .4byte gUnk_08000360
_080B1C48: .4byte gUnk_080B7A3E
_080B1C4C: .4byte gRoomControls
_080B1C50: .4byte gUnk_08000278

	arm_func_start UpdateCollision
UpdateCollision: @ 0x080B1C54
	@ r0 : Entity* this
	ldrb r1, [r0, #0x10]
	ands r1, r1, #0x80 @ disable collision flag
	bxeq lr
	ldr r2, _080B200C @ =gCollidableList
	ldr r3, _080B2010 @ =gCollidableCount
	ldrb r1, [r3]
	str r0, [r2, r1, lsl #2]
	add r1, r1, #1
	strb r1, [r3]
	bx lr

	arm_func_start CollideAll
CollideAll: @ 0x080B1C7C
	push {r4, r5, r6, r7, r8, sb, sl, lr}
	add r0, pc, #0x104 @ =_080B1D8C
	ldm r0, {r8, sb, sl}
	ldrb sl, [sl]
	cmp sl, #0
	beq _080B1D84
	ldr r8, [r8]
	mov r7, r8
_080B1C9C:
	ldr r4, [r8, #8]
	ldrb r0, [r4, #0x10]
	ands r0, r0, #0x80
	beq _080B1D78
	ldrb r0, [r4, #0x3c]
	and r0, r0, #7
	mov r1, #1
	lsl r6, r1, r0
	ldrb r3, [r4, #0x3c]
	ldrb r2, [r4, #0x3d]
	mov ip, sl
_080B1CC8:
	subs ip, ip, #1
	bmi _080B1D78
	ldr r5, [sb, ip, lsl #2]
	cmp r4, r5
	beq _080B1CC8
	ldr r0, [r5, #0x3b]
	ands r0, r0, r6
	beq _080B1CC8
	ldrb r0, [r5, #0x10]
	ands r0, r0, #0x80
	beq _080B1CC8
	ldrb r0, [r4, #0x38]
	ldrb r1, [r5, #0x38]
	ands r0, r0, r1
	beq _080B1CC8
	ldrb r0, [r5, #0x3c]
	orr r0, r0, r3
	lsrs r0, r0, #7
	bhs _080B1D20
	ldrb r0, [r5, #0x3d]
	orrs r0, r0, r2
	bne _080B1CC8
_080B1D20:
	bl CalcCollision
	cmp r0, #0
	beq _080B1CC8
	ldrb r3, [r4, #0x3c]
	ldrb r0, [r4, #0x3d]
	ldrb r1, [r4, #0x43]
	orr r2, r0, r1
	ldrb r0, [r5, #0x41]
	ands r0, r0, #0x80
	bne _080B1D58
	str r4, [r5, #0x4c]
	ldrb r0, [r4, #0x40]
	orr r0, r0, #0x80
	strb r0, [r5, #0x41]
_080B1D58:
	ldrb r0, [r4, #0x41]
	ands r0, r0, #0x80
	bne _080B1CC8
	str r5, [r4, #0x4c]
	ldrb r0, [r5, #0x40]
	orr r0, r0, #0x80
	strb r0, [r4, #0x41]
	b _080B1CC8
_080B1D78:
	ldr r8, [r8, #4]
	cmp r8, r7
	bne _080B1C9C
_080B1D84:
	pop {r4, r5, r6, r7, r8, sb, sl, lr}
	bx lr
_080B1D8C: .4byte gUnk_02018EA0
_080B1D90: .4byte gCollidableList
_080B1D94: .4byte gCollidableCount

	arm_func_start CalcCollision
CalcCollision: @ 0x080B1D98
	@ r6 = this, r7 = other

	push {r2, r3, r6, r7, r8, sb, ip, lr}
	ldr r6, [r4, #0x48]
	ldr r7, [r5, #0x48]
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r5, #0x2e]
	sub r0, r0, r1
	ldrsb r1, [r6]
	add r0, r0, r1
	ldrsb r1, [r7]
	sub r0, r0, r1
	ldrb r1, [r6, #6]
	ldrb r2, [r7, #6]
	add r1, r1, r2
	add r2, r0, r1
	cmp r2, r1, lsl #1
	bhi _080B1F28
	ldrh r1, [r4, #0x32]
	ldrh r2, [r5, #0x32]
	sub r1, r1, r2
	ldrsb r2, [r6, #1]
	add r1, r1, r2
	ldrsb r2, [r7, #1]
	sub r1, r1, r2
	ldrb r2, [r6, #7]
	ldrb r3, [r7, #7]
	add r2, r2, r3
	add r3, r1, r2
	cmp r3, r2, lsl #1
	bhi _080B1F28
	mov r2, #5
	mov r3, #5
	ldr r8, [r4, #0x3c]
	ands r8, r8, #0x10
	ldrbne r2, [r6, #8]
	ldr r8, [r5, #0x3c]
	ands r8, r8, #0x10
	ldrbne r3, [r7, #8]
	add r2, r2, r3
	ldrsh r8, [r4, #0x36]
	ldrsh sb, [r5, #0x36]
	sub r8, r8, sb
	add r8, r2, r8
	cmp r8, r2, lsl #1
	bhi _080B1F28
	ldrb r2, [r4, #0x3c]
	and r2, r2, #0x20
	lsr r2, r2, #3
	ldrb r3, [r5, #0x3c]
	and r3, r3, #0x20
	adds r2, r2, r3, lsr #2
	beq _080B1E74
	add r3, pc, #0x180 @ =_080B1FEC
	ldr r2, [r3, r2]
	mov lr, pc
	bx r2
_080B1E74:
	mov r2, #0
	mov ip, #0
	bl CalcCollisionDirection
	mov r6, r0
	ldrb r1, [r5, #0x3f]
	mov r0, #0x22
	mul r1, r0, r1
	ldrb r0, [r4, #0x40]
	add r0, r0, r1
	mov r1, #0xc
	mul r2, r0, r1
	ldr r1, _080B2014 @ =gCollisionMtx
	add r3, r2, r1
	mov r1, #0
	ldrb r0, [r3]
	cmp r0, #0xff
	ldrheq r1, [r3, #2]
	ldr r0, _080B2018 @ =gUnk_080B3744
	ldr r7, [r0, r1, lsl #2]
	mov r0, r4
	mov r1, r5
	mov r2, r6
	mov lr, pc
	bx r7
_080B1ED4:
	cmp r0, #0
	beq _080B1F20
	cmp r0, #2
	beq _080B1F1C
	ldrb r0, [r4, #0x3c]
	and r0, r0, #0x80
	lsr r0, r0, #5
	ldrb r1, [r5, #0x3c]
	and r1, r1, #0x80
	lsr r1, r1, #4
	add r0, r0, r1
	add r1, pc, #0xF4 @ =_080B1FFC
	ldr r0, [r1, r0]
	mov lr, pc
	bx r0
_080B1F10:
	strb r6, [r5, #0x3e]
	eor r6, r6, #0x10
	strb r6, [r4, #0x3e]
_080B1F1C:
	mov r0, #1
_080B1F20:
	pop {r2, r3, r6, r7, r8, sb, ip, lr}
	bx lr
_080B1F28:
	mov r0, #0
	b _080B1F20

	arm_func_start sub_080B1F30
sub_080B1F30: @ 0x080B1F30
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r5, #0x2e]
	sub r0, r0, r1
	ldrsb r1, [r7]
	sub r0, r0, r1
	ldrh r1, [r4, #0x32]
	ldrh r2, [r5, #0x32]
	sub r1, r1, r2
	ldrsb r2, [r7, #1]
	sub r1, r1, r2
	bx lr

	arm_func_start sub_080B1F5C
sub_080B1F5C: @ 0x080B1F5C
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r5, #0x2e]
	sub r0, r0, r1
	ldrsb r1, [r6]
	add r0, r0, r1
	ldrh r1, [r4, #0x32]
	ldrh r2, [r5, #0x32]
	sub r1, r1, r2
	ldrsb r2, [r6, #1]
	add r1, r1, r2
	bx lr

	arm_func_start sub_080B1F88
sub_080B1F88: @ 0x080B1F88
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r5, #0x2e]
	sub r0, r0, r1
	ldrh r1, [r4, #0x32]
	ldrh r2, [r5, #0x32]
	sub r1, r1, r2
	bx lr

	arm_func_start sub_080B1FA4
sub_080B1FA4: @ 0x080B1FA4
	ldrb r0, [r5, #0x15]
	eor r0, r0, #0x10
	b _080B1FB4
_080B1FB0:
	ldrb r0, [r4, #0x15]
_080B1FB4:
	sub r1, r0, #8
	and r1, r1, #0x1f
	sub r1, r6, r1
	and r1, r1, #0x1f
	cmp r1, #0x11
	bxlo lr
	sub r0, r6, r0
	sub r0, r0, #8
	and r0, r0, #0x1f
	sub r6, r6, r0, lsl #1
	and r6, r6, #0x1f
	bx lr

	arm_func_start sub_080B1FE4
sub_080B1FE4: @ 0x080B1FE4
	ldrb r6, [r4, #0x15]
	bx lr
_080B1FEC: .4byte gUnk_03005D5C
_080B1FF0: .4byte gUnk_03005CA4
_080B1FF4: .4byte gUnk_03005CD0
_080B1FF8: .4byte gUnk_03005CFC
_080B1FFC: .4byte gUnk_03005D5C
_080B2000: .4byte gUnk_03005D24
_080B2004: .4byte gUnk_03005D18
_080B2008: .4byte gUnk_03005D58
_080B200C: .4byte gCollidableList
_080B2010: .4byte gCollidableCount
_080B2014: .4byte gCollisionMtx
_080B2018: .4byte gUnk_080B3744

	arm_func_start IntrMain
IntrMain:
	mov r3, #0x4000000
	add r3, r3, #0x200
	ldr r2, [r3] @ lo 16: interrupt_enable, hi 16: interrupt_request
	ldrh r1, [r3, #8] @ interrupt master enable
	mrs r0, spsr
	push {r0, r1, r2, r3, lr}
	and r1, r2, r2, lsr #16
	ands r0, r1, #0x2000 @ external irq
	bne _080B20D4
	mov ip, #4
	ands r0, r1, #0x80 @ serial comm
	bne _080B2074
	mov ip, #0xc
	ands r0, r1, #4 @ vcount
	bne _080B2074
	mov ip, #0x10
	ands r0, r1, #1 @ vblank
	bne _080B2074
	mov ip, #0x14
	ands r0, r1, #0x40 @ timer 3 overflow
	bne _080B2074
	mov ip, #0
_080B2074:
	strh r0, [r3, #2]
	bic r2, r2, r0
	ldr r1, _080B20E4 @ =0x0000208C
	and r1, r1, r2
	strh r1, [r3]
	mrs r3, apsr
	bic r3, r3, #0xdf
	orr r3, r3, #0x1f
	msr cpsr_fc, r3
	ldr r1, _080B20E8 @ =gUnk_030067E4
	ldr r0, [r1, ip]
	stmdb sp!, {lr}
	mov lr, pc
	bx r0

	arm_func_start sub_080B20AC
sub_080B20AC: @ 0x080B20AC
	ldm sp!, {lr}
	mrs r3, apsr
	bic r3, r3, #0xdf
	orr r3, r3, #0x92
	msr cpsr_fc, r3
	pop {r0, r1, r2, r3, lr}
	strh r2, [r3]
	strh r1, [r3, #8]
	msr spsr_fc, r0
	bx lr
_080B20D4:
	mov r0, #0
	strh r0, [r3, #8]
	strb r0, [r3, #-0x17c]
_080B20E0:
	b _080B20E0
	.align 2, 0
_080B20E4: .4byte 0x0000208C
_080B20E8: .4byte gUnk_030067E4

	arm_func_start sub_080B20EC
sub_080B20EC: @ 0x080B20EC
	add r3, r0, r1, lsr #3
	and r1, r1, #7
	ldr r0, _080B21A4 @ =0x01010101
	lsl r1, r0, r1
_080B20FC:
	ldrb r0, [r3]
	ands r0, r0, r1
	bxeq lr
	lsls r1, r1, #1
	addhs r1, r1, #1
	addhs r3, r3, #1
	subs r2, r2, #1
	bne _080B20FC
	mov r0, #1
	bx lr

	arm_func_start MakeFadeBuff256
MakeFadeBuff256: @ 0x080B2124
	push {r4, r5, r6, r7, r8, sb, sl, fp}
	mul r3, r2, r3
	mov r4, #0x400
	sub r2, r4, r2, lsl #2
	ldr r7, _080B21A8 @ =gUnk_02000006
	ldrb r7, [r7]
	ldr ip, _080B21AC @ =gUnk_08000F54
	add ip, ip, r7, lsl #4
	ldm ip, {r8, sb, sl}
	mov r7, #0x3e
	mov ip, #0x10
_080B2150:
	ldrh r6, [r0], #2
	lsl r6, r6, #1
	and r4, r7, r6
	mla r4, r2, r4, r3
	and r5, r7, r6, lsr #5
	mla r5, r2, r5, r3
	and r6, r7, r6, lsr #10
	mla r6, r2, r6, r3
	and r4, r7, r4, lsr #10
	and r5, r7, r5, lsr #10
	and r6, r7, r6, lsr #10
	ldrh r4, [r8, r4]
	ldrh r5, [sb, r5]
	ldrh r6, [sl, r6]
	orr r4, r4, r5
	orr r4, r4, r6
	strh r4, [r1], #2
	subs ip, ip, #1
	bne _080B2150
	pop {r4, r5, r6, r7, r8, sb, sl, fp}
	bx lr
	.align 2, 0
_080B21A4: .4byte 0x01010101
_080B21A8: .4byte gUnk_02000006
_080B21AC: .4byte gUnk_08000F54

	ldr r11, _080B2270 @ =gUpdateContext
	ldr r1, [r11]
	ldm r1, {r7, r8, r9, r10}
	ldr sp, [r11, #0xc]
	ldr r8, [r11, #4]
	ldr r0, [r11, #8]
	add pc, pc, #0x60 @ =_080B2230

@ gUpdateContext { 
@	void* chosen_table;
@	void* linked_list_top;
@	void* curr_entity;
@	void* restore_sp;
@ }

	arm_func_start UpdateEntities_arm
UpdateEntities_arm: @ 0x080B21B0
@ UpdateEntities starts here
    @ arg0 (r0) : 0 = entities, 1 = managers
	ldr r1, _080B2274 @ =gUnk_080026A4
	add r1, r1, r0, lsl #4
	push {r4 - r11, lr}
	ldr r11, _080B2278 @ =gUpdateContext
	str r1, [r11, #0x0]
	str sp, [r11, #0xc]
	ldm r1, {r7, r8, r9, r10}
next_list: @ traverse entity linked list
	add r8, r8, #8
	str r8, [r11, #4]
	cmp r8, r9
	bhs lists_complete
	ldr r4, [r8, #4] @ entity -> next
next_entity:
	cmp r4, r8
	beq next_list
	mov r0, #0
	str r0, [r7]
	str r4, [r11, #8]
	ldrb r1, [r4, #8] @ entity -> kind
	ldr r1, [r10, r1, lsl #2]
	mov r0, r4
	mov lr, pc
	bx r1 @ call entity kind update function
	ldr r0, [r11, #8]
	cmp r0, r4 @ update collision if entity is still alive
	bleq UpdateCollision
_080B2230: @ jumped here if ClearAndUpdateEntities
	ldr r4, [r0, #4]
	b next_entity
lists_complete:
	mov r0, #0
	str r0, [r11, #8]
	pop {r4 - r11, lr}
	bx lr

_080B2248::
_080B2248: .4byte DeleteThisEntity @ 0x3005fbc
_080B224C: .4byte PlayerUpdate
_080B2250: .4byte DeleteThisEntity
_080B2254: .4byte EnemyUpdate
_080B2258: .4byte ProjectileUpdate
_080B225C: .4byte DeleteThisEntity
_080B2260: .4byte ObjectUpdate
_080B2264: .4byte NPCUpdate
_080B2268: .4byte ItemUpdate
_080B226C: .4byte ManagerUpdate

_080B2270: .4byte gUpdateContext
_080B2274: .4byte gUnk_080026A4
_080B2278: .4byte gUpdateContext

	arm_func_start sub_080B227C
sub_080B227C: @ 0x080B227C
	push {r4, r5, r6, r7, r8, lr}
	ldr r2, [r0, #0x48]
	cmp r2, #0
	beq _080B236C
	ldr r3, [r1, #0x48]
	cmp r3, #0
	beq _080B236C
	ldrh r4, [r1, #0x2e]
	ldrsb r5, [r3]
	add r4, r4, r5
	ldrh r5, [r0, #0x2e]
	sub r4, r4, r5
	ldrsb r5, [r2]
	sub r4, r4, r5
	ldrb r5, [r2, #6]
	ldrb r6, [r3, #6]
	add r5, r5, r6
	add r6, r4, r5
	lsl r7, r5, #1
	cmp r7, r6
	blo _080B236C
	cmp r4, #0
	movpl ip, #8
	movmi ip, #0x18
	rsbmi r4, r4, #0
	sub r8, r5, r4
	ldrh r4, [r1, #0x32]
	ldrsb r5, [r3, #1]
	add r4, r4, r5
	ldrh r5, [r0, #0x32]
	sub r4, r4, r5
	ldrsb r5, [r2, #1]
	sub r4, r4, r5
	ldrb r2, [r2, #7]
	ldrb r3, [r3, #7]
	add r3, r2, r3
	add r5, r4, r3
	lsl r6, r3, #1
	cmp r6, r5
	blo _080B236C
	cmp r4, #0
	movpl r2, #0x10
	movmi r2, #0
	rsbmi r4, r4, #0
	sub r7, r3, r4
	cmp r7, r8
	movhs r7, r8
	movhs r2, ip
	cmp r7, #0
	beq _080B236C
	cmp r7, #5
	movhs r7, #4
	mov r0, r1
	lsl r1, r7, #8
	ldr r3, _080B2378 @ =sub_080044AE
	mov lr, pc
	bx r3
_080B2360:
	pop {r4, r5, r6, r7, r8, lr}
	mov r0, #1
	bx lr
_080B236C:
	pop {r4, r5, r6, r7, r8, lr}
	mov r0, #0
	bx lr
	.align 2, 0
_080B2378: .4byte sub_080044AE

	arm_func_start CalcCollisionDirection
CalcCollisionDirection: @ 0x080B237C
	subs r2, r2, r0
	movpl r0, #0
	movmi r0, #0x20
	rsbmi r2, r2, #0
	subs r3, r1, ip
	rsbmi r3, r3, #0
	addmi r0, r0, #0x10
	cmp r2, r3
	movhs r1, r3
	movhs r3, r2
	movhs r2, r1
	addhs r0, r0, #8
	lsl r2, r2, #3
	lsl r1, r3, #1
	cmp r2, r3
	addhs r0, r0, #1
	addhs r3, r3, r1
	cmp r2, r3
	addhs r0, r0, #1
	addhs r3, r3, r1
	cmp r2, r3
	addhs r0, r0, #1
	addhs r3, r3, r1
	cmp r2, r3
	addhs r0, r0, #1
	ldr r1, _080B23EC @ =gUnk_0800464E
	ldrb r0, [r1, r0]
	bx lr
	.align 2, 0
_080B23EC: .4byte gUnk_0800464E

	arm_func_start sub_080B23F0
sub_080B23F0: @ 0x080B23F0
.ifdef EU
	push {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	ldr fp, _080B2A30 @ =gUnk_03000000
	ldrb r2, [fp, #3]
	cmp r2, #0x80
	bhs _080B19C0EU
	add r0, pc, #0x54 @ =_080B19C0
	str r0, [fp, #0x18]
	str sp, [fp, #0x14]
	ldrb r0, [fp, #0xf]
	cmp r0, #0xff
	bne _080B1984
	bl _080B1FBC
_080B1980:
	mov r0, #0x0
_080B1984:
	ldr r1, _080B2154 @ =0x03006958
	ldr r1, [r1, r0, lsl #2]
	str r1, [fp, #0x1c]
	ldr r0, _080B2A34 @ =gUnk_081326EC
	ldr r0, [r0]
	bl sub_080B19C8
	ldr r0, _080B2A38 @ =gUnk_081326EC
	ldr r0, [r0, #4]
	bl sub_080B19C8
	ldr r0, _080B2A3C @ =gUnk_081326EC
	ldr r0, [r0, #8]
	bl sub_080B19C8
	ldr r0, _080B2A40 @ =gUnk_081326EC
	ldr r0, [r0, #0xc]
	bl sub_080B19C8
_080B19C0EU:
	pop {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	bx lr

	arm_func_start sub_080B19C8
sub_080B19C8: @ 0x080B19C8
	ldrb r2, [r0]
	cmp r2, #0
	bxeq lr
	ldr r1, _080B2A44 @ =0x08131D3C
	ldr r1, [r1, #0x10]
	mov r2, #0
	strb r2, [r1]
	stmdb sp!, {lr}
	bl ResolveOamDrawPriority
	bl sub_080B2534
	ldm sp!, {lr}
	b _080B1C40EU
.else
.ifdef DEMO_JP @ TODO deduplicate same as EU
	push {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	ldr fp, _080B2A30 @ =gUnk_03000000
	ldrb r2, [fp, #3]
	cmp r2, #0x80
	bhs _080B19C0EU
	add r0, pc, #0x54 @ =_080B19C0
	str r0, [fp, #0x18]
	str sp, [fp, #0x14]
	ldrb r0, [fp, #0xf]
	cmp r0, #0xff
	bne _080B1984
	bl _080B1FBC
_080B1980:
	mov r0, #0x0
_080B1984:
	ldr r1, _080B2154 @ =0x03006958
	ldr r1, [r1, r0, lsl #2]
	str r1, [fp, #0x1c]
	ldr r0, _080B2A34 @ =gUnk_081326EC
	ldr r0, [r0]
	bl sub_080B19C8
	ldr r0, _080B2A38 @ =gUnk_081326EC
	ldr r0, [r0, #4]
	bl sub_080B19C8
	ldr r0, _080B2A3C @ =gUnk_081326EC
	ldr r0, [r0, #8]
	bl sub_080B19C8
	ldr r0, _080B2A40 @ =gUnk_081326EC
	ldr r0, [r0, #0xc]
	bl sub_080B19C8
_080B19C0EU:
	pop {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	bx lr

	arm_func_start sub_080B19C8
sub_080B19C8: @ 0x080B19C8
	ldrb r2, [r0]
	cmp r2, #0
	bxeq lr
	ldr r1, _080B2A44 @ =0x08131D3C
	ldr r1, [r1, #0x10]
	mov r2, #0
	strb r2, [r1]
	stmdb sp!, {lr}
	bl ResolveOamDrawPriority
	bl sub_080B2534
	ldm sp!, {lr}
	b _080B1C40EU
.else
	push {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	ldr fp, _080B2A30 @ =gUnk_03000000
	ldrb r2, [fp, #3]
	cmp r2, #0x80
	bhs _080B2440
	add r0, pc, #0x34 @ =_080B2440
	str r0, [fp, #0x18]
	str sp, [fp, #0x14]
	ldr r0, _080B2A34 @ =gUnk_081326EC
	ldr r0, [r0]
	bl sub_080B2448
	ldr r0, _080B2A38 @ =gUnk_081326EC
	ldr r0, [r0, #4]
	bl sub_080B2448
	ldr r0, _080B2A3C @ =gUnk_081326EC
	ldr r0, [r0, #8]
	bl sub_080B2448
	ldr r0, _080B2A40 @ =gUnk_081326EC
	ldr r0, [r0, #0xc]
	bl sub_080B2448
_080B2440:
	pop {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	bx lr

	arm_func_start sub_080B2448
sub_080B2448: @ 0x080B2448
	ldrb r2, [r0]
	cmp r2, #0
	bxeq lr
	ldr r1, _080B2A44 @ =gUnk_081326EC
	ldr r1, [r1, #0x10]
	mov r2, #0
	strb r2, [r1]
	stmdb sp!, {lr}
	bl ResolveOamDrawPriority
	bl sub_080B2534
	ldm sp!, {lr}
	b _080B26B4
.endif
.endif

	arm_func_start ResolveOamDrawPriority
ResolveOamDrawPriority: @ 0x080B2478
	prio_a  .req r8
	prio_b  .req r5

	mov sb, r0
	mov r1, r0
	ldrb r2, [r1], #4
	mov ip, r1
	sub sl, r2, #1
	add r2, r1, sl, lsl #2
	cmp sl, #0
	beq no_objs
_080B2498:
	lsl r3, sl, #2
	mov r6, #0
_080B24A0:
	cmp r6, sl
	bhs _080B2524
	sub r1, r2, r3
	sub r1, r1, r6, lsl #2
_080B24B0:
	cmp r1, ip
	blo _080B251C
# sprite A
	ldr r4, [r1]
# pos 
	ldr r8, [r4, #0x30]
	add r8, #0x80000000
	lsr r8, #3
# load priority bits, NOT so 0 = highest priority
	ldrb r0, [r4, #0x29]
	mvn r0, r0
	orr prio_a, r8, r0, lsl #29
	add r7, r1, r3
next_sprite:
	cmp r2, r7
	blo a_priority
# sprite B
	ldr r5, [r7]
	ldr r0, [r5, #0x30]
	add r0, #0x80000000
	lsr r0, #3
	ldrb r5, [r5, #0x29]
	mvn r5, r5
	orr prio_b, r0, r5, lsl #29
	cmp prio_a, prio_b
	bhs a_priority
	ldr r5, [r7], -r3
	str r5, [r7], r3, lsl #1
	b next_sprite
a_priority:
	str r4, [r7, -r3]!
	sub r1, r1, r3
	b _080B24B0
_080B251C:
	add r6, #1
	b _080B24A0
_080B2524:
	lsrs sl, #1
	bne _080B2498
no_objs:
	mov r0, sb
	bx lr

	arm_func_start sub_080B2534
sub_080B2534: @ 0x080B2534
	stmdb sp!, {lr}
	mov r4, r0
	ldrb r5, [r4], #4
_080B2540:
	ldr r0, [r4], #4
	push {r4, r5}
	bl sub_080B255C
	pop {r4, r5}
	subs r5, r5, #1
	bgt _080B2540
	ldm sp!, {pc}

	arm_func_start sub_080B255C
sub_080B255C: @ 0x080B255C
.ifdef EU
	stmdb sp!, {lr}
	mov r4, r0
	bl sub_080B299C
	ldr r3, [fp, #0x1c]
	mov lr, pc
.ifdef DEMO_JP
	bx r3
.else
	bxne r3
.endif
	mov r5, #0
	strb r5, [fp, #0x12]
	ldrsb r2, [r4, #0x29]
	ands r2, r2, #8
	beq _080B1BB8
	ldrsh r3, [r4, #0x36]
	cmp r3, #0
	bmi _080B1BA4
	mov r1, #0
	mov r2, #0
	bl sub_080B1BCC
	ldrb r1, [r4, #0x18]
	and r1, r1, #0x30
	mov r1, r1
	cmp r0, #0x19
	beq _080B1B98
	cmp r0, #0x2f
	beq _080B1B64
	cmp r0, #0xf
	bne _080B1BA4
	mov r5, #2
	strb r5, [fp, #0x12]
	add r7, r7, r5
	ldrb r2, [fp, #1]
	and r2, r2, #0x18
	add r2, r2, #0x80
	lsr r2, r2, #2
	b _080B1B74
_080B1B64:
	ldrb r2, [r4, #0x2e]
	ldrb r3, [r4, #0x32]
	eor r2, r2, r3
	and r2, r2, #6
_080B1B74:
	ldr r3, _080B2A48 @ =gUnk_030068CC
	add r2, r1, r2, lsl #1
	ldr sl, [r3, r2]
	push {r4, r8, sb}
	mov r8, #0
	and sb, sb, #0xc00
	bl _080B2874
	pop {r4, r8, sb, lr}
	b _080B2718
_080B1B98:
	mov r5, #2
	strb r5, [fp, #0x12]
	add r7, r7, r5
_080B1BA4:
	stmdb sp!, {r4}
	mov r0, r4
	bl _080B2718
	pop {r4, lr}
	b _080B1BC0
_080B1BB8:
	ldm sp!, {lr}
	b _080B2718
_080B1BC0:
	ldrsh r1, [r4, #0x36]
	ldrb r0, [r4, #0x29]
	tst r0, #0x10
	beq _080B1BD8
	cmp r1, #0
	bxpl lr
_080B1BD8:
	tst r0, #0x20
	beq _080B1BEC
	ldrb r0, [fp, #1]
	tst r0, #1
	bxne lr
_080B1BEC:
	mov r2, r7
	cmp r1, #0
	submi r2, r2, r1
	ldr r3, _080B2A4C @ =gUnk_081326EC
	ldr r3, [r3, #0x10]
	ldrb r0, [r3]
	cmp r0, #0x40
	bxhs lr
	add r0, r0, #1
	strb r0, [r3]
	add r3, r3, r0, lsl #2
	lsr r0, sb, #0xa
	and r0, r0, #3
	orr r0, r0, r2, lsl #6
	strh r0, [r3, #2]
	ldrb r0, [r4, #0x18]
	and r0, r0, #0x30
	lsr r0, r0, #4
	orr r0, r0, r6, lsl #6
	strh r0, [r3]
	bx lr
_080B1C40EU:
	ldr r4, _080B2A50 @ =gUnk_081326EC
	ldr r4, [r4, #0x10]
	ldrb r5, [r4]
	cmp r5, #0
	bxeq lr
	stmdb sp!, {lr}
	add r4, r4, #4
_080B1C5C:
	ldrsh r0, [r4]
	asr r6, r0, #6
	and r1, r0, #7
	ldr sl, _080B2A54 @ =gUnk_0300694C
	ldr sl, [sl, r1, lsl #2]
	ldrsh r0, [r4, #2]
	asr r7, r0, #6
	and r1, r0, #3
	lsl sb, r1, #0xa
	mov r8, #0
	push {r4, r5}
	bl _080B2874
	pop {r4, r5}
	add r4, r4, #4
	subs r5, r5, #1
	bgt _080B1C5C
	ldm sp!, {lr}
	bx lr

.else
.ifdef DEMO_JP  @ TODO deduplicate nearly same as EU
	stmdb sp!, {lr}
	mov r4, r0
	bl sub_080B299C
	ldr r3, [fp, #0x1c]
	mov lr, pc
.ifdef DEMO_JP
	bx r3
.else
	bxne r3
.endif
	mov r5, #0
	strb r5, [fp, #0x12]
	ldrsb r2, [r4, #0x29]
	ands r2, r2, #8
	beq _080B1BB8
	ldrsh r3, [r4, #0x36]
	cmp r3, #0
	bmi _080B1BA4
	mov r1, #0
	mov r2, #0
	bl sub_080B1BCC
	ldrb r1, [r4, #0x18]
	and r1, r1, #0x30
	mov r1, r1
	cmp r0, #0x19
	beq _080B1B98
	cmp r0, #0x2f
	beq _080B1B64
	cmp r0, #0xf
	bne _080B1BA4
	mov r5, #2
	strb r5, [fp, #0x12]
	add r7, r7, r5
	ldrb r2, [fp, #1]
	and r2, r2, #0x18
	add r2, r2, #0x80
	lsr r2, r2, #2
	b _080B1B74
_080B1B64:
	ldrb r2, [r4, #0x2e]
	ldrb r3, [r4, #0x32]
	eor r2, r2, r3
	and r2, r2, #6
_080B1B74:
	ldr r3, _080B2A48 @ =gUnk_030068CC
	add r2, r1, r2, lsl #1
	ldr sl, [r3, r2]
	push {r4, r8, sb}
	mov r8, #0
	and sb, sb, #0xc00
	bl _080B2874
	pop {r4, r8, sb, lr}
	b _080B2718
_080B1B98:
	mov r5, #2
	strb r5, [fp, #0x12]
	add r7, r7, r5
_080B1BA4:
	stmdb sp!, {r4}
	mov r0, r4
	bl _080B2718
	pop {r4, lr}
	b _080B1BC0
_080B1BB8:
	ldm sp!, {lr}
	b _080B2718
_080B1BC0:
	ldrsh r1, [r4, #0x36]
	ldrb r0, [r4, #0x29]
	tst r0, #0x10
	beq _080B1BD8
	cmp r1, #0
	bxpl lr
_080B1BD8:
	tst r0, #0x20
	beq _080B1BEC
	ldrb r0, [fp, #1]
	tst r0, #1
	bxne lr
_080B1BEC:
	mov r2, r7
	cmp r1, #0
	submi r2, r2, r1
	ldr r3, _080B2A4C @ =gUnk_081326EC
	ldr r3, [r3, #0x10]
	ldrb r0, [r3]
	cmp r0, #0x40
	bxhs lr
	add r0, r0, #1
	strb r0, [r3]
	add r3, r3, r0, lsl #2
	lsr r0, sb, #0xa
	and r0, r0, #3
	orr r0, r0, r2, lsl #6
	strh r0, [r3, #2]
	ldrb r0, [r4, #0x18]
	and r0, r0, #0x30
	lsr r0, r0, #4
	orr r0, r0, r6, lsl #6
	strh r0, [r3]
	bx lr
_080B1C40EU:
	ldr r4, _080B2A50 @ =gUnk_081326EC
	ldr r4, [r4, #0x10]
	ldrb r5, [r4]
	cmp r5, #0
	bxeq lr
	stmdb sp!, {lr}
	add r4, r4, #4
_080B1C5C:
	ldrsh r0, [r4]
	asr r6, r0, #6
	and r1, r0, #7
	ldr sl, _080B2A54 @ =gUnk_0300694C
	ldr sl, [sl, r1, lsl #2]
	ldrsh r0, [r4, #2]
	asr r7, r0, #6
	and r1, r0, #3
	lsl sb, r1, #0xa
	mov r8, #0
	push {r4, r5}
	bl _080B2874
	pop {r4, r5}
	add r4, r4, #4
	subs r5, r5, #1
	bgt _080B1C5C
	ldm sp!, {lr}
	bx lr

.else
	stmdb sp!, {lr}
	mov r4, r0
	bl sub_080B299C
	mov r5, #0
	strb r5, [fp, #0x12]
	ldrsb r2, [r4, #0x29]
	ands r2, r2, #8
	beq _080B262C
	ldrsh r3, [r4, #0x36]
	cmp r3, #0
	bmi _080B2618
	mov r1, #0
	mov r2, #0
	bl sub_080B1BCC
	ldrb r1, [r4, #0x18]
	and r1, r1, #0x30
	mov r1, r1
	cmp r0, #0x19
	beq _080B260C
	cmp r0, #0x2f
	beq _080B25D8
	cmp r0, #0xf
	bne _080B2618
	mov r5, #2
	strb r5, [fp, #0x12]
	add r7, r7, r5
	ldrb r2, [fp, #1]
	and r2, r2, #0x18
	add r2, r2, #0x80
	lsr r2, r2, #2
	b _080B25E8
_080B25D8:
	ldrb r2, [r4, #0x2e]
	ldrb r3, [r4, #0x32]
	eor r2, r2, r3
	and r2, r2, #6
_080B25E8:
	ldr r3, _080B2A48 @ =gUnk_030068CC
	add r2, r1, r2, lsl #1
	ldr sl, [r3, r2]
	push {r4, r8, sb}
	mov r8, #0
	and sb, sb, #0xc00
	bl _080B2874
	pop {r4, r8, sb, lr}
	b _080B2718
_080B260C:
	mov r5, #2
	strb r5, [fp, #0x12]
	add r7, r7, r5
_080B2618:
	stmdb sp!, {r4}
	mov r0, r4
	bl _080B2718
	pop {r4, lr}
	b _080B2634
_080B262C:
	ldm sp!, {lr}
	b _080B2718
_080B2634:
	ldrsh r1, [r4, #0x36]
	ldrb r0, [r4, #0x29]
	tst r0, #0x10
	beq _080B264C
	cmp r1, #0
	bxpl lr
_080B264C:
	tst r0, #0x20
	beq _080B2660
	ldrb r0, [fp, #1]
	tst r0, #1
	bxne lr
_080B2660:
	mov r2, r7
	cmp r1, #0
	submi r2, r2, r1
	ldr r3, _080B2A4C @ =gUnk_081326EC
	ldr r3, [r3, #0x10]
	ldrb r0, [r3]
	cmp r0, #0x40
	bxhs lr
	add r0, r0, #1
	strb r0, [r3]
	add r3, r3, r0, lsl #2
	lsr r0, sb, #0xa
	and r0, r0, #3
	orr r0, r0, r2, lsl #6
	strh r0, [r3, #2]
	ldrb r0, [r4, #0x18]
	and r0, r0, #0x30
	lsr r0, r0, #4
	orr r0, r0, r6, lsl #6
	strh r0, [r3]
	bx lr
_080B26B4:
	ldr r4, _080B2A50 @ =gUnk_081326EC
	ldr r4, [r4, #0x10]
	ldrb r5, [r4]
	cmp r5, #0
	bxeq lr
	stmdb sp!, {lr}
	add r4, r4, #4
_080B26D0:
	ldrsh r0, [r4]
	asr r6, r0, #6
	and r1, r0, #7
	ldr sl, _080B2A54 @ =gUnk_0300694C
	ldr sl, [sl, r1, lsl #2]
	ldrsh r0, [r4, #2]
	asr r7, r0, #6
	and r1, r0, #3
	lsl sb, r1, #0xa
	mov r8, #0
	push {r4, r5}
	bl _080B2874
	pop {r4, r5}
	add r4, r4, #4
	subs r5, r5, #1
	bgt _080B26D0
	ldm sp!, {lr}
	bx lr

.endif
.endif


_080B2718:
	ldrsb r0, [r4, #0x28]
	cmp r0, #0
	beq _080B27E4
	bpl _080B2730
	ldr sl, [r4, #0x64]
	b _080B2874
_080B2730:
	ldr r4, _080B2A58 @ =gUnk_020000C0
	add r4, r4, r0, lsl #6
	mov r5, #4
	bic sb, sb, #0xf000
_080B2740:
	ldrb r0, [r4]
	tst r0, #1
	bxeq lr
	tst r0, #2
	bne _080B27B8
	ldrb r0, [r4, #1]
	cmp r0, #0xff
	beq _080B27A8
	push {r4, r5, r6, r7, r8, sb, lr}
	ldrb r2, [r4, #4]
	eor r8, r8, r2, lsl #28
	ldrsb r2, [r4, #6]
	tst r8, #0x10000000
	addeq r6, r6, r2
	subne r6, r6, r2
	ldrsb r2, [r4, #7]
	tst r8, #0x20000000
	addeq r7, r7, r2
	addne r7, r7, r2
	ldrb r2, [r4, #5]
	orr sb, sb, r2, lsl #12
	ldrb r2, [r4, #8]
	add sb, sb, r2
	ldrh r1, [r4, #2]
	bl sub_080B27F4
	pop {r4, r5, r6, r7, r8, sb, lr}
_080B27A8:
	add r4, r4, #0x10
	subs r5, r5, #1
	bne _080B2740
	bx lr
_080B27B8:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _080B27A8
	push {r4, r5, lr}
	bl sub_080B299C
	mov r4, r0
	ldrb r5, [fp, #0x12]
	add r7, r7, r5
	bl _080B27E4
	pop {r4, r5, lr}
	b _080B27A8
_080B27E4:
	ldrb r0, [r4, #0x1e]
	cmp r0, #0xff
	bxeq lr
	ldrh r1, [r4, #0x12]

	arm_func_start sub_080B27F4
sub_080B27F4: @ 0x080B27F4
	ldr sl, _080B2A5C @ =gFrameObjLists
	ldr r2, [sl, r1, lsl #2]
	add r2, r2, sl
	ldr r0, [r2, r0, lsl #2]
	add sl, sl, r0
	b _080B2874

	arm_func_start sub_080B280C
sub_080B280C: @ 0x080B280C
	cmp r2, #0xff
	bxeq lr
	ldr r3, _080B2A60 @ =gFrameObjLists
	ldr r1, [r3, r1, lsl #2]
	add r1, r1, r2, lsl #2
	ldr r1, [r3, r1]
	add r1, r1, r3
	ldrb r2, [r1]
	cmp r2, #0
	bxeq lr
	push {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	ldr fp, _080B2A64 @ =gUnk_03000000
	ldrb r3, [fp, #3]
	cmp r3, #0x80
	bhs _080B286C
	mov sl, r1
	ldrsh r6, [r0]
	ldrsh r7, [r0, #2]
	ldr r8, [r0, #4]
	ldrh sb, [r0, #8]
	add r3, pc, #0x8 @ =_080B286C
	str r3, [fp, #0x18]
	str sp, [fp, #0x14]
	bl _080B2874
_080B286C:
	pop {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	bx lr
_080B2874:
	ldrb r0, [sl], #1
	lsls r0, r0, #0x18
	bxeq lr
	lsl sb, sb, #0x10
	orr sb, r0, sb, lsr #16
	ands r0, r8, #0x300
	beq _080B289C
	subs r0, r0, #0x100
	movne r0, #0xc0
	b _080B28A8
_080B289C:
	and r0, r8, #0x30000000
	lsr r0, r0, #0x18
	add r0, r0, r0, lsl #1
_080B28A8:
	ldr r5, _080B2A68 @ =gUnk_0300695C
	add r5, r5, r0
	ldrb r0, [fp, #3]
	orr sb, sb, r0, lsl #16
	add ip, fp, #0x20
	add ip, ip, r0, lsl #3
_080B28C0:
	sub sb, sb, #0x1000000
	ldrsb r2, [sl], #5
	ldrsb r1, [sl, #-4]
	tst r8, #0x300
	bne _080B28E4
	tst r8, #0x20000000
	rsbne r1, r1, #0
	tst r8, #0x10000000
	rsbne r2, r2, #0
_080B28E4:
	ldrb r3, [sl, #-3]
	and r0, r3, #0xf0
	add r4, r5, r0, lsr #2
	add r1, r1, r7
	ldrb r0, [r4, #1]
	sub r1, r1, r0
	cmp r1, #0xa0
	bge _080B2974
	ldrb r0, [r4, #3]
	cmn r1, r0
	ble _080B2974
	add r2, r2, r6
	ldrb r0, [r4]
	sub r2, r2, r0
	cmp r2, #0xf0
	bge _080B2974
	ldrb r0, [r4, #2]
	cmn r2, r0
	ble _080B2974
	and r0, r1, #0xff
	lsl r2, r2, #0x17
	orr r0, r0, r2, lsr #7
	orr r0, r0, r8
	and r1, r3, #0xc0
	orr r0, r0, r1, lsl #8
	and r1, r3, #0x3c
	eor r0, r0, r1, lsl #26
	str r0, [ip], #4
	ldrb r0, [sl, #-2]
	add r0, r0, sb
	tst r3, #1
	bicne r0, r0, #0xf000
	ldrb r1, [sl, #-1]
	add r0, r0, r1, lsl #8
	strh r0, [ip], #4
	add sb, sb, #0x10000
_080B2974:
	lsrs r0, sb, #0x18
	bhs _080B298C
	bne _080B28C0
	lsr r0, sb, #0x10
	strb r0, [fp, #3]
	bx lr
_080B298C:
	mov r0, #0x80
	strb r0, [fp, #3]
	ldr sp, [fp, #0x14]
	ldr pc, [fp, #0x18]

	arm_func_start sub_080B299C
sub_080B299C: @ 0x080B299C
	ldrsb r6, [r0, #0x3d]
	cmp r6, #0
	ldrbgt r6, [fp, #0xe]
	movle r6, #0
	ldr ip, [r0, #0x18]
	ldrh sb, [r0, #0x60]
	ldrb r5, [r0, #0x1a]
	orr r5, r5, r6
	and r5, r5, #0xf
	orr sb, sb, r5, lsl #12
	ldrb r5, [r0, #0x1b]
	and r5, r5, #0xc0
	orr sb, sb, r5, lsl #4
	ldrsh r6, [r0, #0x2e]
	ldrsb r5, [r0, #0x62]
	add r6, r6, r5
	ldrsh r7, [r0, #0x32]
	ldrsh r5, [r0, #0x36]
	add r7, r7, r5
	ldrsb r5, [r0, #0x63]
	add r7, r7, r5
	and r5, ip, #3
	cmp r5, #2
	beq _080B2A0C
	ldrsh r5, [fp, #4]
	sub r6, r6, r5
	ldrsh r5, [fp, #6]
	sub r7, r7, r5
_080B2A0C:
	ldr r8, _080B2A6C @ =0x3E003F00
	and r8, r8, ip
	ldrb r5, [fp, #2]
	orr r8, r8, r5, lsl #12
	ldrb r5, [r0, #0x5b]
	eor r5, r5, ip
	and r5, r5, #0xc0
	orr r8, r8, r5, lsl #22
	bx lr
	.align 2, 0

.ifdef EU
_080B1FBC:
	mov sl, lr
	ldrsh r0, [fp, #0x1c]
	ldrsh r1, [fp, #0x1e]
	ldrsh r2, [fp, #4]
	sub r0, r0, r2
	ldrsh r3, [fp, #6]
	sub r1, r1, r3
	mov r2, #0
	mov r3, #0
	bl sub_080B20ECEU
	mov r5, #0
	ldr r4, _080B2194 @ =0x03003DF8
_080B1FECEU:
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _080B2074EU
	ldrsh r6, [r0, #0x2e]
	ldrsh r7, [r0, #0x32]
	ldr r3, [r4, #4]
	cmp r3, #0
	beq _080B2024
	ldrsb r0, [r3]
	add r6, r6, r0
	ldrsb r0, [r3, #1]
	add r7, r7, r0
	add r3, r3, #2
	b _080B202C
_080B2024:
	ldr r3, [r0, #0x48]
	add r3, r3, #6
_080B202C:
	ldrsh r0, [fp, #4]
	sub r6, r6, r0
	ldrsh r0, [fp, #6]
	sub r7, r7, r0
	ldrb r0, [r3]
	ldrb r1, [r3, #1]
	ldr r2, [fp, #1]
	and r2, r2, #3
	lsl r3, r2, #0x1c
	lsrs r2, r2, #1
	rsblo r0, r0, #0
	subhs r0, r0, #8
	rsbeq r1, r1, #0
	subne r1, r1, #8
	add r0, r0, r6
	add r1, r1, r7
	mov r2, #0
	bl sub_080B20ECEU
_080B2074EU:
	add r4, r4, #0xc
	add r5, r5, #1
	cmp r5, #0x1f
	bls _080B1FECEU
	bx sl
	arm_func_start sub_080B2088
sub_080B2088: @ 0x080B2088
	ldr r5, [r4, #0x48]
	cmp r5, #0
	bxeq lr
	ldrb r0, [r5, #6]
	ldrb r1, [r5, #7]
	ldr r2, [fp, #1]
	and r2, r2, #3
	lsl r3, r2, #0x1c
	lsrs r2, r2, #1
	rsblo r0, r0, #0
	subhs r0, r0, #8
	rsbeq r1, r1, #0
	subne r1, r1, #8
	ldrsb r2, [r5]
	add r0, r6, r0
	add r0, r0, r2
	ldrsb r2, [r5, #1]
	add r1, r7, r1
	add r1, r1, r2
	mov r2, sb
	b sub_080B20ECEU
_080B20DC:
	mov r0, r6
	mov r1, r7
	mov r2, r9
	mov r3, #0x0

	arm_func_start sub_080B20ECEU
sub_080B20ECEU: @ 0x080B20EC
	add ip, r1, #7
	cmp ip, #0xa8
	bxhs lr
	add ip, r0, #7
	cmp ip, #0xf8
	bxhs lr
	and r1, r1, #0xff
	lsl r0, r0, #0x17
	orr r0, r1, r0, lsr #7
	eor r0, r0, r3
	and r1, r2, #0xc00
	add r1, r1, #0xff
	ldrb r3, [fp, #3]
	add ip, fp, #0x20
	add ip, ip, r3, lsl #3
	str r0, [ip]
	strh r1, [ip, #4]
	add r3, r3, #1
	cmp r3, #0x80
	bhs _080B298C
	strb r3, [fp, #3]
	bx lr
_080B2144:
	.4byte gUnk_03006954
	.4byte gUnk_030068F0
	.4byte gUnk_0300689C
.endif
.ifdef DEMO_JP @ TODO deduplicate same as EU
_080B1FBC:
	mov sl, lr
	ldrsh r0, [fp, #0x1c]
	ldrsh r1, [fp, #0x1e]
	ldrsh r2, [fp, #4]
	sub r0, r0, r2
	ldrsh r3, [fp, #6]
	sub r1, r1, r3
	mov r2, #0
	mov r3, #0
	bl sub_080B20ECEU
	mov r5, #0
	ldr r4, _080B2194 @ =0x03003DF8
_080B1FECEU:
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _080B2074EU
	ldrsh r6, [r0, #0x2e]
	ldrsh r7, [r0, #0x32]
	ldr r3, [r4, #4]
	cmp r3, #0
	beq _080B2024
	ldrsb r0, [r3]
	add r6, r6, r0
	ldrsb r0, [r3, #1]
	add r7, r7, r0
	add r3, r3, #2
	b _080B202C
_080B2024:
	ldr r3, [r0, #0x48]
	add r3, r3, #6
_080B202C:
	ldrsh r0, [fp, #4]
	sub r6, r6, r0
	ldrsh r0, [fp, #6]
	sub r7, r7, r0
	ldrb r0, [r3]
	ldrb r1, [r3, #1]
	ldr r2, [fp, #1]
	and r2, r2, #3
	lsl r3, r2, #0x1c
	lsrs r2, r2, #1
	rsblo r0, r0, #0
	subhs r0, r0, #8
	rsbeq r1, r1, #0
	subne r1, r1, #8
	add r0, r0, r6
	add r1, r1, r7
	mov r2, #0
	bl sub_080B20ECEU
_080B2074EU:
	add r4, r4, #0xc
	add r5, r5, #1
	cmp r5, #0x1f
	bls _080B1FECEU
	bx sl
	arm_func_start sub_080B2088
sub_080B2088: @ 0x080B2088
	ldr r5, [r4, #0x48]
	cmp r5, #0
	bxeq lr
	ldrb r0, [r5, #6]
	ldrb r1, [r5, #7]
	ldr r2, [fp, #1]
	and r2, r2, #3
	lsl r3, r2, #0x1c
	lsrs r2, r2, #1
	rsblo r0, r0, #0
	subhs r0, r0, #8
	rsbeq r1, r1, #0
	subne r1, r1, #8
	ldrsb r2, [r5]
	add r0, r6, r0
	add r0, r0, r2
	ldrsb r2, [r5, #1]
	add r1, r7, r1
	add r1, r1, r2
	mov r2, sb
	b sub_080B20ECEU
_080B20DC:
	mov r0, r6
	mov r1, r7
	mov r2, r9
	mov r3, #0x0

	arm_func_start sub_080B20ECEU
sub_080B20ECEU: @ 0x080B20EC
	add ip, r1, #7
	cmp ip, #0xa8
	bxhs lr
	add ip, r0, #7
	cmp ip, #0xf8
	bxhs lr
	and r1, r1, #0xff
	lsl r0, r0, #0x17
	orr r0, r1, r0, lsr #7
	eor r0, r0, r3
	and r1, r2, #0xc00
	add r1, r1, #0xff
	ldrb r3, [fp, #3]
	add ip, fp, #0x20
	add ip, ip, r3, lsl #3
	str r0, [ip]
	strh r1, [ip, #4]
	add r3, r3, #1
	cmp r3, #0x80
	bhs _080B298C
	strb r3, [fp, #3]
	bx lr
_080B2144:
	.4byte gUnk_03006954
	.4byte gUnk_030068F0
	.4byte gUnk_0300689C
.endif
	
_080B2A30: .4byte gUnk_03000000
.ifdef EU
_080B2154: .4byte 0x03006958 @TODO make pointer?
.endif
.ifdef DEMO_JP @ TODO deduplicate same as EU
_080B2154: .4byte 0x03006958 @TODO make pointer?
.endif
_080B2A34: .4byte gUnk_081326EC
_080B2A38: .4byte gUnk_081326EC
_080B2A3C: .4byte gUnk_081326EC
_080B2A40: .4byte gUnk_081326EC
_080B2A44: .4byte gUnk_081326EC
_080B2A48: .4byte gUnk_030068CC
_080B2A4C: .4byte gUnk_081326EC
_080B2A50: .4byte gUnk_081326EC
_080B2A54: .4byte gUnk_0300694C
_080B2A58: .4byte gUnk_020000C0
_080B2A5C: .4byte gFrameObjLists
_080B2A60: .4byte gFrameObjLists
_080B2A64: .4byte gUnk_03000000
_080B2A68: .4byte gUnk_0300695C
_080B2A6C: .4byte 0x3E003F00
.ifdef EU
_080B2194: .4byte 0x03003DF8 @TODO pointer?
.endif
.ifdef DEMO_JP @ TODO deduplicate same as EU
_080B2194: .4byte 0x03003DF8 @TODO pointer?
.endif
