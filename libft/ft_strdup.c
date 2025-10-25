/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:54:21 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:53:31 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	index;

	index = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[index])
	{
		str[index] = s[index];
		index ++;
	}
	str[index] = '\0';
	return (str);
}

/* int	main(void)
{
	char	*dst;

	dst = ft_strdup("Salut !");
	printf("%s", dst);
	free(dst);
	return (1);
} */
