/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:23:35 by ashih             #+#    #+#             */
/*   Updated: 2018/01/05 13:23:40 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int				init_master(t_master *m, char *input_file)
{
	ft_bzero(m, sizeof(t_master));
	m->game = ft_memalloc(sizeof(t_game));
	if (read_file(input_file, m->game))
		return (1);
	m->img_width = m->game->width * SQ_SIZE * 2;
	m->img_height = m->game->height * SQ_SIZE;
	if (!(m->mlx = mlx_init()) ||
		!(m->win = mlx_new_window(m->mlx, m->img_width, m->img_height,
			WIN_NAME)) ||
		!(m->img = mlx_new_image(m->mlx, m->img_width, m->img_height)) ||
		!(m->frame = mlx_get_data_addr(m->img, &(m->bpp), &(m->size_line),
			&(m->endian))))
		return (ft_puterror(ERROR_MALLOC));
	m->bpp /= 8;
	render(m, 0);
	return (0);
}

int				main(int argc, char **argv)
{
	t_master	m;
	char		*input_file;

	if (argc >= 3)
	{
		ft_putstr(USAGE_ERROR);
		return (0);
	}
	input_file = (argc == 2) ? argv[1] : 0;
	if (init_master(&m, input_file))
		return (free_all(&m));
	mlx_hook(m.win, 2, 0, key_press_hook, &m);
	mlx_hook(m.win, 3, 0, key_release_hook, &m);
	mlx_loop_hook(m.mlx, loop_hook, &m);
	mlx_loop(m.mlx);
	return (0);
}
