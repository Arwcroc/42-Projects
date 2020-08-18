/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:56:51 by tefroiss          #+#    #+#             */
/*   Updated: 2020/07/21 18:00:34 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	texture_line(char *line)
{
	line = ft_move_until(line, "not", ft_isalpha);
	line = ft_move_until(line, "is", ft_isalpha);
	return (ft_check_extension(line, ".xpm"));
}

static int	texture_is_ok(char *path, char *direction)
{
	char *line;

	if ((line = searchLine(path, direction)) && texture_line(line))
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

void		check_texture(char *path)
{
	static char *code[6] = {"NO", "SO", "WE", "EA", "SF", "ST"};
	int i;

	i = 0;
	while (i < 6)
	{
		if (texture_is_ok(path, code[i]))
			i++;
		else
			exit(0);
	}
}
