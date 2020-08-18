/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_normalise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:54:46 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/15 15:04:14 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubvector.h"

t_vector	ft_vec_normalise(t_vector *vec)
{
	t_vector new;

	new = vec->div_scalar(vec, vec->length(vec));
	return (new);
}
