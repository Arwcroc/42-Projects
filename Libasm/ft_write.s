section .text
    global _ft_write

;_ft_write:
;   mov rax, 0x2000004
;  syscall
;jnc _end
;mov rax, -1

;_end:
;	ret


_ft_write:
    cmp edi, 0
    jl _error
    cmp rdx, 0
    jl _error
    cmp rsi, 0
    jle _error

_write:
    mov rax, 1
    syscall
    cmp rax, 0
    jl _error
    mov rax, rdx
    ret

_error:
    mov rax, -1
    ret