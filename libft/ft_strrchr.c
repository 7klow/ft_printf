/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:42:35 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:52:34 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	while (index > 0)
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index--;
	}
	if (s[0] == (char)c)
		return ((char *)&s[0]);
	return (NULL);
}

/* int	main(void)
{
	printf("\n%s", ft_strrchr("Ceci est un test.", 'u'));
	printf("\n%s", ft_strrchr("Ceci est un test.", 'e'));
	return (1);
} */
