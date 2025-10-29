/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:14:36 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:53:01 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	j;

	index = 0;
	j = 0;
	while (src[index])
		index++;
	if (size == 0)
		return (index);
	while (src[j] && (j < size - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (index);
}

/* int	main(void)
{
	char	*dest1 = malloc(2);
	char	*dest2 = malloc(2);
	char	*src = "salut";
	size_t	count;

	count = ft_strlcpy(dest1, src, 5);
	printf("\nft_strlcpy: %zu\n%s", count, dest1);
	count = strlcpy(dest2, src, 5);
	printf("\nsrtlcpy: %zu\n%s", count, dest2);
	free(dest1);
	free(dest2);
	return (1);
	// -lbsd
} */
