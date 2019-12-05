/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:09:18 by tefroiss          #+#    #+#             */
/*   Updated: 2019/11/21 18:21:51 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL && n != 0)
	{
		while ((*s1 || *s2) && *s1 == *s2 && --n > 0)
		{
			s1++;
			s2++;
		}
		return (((unsigned char)*s1 - (unsigned char)*s2));
	}
	return (0);
}
