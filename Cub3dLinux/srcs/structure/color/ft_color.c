/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:47:47 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/17 19:33:17 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_color		ft_color(int r, int g, int b)
{
	t_color new;

	new.red = r;
	new.green = g;
	new.blue = b;
	return (new);
}
