/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:51:25 by tefroiss          #+#    #+#             */
/*   Updated: 2019/11/27 18:52:52 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	line = "\0";
	fd = ac > 1 ? open(av[1], O_RDONLY) : 0;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		i++;
		free(line);
	}
	printf("%s", line);
	close(fd);
	return (0);
}