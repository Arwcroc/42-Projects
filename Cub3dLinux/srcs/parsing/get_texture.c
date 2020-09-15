/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 16:44:33 by tefroiss          #+#    #+#             */
/*   Updated: 2020/08/31 15:36:38 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_texture	get_texture(char *path, char *code, t_window *window)
{
	char		*line;
	t_texture	texture;
	char		*n_in_line;

	line = search_line(path, code);
	n_in_line = ft_move_until(line, "is", ft_isspace);
	n_in_line = ft_move_until(n_in_line, "not", ft_isspace);
	texture = ft_texture(window->mlx_ptr, n_in_line);
	free(line);
	return (texture);
}
