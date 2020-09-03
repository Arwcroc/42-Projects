/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:06:08 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/03 12:12:06 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_putnbrhexa(int nb, t_printf *info)
{
	unsigned int	nbr;

	nbr = ft_absl(nb);
	if (nbr > 15)
		ft_putnbrhexa(nbr / 16, info);
	ft_putchar(HEXADECIMAL[nbr % 16], info);
}

void		ft_putnbrhexaneg(long nb, t_printf *info)
{
	long	nbr;

	if (nb < 0)
		nbr = (nb * -1) - 1;
	else
		nbr = nb;
	if (nbr > 15)
		ft_putnbrhexaneg(nbr / 16, info);
	ft_putchar(NEGHEXA[nbr % 16], info);
}

void		ft_putsomef(int size, t_printf *info)
{
	int i;

	i = 0;
	while (i++ < 8 - size)
		ft_putchar('f', info);
}

int			ft_calchexa(int nb)
{
	int	nbr;
	int	i;

	i = 0;
	if (nb < 0)
		nbr = (nb * -1) - 1;
	else
		nbr = nb;
	if (nbr == 0)
		return (1);
	while (nbr >= 1)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

void		ft_printx(t_printf *info, va_list *va)
{
	int		arg;
	int		size;
	int		i;

	if (va != NULL)
	{
		i = 0;
		arg = va_arg(*va, int);
		size = ft_calchexa(arg);
		if (info->precision == 0 && arg == 0)
		{
			while (i++ < info->width)
				ft_putchar(' ', info);
		}
		else
			ft_do_printx(info, size, arg);
	}
}
