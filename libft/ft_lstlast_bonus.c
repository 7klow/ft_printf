/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:58:59 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/21 14:07:16 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/* int	main(void)
{
	t_list	*lst;
	t_list	*n1;
	t_list	*n2;
	t_list	*last;

	lst = NULL;
	n1 = ft_lstnew("test1");
	n2 = ft_lstnew("test2");
	ft_lstadd_back(&lst, n1);
	ft_lstadd_back(&lst, n2);
	last = ft_lstlast(lst);
	if (last)
		printf("%s\n", (char *)last->content);
	return (1);
} */