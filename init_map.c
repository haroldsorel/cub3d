/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:29:15 by haroldsorel       #+#    #+#             */
/*   Updated: 2024/12/10 18:29:16 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static char **add_line_to_map(char **map, char *line)
{
    char    **new;
    int     i;

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
    new[i] = line;
    i++;
    new[i]= NULL;
    free(map);
    return (new);
}

char    **get_map_2(char **char_map)
{
    int     len;
    int     i;
    int     j;
    char    *new_word;
    
    len = row_len(char_map);
    i = 0;
    j = 0;
    while (char_map[i] != NULL)
    {
        j = 0;
        new_word = malloc((len + 1) * sizeof(char));
        if (new_word == NULL)
            return (free_array_of_pointers((void **)char_map), NULL);
        while (char_map[i][j] != '\0')
        {
            if (char_map[i][j] == '\n')
                break ;
            new_word[j] = char_map[i][j]; //make a custom function that does this
            j++;
        }
        while (j < len)
        {
            new_word[j] = ' ';
            j++; 
        }
        new_word[j] = '\0';
        free(char_map[i]);
        char_map[i] = new_word;
        i++;
    }
    return (char_map);
}

char    **get_map(int fd, char **char_map)
{
    char *line;

    line = get_next_line(fd);
    while (line != NULL)
    {
        char_map = add_line_to_map(char_map, line);
        if (char_map == NULL)
        {
            free_array_of_pointers((void **)char_map);
            return (NULL);
        }
        line = get_next_line(fd);
    }
    return (get_map_2(char_map));
}



int init_map(t_map *map, int fd)
{
    char     **char_map;

    char_map = NULL;
    char_map = get_map(fd, char_map);
    if (map == NULL)
        return (-1);
    //if (is_valid_map(char_map) == 0)
    //{
    //    ft_putendl_fd("Invalid Map\n", 1);
    //    free_array_of_pointers(char_map);
    //    return (1);
    //}
    map->map = char_map;
    return (0);
}
