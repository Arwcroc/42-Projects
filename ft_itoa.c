/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:16:43 by tefroiss          #+#    #+#             */
/*   Updated: 2019/11/19 10:41:34 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_calci(unsigned int nbr)
{
	int i;

	i = 0;
	while (nbr >= 1)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	nbr;
	int				sign;
	char			*str;

	i = 0;
	sign = n < 0 ? -1 : 1;
	nbr = ABS(n);
	if (nbr == 0)
		return (str = ft_strdup("0"));
	i = ft_calci(nbr);
	i = sign == 1 ? i : i + 1;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[0] = n < 0 ? '-' : str[0];
	str[i] = '\0';
	i--;
	while (nbr >= 1 && i >= 0)
	{
		str[i] = (nbr % 10) + 48;
		nbr = (nbr / 10);
		i--;
	}
	return (str);
}
