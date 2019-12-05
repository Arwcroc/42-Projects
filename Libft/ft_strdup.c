/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:39:33 by tefroiss          #+#    #+#             */
/*   Updated: 2019/11/21 18:41:20 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*src;

	if (s1 != NULL)
	{
		if (!(src = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
			return (NULL);
		ft_memmove(src, s1, ft_strlen(s1) + 1);
		return (src);
	}
	return (NULL);
}
