/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:16:26 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/02 16:21:13 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int			is_wall_mv(int x, int y, t_game *game)
{
	return (game->map.map[y][x] == 2 || game->map.map[y][x] == 3);
}

void		sprite_dist(t_game *game)
{
	int			i;
	t_sprite	*s;
	t_player	p;

	p = game->player;
	i = -1;
	while (++i <= game->count_s)
	{
		s = &game->all_s[i];
		s->spritex = s->s_pos.x - p.coordinate.x + 0.5;
		s->spritey = s->s_pos.y - p.coordinate.y + 0.5;
		s->dist = (pow(game->player.coordinate.x - s->spritex, 2) + \
				pow(game->player.coordinate.y - s->spritey, 2));
	}
}

void		sort_sprite(t_game *game)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 1;
	j = 0;
	while (j + i <= game->count_s)
	{
		while (i <= game->count_s)
		{
			if (game->all_s[j].dist <= game->all_s[i].dist)
				i++;
			else
			{
				temp = game->all_s[i];
				game->all_s[i] = game->all_s[j];
				game->all_s[j] = temp;
				i = j + 1;
			}
		}
		j++;
		i = j + 1;
	}
}

void		good_sp(t_game *game)
{
	int			x;
	int			y;
	int			i;

	i = 0;
	x = -1;
	while (++x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if (game->map.map[x][y] == 2 || game->map.map[x][y] == 3)
			{
				game->all_s[i].text = game->map.map[x][y] == 2 ? \
					game->s1 : game->s2;
				i++;
			}
			y++;
		}
	}
}

void		ft_sprite_pos(t_game *game)
{
	int			x;
	int			y;
	int			i;
	t_vector	sprite_pos;

	x = -1;
	i = 0;
	while (++x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if (game->map.map[x][y] == 2 || game->map.map[x][y] == 3)
			{
				sprite_pos = ft_vector(y, x);
				game->all_s[i].s_pos = sprite_pos;
				i++;
			}
			y++;
		}
	}
}
