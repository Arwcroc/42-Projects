section .text
	global _ft_read

_ft_read:
	mov rax, 0x2000003
	syscall
	jnc _end
	mov rax, -1

_end:
	ret