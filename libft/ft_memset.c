/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:31:06 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:57:30 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			index;

	str = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		str[index] = (unsigned char)c;
		index++;
	}
	return (s);
}

/* int main()
{
    char str[50] = "Ceci est un test pour ft_memset.";
    printf("\nBefore: %s\n", str);
    ft_memset(str, '/', 12);
    printf("After:  %s", str);
    return 0;
}
 */