/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsorel <hsorel@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:30:52 by hsorel            #+#    #+#             */
/*   Updated: 2024/12/11 16:30:54 by hsorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

char	*replace_word(char *word, int len)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (word[i] != '\0')
	{
		if (word[i] == '\n')
			break ;
		new[i] = word[i];
		i++;
	}
	while (i < len)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**add_line_to_map(char **map, char *line)
{
	char	**new;
	int		i;

	i = 0;
	if (map == NULL)
		new = ft_calloc(2, sizeof(char *));
	else
	{
		while (map[i] != NULL)
			i++;
		new = ft_calloc(i + 2, sizeof(char *));
	}
	if (new == NULL)
		return (NULL);
	i = 0;
	while (map != NULL && map[i] != NULL)
	{
		new[i] = map[i];
		i++;
	}
	new[i] = ft_strdup(line);
	i++;
	new[i] = NULL;
	free(map);
	return (new);
}

static int	reformat_map(char **map)
{
	int		len;
	int		i;
	char	*new_word;

	len = row_len(map);
	i = 0;
	while (map[i] != NULL)
	{
		new_word = replace_word(map[i], len);
		if (new_word == NULL)
			return (-1);
		free(map[i]);
		map[i] = new_word;
		i++;
	}
	return (0);
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
			}
			j++;
		}
		i++;	
	}
}

int	map_parser(t_data *data)
{
	if (reformat_map(data->map->matrix) == -1)
		return (-1);
	if (is_valid_map(data->map->matrix) == 0)
		return (-1);
	init_player_position(data->map->matrix, data->player);
	return (0);
}