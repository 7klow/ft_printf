/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:30:56 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:53:07 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	src_len = ft_strlen(src);
	if (dst_len == size)
		return (size + src_len);
	i = 0;
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/* int	main(void)
{
	char	*dest1 = malloc(10);
	char	*dest2 = malloc(10);
	char	*src = "salut";
	size_t	count;

	count = ft_strlcat(dest1, src, 5);
	printf("\nft_strlcat: %zu\n%s", count, dest1);
	count = strlcat(dest2, src, 5);
	printf("\nsrtlcat: %zu\n%s", count, dest2);
	free(dest1);
	free(dest2);
	return (1);
	// -lbsd
} */
