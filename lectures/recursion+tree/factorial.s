	.file	"factorial.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	getESP
	.type	getESP, @function
getESP:
.LFB23:
	.cfi_startproc
#APP
# 12 "factorial.c" 1
	movl %esp, %eax

# 0 "" 2
#NO_APP
	ret
	.cfi_endproc
.LFE23:
	.size	getESP, .-getESP
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	recFact
	.type	recFact, @function
recFact:
.LFB24:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	baseESP, %ebp
	movl	$1, %eax
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	xorl	%edi, %edi
	movl	maxESPOffset, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
#APP
# 12 "factorial.c" 1
	movl %esp, %ecx

# 0 "" 2
#NO_APP
	subl	%ecx, %ebp
	movl	20(%esp), %edx
	movl	%esi, %ebx
	movl	%ebp, %ecx
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L13:
	imull	%edx, %eax
	subl	$1, %edx
.L5:
	cmpl	%ebx, %ecx
	jle	.L3
	movl	%ecx, %esi
	movl	%ecx, %ebx
	movl	$1, %edi
.L3:
	testl	%edx, %edx
	jg	.L13
	movl	%edi, %ebx
	testb	%bl, %bl
	jne	.L14
.L6:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
.L14:
	.cfi_restore_state
	movl	%esi, maxESPOffset
	jmp	.L6
	.cfi_endproc
.LFE24:
	.size	recFact, .-recFact
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text.unlikely
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.globl	iterFact
	.type	iterFact, @function
iterFact:
.LFB25:
	.cfi_startproc
	movl	4(%esp), %ecx
	movl	baseESP, %edx
#APP
# 12 "factorial.c" 1
	movl %esp, %eax

# 0 "" 2
#NO_APP
	subl	%eax, %edx
	cmpl	$1, %ecx
	movl	%edx, maxESPOffset
	jle	.L18
	addl	$1, %ecx
	movl	$2, %edx
	movl	$1, %eax
	.p2align 4,,10
	.p2align 3
.L17:
	imull	%edx, %eax
	addl	$1, %edx
	cmpl	%ecx, %edx
	jne	.L17
	rep ret
.L18:
	movl	$1, %eax
	ret
	.cfi_endproc
.LFE25:
	.size	iterFact, .-iterFact
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC3:
	.string	"res:%d max esp offset:%d\n"
	.section	.text.unlikely
.LCOLDB4:
	.section	.text.startup,"ax",@progbits
.LHOTB4:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB26:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
#APP
# 12 "factorial.c" 1
	movl %esp, %eax

# 0 "" 2
#NO_APP
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%esi
	.cfi_escape 0x10,0x6,0x2,0x75,0x7c
	movl	%eax, %esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x74,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x78
	xorl	%ebx, %ebx
#APP
# 12 "factorial.c" 1
	movl %esp, %ecx

# 0 "" 2
#NO_APP
	subl	%ecx, %esi
	subl	$12, %esp
	movl	%eax, baseESP
	cmpl	%esi, %ebx
	movl	$0, maxESPOffset
	jl	.L36
	xorl	%edx, %edx
	movl	%ebx, %ecx
.L24:
	movl	%eax, %esi
#APP
# 12 "factorial.c" 1
	movl %esp, %ebx

# 0 "" 2
#NO_APP
	subl	%ebx, %esi
	cmpl	%esi, %ecx
	movl	%esi, %ebx
	jl	.L37
	movl	%ecx, %ebx
.L25:
	movl	%eax, %esi
#APP
# 12 "factorial.c" 1
	movl %esp, %ecx

# 0 "" 2
#NO_APP
	subl	%ecx, %esi
	cmpl	%esi, %ebx
	movl	%esi, %ecx
	jl	.L38
	movl	%ebx, %ecx
.L26:
	movl	%eax, %esi
#APP
# 12 "factorial.c" 1
	movl %esp, %ebx

# 0 "" 2
#NO_APP
	subl	%ebx, %esi
	cmpl	%esi, %ecx
	movl	%esi, %ebx
	jl	.L39
	movl	%ecx, %ebx
.L27:
	movl	%eax, %esi
#APP
# 12 "factorial.c" 1
	movl %esp, %ecx

# 0 "" 2
#NO_APP
	subl	%ecx, %esi
	cmpl	%esi, %ebx
	movl	%esi, %ecx
	jl	.L40
	movl	%ebx, %ecx
.L28:
	movl	%eax, %esi
#APP
# 12 "factorial.c" 1
	movl %esp, %ebx

# 0 "" 2
#NO_APP
	subl	%ebx, %esi
	cmpl	%esi, %ecx
	movl	%esi, %ebx
	jl	.L41
	movl	%ecx, %ebx
.L29:
	movl	%eax, %esi
#APP
# 12 "factorial.c" 1
	movl %esp, %ecx

# 0 "" 2
#NO_APP
	subl	%ecx, %esi
	cmpl	%esi, %ebx
	movl	%esi, %ecx
	jl	.L42
	movl	%ebx, %ecx
.L30:
#APP
# 12 "factorial.c" 1
	movl %esp, %ebx

# 0 "" 2
#NO_APP
	subl	%ebx, %eax
	cmpl	%ecx, %eax
	jle	.L47
.L31:
	movl	%eax, maxESPOffset
	movl	%eax, %ecx
.L32:
	pushl	%ecx
	pushl	$3628800
	pushl	$.LC3
	pushl	$1
	call	__printf_chk
	movl	baseESP, %edx
#APP
# 12 "factorial.c" 1
	movl %esp, %eax

# 0 "" 2
#NO_APP
	subl	%eax, %edx
	pushl	%edx
	pushl	$3628800
	pushl	$.LC3
	pushl	$1
	movl	%edx, maxESPOffset
	call	__printf_chk
	addl	$32, %esp
	leal	-12(%ebp), %esp
	xorl	%eax, %eax
	popl	%ecx
	.cfi_remember_state
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
.L47:
	.cfi_restore_state
	testb	%dl, %dl
	je	.L32
	movl	%ecx, %eax
	jmp	.L31
.L42:
	movl	$1, %edx
	jmp	.L30
.L41:
	movl	$1, %edx
	jmp	.L29
.L40:
	movl	$1, %edx
	jmp	.L28
.L39:
	movl	$1, %edx
	jmp	.L27
.L38:
	movl	$1, %edx
	jmp	.L26
.L37:
	movl	$1, %edx
	jmp	.L25
.L36:
	movl	%esi, %ecx
	movl	$1, %edx
	jmp	.L24
	.cfi_endproc
.LFE26:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE4:
	.section	.text.startup
.LHOTE4:
	.globl	maxESPOffset
	.bss
	.align 4
	.type	maxESPOffset, @object
	.size	maxESPOffset, 4
maxESPOffset:
	.zero	4
	.comm	baseESP,4,4
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
