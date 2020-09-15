/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:08:57 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/03 11:59:54 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_pos(t_vector coordinate, t_game *game, char c)
{
	game->player.coordinate = coordinate;
	if (c == 'S')
	{
		game->player.or = ft_vector(sin(ft_deg_rad(0)), cos(ft_deg_rad(0)));
		ft_player(coordinate, 0, game);
	}
	else if (c == 'E')
	{
		game->player.or = ft_vector(sin(ft_deg_rad(90)), cos(ft_deg_rad(90)));
		ft_player(coordinate, 90, game);
	}
	else if (c == 'N')
	{
		game->player.or = ft_vector(sin(ft_deg_rad(180)), cos(ft_deg_rad(180)));
		ft_player(coordinate, 180, game);
	}
	else if (c == 'W')
	{
		game->player.or = ft_vector(sin(ft_deg_rad(270)), cos(ft_deg_rad(270)));
		ft_player(coordinate, 270, game);
	}
}

int		line_is_useless(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str != '1')
		return (1);
	return (0);
}

int		*put_to_map(char *s, int count_h, int width, t_game *game)
{
	int			i;
	int			*map_line;
	char		sw;
	t_vector	coordinate;

	i = -1;
	sw = 0;
	if (!(map_line = malloc(sizeof(int) * width)))
		return (0);
	while (++i < width)
	{
		if (!s[i])
			sw = 1;
		if (sw || s[i] == '1' || s[i] == ' ')
			map_line[i] = 1;
		else if (s[i] == '0')
			map_line[i] = 0;
		else if (s[i] == '2' || s[i] == '3')
		{
			map_line[i] = s[i] == '2' ? 2 : 3;
			game->count_s++;
		}
		else if (s[i] == 'N' || s[i] == 'S' || s[i] == 'W' || s[i] == 'E')
		{
			map_line[i] = 0;
			coordinate = ft_vector((i + 0.5), (count_h + 0.5));
			get_pos(coordinate, game, s[i]);
		}
		else
			ft_printf("Error");
		ft_printf("%d ", map_line[i]);
	}
	ft_printf("\n");
	return (map_line);
}

void	get_map_continue(char *path, t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (!line_is_useless(line))
		{
			game->map.map[i] = put_to_map(line, i, game->map.width, game);
			i++;
		}
		free(line);
	}
	if (!line_is_useless(line))
	{
		game->map.map[i] = put_to_map(line, i, game->map.width, game);
		i++;
	}
	free(line);
	close(fd);
}

int		get_map(char *path, t_game *game)
{
	char	*line;
	int		fd;
	int		len;

	line = NULL;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!line_is_useless(line))
		{
			if ((len = ft_strlen(line)) > game->map.width)
				game->map.width = len;
			game->map.height++;
		}
		free(line);
	}
	if (!line_is_useless(line))
		game->map.height++;
	free(line);
	close(fd);
	if (!(game->map.map = malloc(sizeof(int *) * game->map.height)))
		return (0);
	get_map_continue(path, game);
	return (1);
}
