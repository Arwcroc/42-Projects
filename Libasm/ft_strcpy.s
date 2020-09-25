			global	ft_strcpy

			section	.text
ft_strcpy:
			xor		rax, rax

_loop:
			mov		cl, byte [rsi + rax]
			cmp		cl, 0
			je		_end
			mov		byte [rdi + rax], cl
			inc		rax
			jmp		_loop

_end:
			mov		byte [rdi + rax], 0
			mov		rax, rdi
			ret