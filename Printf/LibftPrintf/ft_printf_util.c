/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:54:00 by tefroiss          #+#    #+#             */
/*   Updated: 2020/02/11 15:03:38 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_do_printdi(t_printf *info, int size, int arg)
{
	int i;

	i = 0;
	if (info->precision != 0)
	{
		ft_space_di_front(info, size, arg);
		ft_checksize_di(size, info, arg);
		ft_putnbr(arg, info);
		ft_space_di_back(info, size, arg);
	}
	else if (info->precision == 0 && arg != 0)
	{
		ft_space_di_front(info, size, arg);
		if (arg < 0)
			ft_putchar('-', info);
		ft_putnbr(arg, info);
		ft_space_di_back(info, size, arg);
	}
	else if (arg == 0)
		while (i++ < info->width)
			ft_putchar(' ', info);
}

void		ft_putnbr(int nb, t_printf *info)
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
