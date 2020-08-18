/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:21:02 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/15 15:36:19 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubvector.h"

double	ft_vec_dot(t_vector *vec1, t_vector vec2)
{
	double result;

	result = 0.0;
	result += vec1->x * vec2.x;
	result += vec1->y * vec2.y;
	return (result);
}
