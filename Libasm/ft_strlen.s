section .text
	global _ft_strlen

_ft_strlen:
    mov rax, rsi

_loop:
    cmp byte [rax], 0
    je _end
    inc rax
    jmp _loop
    
_end:
	sub rax, rsi
    ret