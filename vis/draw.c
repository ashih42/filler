/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 05:11:16 by ashih             #+#    #+#             */
/*   Updated: 2018/01/01 22:06:36 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int				render(t_master *m, int turn)
{
	t_gstate	*state;

	state = m->game->states_array[turn];
	mlx_clear_window(m->mlx, m->win);
	ft_bzero(m->frame, m->img_width * m->img_height * m->bpp);
	draw_map(m, state);
	draw_next_piece(m, turn);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	print_header(m, state);
	return (0);
}

void			draw_map(t_master *m, t_gstate *state)
{
	int			x;
	int			y;
	int			color;

	x = 0;
	while (x < m->game->height)
	{
		y = 0;
		while (y < m->game->width)
		{
			color = get_color(state->map[x][y]);
			draw_square(y * SQ_SIZE, x * SQ_SIZE, color, m);
			y++;
		}
		x++;
	}
}

void			draw_next_piece(t_master *m, int turn)
{
	t_gstate	*state;
	int			x;
	int			y;
	int			color;

	if (turn + 1 == m->game->turns_total)
		return ;
	state = m->game->states_array[turn + 1];
	x = 0;
	while (x < state->piece_height)
	{
		y = 0;
		while (y < state->piece_width)
		{
			if (state->piece[x][y] == '.')
				color = WALL_COLOR;
			else
				color = (state->whose_turn == 0) ? P1_COLOR_NEW : P2_COLOR_NEW;
			draw_square(y * SQ_SIZE + m->img_width / 2 + 10,
				x * SQ_SIZE + 100, color, m);
			y++;
		}
		x++;
	}
}

int				print_header(t_master *m, t_gstate *state)
{
	int			p1_col;
	int			p2_col;
	int			offset;
	char		*temp;

	offset = m->img_width / 2 + 10;
	p1_col = (state->whose_turn == 0) ? P1_COLOR_NEW : P1_COLOR;
	p1_col = (state->is_dead[0]) ? DEAD_COLOR : p1_col;
	p2_col = (state->whose_turn == 1) ? P2_COLOR_NEW : P2_COLOR;
	p2_col = (state->is_dead[1]) ? DEAD_COLOR : p2_col;
	mlx_string_put(m->mlx, m->win, offset, 0, DEFAULT_COLOR, "Turn");
	temp = ft_itoa(m->current_turn);
	mlx_string_put(m->mlx, m->win, offset + 50, 0, DEFAULT_COLOR, temp);
	ft_strdel(&temp);
	temp = ft_itoa(state->score[0]);
	mlx_string_put(m->mlx, m->win, offset, 20, DEFAULT_COLOR, temp);
	ft_strdel(&temp);
	mlx_string_put(m->mlx, m->win, offset + 40, 20, p1_col, m->game->pname[0]);
	temp = ft_itoa(state->score[1]);
	mlx_string_put(m->mlx, m->win, offset, 40, DEFAULT_COLOR, temp);
	ft_strdel(&temp);
	mlx_string_put(m->mlx, m->win, offset + 40, 40, p2_col, m->game->pname[1]);
	mlx_string_put(m->mlx, m->win, offset, 80, DEFAULT_COLOR, "Next Piece:");
	return (0);
}
