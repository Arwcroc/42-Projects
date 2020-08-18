/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 19:48:30 by tefroiss          #+#    #+#             */
/*   Updated: 2020/08/15 15:37:50 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	tag_sprite(t_ray *ray, t_game *game, int sprite)
{
	int i;
	t_sprite *new;

	i = 0;
	new = NULL;
	while (!game->allsprite[i].last && !new)
	{
		if (ray->point.x == game->allsprite[i].sprite_pos.x && ray->point.y == 
			game->allsprite[i].sprite_pos.y)
			new = &game->allsprite[i];
		i++;
	}
	if (new)
	{
		if (sprite == 2)
			new->text = 1;
		else
			new->text = 2;
	}
}

int		count_sprites(t_game *game)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '2' || game->map.map[i][j] == '3')
				count++;
			j++;
		}
		i++;
	}
	count++;
	if (!(game->buf = (double *)malloc(sizeof(double) * ((game->window.width) * \
		(game->window.height)))))
		return (-5);
	return (count);
}

int	init_sprite(t_game *game)
{
	int i;
	int j;
	int count;

	if (!(game->allsprite = (t_sprite *)malloc(sizeof(t_sprite) * \
		count_sprites(game))))
		return (-5);
	i = 0;
	count = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '2' || game->map.map[i][j] == '3')
			{
				game->allsprite[count].sprite_pos = ft_vector(j, i);
				game->allsprite[count].last = 0;
				count++;
			}
			j++;
		}
		i++;
	}
	game->allsprite[count].last = 1;
	return (0); 
}
