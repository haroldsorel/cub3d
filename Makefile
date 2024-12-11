NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I. -Ilibft #-fsanitize=address
INCLUDES = cub3d.h
mlx = mlx/libmlx.a
libft = libft/libft.a

SRCS =	main.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		misc/free.c \
		parser/parser.c \
		parser/rgb_parser.c \
		parser/map_parser.c \
		parser/texture_parser.c \
		parser/parser_utils.c \
		parser/map_validity.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

#$(NAME):	$(libft) $(mlx) $(OBJS)
#			$(CC) $(CFLAGS) $(OBJS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME):	$(libft) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

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