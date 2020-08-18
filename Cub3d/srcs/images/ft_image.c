/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:00:14 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/15 19:19:23 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_image	ft_image(t_window window, int width, int height)
{
	t_image image;

	if (!(image.img_ptr = mlx_new_image(window.mlx_ptr, width, height)))
		exit(EXIT_FAILURE);
	if (!(image.img_data = mlx_get_data_addr(image.img_ptr, &image.bpp,\
			&image.size_line, &image.endian)))
	{
		mlx_destroy_image(window.mlx_ptr, window.img.img_ptr);
		exit(EXIT_FAILURE);
	}
	image.width = width;
	image.height = height;
	return (image);
}
