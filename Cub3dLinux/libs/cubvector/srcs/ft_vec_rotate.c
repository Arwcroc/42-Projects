/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:42:49 by tefroiss          #+#    #+#             */
/*   Updated: 2020/07/02 14:59:56 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubvector.h"

void	rotate(t_vector *vector, double angle)
{
	t_vector old;

	old = *vector;
	vector->x = old.x * cos(angle * TPI) - old.y * sin(angle * TPI);
	vector->y = old.x * sin(angle * TPI) + old.y * cos(angle * TPI);
}
