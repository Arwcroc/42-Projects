/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:42:59 by tefroiss          #+#    #+#             */
/*   Updated: 2020/07/08 15:47:02 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_window	ft_window(double *width, double *height, char *name)
{
	t_window	new;
	int			x;
	int			y;

	x = 2560;
	y = 1440;
	if (!(new.mlx_ptr = mlx_init()))
		exit(EXIT_FAILURE);
	//mlx_get_screen_size(new.mlx_ptr, &x, &y);
	*width = *width > x ? x : *width;
	*height = *height > y ? y : *height;
	if (!(new.win_ptr = mlx_new_window(new.mlx_ptr, *width, *height, name)))
		exit(EXIT_FAILURE);
	new.width = *width;
	new.height = *height;
	new.img = ft_image(new, *width, *height);
	//new.clear = ft_clear_image;
	return (new);
}

void	put_pixel(t_window *window, t_vector point, t_color color)
{
	int	set;

	set = window->img.size_line * (int)point.y + 4 * (int)point.x;
	window->img.img_data[set] = color.blue;
	window->img.img_data[set + 1] = color.green;
	window->img.img_data[set + 2] = color.red;
}
