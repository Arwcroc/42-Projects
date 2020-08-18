/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_do_sth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:45:55 by tefroiss          #+#    #+#             */
/*   Updated: 2020/07/10 14:24:34 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	go_upside_down(t_game *game, t_vector vector)
{
	t_vector	move;
	t_vector	coor;

	coor = game->player.coordinate;
	move = coor.sub(&coor, vector.mul_scalar(&vector, STEP));
	if (!is_wall(move.x, move.y, game))
		game->player.coordinate = move;
}

void	go_upside(t_game *game, t_vector vector)
{
	t_vector	move;
	t_vector	coor;

	coor = game->player.coordinate;
	move = coor.add(&coor, vector.mul_scalar(&vector, STEP));
	if (!is_wall(move.x, move.y, game))
		game->player.coordinate = move;
}

int	player_move(t_game *game)
{
	int upd;

	upd = 0;
	if (game->key[0] != -1 && (upd = 1))
		go_upside(game, game->player.plane);
	else if (game->key[1] != -1 && (upd = 1))
		go_upside_down(game, game->player.plane);
	if (game->key[2] != -1 && (upd = 1))
		go_upside_down(game, game->player.orientation);
	else if (game->key[3] != -1 && (upd = 1))
		go_upside(game, game->player.orientation);
	return (upd);
}