/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:46:53 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/02/07 14:16:32 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, handle_keys, data);
	mlx_hook(data->mlx_win, 3, 0, handle_rkeys, data);
	mlx_hook(data->mlx_win, 17, 0, handle_destroy, data);
	mlx_loop_hook(data->mlx, game_loop, data);
}

int	init_pixel_array(t_text *text)
{
	int	*array;
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	array = malloc(text->height * text->width * sizeof(int));
	if (array == NULL)
		return (-1);
	while (i < text->width)
	{
		j = 0;
		while (j < text->height)
		{
			array[k] = mlx_get_color(&(text->img), i, j);
			k++;
			j++;
		}
		i++;
	}
	text->pixel_array = array;
	return (0);
}

int	init_textures(t_data *data, t_map *map)
{
	map->no_text.img.img_ptr = mlx_png_file_to_image(data->mlx, \
	map->no_text.path, &(map->no_text.width), &(map->no_text.height));
	if (map->no_text.img.img_ptr == NULL)
		return (-1);
	map->no_text.img.pixel_ptr = mlx_get_data_addr(map->no_text.img.img_ptr, \
		&(map->no_text.img.bpp), &(map->no_text.img.line_len), \
		(map->no_text.img.endian));
	if (init_pixel_array(&(map->no_text)) == -1)
		return (-1);
	map->so_text.img.img_ptr = mlx_png_file_to_image(data->mlx, \
	map->so_text.path, &(map->so_text.width), &(map->so_text.height));
	if (map->so_text.img.img_ptr == NULL)
		return (-1);
	map->so_text.img.pixel_ptr = mlx_get_data_addr(map->so_text.img.img_ptr, \
		&(map->so_text.img.bpp), &(map->so_text.img.line_len), \
		&(map->so_text.img.endian));
	if (init_pixel_array(&(map->so_text)) == -1)
		return (-1);
	map->we_text.img.img_ptr = mlx_png_file_to_image(data->mlx, \
		map->we_text.path, &(map->we_text.width), &(map->we_text.height));
	if (map->we_text.img.img_ptr == NULL)
		return (-1);
	map->we_text.img.pixel_ptr = mlx_get_data_addr(map->we_text.img.img_ptr, \
		&(map->we_text.img.bpp), &(map->we_text.img.line_len), \
		&(map->we_text.img.endian));
	if (init_pixel_array(&(map->we_text)) == -1)
		return (-1);
	map->ea_text.img.img_ptr = mlx_png_file_to_image(data->mlx, \
		map->ea_text.path, &(map->ea_text.width), &(map->ea_text.height));
	if (map->ea_text.img.img_ptr == NULL)
		return (-1);
	map->ea_text.img.pixel_ptr = mlx_get_data_addr(map->ea_text.img.img_ptr, \
		&(map->ea_text.img.bpp), &(map->ea_text.img.line_len), \
		&(map->ea_text.img.endian));
	if (init_pixel_array(&(map->ea_text)) == -1)
		return (-1);
	return (0);
}

int	minilibx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	if (data->mlx_win == NULL)
		return (-1);
	data->img2.img_ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img2.img_ptr == NULL)
		return (-1);
	data->img2.pixel_ptr = mlx_get_data_addr(data->img2.img_ptr,
			&(data->img2.bpp), &(data->img2.line_len), &(data->img2.endian));
	if (init_textures(data, data->map) == -1)
		return (-1);
	init_hooks(data);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img_ptr, 0, 0);
	return (0);
}

void	init_structures(t_data *data, t_map *map, t_player *player)
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
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->no_text.path = NULL;
	map->so_text.path = NULL;
	map->we_text.path = NULL;
	map->ea_text.path = NULL;
	map->matrix = NULL;
	map->info = 0;
	data->height = HEIGHT;
	data->width = WIDTH;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->player = player;
	data->map = map;
	data->map->grid_size = 0;
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
	if (minilibx_init(&data) == -1)
		return (1);
	mlx_loop(data.mlx);
	free_data(&data);
	return (0);
}
