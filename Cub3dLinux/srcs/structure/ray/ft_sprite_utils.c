/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:18:17 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/02 16:20:17 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int		is_wall(int x, int y, t_game *game)
{
	return (game->map.map[y][x] == 1);
}

void	sp_image_pipix(t_vector *v, t_image img, t_color color)
{
	int index;

	if (color.red || color.green || color.blue)
	{
		index = v->y * img.size_line + v->x * (img.bpp / 8);
		img.img_data[index] = (unsigned char)color.blue;
		img.img_data[index + 1] = (unsigned char)color.green;
		img.img_data[index + 2] = (unsigned char)color.red;
	}
}

void	sprites_screen(t_player p, t_sprite *s, t_game *game)
{
	double inv;

	inv = 1.0 / (p.plane.x * p.or.y - p.or.x * p.plane.y);
	s->trans.x = inv * (-p.or.y * s->spritex + p.or.x * \
		s->spritey);
	s->trans.y = inv * (-p.plane.y * s->spritex + p.plane.x * s->spritey);
	s->screen = (int)((game->window.width / 2) * (1 + s->trans.x / s->trans.y));
	s->factor = abs((int)(game->window.height / (s->trans.y)));
	s->lim_y.x = -s->factor / 2 + game->window.height / 2;
	s->lim_y.y = s->factor / 2 + game->window.height / 2;
	s->lim_x.x = -s->factor / 2 + s->screen;
	s->lim_x.y = s->factor / 2 + s->screen;
}
