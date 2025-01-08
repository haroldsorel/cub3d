/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:23:33 by haroldsorel       #+#    #+#             */
/*   Updated: 2024/12/24 14:23:42 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

double  dda(t_data *data, t_player *player)
{
    int     x;
    int     y;
    double  x_inc;
    double  y_inc;
    double  delta_x;
    double  delta_y;
    double  len_x;
    double  len_y;

    x = (int)(player->pos.x / data->map->grid_size);
    y = (int)(player->pos.y / data->map->grid_size);
    delta_x = fabs(data->map->grid_size / player->dir.x);
    delta_y = fabs(data->map->grid_size / player->dir.y);
    // what happens if dir x = 0 or dir y = 0??
    if (player->dir.x < 0.0f)
    {
        x_inc = -1;
        len_x = fabs((player->pos.x - (x * data->map->grid_size)) / player->dir.x);
    }
    else
    {
        x_inc = 1;
        len_x = fabs((((x + 1) * data->map->grid_size) - player->pos.x) / player->dir.x);
    }
    if (player->dir.y < 0.0f)
    {
        y_inc = -1;
        len_y = fabs((player->pos.y - (y * data->map->grid_size)) / player->dir.y);
    }
    else
    {
        y_inc = 1;
        len_y = fabs((((y + 1) * data->map->grid_size) - player->pos.y) / player->dir.y);
    }
    while ((data->map->matrix)[y][x] != '1')
    {
        printf("current ray_pos (%d, %d) xray is : %f yray is : %f\n", x, y, len_x, len_y);
        if (len_x < len_y)
        {
            printf("ray crosses x = %d\n", x);
            x += x_inc;
            len_x += delta_x;
        }
        else
        {
            printf("ray crosses y = %d\n", y);
            y += y_inc;
            len_y += delta_y;
        }
        //what happens if they are equal
    }
    printf("\n\n");
    return (len_x);
}