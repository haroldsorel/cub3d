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

static void get_perp_distance(t_data *data, t_dda *ray)
{
    double  player_angle;
    double  ray_angle;
    double  angle_diff;

    player_angle = atan2(data->player->dir.y, data->player->dir.x);
    ray_angle = atan2(ray->dir_y, ray->dir_x);
    angle_diff = player_angle - ray_angle;
    ray->perp_len = ray->len * cos(angle_diff);
}

void    dda(t_data *data, t_dda *ray)
{
    int wall;
    while (1)
    {
        if (ray->len_x < ray->len_y)
        {
            if (ray->dir_x > 0.0f)
                my_mlx_pixel_put(&(data->img), (ray->x + 1) * data->map->grid_size, data->player->pos.y + (ray->len_x * ray->dir_y), GREEN);
            else
                my_mlx_pixel_put(&(data->img), ray->x * data->map->grid_size, data->player->pos.y + (ray->len_x * ray->dir_y), GREEN);
            ray->x += ray->inc_x;
            ray->len_x += ray->delta_x;
            wall = 1;
        }
        else
        {
            if (ray->dir_y > 0.0f)
                my_mlx_pixel_put(&(data->img), data->player->pos.x + (ray->len_y * ray->dir_x),  (ray->y + 1) * data->map->grid_size, GREEN);
            else
                my_mlx_pixel_put(&(data->img), data->player->pos.x + (ray->len_y * ray->dir_x),  ray->y * data->map->grid_size, GREEN);
            ray->y += ray->inc_y;
            ray->len_y += ray->delta_y;
            wall = 0;
        }
        if ((data->map->matrix)[ray->y][ray->x] == '1')
            break ;
    }
    ray->wall = wall;
    if (wall == 1)
        ray->len = ray->len_x - ray->delta_x;
    else
        ray->len = ray->len_y - ray->delta_y;
    get_perp_distance(data, ray);
}