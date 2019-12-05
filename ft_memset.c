/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:26:09 by tefroiss          #+#    #+#             */
/*   Updated: 2019/11/21 18:51:23 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mem;
	size_t			i;

	if (b != NULL)
	{
		mem = (unsigned char *)b;
		i = 0;
		while (i < len)
		{
			mem[i] = (unsigned char)c;
			i++;
		}
	}
	return (b);
}
