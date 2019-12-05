/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:30:43 by tefroiss          #+#    #+#             */
/*   Updated: 2019/11/21 18:16:29 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n;

	if (haystack != NULL && needle != NULL && *needle)
	{
		n = ft_strlen(needle);
		while (*haystack && len-- >= n)
		{
			if (ft_strncmp(haystack, needle, n) == 0)
				return ((char *)haystack);
			haystack++;
		}
		return (NULL);
	}
	return ((char *)haystack);
}
