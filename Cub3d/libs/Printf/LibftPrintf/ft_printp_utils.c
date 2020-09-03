/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:14:19 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/03 12:12:05 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_space_p_back_neg(t_printf *info)
{
	int i;

	i = 0;
	if (info->padding == 1)
	{
		if (info->precision < 18)
		{
			while (++i <= info->width - 18)
				ft_putchar(' ', info);
		}
		else if (info->precision >= 18)
		{
			while (++i <= info->width - info->precision)
				ft_putchar(' ', info);
		}
	}
}

void		ft_putnbrpneg(long nb, t_printf *info)
{
	long	nbr;

	if (nb < 0)
		nbr = (nb * -1) - 1;
	else
		nbr = nb;
	if (nbr > 15)
		ft_putnbrpneg(nbr / 16, info);
	ft_putchar(NEGHEXA[nbr % 16], info);
}

void		ft_space_p_back(t_printf *info, int size)
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

int			ft_calcp(long nb)
{
	long			nbr;
	int				i;

	i = 0;
	nbr = ft_absl(nb);
	if (nbr == 0)
		return (1);
	while (nbr >= 1)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

void		ft_do_printp(t_printf *info, int size, long arg)
{
	if (arg < 0)
	{
		ft_space_p_front_neg(info);
		ft_putstr("0x", info);
		ft_putsomefp(size, info);
		ft_putnbrpneg(arg, info);
		ft_space_p_back_neg(info);
	}
	else
	{
		ft_space_p_front(info, size);
		ft_putstr("0x", info);
		ft_putnbrp(arg, info);
		size += 2;
		ft_space_p_back(info, size);
	}
}
