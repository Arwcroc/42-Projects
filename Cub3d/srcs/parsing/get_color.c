/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:07:22 by tefroiss          #+#    #+#             */
/*   Updated: 2020/08/31 15:36:59 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_color		get_color(char *path, char *code)
{
	char	*line;
	char	*n_in_line;
	int		red;
	int		green;
	int		blue;

	line = search_line(path, code);
	n_in_line = ft_move_until(line, "is", ft_isdigit);
	red = ft_atoi(n_in_line);
	n_in_line = ft_move_until(ft_move_until(n_in_line, \
		"not", ft_isdigit), "is", ft_isdigit);
	green = ft_atoi(n_in_line);
	n_in_line = ft_move_until(ft_move_until(n_in_line, \
		"not", ft_isdigit), "is", ft_isdigit);
	blue = ft_atoi(n_in_line);
	free(line);
	return (ft_color(red, green, blue));
}
