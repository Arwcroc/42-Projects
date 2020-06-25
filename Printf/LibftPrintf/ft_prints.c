/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:07:22 by tefroiss          #+#    #+#             */
/*   Updated: 2020/02/11 13:36:03 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_size_s(t_printf *info, char *arg)
{
	int i;

	i = 0;
	if (arg != NULL)
	{
		i = ft_strlen(arg);
		if (info->precision == -1)
			return (i);
		else if (info->precision == 0)
			return (0);
		else if (i <= info->precision)
			return (i);
		else if (info->precision < i)
			return (info->precision);
	}
	return (0);
}

void	ft_printfs(t_printf *info, char *arg)
{
	int i;

	i = 0;
	if (arg != NULL)
	{
		i = ft_strlen(arg);
		if (info->precision == 0)
			return ;
		if (i <= info->precision || info->precision == -1)
			ft_putstr(arg, info);
		else
		{
			i = 0;
			while (i < info->precision && *arg)
			{
				ft_putchar(*arg, info);
				arg++;
				i++;
			}
		}
	}
}

void	ft_space_s_front(t_printf *info, int size)
{
	int i;

	i = 0;
	if (info->padding == 0)
	{
		while (++i <= info->width - size)
			ft_putchar(' ', info);
	}
}

void	ft_space_s_back(t_printf *info, int size)
{
	int i;

	i = 0;
	if (info->padding == 1)
	{
		while (++i <= info->width - size)
			ft_putchar(' ', info);
	}
}

void	ft_prints(t_printf *info, va_list *va)
{
	char	*arg;
	int		size;

	size = 0;
	if (va != NULL)
	{
		arg = (char *)va_arg(*va, char *);
		arg = (arg == NULL) ? "(null)" : arg;
		size = ft_size_s(info, arg);
		ft_space_s_front(info, size);
		if (info->precision != 0)
			ft_printfs(info, arg);
		ft_space_s_back(info, size);
	}
}
