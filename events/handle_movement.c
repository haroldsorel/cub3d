/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsorel <hsorel@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:43:25 by hsorel            #+#    #+#             */
/*   Updated: 2024/12/12 16:43:38 by hsorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ws_move(t_player *player, int distance)
{
	float new_pos_x;
    float new_pos_y; 

	new_pos_x = player->pos.x + player->dir.x * distance;
	new_pos_y = player->pos.y + player->dir.y * distance;
    
    player->pos.x = new_pos_x;
    player->pos.y = new_pos_y;
	printf("Player Moved WS! New Position: (%f, %f)\n", player->pos.x, player->pos.y);
}

void	ad_move(t_player *player, int distance, char key)
{
	float new_pos_x;
    float new_pos_y; 

	if (key == 'a')
	{
		new_pos_x = player->pos.x + player->dir.y * distance;
        new_pos_y = player->pos.y - player->dir.x * distance;
	}
    else
	{
		new_pos_x = player->pos.x - player->dir.y * distance;
        new_pos_y = player->pos.y + player->dir.x * distance;
	}
    player->pos.x = new_pos_x;
    player->pos.y = new_pos_y;
	printf("Player Moved AD! New Position: (%f, %f)\n", player->pos.x, player->pos.y);
}

void	handle_movement(int key, t_data *data)
{
	if (key == KEY_W)
		data->player->moving_forward = 1;
	else if (key == KEY_S)
		data->player->moving_back = 1;
	else if (key == KEY_A)
		data->player->moving_left = 1;
	else if (key == KEY_D)
		data->player->moving_right = 1;
}

void	handle_stop_movement(int key, t_data *data)
{
	if (key == KEY_W)
		data->player->moving_forward = 0;
	else if (key == KEY_S)
		data->player->moving_back = 0;
	else if (key == KEY_A)
		data->player->moving_left = 0;
	else if (key == KEY_D)
		data->player->moving_right = 0;
}