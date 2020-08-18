/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 16:35:14 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/15 15:04:14 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubvector.h"

static inline void		init_method(t_vector *new)
{
	new->add = ft_vec_add;
	new->sub = ft_vec_sub;
	new->mul = ft_vec_mul;
	new->div = ft_vec_div;
	new->dot = ft_vec_dot;
	new->add_scalar = ft_vec_add_scalar;
	new->sub_scalar = ft_vec_sub_scalar;
	new->mul_scalar = ft_vec_mul_scalar;
	new->div_scalar = ft_vec_div_scalar;
	new->length = ft_vec_length;
	new->direction = ft_vec_direction;
	new->update = ft_vec_update;
	new->normalise = ft_vec_normalise;
	new->dist = ft_vec_dist;
}

t_vector				ft_vector(double x, double y)
{
	t_vector new;

	new.x = x;
	new.y = y;
	init_method(&new);
	return (new);
}
