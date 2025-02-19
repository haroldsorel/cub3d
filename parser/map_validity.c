/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:07:04 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/02/10 13:52:30 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_rows(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] != '\0' && line[i] != '1')
		return (0);
	while (line[i] != '\0')
	{
		while (line[i] != '\0' && line[i] == ' ')
			i++;
		if (line[i] != '\0' && line[i] != '1')
			return (0);
		while (line[i] != '\0' && line[i] != ' ')
		{
			if (line[i] != '1' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
				return (0);
			i++;
		}
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (1);
}

static int	col_error(char *line)
{
	if (line == NULL)
	{
		return (-1);
	}
	else
	{
		free(line);
		return (0);
	}
}

static int	valid_cols(char **map)
{
	int		i;
	int		j;
	int		len;
	char	*line;

	j = 0;
	len = 0;
	while (map[len] != NULL)
		len++;
	while (map[0][j] != '\0')
	{
		i = 0;
		line = malloc(sizeof(char) * (len + 2));
		while (line != NULL && i < len)
		{
			line[i] = map[i][j];
			i++;
			line[i] = '\0';
		}
		if (line == NULL || valid_rows(line) == 0)
			return (col_error(line));
		free(line);
		j++;
	}
	return (1);
}

static int	map_closed(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
	{
		if (valid_rows(map[i]) == 0)
			return (0);
		i++;
	}
	if (valid_cols(map) == 0)
		return (0);
	if (valid_cols(map) == -1)
		return (-1);
	return (1);
}

int	is_valid_map(char **map)
{
	int	i;
	int	j;
	int	player_present;

	i = 0;
	player_present = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr(" 10NWES", map[i][j]) == NULL)
				return (ft_putstr_fd("Error\nUnknown Character\n", 2), 0);
			if (ft_strchr("NWES", map[i][j]) != NULL)
				player_present++;
			j++;
		}
		i++;
	}
	if (map_closed(map) == 0 || player_present != 1)
		return (ft_putstr_fd("Error\nInvalid Map\n", 2), 0);
	if (map_closed(map) == -1)
		return (0);
	return (1);
}
