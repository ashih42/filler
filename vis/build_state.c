/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 10:54:41 by ashih             #+#    #+#             */
/*   Updated: 2018/01/03 20:23:43 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int				build_gstates_all(int fd, t_game *game)
{
	char		*prev_line;

	prev_line = 0;
	build_gstate_0(fd, game);
	game->turns_total = 1;
	while (prev_line == 0 || !ft_strnequ(prev_line, "==", 2))
	{
		build_gstate_n(fd, game, game->states->content, &prev_line);
		game->turns_total++;
	}
	ft_strdel(&prev_line);
	build_gstates_array(game, game->states);
	return (0);
}

int				build_gstate_0(int fd, t_game *game)
{
	t_gstate	*s0;

	s0 = ft_memalloc(sizeof(t_gstate));
	s0->whose_turn = -1;
	skip_next_line(fd, 1);
	get_map(fd, s0, game);
	ft_lstadd(&(game->states), ft_lst_new_ref(s0, sizeof(t_gstate)));
	return (0);
}

int				build_gstate_n(int fd, t_game *game, t_gstate *prev_state,
		char **prev_line)
{
	t_gstate	*state;
	char		*line;

	state = ft_memalloc(sizeof(t_gstate));
	inherit_values(state, prev_state);
	get_piece(fd, state, prev_line);
	determine_whose_turn(fd, state);
	get_next_line(fd, &line);
	if (!ft_strnequ(line, "Plat", 4))
	{
		*prev_line = line;
		state->is_dead[state->whose_turn] = 1;
		copy_prev_map(game, state, prev_state);
		ft_lstadd(&(game->states), ft_lst_new_ref(state, sizeof(t_gstate)));
		return (0);
	}
	ft_strdel(&line);
	skip_next_line(fd, 1);
	get_map(fd, state, game);
	state->score[state->whose_turn]++;
	ft_lstadd(&(game->states), ft_lst_new_ref(state, sizeof(t_gstate)));
	return (0);
}

void			determine_whose_turn(int fd, t_gstate *state)
{
	char		*line;

	get_next_line(fd, &line);
	if (ft_strnequ(line, "<got", 4))
		state->whose_turn = (line[6] == 'O') ? 0 : 1;
	else
		state->whose_turn = (line[12] == 'O') ? 0 : 1;
	ft_strdel(&line);
}

int				build_gstates_array(t_game *game, t_list *list)
{
	int			i;

	game->states_array = ft_memalloc(sizeof(t_gstate *) * (game->turns_total));
	i = game->turns_total - 1;
	while (i >= 0)
	{
		game->states_array[i--] = list->content;
		list = list->next;
	}
	return (0);
}
