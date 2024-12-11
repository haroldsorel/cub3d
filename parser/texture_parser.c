/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsorel <hsorel@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:31:04 by hsorel            #+#    #+#             */
/*   Updated: 2024/12/11 16:31:05 by hsorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int repetition(t_map *map, char *orientation)
{
	if (ft_strcmp(orientation, "NO") == 0 && map->no_text != NULL)
		return (ft_putstr_fd("File Error: Duplicate NO Texture\n", 2), 1);
	else if (ft_strcmp(orientation, "SO") == 0 && map->so_text != NULL)
		return (ft_putstr_fd("File Error: Duplicate SO Texture\n", 2), 1);
	else if (ft_strcmp(orientation, "WE") == 0 && map->we_text != NULL)
		return (ft_putstr_fd("File Error: Duplicate WE Texture\n", 2), 1);
	else if (ft_strcmp(orientation, "EA") == 0 && map->ea_text != NULL)
		return (ft_putstr_fd("File Error: Duplicate EA Texture\n", 2), 1);
	return (0);
}

int	texture_parser(t_map *map, char *orientation, char *path)
{
	char *new_path;

	if (repetition(map, orientation) == 1)
		return (-1);
	new_path = ft_strdup(path);
	if (new_path == NULL)
		return (-1);
	if (ft_strcmp(orientation, "NO") == 0)
		map->no_text = new_path;
	else if (ft_strcmp(orientation, "SO") == 0)
		map->so_text = new_path;
	else if (ft_strcmp(orientation, "WE") == 0)
		map->we_text = new_path;
	else if (ft_strcmp(orientation, "EA") == 0)
		map->ea_text = new_path;
	else
		free(new_path);
	map->info++;
	return (0);
}