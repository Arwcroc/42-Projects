/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:26:06 by tefroiss          #+#    #+#             */
/*   Updated: 2020/08/18 16:52:35 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void		initbuffer(t_game *game)
{
	int i;

	if (!(game->buf = malloc(sizeof(int *) * game->window.height)))
		exit(0);
	i = -1;
	while (++i < game->window.height)
		if (!(game->buf[i] = malloc(sizeof(int) * game->window.width)))
			exit(0);
	if (!(game->sbuffer = malloc(sizeof(double) * game->window.width)))
		exit(0);
}

void	init_sprite(t_game *game)
{
	int i;

	i = -1;
	if (!(game->sprite_order = malloc(sizeof(int *) * game->count_s)))
		exit(0);
	if (!(game->sprite_dist = malloc(sizeof(int *) * game->count_s)))
		exit(0);
	if (!(game->allsprite = malloc(sizeof(t_sprite) * game->count_s)))
		exit(0);
	initbuffer(game);
}

t_game	ft_game(char *path)
{
	t_game		game;
	t_vector	resolution;
	int			**map;

	resolution = get_resolution(path);
	game.count_s = -1;
	game.window = ft_window(&resolution.x, &resolution.y, GAME_NAME);
	get_map(path, &game);
	map = game.map.map;
	game.wall_no = get_texture(path, "NO", &game.window);
	game.wall_so = get_texture(path, "SO", &game.window);
	game.wall_we = get_texture(path, "WE", &game.window);
	game.wall_ea = get_texture(path, "EA", &game.window);
	game.s1 = get_texture(path, "SF", &game.window);
	game.s2 = get_texture(path, "ST", &game.window);
	game.ceil_color = get_color(path, "C");
	game.floor_color = get_color(path, "F");
	init_sprite(&game);
	return (game);
}
