/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:24:45 by haroldsorel       #+#    #+#             */
/*   Updated: 2023/10/16 13:37:09 by hsorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*temp;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		temp = current->next;
		ft_lstdelone(current, del);
		current = temp;
	}
	*lst = NULL;
}
/*
void    fun(void *ptr)
{
        free(ptr);
}

int main()
{

        char *ptr1 = malloc(2);
        char *ptr2 = malloc(2);
        char *ptr3 = malloc(2);
        char *ptr4 = malloc(2);
        (ptr1)[0] = 'a';
        (ptr2)[0] = 'b';
        (ptr3)[0] = 'c';
        (ptr4)[0] = 'd';
        (ptr1)[1] = '\0';
        (ptr2)[1] = '\0';
        (ptr3)[1] = '\0';
        (ptr4)[1] = '\0';
        t_list  *node1;
        t_list  *node2;
        t_list  *node3;
        t_list  *node4;
        node1 = ft_lstnew(ptr1);
        node2 = ft_lstnew(ptr2);
        node3 = ft_lstnew(ptr3);
        node4 = ft_lstnew(ptr4);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        //iteration sur la list
        ft_lstclear(&node2, &fun);
        t_list  *current = node1;
        //a seg fault is expected here!
        while (current != NULL)
        {
                printf("%s\n", (char *)(current->content));
                current = current->next;
        }
        return (0);
}
*/
