/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:03:27 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/21 14:07:41 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*addlast;

	if (!lst || !new)
		return ;
	addlast = ft_lstlast(*lst);
	if (!addlast)
	{
		*lst = new;
		return ;
	}
	addlast->next = new;
}

/* int main(void)
{
    t_list *lst = NULL;
    t_list *n1;
    t_list *n2;
    t_list *n3;

	n1 = ft_lstnew("test1");
	n1 = ft_lstnew("test2");
	n1 = ft_lstnew("test3");
    ft_lstadd_back(&lst, n1);
    ft_lstadd_back(&lst, n2);
    ft_lstadd_back(&lst, n3);
    t_list *tmp = lst;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }
    return (1);
} */