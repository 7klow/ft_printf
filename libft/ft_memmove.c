/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:53:40 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/21 10:46:13 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}

/* int main(void)
{
    char data[] = "ABCDEFGHIJ";

    ft_memmove(data + 2, data, 5);
	// memmove(data + 2, data, 5);
    printf("Result: %s\n", data);
    return (0);
} */