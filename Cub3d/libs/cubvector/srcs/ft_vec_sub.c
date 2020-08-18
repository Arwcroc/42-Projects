/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 15:02:55 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/15 15:34:30 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubvector.h"

t_vector	ft_vec_sub(t_vector *vec1, t_vector vec2)
{
	t_vector new;

	new = ft_vector(0, 0);
	new.x = vec1->x - vec2.x;
	new.y = vec1->y - vec2.y;
	return (new);
}
