/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:08:57 by tefroiss          #+#    #+#             */
/*   Updated: 2020/08/17 16:49:53 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_pos(t_vector coordinate, t_game *game, char c)
{
	game->player.coordinate = coordinate;
	if (c == 'S')
	{
		game->player.orientation = ft_vector(sin(ft_deg_rad(0)), cos(ft_deg_rad(0)));
		ft_player(coordinate, 0, game);
	}
	else if (c == 'E')
	{
		game->player.orientation = ft_vector(sin(ft_deg_rad(90)), cos(ft_deg_rad(90)));
		ft_player(coordinate, 90, game);
	}
	else if (c == 'N')
	{
		game->player.orientation = ft_vector(sin(ft_deg_rad(180)), cos(ft_deg_rad(180)));
		ft_player(coordinate, 180, game);
	}
	else if (c == 'W')
	{
		game->player.orientation = ft_vector(sin(ft_deg_rad(270)), cos(ft_deg_rad(270)));
		ft_player(coordinate, 270, game);
	}
}

int lineIsUseless(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str != '1')
		return (1);
	return (0);
} 

int *putToMap(char *str, int count_h, int width, t_game *game)
{
	int i = -1;
	int *map_line;
	char sw = 0;
	t_vector coordinate;
	
	if (!(map_line = malloc(sizeof(int) * width)))
		return (0);
	while (++i < width)
	{
		if (!str[i])
			sw = 1;
		if (sw || str[i] == '1' || str[i] == ' ')
			map_line[i] = 1;
		else if (str[i] == '0')
			map_line[i] = 0;
		else if (str[i] == '2' || str[i] == '3')
		{
			map_line[i] = str[i] == '2' ? 2 : 3;
			game->count_s++;
		}
		else if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		{
			map_line[i] = 0;
			coordinate = ft_vector((i + 0.5), (count_h + 0.5));
			get_pos(coordinate, game, str[i]);
		}
		else
			printf("Error");
		printf("%d ", map_line[i]);
	}
	printf("\n");
	return (map_line);
}

int		get_map(char *path, t_game *game)
{
	char *line;
	int fd;
	int len;
	
	line = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.map = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!lineIsUseless(line)) {
			if ((len = ft_strlen(line)) > game->map.width)
				game->map.width = len;
			game->map.height++;
		}
		free(line);
	}
	if (!lineIsUseless(line))
		game->map.height++;
	free(line);
	close(fd);
	if (!(game->map.map = malloc(sizeof(int *) * game->map.height)))
		return (0);
	fd = open(path, O_RDONLY);
	int i = 0;
	while (get_next_line(fd, &line))
	{
		if (!lineIsUseless(line)) {
			game->map.map[i] = putToMap(line, i, game->map.width, game);
			i++;
		}
		free(line);
	}
	if (!lineIsUseless(line)) {
		game->map.map[i] = putToMap(line, i, game->map.width, game);
		i++;
	}
	free(line);
	close(fd);
	return (1);
}
