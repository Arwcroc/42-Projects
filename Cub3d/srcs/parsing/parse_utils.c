/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:31:07 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/25 12:23:36 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_split_and_check(char *str, int c, char *charcode)
{
	char	**str_splitted;
	int		result;

	str_splitted = ft_split(str, c);
	result = ft_str_isequal(str_splitted[0], charcode);
	ft_split_clean(str_splitted);
	return (result);
}

char	*ft_move_until(char *str, char *bool, int (*f)(int))
{
	if (str)
	{
		if (ft_str_isequal(bool, "is"))
		{
			while (*str && !f(*str))
				str++;
			return (f(*str) && *str ? str : NULL);
		}
		else if (ft_str_isequal(bool, "not"))
		{
			while (*str && f(*str))
				str++;
			return (!f(*str) && *str ? str : NULL);
		}
	}
	return (str);
}

char	*searchLine(char *path, char *code)
{
	int		fd;
	char	*line;

	if ((fd = open(path, O_RDONLY)) != -1)
	{
		while (get_next_line(fd, &line) == 1)
		{
			if (ft_split_and_check(line, ' ', code))
			{
				close(fd);
				return (line);
			}
			free(line);
		}
	}
	close(fd);
	return (NULL);
}

int	check_alpha_in_line(char *line)
{
	int i;

	i = 0;
	while (*line)
	{
		if (ft_isalpha(*line))
			i++;
		line++;
	}
	return (!(i > 1));
}

int	ft_fd_is_here(char *path)
{
	int fd;
	int result;

	fd = open(path, O_RDONLY);
	result = fd == -1 ? 0 : 1;
	close(fd);
	return (result);
}