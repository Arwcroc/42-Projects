/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:26:06 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/03 15:55:55 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_sprite(t_game *game)
{
	int i;

	i = -1;
	if (!(game->s_order = malloc(sizeof(int *) * (game->count_s + 1))))
		exit(0);
	if (!(game->s_dist = malloc(sizeof(int *) * (game->count_s + 1))))
		exit(0);
	if (!(game->all_s = malloc(sizeof(t_sprite) * (game->count_s + 1))))
		exit(0);
	if (!(game->buf = (double *)malloc(sizeof(double) * \
		(game->window.width * game->window.height))))
		exit(0);
}

t_game	ft_game(char *path)
{
	t_game		game;
	t_vector	resolution;
	int			**map;

	resolution = get_resolution(path);
	game.count_s = -1;
	game.window = ft_window(&resolution.x, &resolution.y, GAME_NAME);
	game.map.width = 0;
	game.map.height = 0;
	game.map.map = 0;
	get_map(path, &game);
	init_sprite(&game);
	map = game.map.map;
	game.wall_no = get_texture(path, "NO", &game.window);
	game.wall_so = get_texture(path, "SO", &game.window);
	game.wall_we = get_texture(path, "WE", &game.window);
	game.wall_ea = get_texture(path, "EA", &game.window);
	game.s1 = get_texture(path, "SF", &game.window);
	game.s2 = get_texture(path, "ST", &game.window);
	game.ceil_color = get_color(path, "C");
	game.floor_color = get_color(path, "F");
	ft_init_keys(&game);
	return (game);
}
