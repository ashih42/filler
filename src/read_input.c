/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 17:49:46 by ashih             #+#    #+#             */
/*   Updated: 2018/01/04 16:10:46 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_player_info(t_ginfo *ginfo)
{
	char	*line;

	get_next_line(0, &line);
	ginfo->player = line[10] - '0';
	if (ginfo->player == 1)
	{
		ginfo->me = 'O';
		ginfo->enemy = 'X';
	}
	else
	{
		ginfo->me = 'X';
		ginfo->enemy = 'O';
	}
	ft_strdel(&line);
	return (0);
}

int			read_map(t_map *map, char *line, t_ginfo *ginfo)
{
	int		i;

	read_map_dimen(map, line);
	map->array = ft_memalloc(sizeof(char *) * (map->height));
	get_next_line(0, &line);
	ft_strdel(&line);
	i = 0;
	while (i < map->height)
	{
		get_next_line(0, &line);
		map->array[i++] = ft_strdup(ft_strchr(line, ' ') + 1);
		ft_strdel(&line);
	}
	build_heatmap(map, ginfo);
	return (0);
}

void		read_map_dimen(t_map *map, char *line)
{
	char	*height;
	char	*width;

	height = ft_strchr(line, ' ') + 1;
	width = ft_strchr(height, ' ') + 1;
	map->height = ft_atoi(height);
	map->width = ft_atoi(width);
	ft_strdel(&line);
}

int			read_shape(t_shape *shape)
{
	int		i;

	read_shape_dimen(shape);
	shape->array = ft_memalloc(sizeof(char *) * (shape->height));
	i = 0;
	while (i < shape->height)
		get_next_line(0, shape->array + i++);
	reduce_shape(shape);
	return (0);
}

void		read_shape_dimen(t_shape *shape)
{
	char	*line;
	char	*height;
	char	*width;

	get_next_line(0, &line);
	height = ft_strchr(line, ' ') + 1;
	width = ft_strchr(height, ' ') + 1;
	shape->height = ft_atoi(height);
	shape->width = ft_atoi(width);
	ft_strdel(&line);
}
