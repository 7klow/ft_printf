/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:31:51 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:58:03 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d\n", ft_isdigit('3'));
	printf("%d\n", ft_isdigit('a'));
	printf("%d\n", ft_isdigit('Z'));
	printf("%d\n", ft_isdigit(9));
	return (1);
} */