/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:46:53 by haroldsorel       #+#    #+#             */
/*   Updated: 2024/12/10 17:46:55 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	print_data_info(t_data *data)
{
	int	i;

	i = 0;
	printf("\n\nno_text :		%s\n", data->map->no_text);
	printf("so_text :		%s\n", data->map->so_text);
	printf("we_text :		%s\n", data->map->we_text);
	printf("ea_text :		%s\n", data->map->ea_text);
	printf("floor color : 		%d\n", data->map->floor_color);
	printf("ceiling color : 	%d\n", data->map->ceiling_color);
	printf("info :			%d\n\n", data->map->info);
	while ((data->map->matrix)[i] != NULL)
	{
		printf("%s|\n", (data->map->matrix)[i]);
		i++;
	}
	printf("Player x position : %f\n", data->player->pos.x);
	printf("Player y position : %f\n", data->player->pos.y);
}

void	init_structures(t_data *data, t_map *map, t_player *player) 
{
	/*initialize all the default variables*/
	player->pos.x = 0;
	player->pos.y = 0;
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->no_text = NULL;
	map->so_text = NULL;
	map->we_text = NULL;
	map->ea_text = NULL;
	map->matrix = NULL;
	map->info = 0;
	data->height = HEIGHT;
	data->width = WIDTH;
	data->img = NULL;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->player = player;
	data->map = map;
}



int	main(int argc, char **argv)
{
	t_data		data;
	t_map		map;
	t_player	player;
	int			fd;

	if (argc < 2)
		return (ft_putstr_fd("Error: Enter a file name\n", 2), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("Error"), 1);
	init_structures(&data, &map, &player);
	if (parser(&data, fd) == -1)
		return (1); //free necessary
	print_data_info(&data);
	free_data(&data);
	return (0);
}
