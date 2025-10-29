/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:26:01 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:52:41 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	tmp_index;
	size_t	index_little;

	if (!little[0])
		return ((char *)big);
	index = 0;
	while (index < len && big[index])
	{
		tmp_index = index;
		index_little = 0;
		if (big[index] == little[0])
		{
			while (little[index_little] && \
					(tmp_index < len && little[index_little] == big[tmp_index]))
			{
				index_little++;
				tmp_index++;
			}
			if (little[index_little] == '\0')
				return ((char *)&big[index]);
		}
		index++;
	}
	return (NULL);
}

/* int	main(void)
{
	printf("\n%s", ft_strnstr("Ceci est un test.", "es", 10));
	printf("\n%s", ft_strnstr("Ceci est un test.", "te", 0));
	return (1);
} */
