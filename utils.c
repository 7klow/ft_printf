/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:44:00 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/29 10:55:13 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

unsigned long	ft_nbrlen(long nb)
{
	unsigned long	count;

	if (nb == 0)
		return (1);
	count = 0;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_str_nsafe(char *s)
{
	if (!s)
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}

char	*ft_fjoin(char *s1, char *s2)
{
	char	*final;
	size_t	len1;
	size_t	len2;
	size_t	index;
	size_t	j;

	if (!s1 || !s2)
		return (free(s1), ft_strdup("(null)"));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	final = malloc(len1 + len2 + 1);
	if (!final)
		return (free(s1), NULL);
	index = 0;
	while (index < len1)
	{
		final[index] = s1[index];
		index++;
	}
	j = 0;
	while (j < len2)
		final[index++] = s2[j++];
	final[index] = '\0';
	return (free(s1), final);
}

char	*add_char(char *str, int c)
{
	char	*fstr;
	size_t	len;
	size_t	index;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	fstr = malloc(len + 2);
	if (!fstr)
		return (free(str), NULL);
	index = 0;
	while (index < len)
	{
		fstr[index] = str[index];
		index++;
	}
	fstr[index] = (char)c;
	fstr[index + 1] = '\0';
	free(str);
	return (fstr);
}

char	*ft_utoa(unsigned int n)
{
	char			*res;
	unsigned long	nb;
	size_t			len;

	nb = n;
	len = ft_nbrlen(nb);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb == 0)
		res[--len] = '0';
	while (nb > 0)
	{
		res[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
