	.syntax unified
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #1
.ifdef JP
	movs r0, #0xd6
.else
.ifdef EU
	movs r0, #0xd6
.else
.ifdef DEMO_JP
	movs r0, #0xd6 @ TODO deduplicate
.else
	movs r0, #0xd9
.endif
.endif
.endif
	bl CheckLocalFlag
	cmp r0, #0
	bne _0806392E
	movs r5, #0
.ifdef JP
	movs r0, #0xd6
.else
.ifdef EU
	movs r0, #0xd6
.else
.ifdef DEMO_JP
	movs r0, #0xd6 @ TODO deduplicate
.else
	movs r0, #0xd9
.endif
.endif
.endif
	bl SetLocalFlag
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x14]
_0806392E:
	ldr r0, _08063940 @ =gUnk_0810CC04
	lsls r1, r5, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r1, r4, #0
	bl MessageNoOverlap
	pop {r4, r5, pc}
	.align 2, 0
_08063940: .4byte gUnk_0810CC04
	.syntax divided
