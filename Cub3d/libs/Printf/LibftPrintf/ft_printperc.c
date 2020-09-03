/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printperc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:24:53 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/02 17:57:32 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_space_perc_front(t_printf *info)
{
	int i;

	i = 0;
	if (info->padding == 0)
		while (++i <= info->width - 1)
			ft_putchar(' ', info);
	if (info->padding == 2)
	{
		while (++i <= info->width - 1)
			ft_putchar('0', info);
	}
}

void		ft_checksize_perc(t_printf *info)
{
	int i;

	i = 0;
	if (1 < info->precision)
	{
		while (i < info->precision - 1)
		{
			ft_putchar('0', info);
			i++;
		}
	}
}

void		ft_space_perc_back(t_printf *info)
{
	int i;

	i = 0;
	if (info->padding == 1)
		while (++i <= info->width - 1)
			ft_putchar(' ', info);
}

void		ft_printperc(t_printf *info, va_list *va)
{
	int		arg;

	if (va != NULL)
	{
		arg = '%';
		ft_space_perc_front(info);
		if (arg < 0)
			ft_putchar('-', info);
		ft_putchar(arg, info);
		ft_space_perc_back(info);
	}
}
