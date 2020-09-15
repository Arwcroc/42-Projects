/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:36:29 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/02 16:18:54 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void			update_side(t_ray *ray, t_game *game)
{
	t_vector coordinate;

	coordinate = game->player.coordinate;
	if (ray->direction.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (coordinate.x - ray->point.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->point.x + 1.0 - coordinate.x) * \
							ray->deltadist.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (coordinate.y - ray->point.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->point.y + 1.0 - coordinate.y) * \
							ray->deltadist.y;
	}
}

static void		ray_init(t_ray *ray, t_game *game, int x)
{
	t_vector	coordinate;
	t_vector	direction;

	coordinate = game->player.coordinate;
	ray->point = ft_vector((int)coordinate.x, (int)coordinate.y);
	ray->cam_coordinate = 2 * x / (double)game->window.width - 1;
	direction = game->player.plane.mul_scalar(&game->player.plane, \
				ray->cam_coordinate);
	ray->direction = direction.add(&direction, game->player.or);
	if (ray->direction.x && ray->direction.y)
	{
		ray->deltadist = ft_vector(fabs(1 / ray->direction.x), \
			fabs(1 / ray->direction.y));
	}
	ray->step = ft_vector(1, 1);
	ray->sidedist.x = (ray->point.x + 1.0 - coordinate.x) * ray->deltadist.x;
	ray->sidedist.y = (ray->point.y + 1.0 - coordinate.y) * ray->deltadist.y;
	update_side(ray, game);
}

void			good_text(t_game *game, t_ray *ray)
{
	if (ray->side && ray->step.y == 1)
		game->good_text = game->wall_no;
	else if (ray->side && ray->step.y == -1)
		game->good_text = game->wall_so;
	else if (!ray->side && ray->step.x == 1)
		game->good_text = game->wall_ea;
	else
		game->good_text = game->wall_we;
}

static void		cast_ray(t_ray *ray, t_game *game)
{
	while (!is_wall(ray->point.x, ray->point.y, game))
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->point.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->point.y += ray->step.y;
			ray->side = 1;
		}
		if (game->map.map[(int)ray->point.y][(int)ray->point.x] == 2 ||\
		game->map.map[(int)ray->point.y][(int)ray->point.x] == 3)
			tag_sprite(ray, game);
	}
	good_text(game, ray);
}

int				ft_ray(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	cleanbuff(game);
	while (x < game->window.width)
	{
		ray_init(&ray, game, x);
		ft_sprite_pos(game);
		cast_ray(&ray, game);
		draw(game, &ray, x);
		game->buf[game->window.width - x - 1] = game->line.dist;
		x++;
	}
	sprite_casting(game);
	cleanbuff(game);
	return (0);
}
