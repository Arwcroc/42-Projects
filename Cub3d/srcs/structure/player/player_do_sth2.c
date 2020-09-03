/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_do_sth2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:11:31 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/02 12:35:33 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int		player_turn(t_game *game)
{
	if (game->key[5] != -1)
	{
		rotate(&game->player.plane, ROTATION);
		rotate(&game->player.or, ROTATION);
		return (1);
	}
	if (game->key[4] != -1)
	{
		rotate(&game->player.plane, -ROTATION);
		rotate(&game->player.or, -ROTATION);
		return (1);
	}
	return (0);
}
