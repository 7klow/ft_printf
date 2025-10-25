/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:14:45 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/18 12:44:21 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	index;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substring = malloc(1);
		if (!substring)
			return (NULL);
		substring[0] = '\0';
		return (substring);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substring = malloc(len + 1);
	if (!substring)
		return (NULL);
	index = 0;
	while (index < len && s[start])
		substring[index++] = s[start++];
	substring[index] = '\0';
	return (substring);
}

/* int	main(void)
{
	int		len = 26;
	char	*str;
	char	*substring;

	str = malloc(len + 1);
	str = "abcdefghijklmnopqrstuvwxyz";
	substring = ft_substr(str, 0, 10);
	printf("%s", substring);
	free(substring);
	return (1);
} */
