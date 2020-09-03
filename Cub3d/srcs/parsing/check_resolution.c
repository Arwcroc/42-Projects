/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 15:28:05 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/03 14:38:30 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	nb_resolution(int c)
{
	return (ft_isdigit(c) || c == '-');
}

int	resolution_line(char *line, int n)
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

int	check_resolution(char *path)
{
	char *line;
	ft_printf("Check resolution...\n");
	if ((line = search_line(path, "R")) && resolution_line(line, 0))
	{
		free(line);
		ft_printf("Resolution OK !\n");
		return (1);
	}
	free(line);
	ft_printf("Error\nResolution corrupt !\n");
	exit(EXIT_FAILURE);
	return (0);
}
