/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:12:21 by tefroiss          #+#    #+#             */
/*   Updated: 2020/08/31 15:32:40 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int			ft_handle_release(int keycode, t_game *game)
{
	if (keycode == RIGHT)
		game->key[0] = -1;
	else if (keycode == LEFT)
		game->key[1] = -1;
	else if (keycode == DOWN)
		game->key[2] = -1;
	else if (keycode == UP)
		game->key[3] = -1;
	else if (keycode == KEY_A)
		game->key[4] = -1;
	else
		game->key[5] = -1;
	return (0);
}

int			ft_handle_events(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
		exit(0);
	if (keycode == RIGHT)
		game->key[0] = RIGHT;
	else if (keycode == LEFT)
		game->key[1] = LEFT;
	else if (keycode == DOWN)
		game->key[2] = DOWN;
	else if (keycode == UP)
		game->key[3] = UP;
	else if (keycode == KEY_A)
		game->key[4] = KEY_A;
	else if (keycode == KEY_D)
		game->key[5] = KEY_D;
	return (0);
}
