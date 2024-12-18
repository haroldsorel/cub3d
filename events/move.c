/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsorel <hsorel@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:59:56 by hsorel            #+#    #+#             */
/*   Updated: 2024/12/12 21:00:10 by hsorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	move_forward(t_data *data, int distance)
{
	double  new_pos_x;
    double  new_pos_y;

	new_pos_x = data->player->pos.x + data->player->dir.x * distance;
	new_pos_y = data->player->pos.y + data->player->dir.y * distance;
    data->player->pos.x = new_pos_x;
    data->player->pos.y = new_pos_y;
	printf("Player Moved Forward! New Position: (%f, %f)\n", data->player->pos.x, data->player->pos.y);
}

void	move_backward(t_data *data, int distance)
{
	double  new_pos_x;
    double  new_pos_y;

	new_pos_x = data->player->pos.x + data->player->dir.x * distance;
	new_pos_y = data->player->pos.y + data->player->dir.y * distance;
    data->player->pos.x = new_pos_x;
    data->player->pos.y = new_pos_y;
	printf("Player Moved Backward! New Position: (%f, %f)\n", data->player->pos.x, data->player->pos.y);
}

void	move_right(t_data *data, int distance)
{
	double  new_pos_x;
    double  new_pos_y;
    

	new_pos_x = data->player->pos.x - data->player->dir.y * distance;
    new_pos_y = data->player->pos.y + data->player->dir.x * distance;
    data->player->pos.x = new_pos_x;
    data->player->pos.y = new_pos_y;
	printf("Player Moved Right! New Position: (%f, %f)\n", data->player->pos.x, data->player->pos.y);
}

void	move_left(t_data *data, int distance)
{
	double  new_pos_x;
    double  new_pos_y;

	new_pos_x = data->player->pos.x + data->player->dir.y * distance;
    new_pos_y = data->player->pos.y - data->player->dir.x * distance;
    data->player->pos.x = new_pos_x;
    data->player->pos.y = new_pos_y;
	printf("Player Moved Left! New Position: (%f, %f)\n", data->player->pos.x, data->player->pos.y);
}

void    move(t_data *data, int key, int distance)
{
    update_player_pos(data, BLACK);
    mlx_draw_line(data, data->player, BLACK);
    if (key == 'w')
        move_forward(data, distance);
    if (key == 's')
        move_backward(data, distance);
    if (key == 'a')
        move_left(data, distance);
    if (key == 'd')
        move_right(data, distance);
    update_player_pos(data, RED);
    mlx_draw_line(data, data->player, GREEN);
}