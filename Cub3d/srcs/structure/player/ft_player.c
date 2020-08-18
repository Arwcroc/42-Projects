/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:11:30 by tefroiss          #+#    #+#             */
/*   Updated: 2020/07/02 17:07:55 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	plane_orient(double orientation, t_game *game)
{
	t_vector	result;
	double		coefficient;

	coefficient = tan(ft_deg_rad(FOV) / 2);
	result = ft_vector(0, 0);
	if (orientation == 90)
		result.y = -coefficient;
	else if (orientation == 270)
		result.y = coefficient;
	else if (orientation == 0)
		result.x = coefficient;
	else if (orientation == 180)
		result.x = -coefficient;
	game->player.plane = result;
}

void	ft_player(t_vector coordinate, double orientation, t_game *game)
{
	game->player.coordinate = coordinate;
	game->player.map = game->map;
	game->player.color = ft_color(255, 0, 0);
	game->player.fov = ft_deg_rad(FOV);
	plane_orient(orientation, game);
}
