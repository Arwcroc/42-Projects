/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:48:43 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/13 19:04:52 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		j;

	if (s != NULL && f != NULL)
	{
		i = 0;
		j = ft_strlen(s);
		if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
			return (NULL);
		while (*s)
		{
			str[i] = (*f)(i, *s);
			i++;
			s++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
