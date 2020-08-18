/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:20:13 by tefroiss          #+#    #+#             */
/*   Updated: 2020/08/18 18:09:04 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	cmp(const void *left, const void *right)
{
	t_sprite *i;
	t_sprite *j;

	i = (t_sprite *)left;
	j = (t_sprite *)right;
	if (j->dist < i->dist)
		return (1);
	else if (i->dist < j->dist)
		return (-1);
	else
		return ((i->order < j->order) - (j->order < i->order));
}

void	sort_sprite(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->count_s)
	{
		game->allsprite[i].dist = game->sprite_dist[i];
		game->allsprite[i].order = game->sprite_order[i];
	}
	qsort(game->allsprite, game->count_s, sizeof(t_sprite), cmp);
	i = -1;
	while (++i < game->count_s)
	{
		game->sprite_dist[i] = game->allsprite[game->count_s - i - 1].dist;
		game->sprite_order[i] = game->allsprite[game->count_s - i - 1].order;
	}
}

void	sprite_casting(t_game *game)
{
	int i;
	double spritex;
	double spritey;
	double invdet;
	double transx;
	double transy;
	int screen;
	int sprite_height;
	int sprite_width;
	int draw_starty;
	int draw_endy;
	int draw_startx;
	int draw_endx;
	int stripe;
	int tex_x;
	int tex_y;
	int y;
	int d;
	int color;

	i = -1;
	while (++i < game->count_s)
	{
		game->sprite_order[i] = i;
		game->sprite_dist[i] = ((game->player.coordinate.x - \
			game->allsprite[i].sprite_pos.x) * \
			(game->player.coordinate.x - game->allsprite[i].sprite_pos.x) + \
			(game->player.coordinate.y - game->allsprite[i].sprite_pos.y) * \
			(game->player.coordinate.y - game->allsprite[i].sprite_pos.y));
	}
	sort_sprite(game);
	i = -1;

	while (++i < game->count_s)
	{
		spritex = game->allsprite[game->sprite_order[i]].sprite_pos.x - game->player.coordinate.x;
		spritey = game->allsprite[game->sprite_order[i]].sprite_pos.y - game->player.coordinate.y;
		invdet = 1.0 / (game->player.plane.x * game->player.orientation.y - \
			game->player.plane.y * game->player.orientation.x);
		transx = invdet * (game->player.orientation.y * \
			game->allsprite[game->sprite_order[i]].player_pos.x - \
			game->player.plane.x * game->allsprite[game->sprite_order[i]].\
			player_pos.y);
		transy = invdet * (-game->player.orientation.y * \
			game->allsprite[game->sprite_order[i]].player_pos.x + \
			game->player.plane.x * game->allsprite[game->sprite_order[i]].\
			player_pos.y);
		screen = (int)((int)(game->window.width / 2) * (1 + transx / transy));
		sprite_height = abs((int)(game->window.height / (transy)));
		draw_starty = -sprite_height / 2 + game->window.height / 2;
		if (draw_starty < 0)
			draw_starty = 0;
		draw_endy = sprite_height / 2 + game->window.height / 2;
		if (draw_endy >= game->window.height)
			draw_endy = game->window.height - 1;
		sprite_width = abs((int)(game->window.height / (transy)));
		draw_startx = -sprite_width / 2 + screen;
		if (draw_startx < 0)
			draw_startx = 0;
		draw_endx = sprite_width / 2 + screen;
		if (draw_endx >= game->window.width)
			draw_endx = game->window.width - 1;
		stripe = draw_startx - 1;
		printf("%d\n", draw_startx);
		while (++stripe < draw_endx)
		{
			printf("%d\n", draw_startx);
			tex_x = (int)(256 * (stripe - (-sprite_width / 2 + screen)) * \
				game->allsprite[game->sprite_order[i]].text.width / \
				sprite_width) / 256;
			y = draw_starty - 1;
			if (transy > 0 && stripe > 0 && stripe < game->window.width && \
				transy < game->sbuffer[stripe])
			{
				while (++y < draw_endy)
				{
					d = y * 256 - game->window.height * 128 + sprite_height * \
						128;
					tex_y = ((d * \
						game->allsprite[game->sprite_order[i]].text.height) / \
						sprite_height) / 256;
					color = game->allsprite[game->sprite_order[i]].text.\
						img_data[game->allsprite[game->sprite_order[i]].\
						text.width * tex_y + tex_x];
					if ((color & 0x00FFFFFF) != 0)
						game->buf[y][stripe] = color;
				}
			}
		}
	}
}
