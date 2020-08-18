/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:07:47 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/25 12:23:44 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static inline int	nb_color(int c)
{
	return (ft_isdigit(c) || c == '-');
}

static inline int	color_restriction(int c)
{
	return (c >= 0 && c <=255);
}

static inline int	color_line(char *line, int n)
{
	if (line && *line && n < 3 && check_alpha_in_line(line))
	{
		if (!nb_color(*line))
			line = ft_move_until(line, "is", nb_color);
		if (!nb_color(*line) || !(color_restriction(ft_atoi(line))))
			return (0);
		else
		{
			line = ft_move_until(line, "not", nb_color);
			return (color_line(line, n + 1));
		}
	}
	return (!line && n == 3);
}

static int	color_is_ok(char *path, char *code)
{
	char *line;

	if ((line = searchLine(path, code)) && color_line(line, 0))
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

void	check_color(char *path)
{
	static char *code[2] = {"F", "C"};
	int i;

	i = 0;
	while (i < 2)
	{
		if (color_is_ok(path, code[i]))
			i++;
		else
			exit(0);
	}
}