/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:44:59 by tefroiss          #+#    #+#             */
/*   Updated: 2019/12/02 17:07:52 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t size_src;
	size_t size_dest;
	size_t i;

	if (dst != NULL && src != NULL)
	{
		size_src = ft_strlen(src);
		size_dest = ft_strlen((const char *)dst);
		i = 0;
		if ((dstsize < size_dest))
			return (dstsize + size_src);
		while (src[i] && size_dest + i < dstsize - 1)
		{
			dst[size_dest + i] = src[i];
			i++;
		}
		dst[size_dest + i] = '\0';
		return (size_dest + size_src);
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dst != NULL && src != NULL)
	{
		i = 0;
		if (dstsize == 0)
			return (ft_strlen(src));
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (ft_strlen(src));
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		if ((size_t)start >= ft_strlen(s) || !(*s) || len == 0)
			return (ft_strdup("\0"));
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s[start + i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (ft_strdup("\0"));
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*src;

	if (s1 != NULL)
	{
		i = 0;
		while (s1[i] != '\0')
			i++;
		if (!(src = (char*)malloc(sizeof(char) * i + 1)))
			return (NULL);
		i = 0;
		while (s1[i] != '\0')
		{
			src[i] = s1[i];
			i++;
		}
		src[i] = '\0';
		return (src);
	}
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*concat;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		if (!(concat = (char *)malloc((s1_len + s2_len + 1) * sizeof(char))))
			return (NULL);
		ft_strlcpy(concat, s1, s1_len + 1);
		ft_strlcat(concat, s2, s2_len + s1_len + 1);
		return (concat);
	}
	return (ft_strdup("\0"));
}
