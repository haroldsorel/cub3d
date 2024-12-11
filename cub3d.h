/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:25:52 by haroldsorel       #+#    #+#             */
/*   Updated: 2024/12/10 17:25:59 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

/*	color constants	*/
# define RED 0x00FF0000
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define PINK 0xFFC0CB
# define BROWN 0xA52A2A

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACE 49
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_ESCAPE 53
# define MOUSE_DOWN 4
# define MOUSE_UP 5
# define KEY_P 35
# define KEY_O 31
# define KEY_D 2

typedef struct	s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct	s_grid
{
	int	x;
	int	y;
}	t_grid;

typedef struct s_map
{
	char		**matrix;
	char		*no_text;
	char		*so_text;
	char		*we_text;
	char		*ea_text;
	int			ceiling_color;
	int			floor_color;
	int			info;
}	t_map;

typedef	struct s_player
{
	t_pos	pos;
}	t_player;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	t_map		*map;
	t_player	*player;
	void		*mlx;
	void		*mlx_win;
	t_img		*img;
	int			width;
	int			height;
}	t_data;

/*get_next_line*/
char	*get_next_line(int fd);

/*misc*/
void	*free_map(t_map *map);
void	*free_data(t_data *data);
void	*free_array_of_pointers(void **array);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*parsing*/
int		ft_strcmp(char *s1, char *s2);
void	no_other_ws(char *line);
int		init_map(t_data *data, int fd);
int		row_len(char **map);
char	**add_line_to_map(char **map, char *line);
int		parser(t_data *data, int fd);
int		rgb_parser(t_map *map, char *type, char *str);
int		texture_parser(t_map *map, char *orientation, char *path);
int		map_parser(t_data *data);
int		is_valid_map(char **map);


int		is_valid_map(char **map);

#endif