/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:37:51 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/21 10:45:53 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					index;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	index = 0;
	if (!dest && !src)
		return (NULL);
	while (index < n)
	{
		d[index] = (unsigned char)s[index];
		index++;
	}
	return (dest);
}

/* int	main(void)
{
    char src[] = "Hello, World!";
    char dest[20];

	ft_memcpy(dest, src, 14);
	// memcpy(dest, src, 14);
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);
    return (0);
} */