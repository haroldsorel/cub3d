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

int	update_and_render(t_data *data)
{
	my_mlx_pixel_put(&(data->img), data->player->pos.x, data->player->pos.y, BLACK);
	if (data->player->moving_forward == 1)
		ws_move(data->player, SPEED);
	if (data->player->moving_back == 1)
		ws_move(data->player, -SPEED);
	if (data->player->moving_left == 1)
		ad_move(data->player, SPEED, 'a');
	if (data->player->moving_right == 1)
		ad_move(data->player, SPEED, 'd');
	if (data->player->rotating_left)
		rotate(data->player, -RSPEED);
	if (data->player->rotating_right)
		rotate(data->player, RSPEED);
	mlx_clear_window(data->mlx, data->mlx_win);
	my_mlx_pixel_put(&(data->img), data->player->pos.x, data->player->pos.y, RED);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img_ptr, 0, 0);
	return (0);
}
