/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:16:11 by tefroiss          #+#    #+#             */
/*   Updated: 2020/09/03 12:12:06 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_putnbrhexaup(int nb, t_printf *info)
{
	unsigned int	nbr;

	nbr = ft_absl(nb);
	if (nbr > 15)
		ft_putnbrhexaup(nbr / 16, info);
	ft_putchar(HEXADECIMALUP[nbr % 16], info);
}

void		ft_putnbrhexanegup(long nb, t_printf *info)
{
	int	nbr;

	if (nb < 0)
		nbr = (nb * -1) - 1;
	else
		nbr = nb;
	if (nbr > 15)
		ft_putnbrhexanegup(nbr / 16, info);
	ft_putchar(NEGHEXAUP[nbr % 16], info);
}

void		ft_putsomefup(int size, t_printf *info)
{
	int i;

	i = 0;
	while (++i <= 8 - size)
		ft_putchar('F', info);
}

void		ft_printxup(t_printf *info, va_list *va)
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
			ft_do_printxup(info, size, arg);
	}
}
