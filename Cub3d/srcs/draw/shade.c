/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:04:04 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/02 16:05:09 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_color		shade_wall(t_color c, double dist)
{
	t_color origin;

	origin = c;
	c.red = (int)(((double)c.red / c.red + LR) * ((c.red / (0.3 * dist))));
	c.green = (int)(((double)c.green / c.green + LR) * \
				((c.green / (0.3 * dist))));
	c.blue = (int)(((double)c.blue / c.blue + LR) * ((c.blue / (0.3 * dist))));
	c.red = c.red > origin.red ? origin.red : c.red;
	c.green = c.green > origin.green ? origin.green : c.green;
	c.blue = c.blue > origin.blue ? origin.blue : c.blue;
	c.red = c.red < origin.red - 30 ? origin.red - 30 : c.red;
	c.green = c.green < origin.green - 30 ? origin.green - 30 : c.green;
	c.blue = c.blue < origin.blue - 30 ? origin.blue - 30 : c.blue;
	c.red = c.red < 0 ? origin.red : c.red;
	c.green = c.green < 0 ? origin.green : c.green;
	c.blue = c.blue < 0 ? origin.blue : c.blue;
	return (c);
}

t_color		shade_text(t_color c, double dist)
{
	t_color origin;

	origin = c;
	c.red = (int)(((double)c.red / c.red + LR) * ((c.red / (0.3 * dist))));
	c.green = (int)(((double)c.green / c.green + LR) * \
				((c.green / (0.3 * dist))));
	c.blue = (int)(((double)c.blue / c.blue + LR) * ((c.blue / (0.3 * dist))));
	c.red = c.red > origin.red ? origin.red : c.red;
	c.green = c.green > origin.green ? origin.green : c.green;
	c.blue = c.blue > origin.blue ? origin.blue : c.blue;
	c.red = c.red < origin.red - 30 ? origin.red - 30 : c.red;
	c.green = c.green < origin.green - 30 ? origin.green - 30 : c.green;
	c.blue = c.blue < origin.blue - 30 ? origin.blue - 30 : c.blue;
	c.red = c.red < 0 ? origin.red : c.red;
	c.green = c.green < 0 ? origin.green : c.green;
	c.blue = c.blue < 0 ? origin.blue : c.blue;
	return (c);
}
