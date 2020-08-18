/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:01:17 by tefroiss          #+#    #+#             */
/*   Updated: 2020/06/15 15:04:14 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubvector.h"

void	ft_vec_update(t_vector *vec, double x, double y)
{
	vec->x = x;
	vec->y = y;
}
