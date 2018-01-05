/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 17:43:54 by ashih             #+#    #+#             */
/*   Updated: 2018/01/01 20:06:23 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

/*
** Keycode		Key					Function
** 53			ESC					Terminate program
** 49			SPACE				Reset to Turn 0
** 123			LEFT ARROW			Go to previous turn
** 124			RIGHT ARROW			Go to next turn
** 125			DOWN ARROW			Hold to keep rewinding turns
** 126			UP ARROW			Hold to keep forwarding turns
*/

int				key_press_hook(int keycode, void *param)
{
	t_master	*m;

	m = (t_master *)param;
	if (keycode == 125)
		m->rewind = 1;
	else if (keycode == 126)
		m->forward = 1;
	else if (keycode == 123)
		backward_one_turn(m);
	else if (keycode == 124)
		forward_one_turn(m);
	else if (keycode == 49)
		m->current_turn = 0;
	else if (keycode == 53)
		terminate(m);
	return (0);
}

int				key_release_hook(int keycode, void *param)
{
	t_master	*m;

	m = (t_master *)param;
	if (keycode == 125)
		m->rewind = 0;
	else if (keycode == 126)
		m->forward = 0;
	return (0);
}

int				loop_hook(void *param)
{
	t_master	*m;

	m = (t_master *)param;
	if (m->rewind == 1)
		backward_one_turn(m);
	else if (m->forward == 1)
		forward_one_turn(m);
	render(m, m->current_turn);
	return (0);
}
