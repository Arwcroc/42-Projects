					global	ft_list_push_front
					extern	malloc

					section	.text
ft_list_push_front:
					xor		rax, rax
					cmp		rdi, 0
					je		_end_zero

_loop:
					push	rdi
					push	rsi
					mov		rdi, 16
					call	malloc
					
