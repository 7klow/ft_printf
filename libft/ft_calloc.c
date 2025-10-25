/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:44:16 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/18 09:25:10 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*str;
	size_t			index;

	index = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	str = malloc(size * nmemb);
	if (!str)
		return (NULL);
	while (index < (size * nmemb))
	{
		str[index] = 0;
		index++;
	}
	return (str);
}

/* int	main(void)
{
	char	*str;
	str = ft_calloc(sizeof(char), 10);
	str = "Salut !";
	printf("%s", str);
	return (1);
} */
