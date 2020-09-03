/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:14:12 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/02 17:18:40 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void		ft_game_loop_utils(t_game *game)
{
	mlx_clear_window(game->window.mlx_ptr, game->window.win_ptr);
	ft_ray(game);
	draw_map(game);
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,\
		game->window.img.img_ptr, 0, 0);
}

void		ft_game_loop_util(t_game *game, double time_sec)
{
	mlx_string_put(game->window.mlx_ptr, game->window.win_ptr, \
		game->window.width - (game->window.width / 8), \
		game->window.height / 16, 14522460, ft_itoa((int)time_sec));
	mlx_do_sync(game->window.mlx_ptr);
}

int			ft_game_loop(t_game *game)
{
	int				update;
	clock_t			time;
	double			time_sec;
	static double	spf = 1.0 / FPS;

	update = player_move(game);
	if (!update)
		update = player_turn(game);
	else
		player_turn(game);
	if (update)
	{
		time = clock();
		ft_game_loop_utils(game);
		time = clock() - time;
		time_sec = (double)time / CLOCKS_PER_SEC;
		if (spf > time_sec)
		{
			time_sec = spf;
			nanosleep(&(struct timespec){0, time_sec * 1000000000}, 0);
		}
		time_sec = 1 / time_sec;
		ft_game_loop_util(game, time_sec);
	}
	return (0);
}
