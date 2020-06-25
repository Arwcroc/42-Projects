section .text
	global _ft_strcmp

_ft_strcmp:
    xor rax, rax

_loop:
    cmp BYTE [rsi + rax], 0
    je _end
    cmp BYTE [rdi + rax], 0
    je _end
    mov dl, BYTE [rsi + rax]
    cmp dl, BYTE [rdi + rax]
    je _zero
    jl _lower
    jg _greater
    add rax, 1
    jmp _loop

_zero:
    mov rax, 0
    jmp _loop

_lower:
    mov rax, -1
    jmp _loop

_greater:
    mov rax, 1
    jmp _loop

_end:
    ret