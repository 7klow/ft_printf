/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:15:52 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:57:42 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			index;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if ((str1[index] - str2[index]) != 0)
			return (str1[index] - str2[index]);
		index++;
	}
	return (0);
}

/* int main() {
    char s1[10] = "sssssE";
    char s2[10] = "sssssD";
    printf("%d", ft_memcmp(s1, s2, 6));
    return (1);
} */
