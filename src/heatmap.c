/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:46:16 by ashih             #+#    #+#             */
/*   Updated: 2018/01/04 20:37:34 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		build_heatmap(t_map *map, t_ginfo *ginfo)
{
	int		i;
	int		j;

	map->heat = ft_memalloc(sizeof(int *) * map->height);
	j = -1;
	while (++j < map->height)
	{
		map->heat[j] = ft_memalloc(sizeof(int) * map->width);
		i = -1;
		while (++i < map->width)
			map->heat[j][i] = (map->array[j][i] == ginfo->enemy) ? 0 : -1;
	}
	populate_heat(map, ginfo, 0);
}

void		populate_heat(t_map *map, t_ginfo *ginfo, int current)
{
	int		repeat;
	int		i;
	int		j;

	repeat = 0;
	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (map->heat[j][i] == -1)
				repeat = 1;
			if (map->heat[j][i] == current)
				set_neighbors(map, i, j, current + 1);
		}
	}
	if (repeat)
		populate_heat(map, ginfo, current + 1);
}

void		set_neighbors(t_map *map, int i, int j, int new_val)
{
	if (0 <= j - 1 && map->heat[j - 1][i] == -1)
		map->heat[j - 1][i] = new_val;
	if (j + 1 < map->height && map->heat[j + 1][i] == -1)
		map->heat[j + 1][i] = new_val;
	if (0 <= i - 1 && map->heat[j][i - 1] == -1)
		map->heat[j][i - 1] = new_val;
	if (i + 1 < map->width && map->heat[j][i + 1] == -1)
		map->heat[j][i + 1] = new_val;
}
