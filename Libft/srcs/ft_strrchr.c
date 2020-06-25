/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:58:01 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/13 19:04:54 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
