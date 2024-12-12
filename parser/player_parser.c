/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsorel <hsorel@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:08:07 by hsorel            #+#    #+#             */
/*   Updated: 2024/12/12 17:08:22 by hsorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	init_player_direction(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	if (dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	if (dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
	if (dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
}

static void	init_player_position(char **map, t_player *player)
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
				player->pos.x = j;
				player->pos.y = i;
				player->map_pos.x = j; //this is incorrect, map it to the graphic env
				player->map_pos.y = i; //also
				player->starting_dir = map[i][j];
			}
			j++;
		}
		i++;	
	}
}

void	player_parser(t_data *data)
{
	init_player_position(data->map->matrix, data->player);
	init_player_direction(data->player, data->player->starting_dir);
}