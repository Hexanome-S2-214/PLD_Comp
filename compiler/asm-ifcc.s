
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
	movzbl -56(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movzbl -57(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movzbl -58(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -59(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movzbl -60(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movzbl -61(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movb $10, %al
	movl %eax, %edi
	call putchar@PLT
	movzbl -62(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movzbl -63(%rbp), %eax
	movl %eax, %edi
	call putchar@PLT
	movzbl -64(%rbp), %eax
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
	movb %al, -58(%rbp)
	jmp .L47
	jmp .L24
.L48:
	movb $89, %al
	movb %al, -58(%rbp)
	jmp .L47
.L47:
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
	jne .L49
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L50
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L52
	movb $88, %al
	movb %al, -59(%rbp)
	jmp .L51
	jmp .L23
.L52:
	movb $89, %al
	movb %al, -59(%rbp)
	jmp .L51
.L51:
	jmp .L50
	jmp .L50
.L50:
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L53
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L55
	movb $88, %al
	movb %al, -60(%rbp)
	jmp .L54
	jmp .L49
.L55:
	movb $89, %al
	movb %al, -60(%rbp)
	jmp .L54
.L54:
	jmp .L53
	jmp .L53
.L53:
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L56
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L58
	movb $88, %al
	movb %al, -61(%rbp)
	jmp .L57
	jmp .L49
.L58:
	movb $89, %al
	movb %al, -61(%rbp)
	jmp .L57
.L57:
	jmp .L56
	jmp .L56
.L56:
	jmp .L49
	jmp .L49
.L49:
	movl -69(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L59
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $48, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L60
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L62
	movb $88, %al
	movb %al, -62(%rbp)
	jmp .L61
	jmp .L23
.L62:
	movb $89, %al
	movb %al, -62(%rbp)
	jmp .L61
.L61:
	jmp .L60
	jmp .L60
.L60:
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $49, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L63
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L65
	movb $88, %al
	movb %al, -63(%rbp)
	jmp .L64
	jmp .L59
.L65:
	movb $89, %al
	movb %al, -63(%rbp)
	jmp .L64
.L64:
	jmp .L63
	jmp .L63
.L63:
	movl -77(%rbp), %eax
	movl %eax, %ecx
	movb $50, %al
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L66
	movl -20(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L68
	movb $88, %al
	movb %al, -64(%rbp)
	jmp .L67
	jmp .L59
.L68:
	movb $89, %al
	movb %al, -64(%rbp)
	jmp .L67
.L67:
	jmp .L66
	jmp .L66
.L66:
	movb -52(%rbp), %al
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	setne %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L69
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
	jmp .L69
	jmp .L59
.L69:
	movl -28(%rbp), %eax
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	jne .L70
	movb -52(%rbp), %al
	movl %eax, %ecx
	movl $0, %eax
	cmpl %eax, %ecx
	sete %al
	movzbl %al, %eax
	cmpl $1, %eax
	jne .L72
	movl $0, %eax
	movl %eax, -47(%rbp)
	call print_full_board
	jmp .L72
	jmp .L71
.L70:
	movl $0, %eax
	jmp .L71
.L71:
.L72:
	jmp .L59
	jmp .L59
.L59:
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
	movl $0, %eax
	jmp .L12
.L12:

	leave
	ret
