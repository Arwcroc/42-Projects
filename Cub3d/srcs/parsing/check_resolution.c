/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 15:28:05 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/25 12:23:43 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static inline int	nb_resolution(int c)
{
	return (ft_isdigit(c) || c == '-');
}

static inline int	resolution_line(char *line, int n)
{
	if (line && *line && n < 2 && check_alpha_in_line(line))
	{
		if (!nb_resolution(*line))
			line = ft_move_until(line, "is", nb_resolution);
		if (!nb_resolution(*line) || !(ft_atoi(line) > 0))
			return (0);
		else
		{
			line = ft_move_until(line, "not", nb_resolution);
			return (resolution_line(line, n + 1));
		}
	}
	return (!line && n == 2);
}

int					check_resolution(char *path)
{
	char *line;

	if ((line = searchLine(path, "R")) && resolution_line(line, 0))
	{
		free(line);
		return (1);
	}
	free(line);
	exit(EXIT_FAILURE);
	return (0);
}
