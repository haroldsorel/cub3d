/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:08:07 by hsorel            #+#    #+#             */
/*   Updated: 2025/02/10 13:52:39 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_direction(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir.x = 0.0001f;
		player->dir.y = -1.0001f;
	}
	if (dir == 'S')
	{
		player->dir.x = 0.0001f;
		player->dir.y = 1.0001f;
	}
	if (dir == 'E')
	{
		player->dir.x = 1.0001f;
		player->dir.y = 0.0001f;
	}
	if (dir == 'W')
	{
		player->dir.x = -1.0001f;
		player->dir.y = 0.0001f;
	}
}

static void	init_player_position(char **map, t_player *player, int offset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("NSWE", map[i][j]) != NULL)
			{
				player->mat_pos.x = j;
				player->mat_pos.y = i;
				player->pos.x = j * offset + player->radius;
				player->pos.y = i * offset + player->radius;
				player->starting_dir = map[i][j];
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	player_parser(t_data *data)
{
	data->player->radius = 0.2f * (data->map->grid_size / 2);
	init_player_position(data->map->matrix, data->player, data->map->grid_size);
	init_player_direction(data->player, data->player->starting_dir);
	data->player->speed = SPEED * data->map->grid_size;
}
