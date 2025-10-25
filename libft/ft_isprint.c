/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:31:10 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:58:00 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d", ft_isprint('\n'));
	printf("%d", ft_isprint('O'));
	printf("%d", ft_isprint('z'));
	printf("%d", ft_isprint('4'));
	printf("%d", ft_isprint(' '));
	printf("%d", ft_isprint(127));
	return (1);
} */