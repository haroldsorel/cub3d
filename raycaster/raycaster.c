/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:53:38 by haroldsorel       #+#    #+#             */
/*   Updated: 2024/12/19 00:53:47 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

double    get_distance(double x1, double y1, double x2, double y2)
{
    return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

double  cast_one_ray(t_data *data, double dirx, double diry, int color)
{
    double      y;
    double      x;
    int         i;

    i = 0;
    y = data->player->pos.y;
    x = data->player->pos.x;
    if (dirx == 0.0f || dirx == -0.0f)
    {
        while ((data->map->matrix)[(int)(y + i) / data->map->grid_size][(int)x / data->map->grid_size] == '0')
        {
            my_mlx_pixel_put(&(data->img), (int)(data->player->pos.x), (int)(data->player->pos.y + i), color);
            i++;
        }
        return (i); //this maybe wrong
    }
    while ((data->map->matrix)[(int)y/data->map->grid_size][(int)x/data->map->grid_size] == '0')
    {
        my_mlx_pixel_put(&(data->img), (int)x, (int)y, color);
        y += diry;
        x += dirx;
        i++;
    }
    //return (get_distance(data->player->pos.x, data->player->pos.y, x, y));
    return (0);
}

void    raycaster(t_data *data, int color) //this could be simplified
{
    double  angle;
    double  angle_between_rays;
    double  dir_x; //45 degree offset of player->dir
    double  dir_y; //
    int     i;

    i = 0;
    angle = -M_PI / 4;
    angle_between_rays = (M_PI / 2) / WIDTH;
    dir_x = data->player->dir.x * cos(-M_PI / 4) - data->player->dir.y * sin(-M_PI / 4);
    dir_y = data->player->dir.x * sin(-M_PI / 4) + data->player->dir.y * cos(-M_PI / 4);
    while (i <= WIDTH)
    {
        //printf("Ray Number %d Length: %f\n", i, cast_one_ray(data, dir_x, dir_y, color));
        cast_one_ray(data, dir_x, dir_y, color);
        angle += angle_between_rays;
        dir_x = data->player->dir.x * cos(angle) - data->player->dir.y * sin(angle);
        dir_y = data->player->dir.x * sin(angle) + data->player->dir.y * cos(angle);
        i++;
    }
}