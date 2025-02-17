	.syntax unified
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xc]
	cmp r4, #1
	beq _08067F58
	cmp r4, #1
	bgt _08067F04
	cmp r4, #0
	beq _08067F10
	b _0806801A
_08067F04:
	cmp r4, #2
	beq _08067FDC
	cmp r4, #3
	bne _08067F0E
	b _08068000
_08067F0E:
	b _0806801A
_08067F10:
	ldr r1, _08067F50 @ =gUnk_08111358
	adds r0, r5, #0
	bl LoadExtraSpriteData
	cmp r0, #0
	bne _08067F1E
	b _080680F0
_08067F1E:
	movs r2, #1
	movs r0, #1
	strb r0, [r5, #0xc]
	ldrb r1, [r5, #0x18]
	subs r0, #5
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, #0x18]
	ldrb r0, [r5, #0xa]
	strb r0, [r5, #0x14]
	adds r0, r5, #0
	adds r0, #0x69
	strb r4, [r0]
	adds r0, r5, #0
	movs r1, #2
	bl SetDefaultPriority
	adds r0, r5, #0
	bl sub_0807DD50
	ldr r1, _08067F54 @ =gUnk_08111304
	ldrb r0, [r5, #0xb]
	adds r0, r0, r1
	ldrb r1, [r0]
	b _08067FF2
	.align 2, 0
_08067F50: .4byte gUnk_08111358
_08067F54: .4byte gUnk_08111304
_08067F58:
	adds r4, r5, #0
	adds r4, #0x39
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #2
	bne _08067F98
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xc]
	strb r1, [r4]
	adds r0, r5, #0
	adds r0, #0x58
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x69
	strb r0, [r1]
	ldr r1, _08067F94 @ =gPlayerEntity
	adds r0, r5, #0
	bl GetFacingDirection
	bl sub_0806F5A4
	adds r1, r0, #0
	adds r0, r5, #0
	bl InitializeAnimation
	adds r0, r5, #0
	bl sub_0806F118
	b _0806801A
	.align 2, 0
_08067F94: .4byte gPlayerEntity
_08067F98:
	adds r0, r5, #0
	movs r1, #0
	bl ExecuteScriptForEntity
	adds r0, r5, #0
	bl HandleEntity0x82Actions
	ldrb r0, [r5, #0xb]
	cmp r0, #3
	bne _0806801A
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	beq _0806801A
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xc]
	strb r1, [r4]
	ldr r1, _08067FD8 @ =gPlayerEntity
	adds r0, r5, #0
	bl GetFacingDirection
	bl sub_0806F5A4
	adds r1, r0, #0
	adds r0, r5, #0
	bl InitializeAnimation
	adds r0, r5, #0
	bl sub_08068190
	b _0806801A
	.align 2, 0
_08067FD8: .4byte gPlayerEntity
_08067FDC:
	ldr r0, _08067FFC @ =gMessage
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0
	bne _0806801A
	movs r0, #1
	strb r0, [r5, #0xc]
	ldrb r1, [r5, #0x14]
	lsrs r1, r1, #1
	adds r1, #4
_08067FF2:
	adds r0, r5, #0
	bl InitializeAnimation
	b _0806801A
	.align 2, 0
_08067FFC: .4byte gMessage
_08068000:
	adds r0, r5, #0
	bl UpdateFuseInteraction
	cmp r0, #0
	beq _0806801A
	movs r0, #1
	strb r0, [r5, #0xc]
	adds r0, r5, #0
	adds r0, #0x69
	ldrb r1, [r0]
	adds r0, r5, #0
	bl InitializeAnimation
_0806801A:
	adds r0, r5, #0
	adds r0, #0x59
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0xff
	beq _0806802C
	adds r0, r5, #0
	bl GetNextFrame
_0806802C:
	adds r1, r5, #0
	adds r1, #0x5b
	ldrb r2, [r1]
	movs r0, #1
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0806807E
	movs r0, #0xfe
	ands r0, r2
	strb r0, [r6]
	adds r0, r5, #0
	bl sub_080040A8
	cmp r0, #0
	bne _08068068
	ldr r4, _08068064 @ =gUnk_0811137A
	bl Random
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	bl SoundReq
	b _0806807E
	.align 2, 0
_08068064: .4byte gUnk_0811137A
_08068068:
	ldr r4, _080680F4 @ =gUnk_08111374
	bl Random
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	bl EnqueueSFX
_0806807E:
	ldrb r1, [r6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080680A8
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r6]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0
	bl CreateFx
	adds r1, r0, #0
	cmp r1, #0
	beq _080680A8
	ldr r3, _080680F8 @ =0xFFE80000
	adds r0, r5, #0
	movs r2, #0
	bl PositionRelative
_080680A8:
	ldrb r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080680D2
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6]
	adds r0, r5, #0
	movs r1, #0x3d
	movs r2, #0x20
	bl CreateFx
	adds r1, r0, #0
	cmp r1, #0
	beq _080680D2
	ldr r2, _080680FC @ =0xFFEC0000
	ldr r3, _08068100 @ =0xFFF60000
	adds r0, r5, #0
	bl PositionRelative
_080680D2:
	ldrb r1, [r6]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080680F0
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r6]
	bl Random
	movs r1, #0x1f
	ands r0, r1
	ldrb r1, [r7]
	adds r0, r0, r1
	strb r0, [r7]
_080680F0:
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_080680F4: .4byte gUnk_08111374
_080680F8: .4byte 0xFFE80000
_080680FC: .4byte 0xFFEC0000
_08068100: .4byte 0xFFF60000
	.syntax divided
