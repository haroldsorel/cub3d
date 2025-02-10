/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:34:39 by ade-beco          #+#    #+#             */
/*   Updated: 2025/02/10 13:34:58 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_player_struct(t_player *player)
{
	player->pos.x = 0;
	player->pos.y = 0;
	player->mat_pos.x = 0;
	player->mat_pos.y = 0;
	player->starting_dir = 'N';
	player->dir.x = 0;
	player->dir.y = -1;
	player->moving_forward = 0;
	player->moving_back = 0;
	player->moving_left = 0;
	player->moving_right = 0;
	player->rotating_left = 0;
	player->rotating_right = 0;
	player->radius = 0;
}

void	init_map_struct(t_map *map)
{
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->no_text.path = NULL;
	map->so_text.path = NULL;
	map->we_text.path = NULL;
	map->ea_text.path = NULL;
	map->matrix = NULL;
	map->info = 0;
}

void	init_data_struct(t_data *data)
{
	data->height = HEIGHT;
	data->width = WIDTH;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->player = player;
	data->map = map;
	data->map->grid_size = 0;
}
