/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:29:52 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/13 19:05:01 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;

	if (s1 != NULL && s2 != NULL && s1 != s2 && n != 0)
	{
		first = (unsigned char *)s1;
		second = (unsigned char *)s2;
		while (*first == *second && --n > 0)
		{
			first++;
			second++;
		}
		return ((int)(*first - *second));
	}
	return (0);
}
