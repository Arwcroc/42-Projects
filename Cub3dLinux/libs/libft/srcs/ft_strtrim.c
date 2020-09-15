/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:06:48 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/13 19:04:54 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_checkc(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	if (s1 != NULL && set != NULL)
	{
		i = 0;
		while (ft_checkc(s1[i], set))
			i++;
		j = (ft_strlen(s1));
		while (ft_checkc(s1[j - 1], set) && j > 1)
			j--;
		if (j == 1)
			return (ft_strdup("\0"));
		return (ft_substr(s1, i, (j - i)));
	}
	return (ft_strdup("\0"));
}
