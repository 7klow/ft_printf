/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:31:54 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:58:09 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || \
		(c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d", ft_isalpha('\n'));
	printf("%d", ft_isalpha('O'));
	printf("%d", ft_isalpha('z'));
	printf("%d", ft_isalpha('4'));
	printf("%d", ft_isalpha(' '));
	return (1);
} */