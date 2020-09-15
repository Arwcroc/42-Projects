/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_dist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:06:44 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/15 15:04:14 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubvector.h"

double		ft_vec_dist(t_vector *vec1, t_vector vec2)
{
	t_vector diff;

	diff = vec1->sub(vec1, vec2);
	return (diff.length(&diff));
}
