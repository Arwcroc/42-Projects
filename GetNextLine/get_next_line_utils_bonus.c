/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:44:59 by tefroiss          #+#    #+#             */
/*   Updated: 2020/02/11 18:13:36 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	if (s1 != NULL)
	{
		i = ft_strlen(s1);
		if (!(str = (char *)malloc(sizeof(char) * i + 1)))
			return (NULL);
		i = 0;
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s != NULL)
	{
		i = 0;
		if ((size_t)start >= ft_strlen(s) && !(*s) && len == 0)
			return (ft_strdup("\0"));
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s[start + i] != '\0' && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (ft_strdup("\0"));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	int		i;

	if (s1 != NULL && s2 != NULL)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		i = -1;
		if (!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
			return (NULL);
		while (s1[++i] != '\0')
			str[i] = s1[i];
		i = 0;
		while (s2[i] != '\0')
		{
			str[s1_len + (size_t)i] = s2[i];
			i++;
		}
		str[s1_len + i] = '\0';
		return (str);
	}
	return (ft_strdup("\0"));
}
