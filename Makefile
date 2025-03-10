# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsorel <hsorel@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 17:31:07 by hsorel            #+#    #+#              #
#    Updated: 2025/02/13 17:31:08 by hsorel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft
INCLUDES = cub3d.h
mlx = mlx/libmlx.a
libft = libft/libft.a

SRCS =	main.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		misc/free.c \
		misc/mlx_utils.c \
		misc/init_structs.c \
		misc/init_text.c \
		parser/parser.c \
		parser/rgb_parser.c \
		parser/map_parser.c \
		parser/player_parser.c \
		parser/texture_parser.c \
		parser/parser_utils.c \
		parser/map_validity.c \
		events/handle_keys.c \
		events/handle_loops.c \
		events/handle_movement.c \
		events/handle_rotation.c \
		events/move.c \
		raycaster/raycaster.c \
		raycaster/dda.c \
		raycaster/draw_slice.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(libft) $(mlx) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) libft/libft.a -lz -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(libft):
	@make -C libft

$(mlx):
	@make -C mlx

clean:
	rm -f $(OBJS)
	@make -C mlx clean
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C mlx fclean
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
