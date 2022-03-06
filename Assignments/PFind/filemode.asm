	.file	"pfind.c"
	.intel_syntax noprefix
	.text
	.p2align 4
	.globl	checkPermissionString
	.type	checkPermissionString, @function
checkPermissionString:
.LFB57:
	.cfi_startproc
	endbr64
	push	rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi
	call	strlen@PLT
	mov	r8, rax
	xor	eax, eax
	cmp	r8, 9
	jne	.L1
	xor	edx, edx
	mov	esi, 2863311531
	jmp	.L9
	.p2align 4,,10
	.p2align 3
.L29:
	movzx	ecx, BYTE PTR [rbx+rdx]
	cmp	cl, 114
	je	.L5
	cmp	cl, 45
	jne	.L1
.L5:
	add	rdx, 1
	cmp	rdx, 9
	je	.L28
.L9:
	mov	eax, edx
	mov	edi, edx
	imul	rax, rsi
	shr	rax, 33
	lea	eax, [rax+rax*2]
	sub	edi, eax
	mov	eax, edi
	je	.L29
	cmp	edi, 1
	movzx	eax, BYTE PTR [rbx+rdx]
	jne	.L6
	cmp	al, 119
	je	.L5
.L25:
	cmp	al, 45
	je	.L5
	xor	eax, eax
.L1:
	pop	rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	.cfi_restore_state
	cmp	al, 120
	jne	.L25
	add	rdx, 1
	cmp	rdx, 9
	jne	.L9
.L28:
	mov	eax, 1
	pop	rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE57:
	.size	checkPermissionString, .-checkPermissionString
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"lol retard.\n"
.LC1:
	.string	"lol okay. %d\n"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Error: Permissions string 'pstring'is invalid."
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB56:
	.cfi_startproc
	endbr64
	push	rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rsi
	mov	edi, 1
	sub	rsp, 160
	.cfi_def_cfa_offset 176
	mov	rsi, QWORD PTR 8[rsi]
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR 152[rsp], rax
	xor	eax, eax
	mov	rdx, rsp
	call	__xstat@PLT
	test	eax, eax
	js	.L35
	mov	edx, DWORD PTR 24[rsp]
	mov	edi, 1
	xor	eax, eax
	lea	rsi, .LC1[rip]
	call	__printf_chk@PLT
	mov	rdi, QWORD PTR 16[rbx]
	call	checkPermissionString
	test	eax, eax
	je	.L36
	mov	rax, QWORD PTR 152[rsp]
	xor	rax, QWORD PTR fs:40
	jne	.L37
	add	rsp, 160
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	xor	eax, eax
	pop	rbx
	.cfi_def_cfa_offset 8
	ret
.L35:
	.cfi_restore_state
	lea	rdi, .LC0[rip]
	call	puts@PLT
	mov	edi, 1
	call	exit@PLT
.L37:
	call	__stack_chk_fail@PLT
.L36:
	mov	edi, 1
	lea	rsi, .LC2[rip]
	call	__printf_chk@PLT
	mov	edi, 1
	call	exit@PLT
	.cfi_endproc
.LFE56:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
