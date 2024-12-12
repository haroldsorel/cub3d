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

void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, handle_keys, data);
	mlx_hook(data->mlx_win, 3, 0, handle_rkeys, data);
	//mlx_hook(data->mlx_win, 4, 0, mouse_down_handle, data);
	mlx_hook(data->mlx_win, 17, 0, handle_destroy, data);
	mlx_loop_hook(data->mlx, update_and_render, data);
}

int	minilibx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	if (data->mlx_win == NULL)
		return (-1);
	data->img.img_ptr = mlx_new_image(data->mlx, WIDTH/2, HEIGHT);
	if (data->img.img_ptr == NULL)
		return (-1);
	data->img.pixel_ptr = mlx_get_data_addr(data->img.img_ptr,
			&(data->img.bpp), &(data->img.line_len), &(data->img.endian)); //bbp=32 linelen=7680 and endian=0
	init_hooks(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img_ptr, 0, 0);
	return (0);
}

void	init_structures(t_data *data, t_map *map, t_player *player) 
{
	player->pos.x = 0;
	player->pos.y = 0;
	player->map_pos.x = 0;
	player->map_pos.y = 0;
	player->starting_dir = 'N';
	player->dir.x = 0;
	player->dir.y = -1;
	player->moving_forward = 0;
	player->moving_back = 0;
	player->moving_left = 0;
	player->moving_right = 0;
	player->rotating_left = 0;
	player->rotating_right = 0;
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
		return (1);
	print_data_info(&data);
	if (minilibx_init(&data) == -1)
		return (1);
	mlx_loop(data.mlx);
	free_data(&data);
	return (0);
}
