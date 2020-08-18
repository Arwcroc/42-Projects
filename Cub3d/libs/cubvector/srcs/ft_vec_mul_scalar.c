/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_mul_scalar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:15:59 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/15 15:36:06 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubvector.h"

t_vector	ft_vec_mul_scalar(t_vector *vec, double scalar)
{
	t_vector new;

	new = ft_vector(0, 0);
	new.x = vec->x * scalar;
	new.y = vec->y * scalar;
	return (new);
}
