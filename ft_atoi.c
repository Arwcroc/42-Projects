/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:45:28 by tefroiss          #+#    #+#             */
/*   Updated: 2019/11/19 11:33:12 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	if (str != NULL)
	{
		i = 0;
		while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
				&& str[i] != '\0')
			i++;
		sign = (str[i] == '-') ? -1 : 1;
		i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
		nb = 0;
		while (str[i] >= '0' && str[i] <= '9' && str[i])
		{
			nb = nb * 10 + str[i] - 48;
			i++;
		}
		return (nb * sign);
	}
	return (0);
}
