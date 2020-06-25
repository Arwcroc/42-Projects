# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 13:43:24 by tefroiss          #+#    #+#              #
#    Updated: 2020/02/21 18:34:25 by tefroiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	LibftPrintf/ft_printf.c \
				LibftPrintf/ft_printf_util.c \
				LibftPrintf/ft_printf_utils.c \
				LibftPrintf/ft_checkinfo.c \
				LibftPrintf/ft_printc.c \
				LibftPrintf/ft_prints.c \
				LibftPrintf/ft_printdi.c \
				LibftPrintf/ft_printu.c \
				LibftPrintf/ft_printx.c \
				LibftPrintf/ft_printx_util.c \
				LibftPrintf/ft_printx_utils.c \
				LibftPrintf/ft_printxup.c \
				LibftPrintf/ft_printp.c \
				LibftPrintf/ft_printp_utils.c \
				LibftPrintf/ft_printperc.c


OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -Werror

RM			=	rm -f

CLEAN		=	clean

$(NAME)		:	$(OBJS)
				ar rc libftprintf.a $(OBJS)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re