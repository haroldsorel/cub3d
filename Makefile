NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -I. -Ilibft
INCLUDES = cub3d.h
mlx = mlx/libmlx.a
libft = libft/libft.a

SRCS =	main.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		free.c \
		init_map.c \
		map_validity.c
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(libft) $(mlx) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(libft):
	@make -C libft

$(mlx):
	@make -C mlx

clean:
	rm -f $(OBJS)
	@make -C mlx clean

fclean: clean
	rm -f $(NAME)
	@make -C mlx fclean

re: fclean all

.PHONY: all clean fclean re