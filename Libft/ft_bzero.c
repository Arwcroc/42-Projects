/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:16:08 by tefroiss          #+#    #+#             */
/*   Updated: 2019/11/21 19:04:28 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*mem;
	size_t			i;

	if (s != NULL)
	{
		mem = (unsigned char*)s;
		i = 0;
		while (i < n)
		{
			mem[i] = 0;
			i++;
		}
	}
}
