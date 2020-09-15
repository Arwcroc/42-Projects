/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:57:20 by tefroiss          #+#    #+#             */
/*   Updated: 2020/08/31 14:59:00 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_checkc(char c, const char *info)
{
	int i;

	i = 0;
	while (info[i] != '\0')
	{
		if (c == info[i])
			return (1);
		i++;
	}
	return (0);
}
