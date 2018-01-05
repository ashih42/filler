/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_shape_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:41:06 by ashih             #+#    #+#             */
/*   Updated: 2018/01/04 22:41:18 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		first_row_is_empty(t_shape *shape)
{
	int	i;

	i = -1;
	while (++i < shape->width)
	{
		if (shape->array[0][i] == '*')
			return (0);
	}
	return (1);
}

void	shift_up(t_shape *shape)
{
	int	i;

	i = 1;
	while (i < shape->height)
	{
		ft_strcpy(shape->array[i - 1], shape->array[i]);
		i++;
	}
	shape->array[--i][0] = '\0';
}

int		first_col_is_empty(t_shape *shape)
{
	int	i;

	i = -1;
	while (++i < shape->height)
	{
		if (shape->array[i][0] == '*')
			return (0);
	}
	return (1);
}

void	shift_left(t_shape *shape)
{
	int	i;

	i = -1;
	while (++i < shape->height)
	{
		ft_strcpy(shape->array[i], shape->array[i] + 1);
	}
}
