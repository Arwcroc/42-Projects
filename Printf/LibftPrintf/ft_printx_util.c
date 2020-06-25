/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:52:09 by tefroiss          #+#    #+#             */
/*   Updated: 2020/02/21 16:43:14 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_do_printx(t_printf *info, int size, int arg)
{
	if (arg < 0)
	{
		ft_space_x_front_neg(info);
		ft_checksize_x_neg(info);
		ft_putsomef(size, info);
		ft_putnbrhexaneg(arg, info);
		ft_space_x_back_neg(info);
	}
	else
	{
		ft_space_x_front(info, size);
		ft_checksize_x(size, info);
		ft_putnbrhexa(arg, info);
		ft_space_x_back(info, size);
	}
}

void		ft_do_printxup(t_printf *info, int size, int arg)
{
	if (arg < 0)
	{
		ft_space_x_front_neg(info);
		ft_checksize_x_neg(info);
		ft_putsomefup(size, info);
		ft_putnbrhexanegup(arg, info);
		ft_space_x_back_neg(info);
	}
	else
	{
		ft_space_x_front(info, size);
		ft_checksize_x(size, info);
		ft_putnbrhexaup(arg, info);
		ft_space_x_back(info, size);
	}
}

void		ft_space_x_back_neg(t_printf *info)
{
	int i;

	i = 0;
	if (info->padding == 1)
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
