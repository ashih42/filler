/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:31:26 by ashih             #+#    #+#             */
/*   Updated: 2018/01/04 22:41:29 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	reduce_shape(t_shape *shape)
{
	shape->width_r = shape->width;
	shape->height_r = shape->height;
	shape->x_offset = 0;
	shape->y_offset = 0;
	while (last_col_is_empty(shape))
		shape->width_r--;
	while (last_row_is_empty(shape))
		shape->height_r--;
	while (first_col_is_empty(shape))
	{
		shift_left(shape);
		shape->width_r--;
		shape->x_offset--;
	}
	while (first_row_is_empty(shape))
	{
		shift_up(shape);
		shape->height_r--;
		shape->y_offset--;
	}
}

int		last_row_is_empty(t_shape *shape)
{
	int	i;

	i = -1;
	while (++i < shape->width)
	{
		if (shape->array[shape->height_r - 1][i] == '*')
			return (0);
	}
	return (1);
}

int		last_col_is_empty(t_shape *shape)
{
	int	i;

	i = -1;
	while (++i < shape->height)
	{
		if (shape->array[i][shape->width_r - 1] == '*')
			return (0);
	}
	return (1);
}
