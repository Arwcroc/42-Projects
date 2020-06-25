/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:16:58 by tefroiss          #+#    #+#             */
/*   Updated: 2020/02/11 15:08:30 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void	ft_printc(t_printf *info, va_list *va)
{
	int arg;
	int i;

	i = 0;
	arg = va_arg(*va, int);
	if (info->padding == 0)
	{
		while (++i < info->width)
			ft_putchar(' ', info);
	}
	ft_putchar(arg, info);
	if (info->padding == 1)
	{
		while (++i < info->width)
			ft_putchar(' ', info);
	}
}
