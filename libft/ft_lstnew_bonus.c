/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:19:01 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/21 14:07:08 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* int main(void)
{
    t_list	*lst;
    int		value;

	value = 2983;
    lst = ft_lstnew(&value);
    while (lst)
    {
        printf("%d\n", *(int *)lst->content);
        lst = lst->next;
    }
    return (1);
} */