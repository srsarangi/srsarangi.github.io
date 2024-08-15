	.file	"stub.c"
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"Input 1 = %x \n\000"
	.align	2
.LC1:
	.ascii	"Operator = %c \n\000"
	.align	2
.LC2:
	.ascii	"Input 2 = %x \n\000"
	.text
	.align	2
	.global	process
	.type	process, %function
process:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {r4, r5, fp, ip, lr, pc}
	sub	fp, ip, #4
	and	r4, r1, #255
	mov	r1, r0
	ldr	r0, .L2
	mov	r5, r2
	mov r7, r1 	
	bl	printf
	mov	r1, r4
	ldr	r0, .L2+4
	mov r8, r1
	bl	printf
	mov	r1, r5
	mov r9, r1
	ldr	r0, .L2+8
	bl	printf

### INSERT YOUR CODE HERE
	### r7 contains the first operand
	### r8 contains the sign (+, -, *)
	### r9 contains the second operand

	mov	r0, #0
	### Put the final output in r0
### YOUR CODE ENDS HERE

	ldmfd	sp, {r4, r5, fp, sp, pc}
.L3:
	.align	2
.L2:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.size	process, .-process
	.section	.rodata
	.align	2
	.type	filename.0, %object
	.size	filename.0, 9
filename.0:
	.ascii	"input.txt\000"
	.global	__extendsfdf2
	.section	.rodata.str1.4
	.align	2
.LC3:
	.ascii	"r\000"
	.align	2
.LC4:
	.ascii	"%f %c %f\000"
	.align	2
.LC6:
	.ascii	"Result = %f (float) , %x (hex)\n\000"
	.align	2
.LC5:
	.ascii	"File Not Found \000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 140
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {r4, r5, fp, ip, lr, pc}
	sub	fp, ip, #4
	sub	sp, sp, #144
	ldr	r0, .L12
	ldr	r1, .L12+4
	bl	fopen
	subs	r5, r0, #0
	subne	r4, fp, #152
	bne	.L6
	b	.L11
.L8:
	sub	ip, fp, #160
	str	ip, [sp, #0]
	bl	sscanf
.L6:
	mov	r1, #128
	mov	r2, r5
	mov	r0, r4
	bl	fgets
	cmp	r0, #0
	ldr	r1, .L12+8
	sub	r2, fp, #156
	sub	r3, fp, #21
	mov	r0, r4
	bne	.L8
	mov	r0, r5
	bl	fclose
.L9:
	ldr	r2, [fp, #-160]
	ldrb	r1, [fp, #-21]	@ zero_extendqisi2
	ldr	r0, [fp, #-156]
	bl	process
	mov	r4, r0
	bl	__extendsfdf2
	mov	r3, r4
	mov	r2, r1
	mov	r1, r0
	ldr	r0, .L12+12
	bl	printf
	sub	sp, fp, #20
	ldmfd	sp, {r4, r5, fp, sp, pc}
.L11:
	ldr	r0, .L12+16
	bl	puts
	b	.L9
.L13:
	.align	2
.L12:
	.word	filename.0
	.word	.LC3
	.word	.LC4
	.word	.LC6
	.word	.LC5
	.size	main, .-main
	.ident	"GCC: (GNU) 3.4.3"
