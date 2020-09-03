/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:41:48 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/02 16:12:07 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		size_line(t_game *game, t_ray *ray)
{
	int line_h;

	if (ray->side == 0)
		game->line.dist = (ray->point.x - game->player.coordinate.x + \
		(1 - ray->step.x) / 2) / ray->direction.x;
	else
		game->line.dist = (ray->point.y - game->player.coordinate.y + \
		(1 - ray->step.y) / 2) / ray->direction.y;
	line_h = (int)(game->window.height / game->line.dist);
	if (game->line.dist == 0)
		line_h = 0;
	game->line.draw_s = -line_h / 2 + game->window.height / 2;
	game->line.draw_e = line_h / 2 + game->window.height / 2;
}

void		ft_put_pixel(t_vector *vector, t_color color, t_image dataimg)
{
	int index;

	index = vector->y * dataimg.size_line + 4 * vector->x;
	dataimg.img_data[index] = (unsigned char)color.blue;
	dataimg.img_data[index + 1] = (unsigned char)color.green;
	dataimg.img_data[index + 2] = (unsigned char)color.red;
}

t_color		show_texture(t_ray *ray, t_game *game, double y)
{
	t_color		color;
	int			hit_x;
	double		hit_y;
	int			index;

	if (ray->side)
		hit_y = game->player.coordinate.x + game->line.dist * ray->direction.x;
	else
		hit_y = game->player.coordinate.y + game->line.dist * ray->direction.y;
	hit_x = ((int)hit_y + 1 - hit_y) * game->good_text.width;
	hit_y = ((y - game->line.draw_s) / (game->line.draw_e - \
			game->line.draw_s)) * game->good_text.height;
	index = (int)hit_y * game->good_text.size_line + hit_x * \
			(game->good_text.bpp / 8);
	color.blue = game->good_text.img_data[index];
	color.green = game->good_text.img_data[index + 1];
	color.red = game->good_text.img_data[index + 2];
	return (color);
}

void		draw_line(t_game *game, t_ray *ray, int x)
{
	int			i;
	t_vector	vector;
	t_color		texture;

	i = 0;
	while (i <= game->window.height)
	{
		vector = ft_vector(game->window.width - x - 1, i);
		if (i < game->line.draw_s)
			ft_put_pixel(&vector, game->ceil_color, game->window.img);
		else if (i < game->line.draw_e)
		{
			texture = show_texture(ray, game, i);
			texture = shade_wall(texture, game->line.dist);
			ft_put_pixel(&vector, texture, game->window.img);
		}
		else
			ft_put_pixel(&vector, game->floor_color, game->window.img);
		i++;
	}
}

void		draw(t_game *game, t_ray *ray, int x)
{
	size_line(game, ray);
	draw_line(game, ray, x);
}
