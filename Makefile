# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashih <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 15:14:36 by ashih             #+#    #+#              #
#    Updated: 2018/01/05 13:39:39 by ashih            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = players/ashih.filler
VIS = visualizer

CFLAGS = -Wall -Werror -Wextra

INCLUDE = include
LIBFT = libft
MINILIBX = minilibx

SRC_CFILES = debug.c\
			 freedom.c\
			 heatmap.c\
			 main.c\
			 read_input.c\
			 reduce_shape.c\
			 reduce_shape_helper.c
SRC_OFILES = $(SRC_CFILES:.c=.o)

VIS_CFILES = build_state.c\
		 build_state_helper.c\
		 draw.c\
		 draw_helper.c\
		 key_func.c\
		 key_hook.c\
		 read_file.c\
		 vis_debug.c\
		 vis_freedom.c\
		 vis_main.c
VIS_OFILES = $(VIS_CFILES:.c=.o)

all: $(NAME) $(VIS)

$(NAME):
	@echo "\x1b[1m\nBuilding $(LIBFT) library...\x1b[0m"
	make -C $(LIBFT)
	@echo "\x1b[1m\nBuilding $(NAME)...\x1b[0m"
	$(CC) $(CFLAGS) -c $(addprefix src/, $(SRC_CFILES)) -I$(INCLUDE)
	$(CC) -o $(NAME) $(SRC_OFILES) -L$(LIBFT) -lft

$(VIS):
	@echo "\x1b[1m\nBuilding $(MINILIBX) library...\x1b[0m"
	make -C $(MINILIBX)
	@echo "\x1b[1m\nBuilding $(VIS)...\x1b[0m"
	$(CC) $(CFLAGS) -c $(addprefix vis/, $(VIS_CFILES)) -I$(INCLUDE)
	$(CC) -o $(VIS) $(VIS_OFILES) -L$(LIBFT) -lft -L$(MINILIBX) -lmlx\
		-framework OpenGL -framework AppKit

clean:
	@echo "\x1b[1m\nCleaning...\x1b[0m"
	make -C $(LIBFT) clean
	make -C $(MINILIBX) clean
	/bin/rm -f $(SRC_OFILES)
	/bin/rm -f $(VIS_OFILES)

fclean: clean
	/bin/rm -f $(LIBFT)/libft.a
	/bin/rm -f $(MINILIBX)/libmlx.a
	/bin/rm -f $(NAME)
	/bin/rm -f $(VIS)

re: fclean all

.PHONY: all clean fclean re
