
.globl print_wrong_input
print_wrong_input:
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
.L3:
	movb $87, %al
	movl %eax, %edi
	call putchar@PLT
	movb $114, %al
	movl %eax, %edi
	call putchar@PLT
	movb $111, %al
	movl %eax, %edi
	call putchar@PLT
	movb $110, %al
	movl %eax, %edi
	call putchar@PLT
	movb $103, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $73, %al
	movl %eax, %edi
	call putchar@PLT
	movb $110, %al
	movl %eax, %edi
	call putchar@PLT
	movb $112, %al
	movl %eax, %edi
	call putchar@PLT
	movb $117, %al
	movl %eax, %edi
	call putchar@PLT
	movb $116, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
.L2:

	leave
	ret

.globl print_player_turn
print_player_turn:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
.L5:
	movl %edi, -4(%rbp)
	movb $80, %al
	movl %eax, %edi
	call putchar@PLT
	movb $108, %al
	movl %eax, %edi
	call putchar@PLT
	movb $97, %al
	movl %eax, %edi
	call putchar@PLT
	movb $121, %al
	movl %eax, %edi
	call putchar@PLT
	movb $101, %al
	movl %eax, %edi
	call putchar@PLT
	movb $114, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movl -4(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L7
	movb $48, %al
	movl %eax, %edi
	call putchar@PLT
	jmp .L6
.L7:
	movb $49, %al
	movl %eax, %edi
	call putchar@PLT
	jmp .L6
.L6:
	movb $58, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movl $0, %eax
	jmp .L4
.L4:

	leave
	ret

.globl print_game_won
print_game_won:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
.L9:
	movl %edi, -4(%rbp)
	movb $65, %al
	movl %eax, -12(%rbp)
	movl -4(%rbp), %eax
	addl -12(%rbp), %eax
	movb %al, -17(%rbp)
	movb $80, %al
	movl %eax, %edi
	call putchar@PLT
	movb $108, %al
	movl %eax, %edi
	call putchar@PLT
	movb $97, %al
	movl %eax, %edi
	call putchar@PLT
	movb $121, %al
	movl %eax, %edi
	call putchar@PLT
	movb $101, %al
	movl %eax, %edi
	call putchar@PLT
	movb $114, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -17(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $87, %al
	movl %eax, %edi
	call putchar@PLT
	movb $111, %al
	movl %eax, %edi
	call putchar@PLT
	movb $110, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
.L8:

	leave
	ret

.globl print_full_board
print_full_board:
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
.L11:
	movb $66, %al
	movl %eax, %edi
	call putchar@PLT
	movb $111, %al
	movl %eax, %edi
	call putchar@PLT
	movb $97, %al
	movl %eax, %edi
	call putchar@PLT
	movb $114, %al
	movl %eax, %edi
	call putchar@PLT
	movb $100, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $105, %al
	movl %eax, %edi
	call putchar@PLT
	movb $115, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $102, %al
	movl %eax, %edi
	call putchar@PLT
	movb $117, %al
	movl %eax, %edi
	call putchar@PLT
	movb $108, %al
	movl %eax, %edi
	call putchar@PLT
	movb $108, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
.L10:

	leave
	ret

.globl main
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $160, %rsp
.L13:
	movl $6, %eax
	movl %eax, -4(%rbp)
	movl $7, %eax
	movl %eax, -12(%rbp)
	movl $0, %eax
	movl %eax, -20(%rbp)
	movl $9, %eax
	movl %eax, -28(%rbp)
	movl $1, %eax
	movl %eax, -47(%rbp)
	movl $0, %eax
	movb %al, -52(%rbp)
	movb $32, %al
	movb %al, -56(%rbp)
	movb $32, %al
	movb %al, -57(%rbp)
	movb $32, %al
	movb %al, -59(%rbp)
	movb $32, %al
	movb %al, -58(%rbp)
	movb $32, %al
	movb %al, -60(%rbp)
	movb $32, %al
	movb %al, -61(%rbp)
	movb $32, %al
	movb %al, -62(%rbp)
	movb $32, %al
	movb %al, -63(%rbp)
	movb $32, %al
	movb %al, -64(%rbp)
	jmp .L14
.L14:
	movl -47(%rbp), %eax
	movl %eax, %ecx
	movl $1, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	je .L15
	jmp .L16
.L15:
	movl $1, %eax
	movl %eax, -39(%rbp)
	movb $66, %al
	movl %eax, %edi
	call putchar@PLT
	movb $79, %al
	movl %eax, %edi
	call putchar@PLT
	movb $65, %al
	movl %eax, %edi
	call putchar@PLT
	movb $82, %al
	movl %eax, %edi
	call putchar@PLT
	movb $68, %al
	movl %eax, %edi
	call putchar@PLT
	movb $58, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $48, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $49, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $50, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $48, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -56(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -57(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -58(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $49, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -59(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -60(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -61(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $50, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -62(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -63(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -64(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movl -20(%rbp), %eax
	movl %eax, %edi
	call print_player_turn
	call getchar@PLT
	movl %eax, -69(%rbp)
	call getchar@PLT
	movl %eax, -77(%rbp)
	call getchar@PLT
	movl -69(%rbp), %eax
	movl %eax, -85(%rbp)
	movb $48, %al
	movl %eax, %ebx
	movl -85(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	setl %al
	movzbl %al, %eax
	je .L17
	movl -69(%rbp), %eax
	movl %eax, -93(%rbp)
	movb $48, %al
	movl %eax, %ebx
	movl -93(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %ecx
	movl $2, %eax
	cmpl %eax, %ecx
	setg %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L19
	call print_wrong_input
	movl $0, %eax
	movl %eax, -39(%rbp)
	jmp .L19
	jmp .L14
.L17:
	movl $1, %eax
	jmp .L18
.L18:
.L19:
	movl -77(%rbp), %eax
	movl %eax, -101(%rbp)
	movb $48, %al
	movl %eax, %ebx
	movl -101(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	setl %al
	movzbl %al, %eax
	je .L20
	movl -77(%rbp), %eax
	movl %eax, -109(%rbp)
	movb $48, %al
	movl %eax, %ebx
	movl -109(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %ecx
	movl $2, %eax
	cmpl %eax, %ecx
	setg %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L22
	call print_wrong_input
	movl $0, %eax
	movl %eax, -39(%rbp)
	jmp .L22
	jmp .L21
.L20:
	movl $1, %eax
	jmp .L21
.L21:
.L22:
	movl -39(%rbp), %eax
	movl %eax, %ecx
	movl $1, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L23
	movl -28(%rbp), %eax
	movl %eax, -117(%rbp)
	movl $1, %eax
	movl %eax, %ebx
	movl -117(%rbp), %eax
	subl %ebx, %eax
	movl %eax, -28(%rbp)
	movl -69(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L24
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L25
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L27
	movb $88, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -56(%rbp)
	jmp .L26
	jmp .L14
.L27:
	movb $89, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -56(%rbp)
	jmp .L26
.L26:
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L28
	movzbl -58(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L30
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L30
	jmp .L29
.L28:
	movl $0, %eax
	jmp .L29
.L29:
.L30:
	movzbl -59(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L31
	movzbl -62(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L33
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L33
	jmp .L32
.L31:
	movl $0, %eax
	jmp .L32
.L32:
.L33:
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L34
	movzbl -64(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L36
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L36
	jmp .L35
.L34:
	movl $0, %eax
	jmp .L35
.L35:
.L36:
	jmp .L25
	jmp .L25
.L25:
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L37
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L39
	movb $88, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -57(%rbp)
	jmp .L38
	jmp .L24
.L39:
	movb $89, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -57(%rbp)
	jmp .L38
.L38:
	movzbl -56(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L40
	movzbl -58(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L42
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L42
	jmp .L41
.L40:
	movl $0, %eax
	jmp .L41
.L41:
.L42:
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L43
	movzbl -63(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L45
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L45
	jmp .L44
.L43:
	movl $0, %eax
	jmp .L44
.L44:
.L45:
	jmp .L37
	jmp .L37
.L37:
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L46
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L48
	movb $88, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -58(%rbp)
	jmp .L47
	jmp .L24
.L48:
	movb $89, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -58(%rbp)
	jmp .L47
.L47:
	movzbl -56(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L49
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L51
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L51
	jmp .L50
.L49:
	movl $0, %eax
	jmp .L50
.L50:
.L51:
	movzbl -61(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L52
	movzbl -64(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L54
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L54
	jmp .L53
.L52:
	movl $0, %eax
	jmp .L53
.L53:
.L54:
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L55
	movzbl -62(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L57
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L57
	jmp .L56
.L55:
	movl $0, %eax
	jmp .L56
.L56:
.L57:
	jmp .L46
	jmp .L46
.L46:
	jmp .L24
	jmp .L24
.L24:
	movl -69(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L58
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L59
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L61
	movb $88, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -59(%rbp)
	jmp .L60
	jmp .L23
.L61:
	movb $89, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -59(%rbp)
	jmp .L60
.L60:
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L62
	movzbl -61(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L64
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L64
	jmp .L63
.L62:
	movl $0, %eax
	jmp .L63
.L63:
.L64:
	movzbl -56(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L65
	movzbl -62(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L67
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L67
	jmp .L66
.L65:
	movl $0, %eax
	jmp .L66
.L66:
.L67:
	jmp .L59
	jmp .L59
.L59:
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L68
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L70
	movb $88, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -60(%rbp)
	jmp .L69
	jmp .L58
.L70:
	movb $89, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -60(%rbp)
	jmp .L69
.L69:
	movzbl -59(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L71
	movzbl -61(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L73
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L73
	jmp .L72
.L71:
	movl $0, %eax
	jmp .L72
.L72:
.L73:
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L74
	movzbl -63(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L76
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L76
	jmp .L75
.L74:
	movl $0, %eax
	jmp .L75
.L75:
.L76:
	movzbl -56(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L77
	movzbl -64(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L79
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L79
	jmp .L78
.L77:
	movl $0, %eax
	jmp .L78
.L78:
.L79:
	movzbl -58(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L80
	movzbl -62(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L82
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L82
	jmp .L81
.L80:
	movl $0, %eax
	jmp .L81
.L81:
.L82:
	jmp .L68
	jmp .L68
.L68:
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L83
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L85
	movb $88, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -61(%rbp)
	jmp .L84
	jmp .L58
.L85:
	movb $89, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -61(%rbp)
	jmp .L84
.L84:
	movzbl -59(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L86
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L88
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L88
	jmp .L87
.L86:
	movl $0, %eax
	jmp .L87
.L87:
.L88:
	movzbl -58(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L89
	movzbl -64(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L91
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L91
	jmp .L90
.L89:
	movl $0, %eax
	jmp .L90
.L90:
.L91:
	jmp .L83
	jmp .L83
.L83:
	jmp .L58
	jmp .L58
.L58:
	movl -69(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L92
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L93
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L95
	movb $88, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -62(%rbp)
	jmp .L94
	jmp .L23
.L95:
	movb $89, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -62(%rbp)
	jmp .L94
.L94:
	movzbl -63(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L96
	movzbl -64(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L98
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L98
	jmp .L97
.L96:
	movl $0, %eax
	jmp .L97
.L97:
.L98:
	movzbl -56(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L99
	movzbl -59(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L101
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L101
	jmp .L100
.L99:
	movl $0, %eax
	jmp .L100
.L100:
.L101:
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L102
	movzbl -58(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L104
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L104
	jmp .L103
.L102:
	movl $0, %eax
	jmp .L103
.L103:
.L104:
	jmp .L93
	jmp .L93
.L93:
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L105
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L107
	movb $88, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -63(%rbp)
	jmp .L106
	jmp .L92
.L107:
	movb $89, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -63(%rbp)
	jmp .L106
.L106:
	movzbl -62(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L108
	movzbl -64(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L110
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L110
	jmp .L109
.L108:
	movl $0, %eax
	jmp .L109
.L109:
.L110:
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L111
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L113
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L113
	jmp .L112
.L111:
	movl $0, %eax
	jmp .L112
.L112:
.L113:
	jmp .L105
	jmp .L105
.L105:
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L114
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L116
	movb $88, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -64(%rbp)
	jmp .L115
	jmp .L92
.L116:
	movb $89, %al
	movb %al, -54(%rbp)
	movb -54(%rbp), %al
	movb %al, -64(%rbp)
	jmp .L115
.L115:
	movzbl -62(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L117
	movzbl -63(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L119
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L119
	jmp .L118
.L117:
	movl $0, %eax
	jmp .L118
.L118:
.L119:
	movzbl -58(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L120
	movzbl -61(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L122
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L122
	jmp .L121
.L120:
	movl $0, %eax
	jmp .L121
.L121:
.L122:
	movzbl -56(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L123
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb -54(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L125
	movb -54(%rbp), %al
	movb %al, -52(%rbp)
	jmp .L125
	jmp .L124
.L123:
	movl $0, %eax
	jmp .L124
.L124:
.L125:
	jmp .L114
	jmp .L114
.L114:
	jmp .L92
	jmp .L92
.L92:
	movb -52(%rbp), %al
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	setne %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L126
	movl $0, %eax
	movl %eax, -47(%rbp)
	movb -52(%rbp), %al
	movl %eax, -125(%rbp)
	movb $65, %al
	movl %eax, %ebx
	movl -125(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %edi
	call print_game_won
	jmp .L126
	jmp .L23
.L126:
	movl -28(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L127
	movb -52(%rbp), %al
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L129
	movl $0, %eax
	movl %eax, -47(%rbp)
	call print_full_board
	jmp .L129
	jmp .L128
.L127:
	movl $0, %eax
	jmp .L128
.L128:
.L129:
	movl -20(%rbp), %eax
	movl %eax, -133(%rbp)
	movl $1, %eax
	addl -133(%rbp), %eax
	movl %eax, -141(%rbp)
	movl $2, %eax
	movl %eax, %ebx
	movl -141(%rbp), %eax
	cltd
	idivl %ebx
	movl %edx, %eax
	movl %eax, -20(%rbp)
	jmp .L23
	jmp .L23
.L23:
	jmp .L14
.L16:
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $70, %al
	movl %eax, %edi
	call putchar@PLT
	movb $73, %al
	movl %eax, %edi
	call putchar@PLT
	movb $78, %al
	movl %eax, %edi
	call putchar@PLT
	movb $65, %al
	movl %eax, %edi
	call putchar@PLT
	movb $76, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $66, %al
	movl %eax, %edi
	call putchar@PLT
	movb $79, %al
	movl %eax, %edi
	call putchar@PLT
	movb $65, %al
	movl %eax, %edi
	call putchar@PLT
	movb $82, %al
	movl %eax, %edi
	call putchar@PLT
	movb $68, %al
	movl %eax, %edi
	call putchar@PLT
	movb $58, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -56(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -57(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -58(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -59(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -60(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -61(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -62(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -63(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -64(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $124, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $45, %al
	movl %eax, %edi
	call putchar@PLT
	movb $43, %al
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movl $0, %eax
	jmp .L12
.L12:

	leave
	ret
