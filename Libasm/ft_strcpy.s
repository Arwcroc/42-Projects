section .text
	global _ft_strcpy

_ft_strcpy:
    mov rax, rsi
	mov rdx, rdi

_while:
    cmp byte [rsi], 0
    jz _end
    mov al, [rsi]
    mov [rdi], al
    inc rdi
	inc rsi
    jmp _while

_end:
	mov byte [rdi], 0
    mov rax, rdx
    ret