/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:48:56 by ashih             #+#    #+#             */
/*   Updated: 2018/01/04 22:39:28 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		print_player_info(t_ginfo *ginfo)
{
	ft_printf("{robot} I am Player %d\n", ginfo->player);
	ft_printf("{robot} My cell is: %c\n", ginfo->me);
	ft_printf("{robot} Enemy cell is: %c\n", ginfo->enemy);
	ft_printf("\n");
}

void		print_map(t_map *map)
{
	int		i;

	ft_printf("MAP height=%d, width=%d\n", map->height, map->width);
	i = -1;
	while (++i < map->height)
	{
		ft_printf("%s\n", map->array[i]);
	}
	print_heatmap(map);
}

void		print_heatmap(t_map *map)
{
	int		i;
	int		j;

	ft_printf("{red}HEAT MAP\n");
	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			ft_printf("%d ", map->heat[j][i]);
		}
		ft_printf("\n");
	}
	ft_printf("{reset}\n");
}

void		print_shape(t_shape *shape)
{
	int		i;

	ft_printf("{yellow}SHAPE: height=%d, width=%d\n",
		shape->height, shape->width);
	ft_printf("height_r=%d, width_r=%d, x_offset=%d, y_offset=%d\n",
		shape->height_r, shape->width_r, shape->x_offset, shape->y_offset);
	i = -1;
	while (++i < shape->height)
	{
		ft_printf("%s\n", shape->array[i]);
	}
	ft_printf("{reset}\n");
}
