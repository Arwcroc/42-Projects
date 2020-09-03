# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/17 17:07:02 by tefroiss          #+#    #+#              #
#    Updated: 2020/09/03 15:57:43 by tefroiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cub3D

SRCS		=	./srcs/math/ft_deg_rad.c \
				./srcs/parsing/check_extension.c \
				./srcs/parsing/check_resolution.c \
				./srcs/parsing/check_texture.c \
				./srcs/parsing/check_color.c \
				./srcs/parsing/parse_utils.c \
				./srcs/parsing/get_resolution.c \
				./srcs/parsing/get_texture.c \
				./srcs/parsing/get_color.c \
				./srcs/structure/game/ft_game.c \
				./srcs/structure/game/ft_game_loop.c \
				./srcs/structure/texture/ft_texture.c \
				./srcs/structure/color/ft_color.c \
				./srcs/windows/ft_window.c \
				./srcs/images/ft_image.c \
				./srcs/parsing/get_map.c \
				./srcs/structure/ray/ft_ray.c \
				./srcs/structure/ray/ft_sprite.c \
				./srcs/structure/ray/ft_sprite_util.c \
				./srcs/structure/ray/ft_sprite_utils.c \
				./srcs/draw/draw.c \
				./srcs/draw/shade.c \
				./srcs/structure/player/ft_player.c \
				./srcs/structure/player/player_do_sth.c \
				./srcs/structure/player/player_do_sth2.c \
				./srcs/structure/map/draw_map.c \
				./srcs/structure/game/ft_key.c \
				./srcs/windows/ft_bmp.c

MAIN 		= 	srcs/main.c

OBJS_MAIN 	= 	$(MAIN:.c=.o)
OBJS		=	$(SRCS:.c=.o)

LIBFT_PATH	=	"./libs/libft/"
VECTOR_PATH	=	"./libs/cubvector/"
PRINTF_PATH	=	"./libs/Printf/"

LIBRARY		=	-L ./libs/libft -lft \
				-L ./libs/cubvector -lcubvector \
				-L ./libs/Printf -lftprintf \

LFLAGS		=	-lmlx -framework OpenGL -framework AppKit
#				-L. ./minilibx/libmlx,a -lXext -lX11 -lm -lbsd
#LFLAGS		=	-L /Users/teofroissart/Documents/42\ Projects/42Utils/minilibx_opengl_20191021/ -lmlx -framework OpenGL -framework Appkit

CC			=	clang

CFLAGS		+=	-Wall -Wextra -Werror -g3 -O3

RM			=	rm -f

CLEAN		=	clean

INCLUDES	=	./includes/cub3d.h


#########################################################################################
#										MAKE											#
#########################################################################################


%.o			:	%.c ${INCLUDES}
				$(CC) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(OBJS_MAIN)
				make -C $(LIBFT_PATH)
				make -C $(VECTOR_PATH)
				make -C $(PRINTF_PATH)
				${CC} ${LFLAGS} ${LIBRARY} ${CFLAGS} ${OBJS} ${OBJS_MAIN} -o ${NAME}

clean		:
				make clean -C $(LIBFT_PATH)
				make clean -C $(VECTOR_PATH)
				make clean -C $(PRINTF_PATH)
				$(RM) $(OBJS)
				$(RM) ${OBJS_MAIN}

fclean		:	clean
				make fclean -C $(LIBFT_PATH)
				make fclean -C $(VECTOR_PATH)
				make fclean -C $(PRINTF_PATH)
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
