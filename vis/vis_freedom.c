/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_freedom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:23:53 by ashih             #+#    #+#             */
/*   Updated: 2018/01/05 13:23:58 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int			free_all(t_master *m)
{
	free_game(m->game);
	ft_strdel(&(m->frame));
	ft_memdel(&(m->img));
	ft_memdel(&(m->win));
	ft_memdel(&(m->mlx));
	return (0);
}

void		free_game(t_game *game)
{
	t_list	*temp;

	ft_strdel(&(game->pname[0]));
	ft_strdel(&(game->pname[1]));
	while (game->states != 0)
	{
		temp = game->states;
		free_gstate(temp->content, game);
		game->states = game->states->next;
		ft_memdel((void **)&temp);
	}
	ft_memdel((void **)&(game->states_array));
	ft_memdel((void **)&game);
}

void		free_gstate(t_gstate *state, t_game *game)
{
	int		i;

	i = 0;
	while (i < game->height)
		ft_strdel(&(state->map[i++]));
	ft_memdel((void **)&(state->map));
	i = 0;
	while (i < state->piece_height)
		ft_strdel(&(state->piece[i++]));
	ft_memdel((void **)&(state->piece));
	ft_memdel((void **)&state);
}
