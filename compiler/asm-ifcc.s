
.globl main
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
.L3:
	movl $3, %eax
	movl %eax, -28(%rbp)
	movl $10, %eax
	movl %eax, -16(%rbp)
	movl -44(%rbp), %eax
	movl %eax, -12(%rbp)
	movl -12(%rbp), %eax
	jmp .L2
.L2:

	leave
	ret
