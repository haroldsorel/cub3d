/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:29:08 by haroldsorel       #+#    #+#             */
/*   Updated: 2024/12/10 18:29:09 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void    *free_array_of_pointers(void **array)
{
    int i;

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
