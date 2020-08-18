/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_add_scalar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:49:47 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/15 15:03:35 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubvector.h"

t_vector	ft_vec_add_scalar(t_vector *vec, double scalar)
{
	t_vector new;

	new = ft_vector(0, 0);
	new.x = vec->x + scalar;
	new.y = vec->y + scalar;
	return (new);
}
