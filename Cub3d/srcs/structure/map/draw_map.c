/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:37:18 by tefroiss          #+#    #+#             */
/*   Updated: 2020/07/23 14:23:35 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	draw_cube(int y, int x, t_game *game, t_color color)
{
	int i;
	int j;
	int index;

	i = 0;
	while (i < (game->window.height) / 100)
	{
		j = 0;
		while (j < (game->window.width) / 100)
		{
			index = (y * (game->window.height / 90) + i) * \
			game->window.img.size_line + (x * (game->window.width / 90) + j) \
			* (game->window.img.bpp / 8);
			game->window.img.img_data[index] = (unsigned char)color.blue;
			game->window.img.img_data[index + 1] = (unsigned char)color.green;
			game->window.img.img_data[index + 2] = (unsigned char)color.red;
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	int i;
	int j;
	t_color color;

	i = 0;
	color = ft_color(115, 8, 0);
	while (i < (game->map.height))
	{
		j = 0;
		while (j < (game->map.width))
		{
			if (game->map.map[i][j] == 1)
			  	draw_cube(i, j, game, ft_color(193, 191, 187));
			else if (game->map.map[i][j] == 2)
				draw_cube(i, j, game, ft_color(255, 0, 0));
			else if (game->map.map[i][j] == 3)
				draw_cube(i, j, game, ft_color(150, 150, 0));
			j++;
		}
		i++;
	}
	 draw_cube((int)(game->player.coordinate.y), \
	 		(int)(game->player.coordinate.x), game, color);
}
