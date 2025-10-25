/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:21:32 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/18 10:40:37 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index++;
	}
	if ((char)c == '\0')
		return ((char *)&s[index]);
	return (NULL);
}

/* int	main(void)
{
	printf("\n%s", ft_strchr("Ceci est un test.", 'e'));
	printf("\n%s", ft_strchr("Ceci est un test.", 't'));
	return (1);
} */