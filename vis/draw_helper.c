/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 17:28:59 by ashih             #+#    #+#             */
/*   Updated: 2018/01/01 20:21:00 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static const t_color_map	g_color_map[] =
{
	{'.', WALL_COLOR},
	{'O', P1_COLOR},
	{'o', P1_COLOR_NEW},
	{'X', P2_COLOR},
	{'x', P2_COLOR_NEW},
	{0, 0}
};

int							get_color(char c)
{
	int						i;

	i = -1;
	while (g_color_map[++i].symbol != 0)
	{
		if (g_color_map[i].symbol == c)
			return (g_color_map[i].color);
	}
	return (0);
}

void						draw_dot(int x, int y, int color, t_master *m)
{
	if (0 <= x && x < m->img_width && 0 <= y && y < m->img_height)
		*(int *)(m->frame + (x + y * m->img_width) * m->bpp) = color;
}

void						draw_square(int x, int y, int color, t_master *m)
{
	int						i;
	int						j;

	i = 0;
	while (i < SQ_SIZE - 2)
	{
		j = 0;
		while (j < SQ_SIZE - 2)
		{
			draw_dot(x + j, y + i, color, m);
			j++;
		}
		i++;
	}
}
