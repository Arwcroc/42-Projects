/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:41:40 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/04 17:03:50 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
**	norme
**	check map
**	stop error condition
*/

void			ft_init_keys(t_game *game)
{
	game->key[0] = -1;
	game->key[1] = -1;
	game->key[2] = -1;
	game->key[3] = -1;
	game->key[4] = -1;
	game->key[5] = -1;
}

static int		ft_handle_destruction(int keycode, t_game *game)
{
	(void)keycode;
	free(game->s_order);
	free(game->s_dist);
	free(game->all_s);
	free(game->buf);
	free(game->map.map);
	exit(EXIT_SUCCESS);
	return (0);
}

static void		ft_parse(char *arg)
{
	ft_printf("Map file OK !\n");
	check_resolution(arg);
	check_texture(arg);
	check_color(arg);
}

int				main(int ac, char **av)
{
	t_game game;

	ft_printf("Check map file...\n");
	if (ac > 1 && ft_check_extension(av[1], ".cub"))
	{
		ft_parse(av[1]);
		game = ft_game(av[1]);
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
	ft_printf("Error\nMap file corrupt !\n");
	return (0);
}
