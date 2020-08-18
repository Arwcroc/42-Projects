/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:41:40 by tefroiss          #+#    #+#             */
/*   Updated: 2020/07/27 16:58:49 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_init_keys(t_game *game)
{
	game->key[0] = -1;
	game->key[1] = -1;
	game->key[2] = -1;
	game->key[3] = -1;
	game->key[4] = -1;
	game->key[5] = -1;
}

int			ft_game_loop(t_game *game)
{
	int update;
	clock_t time;
	double time_sec;
	static double spf = 1.0 / FPS;

 	update = player_move(game);
	if (!update)
 		update = player_turn(game);
	else
		player_turn(game);
	if (update)
	{
		time = clock();
		mlx_clear_window(game->window.mlx_ptr, game->window.win_ptr);
		ft_ray(game);
		draw_map(game);
		mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,\
	 						game->window.img.img_ptr, 0, 0);
		time = clock() - time;
		time_sec = (double)time / CLOCKS_PER_SEC;
		if (spf > time_sec)
		{
			time_sec = spf;
			nanosleep(&(struct timespec){0, time_sec * 1000000000}, 0);
		}
		time_sec = 1 / time_sec;
		mlx_string_put(game->window.mlx_ptr, game->window.win_ptr, \
			game->window.width - (game->window.width / 8), \
			game->window.height / 16, 14522460, ft_itoa((int)time_sec));
		mlx_do_sync(game->window.mlx_ptr);
	}
	return (0);
}

static int	ft_handle_destruction(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	exit(EXIT_SUCCESS);
	return (0);
}

static void	ft_parse(char *arg)
{
	check_resolution(arg);
	check_texture(arg);
	check_color(arg);
//	check_map(arg);
}

int			main(int ac, char **av)
{
	t_game game;


	if (ac > 1 && ft_check_extension(av[1], ".cub"))
	{
		ft_parse(av[1]);
		game = ft_game(av[1]);
		ft_init_keys(&game);
		ft_ray(&game);
		draw_map(&game);
		if (ac > 2 && ft_strcmp(av[2], "--save") == 0)
		 	write_bmp_header(&game);
		else
		{
			mlx_put_image_to_window(game.window.mlx_ptr, game.window.win_ptr,\
			 				game.window.img.img_ptr, 0, 0);
			mlx_hook(game.window.win_ptr, 2, 1L << 0, ft_handle_events, &game);
			mlx_loop_hook(game.window.mlx_ptr, ft_game_loop, &game);
			mlx_hook(game.window.win_ptr, 3, 1L << 1, ft_handle_release, &game);
			mlx_hook(game.window.win_ptr, 17, 1L << 17,
						ft_handle_destruction, &game);
			mlx_loop(game.window.mlx_ptr);
		}
	}
	return (0);
}