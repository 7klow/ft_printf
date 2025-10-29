/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:31:03 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:52:56 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

/* int	main(void)
{
	printf("\n%zu", ft_strlen("Compte moi tout ca normalement ca fait 40"));
	printf("\n%zu", ft_strlen(""));
	printf("\n%zu", ft_strlen("98932402347"));
	return (1);
} */