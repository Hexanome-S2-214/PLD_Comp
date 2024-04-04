
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
	subq $128, %rsp
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
	movb %al, -45(%rbp)
	movb $32, %al
	movb %al, -46(%rbp)
	movb $32, %al
	movb %al, -48(%rbp)
	movb $32, %al
	movb %al, -47(%rbp)
	movb $32, %al
	movb %al, -49(%rbp)
	movb $32, %al
	movb %al, -50(%rbp)
	movb $32, %al
	movb %al, -51(%rbp)
	movb $32, %al
	movb %al, -52(%rbp)
	movb $32, %al
	movb %al, -53(%rbp)
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
	movzbl -45(%rbp), %eax
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
	movzbl -46(%rbp), %eax
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
	movzbl -47(%rbp), %eax
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
	movzbl -48(%rbp), %eax
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
	movzbl -49(%rbp), %eax
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
	movzbl -50(%rbp), %eax
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
	movzbl -51(%rbp), %eax
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
	movzbl -52(%rbp), %eax
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
	movzbl -53(%rbp), %eax
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
	movl %eax, -74(%rbp)
	movb $88, %al
	movl %eax, %ebx
	movl -74(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %edi
	call print_player_turn
	call getchar@PLT
	movl %eax, -58(%rbp)
	call getchar@PLT
	movl %eax, -66(%rbp)
	call getchar@PLT
	movl -58(%rbp), %eax
	movl %eax, -82(%rbp)
	movb $48, %al
	movl %eax, %ebx
	movl -82(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	setl %al
	movzbl %al, %eax
	je .L17
	movl -58(%rbp), %eax
	movl %eax, -90(%rbp)
	movb $48, %al
	movl %eax, %ebx
	movl -90(%rbp), %eax
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
	movl -66(%rbp), %eax
	movl %eax, -98(%rbp)
	movb $48, %al
	movl %eax, %ebx
	movl -98(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	setl %al
	movzbl %al, %eax
	je .L20
	movl -66(%rbp), %eax
	movl %eax, -106(%rbp)
	movb $48, %al
	movl %eax, %ebx
	movl -106(%rbp), %eax
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
	movl -22(%rbp), %eax
	movl %eax, -114(%rbp)
	movl $1, %eax
	movl %eax, %ebx
	movl -114(%rbp), %eax
	subl %ebx, %eax
	movl %eax, -22(%rbp)
	movl -58(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L24
	movl -66(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L25
	movb -17(%rbp), %al
	movb %al, -45(%rbp)
	movzbl -46(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L26
	movzbl -47(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L28
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L28
	jmp .L27
.L26:
	movl $0, %eax
	jmp .L27
.L27:
.L28:
	movzbl -48(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L29
	movzbl -51(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L31
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L31
	jmp .L30
.L29:
	movl $0, %eax
	jmp .L30
.L30:
.L31:
	movzbl -49(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L32
	movzbl -53(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L34
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L34
	jmp .L33
.L32:
	movl $0, %eax
	jmp .L33
.L33:
.L34:
	jmp .L25
	jmp .L25
.L25:
	movl -66(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L35
	movb -17(%rbp), %al
	movb %al, -46(%rbp)
	movzbl -45(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L36
	movzbl -47(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L38
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L38
	jmp .L37
.L36:
	movl $0, %eax
	jmp .L37
.L37:
.L38:
	movzbl -49(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L39
	movzbl -52(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L41
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L41
	jmp .L40
.L39:
	movl $0, %eax
	jmp .L40
.L40:
.L41:
	jmp .L35
	jmp .L35
.L35:
	movl -66(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L42
	movb -17(%rbp), %al
	movb %al, -47(%rbp)
	movzbl -45(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L43
	movzbl -46(%rbp), %eax
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
	movzbl -50(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L46
	movzbl -53(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L48
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L48
	jmp .L47
.L46:
	movl $0, %eax
	jmp .L47
.L47:
.L48:
	movzbl -49(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L49
	movzbl -51(%rbp), %eax
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
	jmp .L42
	jmp .L42
.L42:
	jmp .L24
	jmp .L24
.L24:
	movl -58(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L52
	movl -66(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L53
	movb -17(%rbp), %al
	movb %al, -48(%rbp)
	movzbl -49(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L54
	movzbl -50(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L56
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L56
	jmp .L55
.L54:
	movl $0, %eax
	jmp .L55
.L55:
.L56:
	movzbl -45(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L57
	movzbl -51(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L59
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L59
	jmp .L58
.L57:
	movl $0, %eax
	jmp .L58
.L58:
.L59:
	jmp .L53
	jmp .L53
.L53:
	movl -66(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L60
	movb -17(%rbp), %al
	movb %al, -49(%rbp)
	movzbl -48(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L61
	movzbl -50(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L63
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L63
	jmp .L62
.L61:
	movl $0, %eax
	jmp .L62
.L62:
.L63:
	movzbl -46(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L64
	movzbl -52(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L66
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L66
	jmp .L65
.L64:
	movl $0, %eax
	jmp .L65
.L65:
.L66:
	movzbl -45(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L67
	movzbl -53(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L69
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L69
	jmp .L68
.L67:
	movl $0, %eax
	jmp .L68
.L68:
.L69:
	movzbl -47(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L70
	movzbl -51(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L72
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L72
	jmp .L71
.L70:
	movl $0, %eax
	jmp .L71
.L71:
.L72:
	jmp .L60
	jmp .L60
.L60:
	movl -66(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L73
	movb -17(%rbp), %al
	movb %al, -50(%rbp)
	movzbl -48(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L74
	movzbl -49(%rbp), %eax
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
	movzbl -47(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L77
	movzbl -53(%rbp), %eax
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
	jmp .L73
	jmp .L73
.L73:
	jmp .L52
	jmp .L52
.L52:
	movl -58(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L80
	movl -66(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L81
	movb -17(%rbp), %al
	movb %al, -51(%rbp)
	movzbl -52(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L82
	movzbl -53(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L84
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L84
	jmp .L83
.L82:
	movl $0, %eax
	jmp .L83
.L83:
.L84:
	movzbl -45(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L85
	movzbl -48(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L87
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L87
	jmp .L86
.L85:
	movl $0, %eax
	jmp .L86
.L86:
.L87:
	movzbl -49(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L88
	movzbl -47(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L90
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L90
	jmp .L89
.L88:
	movl $0, %eax
	jmp .L89
.L89:
.L90:
	jmp .L81
	jmp .L81
.L81:
	movl -66(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L91
	movb -17(%rbp), %al
	movb %al, -52(%rbp)
	movzbl -51(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L92
	movzbl -53(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L94
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L94
	jmp .L93
.L92:
	movl $0, %eax
	jmp .L93
.L93:
.L94:
	movzbl -46(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L95
	movzbl -49(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L97
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L97
	jmp .L96
.L95:
	movl $0, %eax
	jmp .L96
.L96:
.L97:
	jmp .L91
	jmp .L91
.L91:
	movl -66(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L98
	movb -17(%rbp), %al
	movb %al, -53(%rbp)
	movzbl -51(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L99
	movzbl -52(%rbp), %eax
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
	movzbl -47(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L102
	movzbl -50(%rbp), %eax
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
	movzbl -45(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L105
	movzbl -49(%rbp), %eax
	movl %eax, %ecx
	movb -17(%rbp), %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L107
	movb -17(%rbp), %al
	movb %al, -43(%rbp)
	jmp .L107
	jmp .L106
.L105:
	movl $0, %eax
	jmp .L106
.L106:
.L107:
	jmp .L98
	jmp .L98
.L98:
	jmp .L80
	jmp .L80
.L80:
	movb -43(%rbp), %al
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	setne %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L108
	movl $0, %eax
	movl %eax, -38(%rbp)
	movb -43(%rbp), %al
	movl %eax, -122(%rbp)
	movb $65, %al
	movl %eax, %ebx
	movl -122(%rbp), %eax
	subl %ebx, %eax
	movl %eax, %edi
	call print_game_won
	jmp .L108
	jmp .L23
.L108:
	movl -22(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L109
	movb -43(%rbp), %al
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L111
	movl $0, %eax
	movl %eax, -38(%rbp)
	call print_full_board
	jmp .L111
	jmp .L110
.L109:
	movl $0, %eax
	jmp .L110
.L110:
.L111:
	movb -17(%rbp), %al
	movl %eax, %ecx
	movb $88, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L113
	movb $79, %al
	movb %al, -17(%rbp)
	jmp .L112
	jmp .L23
.L113:
	movb $88, %al
	movb %al, -17(%rbp)
	jmp .L112
.L112:
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
	movzbl -45(%rbp), %eax
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
	movzbl -46(%rbp), %eax
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
	movzbl -47(%rbp), %eax
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
	movzbl -48(%rbp), %eax
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
	movzbl -49(%rbp), %eax
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
	movzbl -50(%rbp), %eax
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
	movzbl -51(%rbp), %eax
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
	movzbl -52(%rbp), %eax
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
	movzbl -53(%rbp), %eax
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
