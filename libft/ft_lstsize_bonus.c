/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:02:34 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/21 14:06:57 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	index;

	index = 0;
	while (lst)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}

/* int main(void)
{
    t_list	*lst = NULL;
    t_list	*n1;
    t_list	*n2;
    t_list	*n3;

	n1 = ft_lstnew("test1");
	n2 = ft_lstnew("test2");
	n3 = ft_lstnew("test3");
	n1->next = n2;
    n2->next = n3;
    lst = n1;
    printf("%d elements\n", ft_lstsize(lst));
    return (1);
} */