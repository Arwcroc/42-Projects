/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:50:01 by tefroiss          #+#    #+#             */
/*   Updated: 2020/01/27 14:26:55 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

void	fill_stock(char **stock, char *buf)
{
	char *temp;

	if (*stock == NULL)
		*stock = ft_strdup(buf);
	else
	{
		temp = ft_strjoin(*stock, buf);
		free(*stock);
		*stock = temp;
	}
}

void	reset_stock(char **stock, int i)
{
	char	*temp;

	if ((*stock)[i + 1])
	{
		temp = ft_strdup(&(*stock)[i + 1]);
		free(*stock);
		*stock = temp;
	}
	else
	{
		free(*stock);
		*stock = NULL;
	}
}

int		check_line(char **line, char **stock)
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
				reset_stock(stock, i);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			read_result;
	char		buf[(BUFFER_SIZE) + 1];
	static char	*stock = NULL;

	if (fd >= 0 && BUFFER_SIZE > 0 && line != NULL && !read(fd, buf, 0))
	{
		while ((read_result = read(fd, buf, BUFFER_SIZE)))
		{
			buf[read_result] = '\0';
			fill_stock(&stock, buf);
			if (check_line(line, &stock))
				return (1);
		}
		if (check_line(line, &stock))
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
