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

void castRay(t_data *data, t_player *player)
{
    int mapX = (int)player->pos.x / data->map->grid_size;
    int mapY = (int)player->pos.y / data->map->grid_size;
    double deltaDistX = fabs(data->map->grid_size / player->dir.x);
    double deltaDistY = fabs(data->map->grid_size / player->dir.y);
    int stepX, stepY;
    double sideDistX, sideDistY;

    if (player->dir.x < 0) 
    {
        stepX = -1;
        sideDistX = fabs((player->pos.x - (data->map->grid_size * mapX) / player->dir.x));
    } 
    else
    {
        stepX = 1;
        sideDistX = ((data->map->grid_size * (mapX + 1)) - player->pos.x) / player->dir.x;
    }
    if (player->dir.y < 0)
    {
        stepY = -1;
        sideDistY = fabs((player->pos.y - (data->map->grid_size * mapY) / player->dir.y));
    } else
    {
        stepY = 1;
        sideDistY = ((data->map->grid_size * (mapY + 1)) - player->pos.y) / player->dir.y;
    }
    int hit = 0;
    int side;
    while (hit == 0)
    {
        if (sideDistX < sideDistY)
        {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        }
        else
        {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }
        printf("%f, %f\n", player->dir.x, player->dir.y);
        printf("current ray position: %d, %d\n", mapX , mapY);
        if ((data->map->matrix)[mapY][mapX] == '1')
            hit = 1;
    }
    double perpWallDist;
    if (side == 0) {
        perpWallDist = (mapX - player->pos.x + (1 - stepX) / 2) / player->dir.x;
    } else {
        perpWallDist = (mapY - player->pos.y + (1 - stepY) / 2) / player->dir.y;
    }
    printf("Hit wall at mapX: %d, mapY: %d, Distance: %f\n", mapX, mapY, perpWallDist);
}
