/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:30:32 by ashih             #+#    #+#             */
/*   Updated: 2018/01/05 13:25:33 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define USAGE_ERROR "usage: visualizer input_file\n"
# define ERROR_OPEN_FILE "No such file"
# define ERROR_CLOSE_FILE "Cannot close file"
# define ERROR_MALLOC "Out of memory"

# define WIN_NAME "filler visualizer"
# define SIDEBAR_WIDTH 700
# define SQ_SIZE 10

# define WALL_COLOR 0x4A4A4A
# define P1_COLOR 0xFF0000
# define P1_COLOR_NEW 0xFF69B4
# define P2_COLOR 0x0000FF
# define P2_COLOR_NEW 0x00BFFF
# define DEFAULT_COLOR 0xFFFFFF
# define DEAD_COLOR 0x838B8B

typedef struct		s_gstate
{
	int				turn_number;
	int				whose_turn;
	int				is_dead[2];
	int				score[2];
	char			**map;
	int				piece_width;
	int				piece_height;
	char			**piece;
}					t_gstate;

typedef struct		s_game
{
	char			*pname[2];
	int				width;
	int				height;
	t_list			*states;
	t_gstate		**states_array;
	int				turns_total;
}					t_game;

typedef struct		s_master
{
	void			*mlx;
	void			*win;
	void			*img;
	int				img_width;
	int				img_height;
	char			*frame;
	int				bpp;
	int				size_line;
	int				endian;
	t_game			*game;
	int				current_turn;
	int				rewind;
	int				forward;
}					t_master;

typedef struct		s_color_map
{
	char			symbol;
	int				color;
}					t_color_map;

/*
** key_hook.c
*/
int					key_press_hook(int keycode, void *param);
int					key_release_hook(int keycode, void *param);
int					loop_hook(void *param);

/*
** key_func.c
*/
int					terminate(t_master *m);
int					backward_one_turn(t_master *m);
int					forward_one_turn(t_master *m);

/*
** read_file.c
*/
int					read_file(char *input_file, t_game *game);
int					get_player_names(int fd, t_game *game);
void				strip_slashes(char *str);
int					get_map_dimen(int fd, t_game *game);

/*
** build_state.c
*/
int					build_gstates_all(int fd, t_game *game);
int					build_gstate_0(int fd, t_game *game);
int					build_gstate_n(int fd, t_game *game, t_gstate *prev_state,
		char **prev_line);
void				determine_whose_turn(int fd, t_gstate *state);
int					build_gstates_array(t_game *game, t_list *list);

/*
** build_state_helper.c
*/
void				inherit_values(t_gstate *state, t_gstate *prev_state);
void				copy_prev_map(t_game *game, t_gstate *state,
		t_gstate *prev_state);
void				to_upper_str(char *str);
int					get_piece(int fd, t_gstate *state, char **prev_line);
int					get_map(int fd, t_gstate *state, t_game *game);

/*
** draw.c
*/
int					render(t_master *m, int turn);
void				draw_map(t_master *m, t_gstate *state);
void				draw_next_piece(t_master *m, int turn);
int					print_header(t_master *m, t_gstate *state);

/*
** draw_helper.c
*/
int					get_color(char c);
void				draw_dot(int x, int y, int color, t_master *m);
void				draw_square(int x, int y, int color, t_master *m);

/*
** vis_main.c
*/
int					init_master(t_master *m, char *input_file);
int					main(int argc, char **argv);

/*
** vis_freedom.c
*/
int					free_all(t_master *m);
void				free_game(t_game *game);
void				free_gstate(t_gstate *state, t_game *game);

/*
** vis_debug.c
*/
void				print_gstate(t_game *game, t_gstate *state);

#endif
