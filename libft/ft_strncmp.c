/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:51:34 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/21 11:31:03 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	while ((s1[index] && (s1[index] == s2[index])) && (index < n - 1))
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

/* int	main(void)
{
	printf("%d", ft_strncmp("Salut", "salut", 0));
	printf("%d", ft_strncmp("heLlo", "heLLo", 3));
	printf("%d", ft_strncmp("Bnjrs", "Bnjrs", 5));
	return (1);
} */