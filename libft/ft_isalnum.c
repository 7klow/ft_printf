/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:31:57 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:58:13 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d", ft_isalnum('\n'));
	printf("%d", ft_isalnum('O'));
	printf("%d", ft_isalnum('z'));
	printf("%d", ft_isalnum('4'));
	printf("%d", ft_isalnum(' '));
	return (1);
} */