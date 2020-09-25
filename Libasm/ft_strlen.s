			global	ft_strlen

			section	.text
ft_strlen:
			xor		rax, rax

_loop:
			cmp		byte [rdi + rax], 0
			je		_end
			inc		rax
			jmp		_loop

_end:
			ret