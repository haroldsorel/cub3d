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

typedef struct s_map
{
    char    **map;
    int     rows;
    int     cols;
    int     floor_color;
    int     ceiling_color;
    int     wall_color;
}   t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
    t_map		*map;
	void        *mlx;
	void        *mlx_win;
	t_img       *img;
}   t_data;

char    *get_next_line(int fd);
void    *free_array_of_pointers(void **array);

int     init_map(t_map *map, int fd);
int     row_len(char **map);

#endif