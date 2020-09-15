/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:20:13 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/02 16:20:55 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void
	sprite_text(t_vector *v, t_sprite *s, t_texture text, t_color *color)
{
	int		index;
	double	hit_x;
	double	hit_y;

	hit_x = (v->x - s->lim_x.x) / (s->lim_x.y - s->lim_x.x) * text.width;
	hit_y = (v->y - s->lim_y.x) / (s->lim_y.y - s->lim_y.x) * text.height;
	index = (int)hit_y * text.size_line + (int)hit_x * (text.bpp / 8);
	color->blue = text.img_data[index];
	color->green = text.img_data[index + 1];
	color->red = text.img_data[index + 2];
}

void
	sprite_draw(t_game *game, t_sprite s)
{
	int			x;
	int			y;
	t_color		color;
	t_vector	vector;

	x = s.lim_x.x - 1;
	while (++x < s.lim_x.y)
	{
		y = s.lim_y.x - 1;
		while (++y < s.lim_y.y)
		{
			vector = ft_vector(x, y);
			if (s.trans.y > 0 && x > 0 && y > 0 && y < game->window.height &&\
			x < game->window.width && s.trans.y < game->buf[x])
			{
				sprite_text(&vector, &s, s.text, &color);
				color = shade_text(color, s.trans.y);
				sp_image_pipix(&vector, game->window.img, color);
			}
		}
	}
}

void
	cleanbuff(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->window.width * game->window.height)
		game->buf[i] = 0;
}

void
	tag_sprite(t_ray *ray, t_game *game)
{
	int			i;
	t_sprite	*new;

	i = 0;
	new = NULL;
	while (i <= game->count_s && new == NULL)
	{
		if (ray->point.x == game->all_s[i].s_pos.x && ray->point.y ==\
			game->all_s[i].s_pos.y)
			new = &game->all_s[i];
		i++;
	}
	if (new)
		new->hit = 1;
}

void
	sprite_casting(t_game *game)
{
	int i;

	i = -1;
	good_sp(game);
	sprite_dist(game);
	sort_sprite(game);
	while (++i <= game->count_s)
	{
		if (game->all_s[i].hit)
		{
			sprites_screen(game->player, &game->all_s[i], game);
			sprite_draw(game, game->all_s[i]);
		}
		game->all_s[i].hit = 0;
	}
}
