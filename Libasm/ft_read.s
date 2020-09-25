			global	ft_read
			extern	__errno_location

			section	.text	
ft_read:
			cmp		rdi, 0
			jl		_err_end
			cmp		rsi, 0
			jle		_err_end

_go_read:
			mov		rax, 0
			syscall
			cmp		rax, 0
			jl		_err_end
			ret

_err_end:
			neg		rax
			mov		rcx, rax
			call	__errno_location
			mov		[rax], rcx
			mov		rax, -1
			ret