/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:48:49 by tefroiss          #+#    #+#             */
/*   Updated: 2020/02/11 15:11:31 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long		ft_abs(long nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

void		ft_init_struct(t_printf *info)
{
	info->padding = 0;
	info->type = 48;
	info->width = 0;
	info->precision = -1;
	info->count = 0;
}

void		ft_init_struct_wc(t_printf *info)
{
	info->padding = 0;
	info->type = 48;
	info->width = 0;
	info->precision = -1;
}

void		ft_whattoprint(t_printf *info, va_list *va)
{
	if (info->type == 'c')
		ft_printc(info, va);
	if (info->type == 's')
		ft_prints(info, va);
	if (info->type == 'd' || info->type == 'i')
		ft_printdi(info, va);
	if (info->type == 'u')
		ft_printu(info, va);
	if (info->type == 'x')
		ft_printx(info, va);
	if (info->type == 'X')
		ft_printxup(info, va);
	if (info->type == 'p')
		ft_printp(info, va);
	if (info->type == '%')
		ft_printperc(info, va);
	return ;
}

int			ft_printf(const char *format, ...)
{
	t_printf	info;
	va_list		va;

	ft_init_struct(&info);
	if (format != NULL && *format)
	{
		va_start(va, format);
		while (*format)
		{
			ft_init_struct_wc(&info);
			if (*format == '%')
			{
				format = ft_fillstruct(format, &info, va);
				ft_whattoprint(&info, &va);
			}
			else
			{
				ft_putchar(*format, &info);
				if (*(format) != '\0')
					format++;
			}
		}
		va_end(va);
	}
	return (info.count);
}
