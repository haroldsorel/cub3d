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

void    init_ray(t_dda *ray, t_data *data, double dirx, double diry)
{
    ray->x = (int)(data->player->pos.x / data->map->grid_size);
    ray->y = (int)(data->player->pos.y / data->map->grid_size);
    ray->delta_x = fabs(data->map->grid_size / dirx);
    ray->delta_y = fabs(data->map->grid_size / diry);
    ray->dir_x = dirx;
    ray->dir_y = diry;
    if (ray->dir_x < 0.0f)
    {
        ray->inc_x = -1;
        ray->len_x = fabs((data->player->pos.x - (ray->x * data->map->grid_size)) / dirx);
    }
    else
    {
        ray->inc_x = 1;
        ray->len_x = fabs((((ray->x + 1) * data->map->grid_size) - data->player->pos.x) / dirx);
    }
    if (ray->dir_y < 0.0f)
    {
        ray->inc_y = -1;
        ray->len_y = fabs((data->player->pos.y - (ray->y * data->map->grid_size)) / diry);
    }
    else
    {
        ray->inc_y = 1;
        ray->len_y = fabs((((ray->y + 1) * data->map->grid_size) - data->player->pos.y) / diry);
    }
}

void    draw_col(t_data *data, t_dda *ray, int col)
{
    int i;
    double  wall_height;
    int     draw_start;
    int     draw_end;

    wall_height = (data->map->grid_size * HEIGHT)/ ray->perp_len;
    if (wall_height > HEIGHT)
        wall_height = HEIGHT; //put maybe a -1
    draw_start = HEIGHT / 2 - (wall_height / 2);
    i = 0;
    draw_end = wall_height + draw_start;
    while (i < draw_start)
    {
        my_mlx_pixel_put(&(data->img2), col, i, CYAN);
        i++;
    }
    while (i < draw_end)
    {
        if (ray->wall == 1)
            my_mlx_pixel_put(&(data->img2), col, i, RED);
        else
            my_mlx_pixel_put(&(data->img2), col, i, DARKER_RED);
        i++;
    }
    while (i < HEIGHT)
    {
        my_mlx_pixel_put(&(data->img2), col, i, BLACK);
        i++;
    }
    i = 0;
}

void    raycaster(t_data *data)
{
    t_dda   ray;
    double  dirx;
    double  diry;
    double  angle;
    double  step;
    int     i;

    i = 0;
    step = FOV / (WIDTH / 2);
    angle = -M_PI / 6;
    while (angle < M_PI / 6)
    {
        dirx = data->player->dir.x * cos(angle) - data->player->dir.y * sin(angle);
        diry = data->player->dir.x * sin(angle) + data->player->dir.y * cos(angle);
        init_ray(&ray, data, dirx, diry);
        dda(data, &ray);
        draw_col(data, &ray, i);
        i++;
        angle += step;
    }
}