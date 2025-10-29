/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:54:52 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/21 14:07:28 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* int	main(void)
{
	t_list	*lst;
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;
	t_list	*tmp;

	lst = NULL;
	n1 = ft_lstnew("test1");
	n2 = ft_lstnew("test2");
	n3 = ft_lstnew("test3");
	ft_lstadd_front(&lst, n3);
	ft_lstadd_front(&lst, n2);
	ft_lstadd_front(&lst, n1);
	tmp = lst;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	return (1);
} */