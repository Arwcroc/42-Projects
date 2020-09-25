SRCS		=	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s

BONUS		=	atoi_base_bonus.s \
				ft_list_push_front_bonus.s \
				ft_list_size_bonus.s \
				ft_list_sort_bonus.s \
				ft_list_remove_if_bonus.s

SRCC		=	main.c 

OBJS		=	${SRCS:.s=.o}
OBJC		=	${SRCC:.c=.o}
OBJS_B		=	${BONUS:.s=.o}

NAME		=	libasm.a
NAME_TEST	=	libasm.out
NAME_BONUS	=	libasm_bonus.out

RM			=	rm -f

CC			=	clang

NASM		=	nasm -f elf64

CFLAG		=	-Wall -Wextra -Werror -Ofast -pedantic-errors

INCS		=	./libasm.h

#########################################################################################
#										MAKE											#
#########################################################################################

%.o				:	%.s 
					${NASM} $< -o $@

%.o				:	%.c $(INCS)
					${CC} ${CFLAG} -c  $< -o $@

all				:	${NAME}

${NAME}			:	${OBJS}
					ar rc ${NAME} ${OBJS}

test			:	${NAME_TEST}

${NAME_TEST}	:	${NAME} ${OBJC}
					${CC} ${CFLAGS} ${NAME} ${OBJS} ${OBJC} -o ${NAME_TEST}

bonus			:	${NAME_BONUS}

${NAME_BONUS}	:	${NAME} ${OBJC} ${OBJS_B}
					${CC} ${CFLAGS} ${NAME} ${OBJS} ${OBJC} ${OBJS_B} -o ${NAME_BONUS}

clean			:
					${RM} ${OBJS} ${OBJC} ${OBJS_B}

fclean			:	clean
					${RM} ${NAME}
					${RM} ${NAME_TEST}
					${RM} ${NAME_BONUS}

re				:	fclean all

.PHONY			:	re fclean clean bonus test all