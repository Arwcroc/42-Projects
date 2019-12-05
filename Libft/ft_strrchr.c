/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:58:01 by tefroiss          #+#    #+#             */
/*   Updated: 2019/11/21 18:33:42 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *result;

	result = NULL;
	if (s != NULL)
	{
		while (*s)
		{
			result = (c == *s) ? (char *)s : result;
			s++;
		}
		result = (c == '\0') ? (char *)s : result;
	}
	return (result);
}
