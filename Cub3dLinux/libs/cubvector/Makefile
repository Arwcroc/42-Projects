# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/13 18:45:37 by tefroiss          #+#    #+#              #
#    Updated: 2020/06/25 16:46:07 by tefroiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libcubvector.a

SRCS	=		./srcs/ft_vector.c \
				./srcs/ft_vec_add.c \
				./srcs/ft_vec_sub.c \
				./srcs/ft_vec_div.c \
				./srcs/ft_vec_mul.c \
				./srcs/ft_vec_add_scalar.c \
				./srcs/ft_vec_sub_scalar.c \
				./srcs/ft_vec_mul_scalar.c \
				./srcs/ft_vec_div_scalar.c \
				./srcs/ft_vec_direction.c \
				./srcs/ft_vec_normalise.c \
				./srcs/ft_vec_dist.c \
				./srcs/ft_vec_length.c \
				./srcs/ft_vec_dot.c \
				./srcs/ft_vec_update.c \
				./srcs/ft_vec_rotate.c \

OBJS		=	$(SRCS:.c=.o)

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -g3

RM			=	rm -f

CLEAN		=	clean

INCLUDES	=	./includes/cubvector.h

#########################################################################################
#										MAKE											#
#########################################################################################

%.o			:	%.c ${INCLUDES}
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(OBJS)
				ar rc ${NAME} ${OBJS}

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re