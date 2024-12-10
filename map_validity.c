/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:07:04 by haroldsorel       #+#    #+#             */
/*   Updated: 2024/12/10 22:07:06 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int row_len(char **char_map)
{
    int i;
    int len;
    int longest;

    longest = 0;
    i = 0;
    while (char_map[i] != NULL)
    {
        len = ft_strlen(char_map[i]);
        if (ft_strchr(char_map[i], '\n'))
            len--;
        if (len > longest)
            longest = len;
        i++;
    }
    return (longest);
}
/*
int valid_line(char *line)
{

}
*/

/*
int map_closed(char **map)
{
    char    *line;
    char    closed;
    int     i;
    int     j;

    i = 0;
    j = 0;
    closed = 1;
    line = malloc(sizeof(char) * get_cols)
    while (map[i] != NULL)
    {
        if (valid_line(line) == 0)
            closed = 1;
    }
    line = malloc(sizeof(char) * get_cols)
    free(line);
    return (1);
}
*/
int is_valid_map(char **map)
{
    int i;
    int j;
    int player_present;

    i = 0;
    j = 0;
    player_present = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (ft_strchr(" 10NWES\n", map[i][j]) == NULL)
                return (0);
            if (ft_strchr(" NWES\n", map[i][j]) != NULL)
                player_present++;
            j++;
        }
        i++;
    }
    if (/*map_closed(map) == 0|| */player_present != 1)
        return (0);
    return (1);
}

