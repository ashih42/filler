/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 05:48:19 by ashih             #+#    #+#             */
/*   Updated: 2018/01/03 20:24:32 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int			read_file(char *input_file, t_game *game)
{
	int		fd;

	if (input_file == 0)
		fd = 0;
	else
	{
		if ((fd = open(input_file, O_RDONLY)) == -1)
			return (ft_puterror(ERROR_OPEN_FILE));
	}
	if (get_player_names(fd, game) || get_map_dimen(fd, game))
		return (1);
	build_gstates_all(fd, game);
	if (input_file != 0)
		if (close(fd) == -1)
			return (ft_puterror(ERROR_CLOSE_FILE));
	return (0);
}

int			get_player_names(int fd, t_game *game)
{
	char	*line;
	char	*temp;

	skip_next_line(fd, 5);
	get_next_line(fd, &line);
	temp = ft_strchr(line, ' ') + 1;
	if (!(game->pname[0] = ft_strdup(temp)))
		return (ft_puterror(ERROR_MALLOC));
	strip_slashes(game->pname[0]);
	ft_strdel(&line);
	skip_next_line(fd, 1);
	get_next_line(fd, &line);
	temp = ft_strchr(line, ' ') + 1;
	if (!(game->pname[1] = ft_strdup(temp)))
		return (ft_puterror(ERROR_MALLOC));
	strip_slashes(game->pname[1]);
	ft_strdel(&line);
	skip_next_line(fd, 1);
	return (0);
}

void		strip_slashes(char *str)
{
	while (ft_strchr(str, '/'))
	{
		ft_strcpy(str, ft_strchr(str, '/') + 1);
	}
}

int			get_map_dimen(int fd, t_game *game)
{
	char	*line;
	char	*height;
	char	*width;

	get_next_line(fd, &line);
	height = ft_strchr(line, ' ') + 1;
	width = ft_strchr(height, ' ') + 1;
	game->height = ft_atoi(height);
	game->width = ft_atoi(width);
	ft_strdel(&line);
	return (0);
}
