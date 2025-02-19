/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:31:04 by hsorel            #+#    #+#             */
/*   Updated: 2025/02/10 13:52:45 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	repetition(t_map *map, char *orientation)
{
	if (ft_strcmp(orientation, "NO") == 0 && map->no_text.path != NULL)
		return (ft_putstr_fd("Error\nDuplicate NO Texture\n", 2), 1);
	else if (ft_strcmp(orientation, "SO") == 0 && map->so_text.path != NULL)
		return (ft_putstr_fd("Error\nDuplicate SO Texture\n", 2), 1);
	else if (ft_strcmp(orientation, "WE") == 0 && map->we_text.path != NULL)
		return (ft_putstr_fd("Error\nDuplicate WE Texture\n", 2), 1);
	else if (ft_strcmp(orientation, "EA") == 0 && map->ea_text.path != NULL)
		return (ft_putstr_fd("Error\nDuplicate EA Texture\n", 2), 1);
	return (0);
}

static void	set_text(t_map *map, char *path, char *orientation)
{
	if (ft_strcmp(orientation, "NO") == 0)
	{
		map->no_text.path = path;
		map->no_text.type = 'N';
	}
	else if (ft_strcmp(orientation, "SO") == 0)
	{
		map->so_text.path = path;
		map->so_text.type = 'S';
	}
	else if (ft_strcmp(orientation, "WE") == 0)
	{
		map->we_text.path = path;
		map->we_text.type = 'W';
	}
	else if (ft_strcmp(orientation, "EA") == 0)
	{
		map->ea_text.path = path;
		map->ea_text.type = 'E';
	}
	else
		free(path);
}

int	texture_parser(t_map *map, char *orientation, char *path)
{
	char	*new_path;

	if (repetition(map, orientation) == 1)
		return (-1);
	if (access(path, F_OK) == -1)
	{
		ft_putstr_fd("Error\nFile Not Found: ", 2);
		ft_putendl_fd(path, 2);
		return (-1);
	}
	new_path = ft_strdup(path);
	if (new_path == NULL)
		return (-1);
	set_text(map, new_path, orientation);
	map->info++;
	return (0);
}
