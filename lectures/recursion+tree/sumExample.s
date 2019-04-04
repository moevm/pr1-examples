	.file	"sumExample.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	recSum
	.type	recSum, @function
recSum:
.LFB62:
	.cfi_startproc
	movl	8(%esp), %edx
	xorl	%eax, %eax
	movl	4(%esp), %ecx
	testl	%edx, %edx
	je	.L4
	.p2align 4,,10
	.p2align 3
.L3:
	addl	-4(%ecx,%edx,4), %eax
	subl	$1, %edx
	jne	.L3
	rep ret
.L4:
	rep ret
	.cfi_endproc
.LFE62:
	.size	recSum, .-recSum
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	iterSum
	.type	iterSum, @function
iterSum:
.LFB63:
	.cfi_startproc
	movl	8(%esp), %eax
	testl	%eax, %eax
	jle	.L10
	movl	4(%esp), %edx
	leal	(%edx,%eax,4), %ecx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L9:
	addl	(%edx), %eax
	addl	$4, %edx
	cmpl	%edx, %ecx
	jne	.L9
	rep ret
.L10:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE63:
	.size	iterSum, .-iterSum
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"%ld\n"
	.section	.text.unlikely
.LCOLDB3:
	.section	.text.startup,"ax",@progbits
.LHOTB3:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB64:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	call	clock
	movl	%eax, %ebx
	call	clock
	subl	$4, %esp
	subl	%ebx, %eax
	pushl	%eax
	pushl	$.LC2
	pushl	$1
	call	__printf_chk
	call	clock
	movl	%eax, %ebx
	call	clock
	addl	$12, %esp
	subl	%ebx, %eax
	pushl	%eax
	pushl	$.LC2
	pushl	$1
	call	__printf_chk
	addl	$16, %esp
	leal	-8(%ebp), %esp
	xorl	%eax, %eax
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE64:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE3:
	.section	.text.startup
.LHOTE3:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
