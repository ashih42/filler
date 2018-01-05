/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_state_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 17:27:21 by ashih             #+#    #+#             */
/*   Updated: 2018/01/01 20:50:14 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		inherit_values(t_gstate *state, t_gstate *prev_state)
{
	state->turn_number = prev_state->turn_number + 1;
	state->is_dead[0] = prev_state->is_dead[0];
	state->is_dead[1] = prev_state->is_dead[1];
	state->score[0] = prev_state->score[0];
	state->score[1] = prev_state->score[1];
}

void		copy_prev_map(t_game *game, t_gstate *state, t_gstate *prev_state)
{
	int		i;

	state->map = ft_memalloc(sizeof(char *) * (game->height));
	i = 0;
	while (i < game->height)
	{
		state->map[i] = ft_strdup(prev_state->map[i]);
		to_upper_str(state->map[i]);
		i++;
	}
}

void		to_upper_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int			get_piece(int fd, t_gstate *state, char **prev_line)
{
	char	*height;
	char	*width;
	int		i;

	if (*prev_line == 0)
		get_next_line(fd, prev_line);
	height = ft_strchr(*prev_line, ' ') + 1;
	width = ft_strchr(height, ' ') + 1;
	state->piece_height = ft_atoi(height);
	state->piece_width = ft_atoi(width);
	ft_strdel(prev_line);
	state->piece = ft_memalloc(sizeof(char *) * state->piece_height);
	i = 0;
	while (i < state->piece_height)
		get_next_line(fd, &(state->piece[i++]));
	return (0);
}

int			get_map(int fd, t_gstate *state, t_game *game)
{
	char	*line;
	int		i;

	state->map = ft_memalloc(sizeof(char *) * (game->height));
	i = 0;
	while (i < game->height)
	{
		get_next_line(fd, &line);
		state->map[i++] = ft_strdup(ft_strchr(line, ' ') + 1);
		ft_strdel(&line);
	}
	return (0);
}
