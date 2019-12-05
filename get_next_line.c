/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:54:12 by tefroiss          #+#    #+#             */
/*   Updated: 2019/12/04 13:25:10 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	if (str != NULL)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

void	fill_stock(char **stock, char *buf)
{
	char *str;

	if (*stock == NULL)
		*stock = ft_strdup(buf);
	else
	{
		str = ft_strjoin(*stock, buf);
		free(*stock);
		*stock = str;
	}
}

void	set_stock(char **stock, int i)
{
	char *temp;

	if ((*stock)[i + 1])
	{
		temp = ft_strdup(&((*stock)[i + 1]));
		free(*stock);
		*stock = temp;
	}
	else
	{
		free(*stock);
		*stock = NULL;
	}
}

int		aff_line(char **line, char **stock)
{
	int i;

	if (*stock != NULL)
	{
		i = 0;
		while ((*stock)[i])
		{
			if ((*stock)[i] == '\n')
			{
				*line = ft_substr(*stock, 0, i);
				set_stock(stock, i);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

/*
** mettre des fd apres tous les stocks, mettre le static char a
** *stock[256], regarder pourquoi ca segfault, rajouter int fd dans
** les protos, 256 parce que c'est le max de fichiers utilisable
*/

int		get_next_line(int fd, char **line)
{
	int				read_return;
	char			buf[(BUFFER_SIZE) + 1];
	static char		*stock = NULL;

	if (fd >= 0 && BUFFER_SIZE > 0 && line != NULL && !read(fd, buf, 0))
	{
		while ((read_return = read(fd, buf, BUFFER_SIZE)))
		{
			buf[read_return] = '\0';
			fill_stock(&stock, buf);
			if (aff_line(line, &stock))
				return (1);
		}
		if (aff_line(line, &stock))
			return (1);
		*line = (stock != NULL) ? ft_strdup(stock) : ft_strdup("\0");
		if (stock != NULL)
		{
			free(stock);
			stock = NULL;
		}
		return (0);
	}
	return (-1);
}
