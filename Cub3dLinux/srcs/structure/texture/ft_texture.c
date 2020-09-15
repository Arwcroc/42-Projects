/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:40:37 by tefroiss          #+#    #+#             */
/*   Updated: 2020/08/27 15:09:40 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_texture	ft_texture(void *mlx_ptr, char *path)
{
	t_texture data;

	data.img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, &data.width, \
					&data.height);
	data.img_data = (unsigned char *)mlx_get_data_addr(data.img_ptr, &data.bpp,\
					&data.size_line, &data.endian);
	return (data);
}
