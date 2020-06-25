/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:57:13 by tefroiss          #+#    #+#             */
/*   Updated: 2020/02/11 15:02:59 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_space_di_front(t_printf *info, int size, int arg)
{
	int i;

	i = 0;
	if (info->padding == 0)
	{
		if (info->precision < size)
		{
			while (++i <= info->width - size)
				ft_putchar(' ', info);
		}
		else if (info->precision >= size && arg >= 0)
		{
			while (++i <= info->width - info->precision)
				ft_putchar(' ', info);
		}
		else if (arg < 0)
		{
			while (++i <= info->width - (info->precision + 1))
				ft_putchar(' ', info);
		}
	}
}

void		ft_checksize_di(int size, t_printf *info, int arg)
{
	int i;

	i = 0;
	if (arg < 0)
		ft_putchar('-', info);
	if (info->padding == 2)
	{
		while (++i <= info->width - size)
			ft_putchar('0', info);
	}
	i = 0;
	size = arg < 0 ? size - 1 : size;
	if (size < info->precision)
	{
		while (i < info->precision - size)
		{
			ft_putchar('0', info);
			i++;
		}
	}
}

void		ft_space_di_back(t_printf *info, int size, int arg)
{
	int i;

	i = 0;
	if (info->padding == 1)
	{
		if (info->precision < size)
		{
			while (++i <= info->width - size)
				ft_putchar(' ', info);
		}
		else if (info->precision >= size && arg >= 0)
		{
			while (++i <= info->width - info->precision)
				ft_putchar(' ', info);
		}
		else if (arg < 0)
		{
			while (++i <= info->width - (info->precision + 1))
				ft_putchar(' ', info);
		}
	}
}

void		ft_printdi(t_printf *info, va_list *va)
{
	int		arg;
	int		size;

	if (va != NULL)
	{
		arg = va_arg(*va, int);
		size = ft_calci(ft_abs(arg));
		size = arg < 0 ? size + 1 : size;
		ft_do_printdi(info, size, arg);
	}
}
