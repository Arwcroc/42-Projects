/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:09:19 by tefroiss          #+#    #+#             */
/*   Updated: 2020/08/31 15:36:26 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	get_resolution(char *path)
{
	char	*line;
	int		width;
	int		height;

	line = search_line(path, "R");
	width = ft_atoi(ft_move_until(line, "is", ft_isdigit));
	height = ft_atoi((ft_move_until(ft_move_until(line, \
		"is", ft_isdigit), "not", ft_isdigit)));
	free(line);
	return (ft_vector(width, height));
}
