/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:09:32 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/02 17:57:22 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

const char	*ft_checkflag(const char *format, t_printf *info)
{
	while ((*format == '-' || *format == '0'))
	{
		if (*format == '-')
			info->padding = 1;
		if (*format == '0')
		{
			if (*(format + 1) == '-')
			{
				info->padding = 1;
				format++;
			}
			else
				info->padding = 2;
		}
		format++;
	}
	return (format);
}

const char	*ft_checkwidth(const char *format, t_printf *info, va_list va)
{
	if (*format >= '0' && *format <= '9')
	{
		while (*format >= '0' && *format <= '9')
		{
			info->width = info->width * 10 + (*format - '0');
			format++;
		}
	}
	else if (*format == '*')
	{
		info->width = va_arg(va, int);
		if (info->width < 0)
		{
			info->width *= -1;
			info->padding = 1;
		}
		format++;
	}
	return (format);
}

const char	*ft_checkprecision(const char *format, t_printf *info, va_list va)
{
	if (*format == '.')
	{
		info->precision = 0;
		format++;
		if (*format >= '0' && *format <= '9')
		{
			while (*format >= '0' && *format <= '9')
			{
				info->precision = info->precision * 10 + (*format - '0');
				format++;
			}
		}
		else if (*format == '*')
		{
			info->precision = va_arg(va, int);
			format++;
		}
		if (info->precision < 0 && info->precision != -1)
			info->precision = -1;
		if (info->precision >= 0)
			if (info->padding == 2)
				info->padding = 0;
	}
	return (format);
}

const char	*ft_checktype(const char *format, t_printf *info)
{
	if (ft_checkc(*format, CONVERTER))
	{
		info->type = *format;
		format++;
	}
	else if (*format == '%')
		info->type = *format;
	return (format);
}

const char	*ft_fillstruct(const char *format, t_printf *info, va_list va)
{
	format++;
	format = ft_checkflag(format, info);
	format = ft_checkwidth(format, info, va);
	format = ft_checkprecision(format, info, va);
	format = ft_checktype(format, info);
	return (format);
}
