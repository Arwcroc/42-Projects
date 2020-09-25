			global	ft_strdup
			extern	ft_strlen
			extern	malloc
			extern	ft_strcpy

			section	.text
ft_strdup:
			push	rdi
			call	ft_strlen

_go_malloc:
			inc		rax
			mov		rdi, rax
			call	malloc
			cmp		rax, 0
			je		_error
			pop		rsi
			mov		rdi, rax
			call	ft_strcpy
			jmp		_end

_error:
			xor		rax, rax

_end:
			ret