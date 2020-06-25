/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:46:55 by tefroiss          #+#    #+#             */
/*   Updated: 2020/02/20 13:54:23 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putsomefp(int size, t_printf *info)
{
	int i;

	i = 0;
	while (++i <= 16 - size)
		ft_putchar('f', info);
}

void		ft_space_p_front(t_printf *info, int size)
{
	int i;

	i = 0;
	if (info->padding == 0)
	{
		while (++i <= info->width - (size + 2))
			ft_putchar(' ', info);
	}
	if (info->padding == 2)
	{
		if (info->precision < size)
			while (++i <= info->width - size)
				ft_putchar(' ', info);
		else
			while (++i <= info->width - info->precision)
				ft_putchar(' ', info);
	}
}

void		ft_space_p_front_neg(t_printf *info)
{
	int i;

	i = 1;
	if (info->padding == 0)
	{
		if (info->padding < 17)
		{
			while (++i <= info->width - 17)
				ft_putchar(' ', info);
		}
		else if (info->precision >= 17)
		{
			while (++i <= info->width - info->precision)
				ft_putchar(' ', info);
		}
	}
	if (info->padding == 2)
	{
		if (info->padding > 16 && info->width > info->padding)
			while (++i <= info->width - info->padding)
				ft_putchar(' ', info);
		if (info->padding > 16)
			while (++i <= info->padding - 8)
				ft_putchar('0', info);
	}
}

void		ft_putnbrp(long nb, t_printf *info)
{
	long	nbr;

	nbr = ft_abs(nb);
	if (nbr > 15)
		ft_putnbrp(nbr / 16, info);
	ft_putchar(HEXADECIMAL[nbr % 16], info);
}

void		ft_printp(t_printf *info, va_list *va)
{
	long	arg;
	int		size;

	if (va != NULL)
	{
		arg = va_arg(*va, long);
		size = ft_calcp(arg);
		ft_do_printp(info, size, arg);
	}
}
