/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:23:48 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/02 17:57:34 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_space_x_front_neg(t_printf *info)
{
	int i;

	i = 0;
	if (info->padding == 0)
	{
		if (info->precision < 8)
		{
			while (++i <= info->width - 8)
				ft_putchar(' ', info);
		}
		else if (info->precision >= 8)
		{
			while (++i <= info->width - info->precision)
				ft_putchar(' ', info);
		}
	}
}

void		ft_checksize_x(int size, t_printf *info)
{
	int i;

	i = 0;
	if (info->padding == 2)
	{
		if (info->precision > 8 && info->width > info->precision)
			while (++i <= info->width - info->precision)
				ft_putchar(' ', info);
		if (info->precision < 8)
		{
			while (++i <= info->precision - 8)
				ft_putchar(' ', info);
		}
	}
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

void		ft_checksize_x_neg(t_printf *info)
{
	int i;

	i = 0;
	if (info->padding == 2)
	{
		while (i < info->width - 8)
		{
			ft_putchar('0', info);
			i++;
		}
	}
	i = 0;
	if (8 < info->precision)
	{
		while (i < info->precision - 8)
		{
			ft_putchar('0', info);
			i++;
		}
	}
}

void		ft_space_x_front(t_printf *info, int size)
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
		if (info->precision < size)
			while (++i <= info->width - size)
				ft_putchar('0', info);
		else
			while (++i <= info->width - info->precision)
				ft_putchar(' ', info);
	}
}

void		ft_space_x_back(t_printf *info, int size)
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
		else if (info->precision >= size)
		{
			while (++i <= info->width - info->precision)
				ft_putchar(' ', info);
		}
	}
}
