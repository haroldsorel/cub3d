/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:46:53 by haroldsorel       #+#    #+#             */
/*   Updated: 2024/12/10 17:46:55 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void    print_map(char **map)
{
    int i;

    i = 0;
    while (map[i] != NULL)
    {
        printf("%s|\n", map[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    int     fd;
    t_map   map;
    //void  *mlx;
    //void  *mlx_win;
    if (argc != 2)
        return (1);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (-1);
    //mlx = mlx_init();
    //mlx_win = mlx_new_window(mlx, 1000, 1000, "new window");
    //mlx_loop(mlx);
    //(void) mlx_win;
    init_map(&map, fd);
    print_map(map.map);
    return (0);
}
