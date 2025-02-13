/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:29:08 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/02/13 13:52:27 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*free_array_of_pointers(void **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return (NULL);
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
	return (NULL);
}

void	*free_map(t_map *map)
{
	if (map->no_text.path)
		free(map->no_text.path);
	if (map->so_text.path)
		free(map->so_text.path);
	if (map->ea_text.path)
		free(map->ea_text.path);
	if (map->we_text.path)
		free(map->we_text.path);
	if (map->no_text.pixel_array)
		free(map->no_text.pixel_array);
	if (map->so_text.pixel_array)
		free(map->so_text.pixel_array);
	if (map->ea_text.pixel_array)
		free(map->ea_text.pixel_array);
	if (map->we_text.pixel_array)
		free(map->we_text.pixel_array);
	free_array_of_pointers((void **)map->matrix);
	return (NULL);
}

void	*free_data(t_data *data)
{
	free_map(data->map);
	close(data->fd);
	return (NULL);
}
