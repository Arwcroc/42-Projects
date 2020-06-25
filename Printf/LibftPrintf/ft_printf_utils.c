/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:18:33 by tefroiss          #+#    #+#             */
/*   Updated: 2020/02/20 11:18:49 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str != NULL)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

void		ft_putchar(char c, t_printf *info)
{
	write(1, &c, 1);
	info->count += 1;
}

void		ft_putstr(char *str, t_printf *info)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], info);
		i++;
	}
}

int			ft_calci(unsigned int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void		ft_putnbru(unsigned int nb, t_printf *info)
{
	unsigned int nbr;

	if (nb < 0)
		nbr = nb * -1;
	else
		nbr = nb;
	if (nbr > 9)
		ft_putnbr(nbr / 10, info);
	ft_putchar(nbr % 10 + 48, info);
}
