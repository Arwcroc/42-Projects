/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:56:51 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/03 14:38:06 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		texture_line(char *line)
{
	line = ft_move_until(line, "not", ft_isalpha);
	line = ft_move_until(line, "is", ft_isalpha);
	return (ft_check_extension(line, ".xpm"));
}

int		texture_is_ok(char *path, char *direction)
{
	char *line;

	if ((line = search_line(path, direction)) && texture_line(line))
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

void	check_texture(char *path)
{
	static char	*code[6] = {"NO", "SO", "WE", "EA", "SF", "ST"};
	int			i;

	i = 0;
	ft_printf("Check texture...\n");
	while (i < 6)
	{
		if (texture_is_ok(path, code[i]))
		{
			ft_printf("Texture %s OK !\n", code[i]);
			i++;
		}
		else
		{
			ft_printf("Error\nTexture %s corrupt !\n", code[i]);
			exit(0);
		}
	}
}
