/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:23:20 by tefroiss          #+#    #+#             */
/*   Updated: 2020/08/15 14:44:21 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_color		sprite_text(t_vector vector, t_sprite sp, t_texture text)
{
	int		index;
	double	hit_x;
	double	hit_y;
	t_color	color;

	hit_x = (vector.x - sp.lim_x.x) / (sp.lim_x.y - sp.lim_x.x) * text.width;
	hit_y = (vector.x - sp.lim_y.x) / (sp.lim_y.y - sp.lim_y.x) * text.height;
	index = (int)hit_y * text.size_line + (int)hit_x * (text.bpp / 8);
	color.blue = text.img_data[index];
	color.green = text.img_data[index + 1];
	color.red = text.img_data[index + 2];
	return (color);
}

void		sprite_put_pix(int x, int y, t_image img, t_color color)
{
	int index;

	if (color.red || color.green || color.blue)
	{
		index = y * img.size_line + x * (img.bpp / 8);
		color.blue = img.img_data[index];
		color.green = img.img_data[index + 1];
		color.red = img.img_data[index + 2];
	}
}

t_color		shade_text(t_color c, double dist)
{
	t_color origin;

	origin = c;
	c.red = (int)(((double)c.red / c.red + 0.1) * ((c.red / (0.3 * dist))));
	c.green = (int)(((double)c.green / c.green + 0.1) * \
				((c.green / (0.3 * dist))));
	c.blue = (int)(((double)c.blue / c.blue + 0.1) * ((c.blue / (0.3 * dist))));
	c.red = c.red > origin.red ? origin.red : c.red;
	c.green = c.green > origin.green ? origin.green : c.green;
	c.blue = c.blue > origin.blue ? origin.blue : c.blue;
	c.red = c.red < origin.red - 30 ? origin.red - 30 : c.red;
	c.green = c.green < origin.green - 30 ? origin.green - 30 : c.green;
	c.blue = c.blue < origin.blue - 30 ? origin.blue - 30 : c.blue;
	c.red = c.red < 0 ? origin.red : c.red;
	c.green = c.green < 0 ? origin.green : c.green;
	c.blue = c.blue < 0 ? origin.blue : c.blue;
	return (c);
}

void		in_src(t_window window, int y, int x)
{
	if (y < window.height && y >= 0 && x < window.width && x >= 0)
		return (1);
	return (0);
}

void		sprite_draw2(t_game *game, t_sprite *sprite)
{
	t_color		sp;
	int			i;
	int			j;

	i = sprite->lim_y.x - 1;
	while (++i < sprite->lim_y.y)
	{
		j = sprite->lim_x.x;
		while (j < sprite->lim_x.y)
		{
			if (in_src(game->window, j, i) && sprite->buffer_dist <= \
			game->buf[j + (i * game->window.height)] || 0 == \
			game->buf[j + (i * game->window.height)] && \
			sprite->buffer_dist <= game->buf[j])
			{
				sp = sprite_text(ft_vector(j, i), sprite, game->text_s2);
				sp = shade_text(sp, sprite->buffer_dist);
				game->window.img = sprite_put_pix(j, i, game->window.img, sp);
				if (sp.red || sp.green || sp.blue)
					game->buf[j + (i * game->window.width)] = \
					sprite->buffer_dist;
			}
			j++;
		}
	}
}

void		sprite_draw(t_game *game, t_sprite *sprite)
{
	t_color		sp;
	int			i;
	int			j;

	i = sprite->lim_y.x - 1;
	while (++i < sprite->lim_y.y)
	{
		j = sprite->lim_x.x;
		while (j < sprite->lim_x.y)
		{
			if (in_src(game->window, j, i) && sprite->buffer_dist <= \
			game->buf[j + (i * game->window.height)] || 0 == \
			game->buf[j + (i * game->window.height)] && \
			sprite->buffer_dist <= game->buf[j])
			{
				sp = sprite_text(ft_vector(j, i), sprite, game->text_s1);
				sp = shade_text(sp, sprite->buffer_dist);
				game->window.img = sprite_put_pix(j, i, game->window.img, sp);
				if (sp.red || sp.green || sp.blue)
					game->buf[j + (i * game->window.width)] = \
					sprite->buffer_dist;
			}
			j++;
		}
	}
}

void		dist_sprite(t_game *game)
{
	t_sprite	*s;
	int			i;
	t_player	player;

	i = 0;
	player = game->player;
	while (game->allsprite[i].last)
	{
		s = &game->allsprite[i];
		s->player_pos.x = s->sprite_pos.x - player.coordinate.x + 0.5;
		s->player_pos.y = s->sprite_pos.y - player.coordinate.y + 0.5;
		s->buffer_dist = (pow(player.coordinate.x - s->player_pos.x, 2) + \
							pow(player.coordinate.y - s->player_pos.y, 2));
		s->dist = (pow(player.coordinate.x - s->player_pos.x, 2) + \
					pow(player.coordinate.y - s->player_pos.y, 2));
		i++;
	}
}

void		sort_sprites(t_sprite *sprite)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 1;
	j = 0;
	while (!sprite[j + i].last)
	{
		while (!sprite[i].last)
		{
			if (sprite[j].dist <= sprite[i].dist)
				i++;
			else
			{
				temp = sprite[i];
				sprite[i] = sprite[j];
				sprite[j] = temp;
				i = j + 1;
			}
		}
		j++;
		i = j + 1;
	}
}

void		sprite_oscreen(t_player p, t_sprite *s, t_game *game)
{
	double		i;
	t_vector	v;
	int			screen;
	int			factor;

	i = 1.0 / (p.plane.x * p.orientation.y - p.plane.y * p.orientation.x);
	v.x = i * (p.orientation.y * s->player_pos.x - p.plane.x * s->player_pos.y);
	v.y = i * (-p.orientation.y * s->player_pos.x + p.plane.x * \
			s->player_pos.y);
	screen = (int)((int)(game->window.width / 2) * (1 + v.x / v.y));
	factor = abs((int)(game->window.height / v.y));
	s->lim_y.x = -factor / 2 + game->window.height / 2 + ((int)(0.0 / v.y));
	s->lim_y.y = factor / 2 + game->window.height / 2 + ((int)(0.0 / v.y));
	s->lim_x.x = -factor / 2 + screen;
	s->lim_x.y = factor / 2 + screen;
}

void		ft_sprites(t_game *game)
{
	int i;

	i = 0;
	dist_sprite(game);
	sort_sprite(game->allsprite);
	while (!game->allsprite[i].last)
	{
		if (game->allsprite[i].text == 0 || game->allsprite[i].text == 1)
		{
			if (game->allsprite[i].text == 0)
				sprite_draw(game, &game->allsprite[i]);
			else
				sprite_draw2(game, &game->allsprite[i]);
		}
		i++;
	}
}
