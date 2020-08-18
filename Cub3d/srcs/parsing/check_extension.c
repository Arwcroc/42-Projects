/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:52:59 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/25 12:27:39 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** c'est une histoire de chemin
*/

int	ft_isexist(char *path)
{
	int fd;
	int result;

	fd = open(path, O_RDONLY);
	result = fd == -1 ? 0 : 1;
	close(fd);
	return (result);
}

int	ft_str_isequal(char *str1, char *str2)
{
	if (str1 && str2)
	{
		if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0 && \
				ft_strncmp(str1, str2, ft_strlen(str2)) == 0)
			return (1);
	}
	return (0);
}

int	ft_test_extension_path(char *path, char *extension)
{
	char *last_point;

	last_point = ft_strrchr(path, '.');
	return (last_point && ft_str_isequal(last_point, extension)\
				&& ft_isexist(path));
}

int	ft_check_extension(char *filename, char *extension)
{
	int		result;

	result = 0;
	if (ft_test_extension_path(filename, extension))
		result = 1;
	else
		result = 0;
	return (result);
}