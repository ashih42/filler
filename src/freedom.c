/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:56:06 by ashih             #+#    #+#             */
/*   Updated: 2018/01/05 13:04:02 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_all(t_ginfo *ginfo)
{
	free_map(&(ginfo->map));
	free_shape(&(ginfo->shape));
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		ft_strdel(map->array + i);
		ft_memdel((void **)map->heat + i);
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&(map->heat));
}

void	free_shape(t_shape *shape)
{
	int	i;

	i = -1;
	while (++i < shape->height)
		ft_strdel(shape->array + i);
	ft_memdel((void **)&(shape->array));
}
