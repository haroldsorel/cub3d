/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_loops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsorel <hsorel@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:27:07 by hsorel            #+#    #+#             */
/*   Updated: 2024/12/12 19:27:15 by hsorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	movement_loop(t_data *data)
{
	if (data->player->moving_forward == 1)
		move(data, 'w', SPEED);
	if (data->player->moving_back == 1)
		move(data, 's', -SPEED);
	if (data->player->moving_left == 1)
		move(data, 'a' , SPEED);
	if (data->player->moving_right == 1)
		move(data, 'd' , SPEED);
	if (data->player->rotating_left == 1)
		rotate(data, -RSPEED);
	if (data->player->rotating_right == 1)
		rotate(data, RSPEED);
}

int	game_loop(t_data *data)
{
	render_minimap(data);
	movement_loop(data);
	update_player_pos(data, RED);
	mlx_draw_line(data, data->player, BROWN);
	raycaster(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img_ptr, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2.img_ptr, WIDTH / 2, 0);
	return (0);
}
