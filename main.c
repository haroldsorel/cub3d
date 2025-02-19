/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:46:53 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/02/13 13:54:00 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, handle_keys, data);
	mlx_hook(data->mlx_win, 3, 0, handle_rkeys, data);
	mlx_hook(data->mlx_win, 17, 0, handle_destroy, data);
	mlx_loop_hook(data->mlx, game_loop, data);
}

static int	minilibx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	if (data->mlx_win == NULL)
		return (-1);
	data->img2.img_ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img2.img_ptr == NULL)
		return (-1);
	data->img2.pixel_ptr = mlx_get_data_addr(data->img2.img_ptr,
			&(data->img2.bpp), &(data->img2.line_len), &(data->img2.endian));
	if (init_no_text(data, data->map) == -1 \
		|| init_so_text(data, data->map) == -1 \
		|| init_we_text(data, data->map) == -1 \
		|| init_ea_text(data, data->map) == -1)
		return (-1);
	init_hooks(data);
	return (0);
}

static int	check_file(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] != '.')
		i--;
	if (i == -1)
		return (-1);
	i++;
	if (ft_strcmp(&(str[i]), "cub") != 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_map		map;
	t_player	player;

	if (argc != 2)
		return (ft_putstr_fd("Error\nWrong Arguments\n", 2), 1);
	if (check_file(argv[1]) == -1)
		return (ft_putstr_fd("Error\nWrong File Extension\n", 2), 1);
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd == -1)
		return (perror("Error\nperror"), 1);
	init_player_struct(&player);
	init_map_struct(&map);
	init_data_struct(&data, &map, &player);
	if (parser(&data, data.fd) == -1)
		return (1);
	if (minilibx_init(&data) == -1)
		return (free_data(&data), 1);
	mlx_loop(data.mlx);
	free_data(&data);
	close(data.fd);
	return (0);
}
