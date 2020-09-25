			global	ft_strcmp

			section	.text
ft_strcmp:
			xor		rax, rax

_loop:
			mov		dl, byte [rax + rsi]
			cmp		byte [rax + rdi], dl
			jl		_lower
			jg		_greater
			cmp		byte [rax + rsi], 0
			je		_zero
			inc		rax
			jmp		_loop

_zero:
			mov		rax, 0
			ret

_lower:
			mov		rax, -1
			ret

_greater:
			mov		rax, 1
			ret