/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:34:52 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:58:05 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d", ft_isascii('\n'));
	printf("%d", ft_isascii('O'));
	printf("%d", ft_isascii('z'));
	printf("%d", ft_isascii('4'));
	printf("%d", ft_isascii(' '));
	printf("%d", ft_isascii(128));
	return (1);
} */