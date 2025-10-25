/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:08:08 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:52:27 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trimchar(char c, const char *set)
{
	int	index;

	index = 0;
	while (set[index])
	{
		if (c == set[index])
			return (1);
		index++;
	}
	return (0);
}

static int	trimlen(const char *s1, const char *set)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	while (s1[len])
		len++;
	len--;
	while (s1[index] && is_trimchar(s1[index], set))
		index++;
	while (len >= index && is_trimchar(s1[len], set))
		len--;
	if (len < index)
		return (0);
	return (len - index + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		index;
	int		istring;
	int		trim_len;
	char	*string;

	index = 0;
	istring = 0;
	if (!s1 || !set)
		return (NULL);
	trim_len = trimlen(s1, set);
	string = malloc(trim_len + 1);
	if (!string)
		return (NULL);
	while (is_trimchar(s1[index], set))
		index++;
	while (istring < trim_len)
		string[istring++] = s1[index++];
	string[istring] = '\0';
	return (string);
}

/* int	main(void)
{
	printf("%s", ft_strtrim("ababaaaMy name is Simonbbaaabbad", "ab"));
	return (1);
} */
