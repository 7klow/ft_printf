/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 08:58:29 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/20 09:20:27 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp_lst;

	tmp_lst = lst;
	while (tmp_lst)
	{
		f(tmp_lst->content);
		tmp_lst = tmp_lst->next;
	}
}
