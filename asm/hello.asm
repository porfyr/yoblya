	global start

	section .text
start
	mov	rax, 0x2000004
	mov 	rdi, 1
	mov 	rsi, str
	mov 	rdx, str.len
	syscall

	mov 	rax, 0x2000001
	xor 	rdi, rdi
	syscall

	section .data
str: 	db 	"hello mom"
.len 	equ 	$ - str
