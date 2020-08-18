/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:15:51 by tefroiss          #+#    #+#             */
/*   Updated: 2020/07/27 18:13:12 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		write_header(t_bmp_header *bmp, int fd)
{
	write(fd, "BM", 2);
	write(fd, &bmp->file_size, sizeof(int));
	write(fd, &bmp->nothing, sizeof(int));
	write(fd, &bmp->pixel_offset, sizeof(int));
	write(fd, &bmp->header_size, sizeof(int));
	write(fd, &bmp->img_width, sizeof(int));
	write(fd, &bmp->img_height, sizeof(int));
	write(fd, &bmp->plane, sizeof(short int));
	write(fd, &bmp->bpp, sizeof(short int));
	write(fd, &bmp->nothing, sizeof(int));
	write(fd, &bmp->nothing, sizeof(int));
	write(fd, &bmp->nothing, sizeof(int));
	write(fd, &bmp->nothing, sizeof(int));
	write(fd, &bmp->nothing, sizeof(int));
	write(fd, &bmp->nothing, sizeof(int));
}

void		write_pixel(t_bmp_header *bmp, t_game *game, int fd)
{
	int x;
	int y;
	int i;

	y = bmp->img_height;
	while (y)
	{
		x = 0;
		while (x < bmp->img_width)
		{
			i = (y * game->window.img.size_line + x * 4);
			write(fd, &game->window.img.img_data[i], 4);
			x++;
		}
		y--;
	}
}

void		bmp_init(t_game *game, t_bmp_header *bmp)
{
	bmp->file_size = 54 + game->window.img.height * game->window.img.size_line;
	bmp->pixel_offset = 54;
	bmp->header_size = 40;
	bmp->nothing = 0;
	bmp->img_width = game->window.img.width;
	bmp->img_height = game->window.img.height;
	bmp->plane = 1;
	bmp->bpp = game->window.img.bpp;
}

void		write_bmp_header(t_game *game)
{
	t_bmp_header	bmp;
	int				fd;

	bmp_init(game, &bmp);
	if ((fd = open("cub3d.bmp", O_WRONLY | O_CREAT, S_IRWXU | O_TRUNC)) < 0)
		exit(0);
	write_header(&bmp, fd);
	write_pixel(&bmp, game, fd);
	close(fd);
}
