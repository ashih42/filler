/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 17:42:07 by ashih             #+#    #+#             */
/*   Updated: 2018/01/01 20:27:21 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int				terminate(t_master *m)
{
	free_all(m);
	exit(0);
	return (0);
}

int				backward_one_turn(t_master *m)
{
	if (m->current_turn > 0)
		m->current_turn--;
	return (0);
}

int				forward_one_turn(t_master *m)
{
	if (m->current_turn < m->game->turns_total - 1)
		m->current_turn++;
	return (0);
}
