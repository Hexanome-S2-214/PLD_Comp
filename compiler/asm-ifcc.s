
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
	movb $88, %al
	movl %eax, %edi
	call putchar@PLT
	jmp .L6
.L7:
	movb $89, %al
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
	movb $79, %al
	movl %eax, %edi
	call putchar@PLT
	movb $78, %al
	movl %eax, %edi
	call putchar@PLT
	movb $33, %al
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
	movb $44, %al
	movl %eax, %edi
	call putchar@PLT
	movb $32, %al
	movl %eax, %edi
	call putchar@PLT
	movb $68, %al
	movl %eax, %edi
	call putchar@PLT
	movb $82, %al
	movl %eax, %edi
	call putchar@PLT
	movb $65, %al
	movl %eax, %edi
	call putchar@PLT
	movb $87, %al
	movl %eax, %edi
	call putchar@PLT
	movb $33, %al
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
	subq $144, %rsp
.L13:
	movl $6, %eax
	movl %eax, -4(%rbp)
	movl $7, %eax
	movl %eax, -12(%rbp)
	movb $88, %al
	movb %al, -17(%rbp)
	movl $9, %eax
	movl %eax, -22(%rbp)
	movl $1, %eax
	movl %eax, -38(%rbp)
	movl $0, %eax
	movb %al, -43(%rbp)
	movb $32, %al
	movb %al, -53(%rbp)
	movb $32, %al
	movb %al, -54(%rbp)
	movb $32, %al
	movb %al, -56(%rbp)
	movb $32, %al
	movb %al, -55(%rbp)
	movb $32, %al
	movb %al, -57(%rbp)
	movb $32, %al
	movb %al, -58(%rbp)
	movb $32, %al
	movb %al, -59(%rbp)
	movb $32, %al
	movb %al, -60(%rbp)
	movb $32, %al
	movb %al, -61(%rbp)
	jmp .L14
.L14:
	movl -38(%rbp), %eax
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
	movl %eax, -30(%rbp)
	movl $1, %eax
	movl %eax, -48(%rbp)
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
	movzbl -53(%rbp), %eax
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
	movzbl -54(%rbp), %eax
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
	movzbl -55(%rbp), %eax
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
	movb $50, %al
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
	movb -17(%rbp), %al
	movl %eax, -82(%rbp)
	movb $88, %al
	movl %eax, %ebx
	movl -82(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %edi
	call print_player_turn
	call getchar@PLT
	movl %eax, -66(%rbp)
	call getchar@PLT
	movl %eax, -74(%rbp)
	call getchar@PLT
	movl -66(%rbp), %eax
	movl %eax, -90(%rbp)
	movb $48, %al
	movl %eax, %ebx
	movl -90(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	setl %al
	movzbl %al, %eax
	je .L17
	movl -66(%rbp), %eax
	movl %eax, -98(%rbp)
	movb $48, %al
	movl %eax, %ebx
	movl -98(%rbp), %eax
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
	movl %eax, -30(%rbp)
	jmp .L19
	jmp .L14
.L17:
	movl $1, %eax
	jmp .L18
.L18:
.L19:
	movl -74(%rbp), %eax
	movl %eax, -106(%rbp)
	movb $48, %al
	movl %eax, %ebx
	movl -106(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	setl %al
	movzbl %al, %eax
	je .L20
	movl -74(%rbp), %eax
	movl %eax, -114(%rbp)
	movb $48, %al
	movl %eax, %ebx
	movl -114(%rbp), %eax
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
	movl %eax, -30(%rbp)
	jmp .L22
	jmp .L21
.L20:
	movl $1, %eax
	jmp .L21
.L21:
.L22:
	movl -30(%rbp), %eax
	movl %eax, %ecx
	movl $1, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L23
	movl -66(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L24
	movl -74(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L25
	movzbl -53(%rbp), %eax
	movl %eax, %ecx
	movb $32, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L27
	movb -17(%rbp), %al
	movb %al, -53(%rbp)
	movzbl -54(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L28
	movzbl -55(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L30
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L30
	jmp .L29
.L28:
	movl $0, %eax
	jmp .L29
.L29:
.L30:
	movzbl -56(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L31
	movzbl -59(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L33
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L33
	jmp .L32
.L31:
	movl $0, %eax
	jmp .L32
.L32:
.L33:
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L34
	movzbl -61(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L36
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L36
	jmp .L35
.L34:
	movl $0, %eax
	jmp .L35
.L35:
.L36:
	jmp .L26
	jmp .L26
.L27:
	movl $0, %eax
	movl %eax, -48(%rbp)
	jmp .L26
.L26:
	jmp .L25
	jmp .L25
.L25:
	movl -74(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L37
	movzbl -54(%rbp), %eax
	movl %eax, %ecx
	movb $32, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L39
	movb -17(%rbp), %al
	movb %al, -54(%rbp)
	movzbl -53(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L40
	movzbl -55(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L42
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L42
	jmp .L41
.L40:
	movl $0, %eax
	jmp .L41
.L41:
.L42:
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L43
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L45
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L45
	jmp .L44
.L43:
	movl $0, %eax
	jmp .L44
.L44:
.L45:
	jmp .L38
	jmp .L38
.L39:
	movl $0, %eax
	movl %eax, -48(%rbp)
	jmp .L38
.L38:
	jmp .L37
	jmp .L37
.L37:
	movl -74(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L46
	movzbl -55(%rbp), %eax
	movl %eax, %ecx
	movb $32, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L48
	movb -17(%rbp), %al
	movb %al, -55(%rbp)
	movzbl -53(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L49
	movzbl -54(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L51
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L51
	jmp .L50
.L49:
	movl $0, %eax
	jmp .L50
.L50:
.L51:
	movzbl -58(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L52
	movzbl -61(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L54
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L54
	jmp .L53
.L52:
	movl $0, %eax
	jmp .L53
.L53:
.L54:
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L55
	movzbl -59(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L57
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L57
	jmp .L56
.L55:
	movl $0, %eax
	jmp .L56
.L56:
.L57:
	jmp .L47
	jmp .L47
.L48:
	movl $0, %eax
	movl %eax, -48(%rbp)
	jmp .L47
.L47:
	jmp .L46
	jmp .L46
.L46:
	jmp .L24
	jmp .L24
.L24:
	movl -66(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L58
	movl -74(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L59
	movzbl -56(%rbp), %eax
	movl %eax, %ecx
	movb $32, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L61
	movb -17(%rbp), %al
	movb %al, -56(%rbp)
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L62
	movzbl -58(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L64
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L64
	jmp .L63
.L62:
	movl $0, %eax
	jmp .L63
.L63:
.L64:
	movzbl -53(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L65
	movzbl -59(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L67
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L67
	jmp .L66
.L65:
	movl $0, %eax
	jmp .L66
.L66:
.L67:
	jmp .L60
	jmp .L60
.L61:
	movl $0, %eax
	movl %eax, -48(%rbp)
	jmp .L60
.L60:
	jmp .L59
	jmp .L59
.L59:
	movl -74(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L68
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb $32, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L70
	movb -17(%rbp), %al
	movb %al, -57(%rbp)
	movzbl -56(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L71
	movzbl -58(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L73
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L73
	jmp .L72
.L71:
	movl $0, %eax
	jmp .L72
.L72:
.L73:
	movzbl -54(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L74
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L76
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L76
	jmp .L75
.L74:
	movl $0, %eax
	jmp .L75
.L75:
.L76:
	movzbl -53(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L77
	movzbl -61(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L79
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L79
	jmp .L78
.L77:
	movl $0, %eax
	jmp .L78
.L78:
.L79:
	movzbl -55(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L80
	movzbl -59(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L82
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L82
	jmp .L81
.L80:
	movl $0, %eax
	jmp .L81
.L81:
.L82:
	jmp .L69
	jmp .L69
.L70:
	movl $0, %eax
	movl %eax, -48(%rbp)
	jmp .L69
.L69:
	jmp .L68
	jmp .L68
.L68:
	movl -74(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L83
	movzbl -58(%rbp), %eax
	movl %eax, %ecx
	movb $32, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L85
	movb -17(%rbp), %al
	movb %al, -58(%rbp)
	movzbl -56(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L86
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L88
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L88
	jmp .L87
.L86:
	movl $0, %eax
	jmp .L87
.L87:
.L88:
	movzbl -55(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L89
	movzbl -61(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L91
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L91
	jmp .L90
.L89:
	movl $0, %eax
	jmp .L90
.L90:
.L91:
	jmp .L84
	jmp .L84
.L85:
	movl $0, %eax
	movl %eax, -48(%rbp)
	jmp .L84
.L84:
	jmp .L83
	jmp .L83
.L83:
	jmp .L58
	jmp .L58
.L58:
	movl -66(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L92
	movl -74(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L93
	movzbl -59(%rbp), %eax
	movl %eax, %ecx
	movb $32, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L95
	movb -17(%rbp), %al
	movb %al, -59(%rbp)
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L96
	movzbl -61(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L98
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L98
	jmp .L97
.L96:
	movl $0, %eax
	jmp .L97
.L97:
.L98:
	movzbl -53(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L99
	movzbl -56(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L101
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L101
	jmp .L100
.L99:
	movl $0, %eax
	jmp .L100
.L100:
.L101:
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L102
	movzbl -55(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L104
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L104
	jmp .L103
.L102:
	movl $0, %eax
	jmp .L103
.L103:
.L104:
	jmp .L94
	jmp .L94
.L95:
	movl $0, %eax
	movl %eax, -48(%rbp)
	jmp .L94
.L94:
	jmp .L93
	jmp .L93
.L93:
	movl -74(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L105
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb $32, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L107
	movb -17(%rbp), %al
	movb %al, -60(%rbp)
	movzbl -59(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L108
	movzbl -61(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L110
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L110
	jmp .L109
.L108:
	movl $0, %eax
	jmp .L109
.L109:
.L110:
	movzbl -54(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L111
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L113
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L113
	jmp .L112
.L111:
	movl $0, %eax
	jmp .L112
.L112:
.L113:
	jmp .L106
	jmp .L106
.L107:
	movl $0, %eax
	movl %eax, -48(%rbp)
	jmp .L106
.L106:
	jmp .L105
	jmp .L105
.L105:
	movl -74(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L114
	movzbl -61(%rbp), %eax
	movl %eax, %ecx
	movb $32, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L116
	movb -17(%rbp), %al
	movb %al, -61(%rbp)
	movzbl -59(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L117
	movzbl -60(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L119
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L119
	jmp .L118
.L117:
	movl $0, %eax
	jmp .L118
.L118:
.L119:
	movzbl -55(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L120
	movzbl -58(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L122
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L122
	jmp .L121
.L120:
	movl $0, %eax
	jmp .L121
.L121:
.L122:
	movzbl -53(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L123
	movzbl -57(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L125
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L125
	jmp .L124
.L123:
	movl $0, %eax
	jmp .L124
.L124:
.L125:
	jmp .L115
	jmp .L115
.L116:
	movl $0, %eax
	movl %eax, -48(%rbp)
	jmp .L115
.L115:
	jmp .L114
	jmp .L114
.L114:
	jmp .L92
	jmp .L92
.L92:
	movl -48(%rbp), %eax
	movl %eax, %ecx
	movl $1, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L126
	movl -22(%rbp), %eax
	movl %eax, -122(%rbp)
	movl $1, %eax
	movl %eax, %ebx
	movl -122(%rbp), %eax
	subl %ebx, %eax
	movl %eax, -22(%rbp)
	jmp .L126
	jmp .L23
.L126:
	movb -43(%rbp), %al
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	setne %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L127
	movl $0, %eax
	movl %eax, -38(%rbp)
	movb -43(%rbp), %al
	movl %eax, -130(%rbp)
	movb $65, %al
	movl %eax, %ebx
	movl -130(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %edi
	call print_game_won
	jmp .L127
	jmp .L23
.L127:
	movl -22(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L128
	movb -43(%rbp), %al
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L130
	movl $0, %eax
	movl %eax, -38(%rbp)
	call print_full_board
	jmp .L130
	jmp .L129
.L128:
	movl $0, %eax
	jmp .L129
.L129:
.L130:
	movl -48(%rbp), %eax
	movl %eax, %ecx
	movl $1, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L131
	movb -17(%rbp), %al
	movl %eax, %ecx
	movb $88, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L133
	movb $79, %al
	movb %al, -17(%rbp)
	jmp .L132
	jmp .L23
.L133:
	movb $88, %al
	movb %al, -17(%rbp)
	jmp .L132
.L132:
	jmp .L131
	jmp .L131
.L131:
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
	movzbl -53(%rbp), %eax
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
	movzbl -54(%rbp), %eax
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
	movzbl -55(%rbp), %eax
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
	movl $0, %eax
	jmp .L12
.L12:

	leave
	ret
