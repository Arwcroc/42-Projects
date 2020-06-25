/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:24:35 by tefroiss          #+#    #+#             */
/*   Updated: 2020/02/10 18:20:54 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_space_u_front(t_printf *info, int size)
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
		else
		{
			while (++i <= info->width - info->precision)
				ft_putchar(' ', info);
		}
	}
	if (info->padding == 2)
	{
		while (++i <= info->width - size)
			ft_putchar('0', info);
	}
}

void		ft_checksize_u(int size, t_printf *info)
{
	int i;

	i = 0;
	if (size < info->precision)
	{
		while (i < info->precision - size)
		{
			ft_putchar('0', info);
			i++;
		}
	}
}

void		ft_space_u_back(t_printf *info, int size)
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
		else
		{
			while (++i <= info->width - info->precision)
				ft_putchar(' ', info);
		}
	}
}

void		ft_do_printu(t_printf *info, int size, int arg)
{
	int i;

	i = 0;
	if (info->precision != 0)
	{
		ft_space_u_front(info, size);
		ft_checksize_u(size, info);
		ft_putnbru(arg, info);
		ft_space_u_back(info, size);
	}
	else if (info->precision == 0 && arg != 0)
	{
		ft_space_u_front(info, size);
		ft_putnbru(arg, info);
		ft_space_u_back(info, size);
	}
	else
	{
		while (i++ < info->width)
			ft_putchar(' ', info);
	}
}

void		ft_printu(t_printf *info, va_list *va)
{
	int		arg;
	int		size;
	int		i;

	if (va != NULL)
	{
		i = 0;
		arg = va_arg(*va, unsigned int);
		size = ft_calci(arg);
		ft_do_printu(info, size, arg);
	}
}
