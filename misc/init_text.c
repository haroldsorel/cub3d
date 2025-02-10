/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:39:23 by ade-beco          #+#    #+#             */
/*   Updated: 2025/02/10 13:40:48 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_no_text(t_data *data, t_map *map)
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
	return (0);
}

int	init_so_text(t_data *data, t_map *map)
{
	map->so_text.img.img_ptr = mlx_png_file_to_image(data->mlx, \
		map->so_text.path, &(map->so_text.width), &(map->so_text.height));
	if (map->so_text.img.img_ptr == NULL)
		return (-1);
	map->so_text.img.pixel_ptr = mlx_get_data_addr(map->so_text.img.img_ptr, \
		&(map->so_text.img.bpp), &(map->so_text.img.line_len), \
		&(map->so_text.img.endian));
	if (init_pixel_array(&(map->so_text)) == -1)
		return (-1);
	return (0);
}

int	init_we_text(t_data *data, t_map *map)
{
	map->we_text.img.img_ptr = mlx_png_file_to_image(data->mlx, \
		map->we_text.path, &(map->we_text.width), &(map->we_text.height));
	if (map->we_text.img.img_ptr == NULL)
		return (-1);
	map->we_text.img.pixel_ptr = mlx_get_data_addr(map->we_text.img.img_ptr, \
		&(map->we_text.img.bpp), &(map->we_text.img.line_len), \
		&(map->we_text.img.endian));
	if (init_pixel_array(&(map->we_text)) == -1)
		return (-1);
	return (0);
}

int	init_ea_text(t_data *data, t_map *map)
{
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
