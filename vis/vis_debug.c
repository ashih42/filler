/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:24:17 by ashih             #+#    #+#             */
/*   Updated: 2018/01/05 13:24:21 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void			print_gstate(t_game *game, t_gstate *state)
{
	int			i;

	ft_printf("{bold}Turn %d\n{reset}", state->turn_number);
	ft_printf("Whose turn? %d\n", state->whose_turn);
	ft_printf("{red}P1 Dead? %d\n{reset}", state->is_dead[0]);
	ft_printf("{blue}P2 Dead? %d\n{reset}", state->is_dead[1]);
	ft_printf("{red}P1 Score = %d\n{reset}", state->score[0]);
	ft_printf("{blue}P2 Score = %d\n{reset}", state->score[1]);
	ft_printf("{yellow}Piece Width = %d\n", state->piece_width);
	ft_printf("Piece Height = %d\n", state->piece_height);
	ft_printf("Piece:\n");
	i = 0;
	while (i < state->piece_height)
		ft_printf("%s\n", state->piece[i++]);
	ft_printf("{reset}Map:\n");
	i = 0;
	while (i < game->height)
		ft_printf("%s\n", state->map[i++]);
	ft_printf("\n");
}
