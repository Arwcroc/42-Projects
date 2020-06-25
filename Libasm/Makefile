SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

SRCC = main.c 

OBJS = ${SRCS:.s=.o}
OBJC = ${SRCC:.c=.o}

NAME = libasm.a
NAME_TEST = libasm.out

RM	= rm -f

CC = gcc

CFLAG = -Wall -Wextra -Werror

all:	${NAME}

.s.o:
	nasm -fmacho64 $<

.c.o:
	${CC} ${CFLAG} -c  $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} lib.h
	ar rc ${NAME} ${OBJS}

test: ${NAME_TEST}

${NAME_TEST}:	${NAME} ${OBJC}
	${RM} $(OBJM)
	${CC} ${NAME} ${OBJC} -o ${NAME_TEST}

clean :
	${RM} ${OBJS} ${OBJC} ${OBJB} ${OBJM}

fclean:	clean
	${RM} ${NAME}
	${RM} ${NAME_TEST}

re: 	fclean all