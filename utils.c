/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:44:00 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/27 18:39:52 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_nbrlen(long nb)
{
	long	count;

	count = 0;
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	if (nb >= 0 && nb <= 9)
		count += 1;
	return (count);
}

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*final_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	final_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!final_string)
		return (free(s1), NULL);
	while (s1[i])
	{
		final_string[i] = s1[i];
		i++;
	}
	while (s2[j])
		final_string[i++] = s2[j++];
	final_string[i] = '\0';
	return (free(s1), final_string);
}

static char	*char_err(char c)
{
	char	*new;

	new = malloc(2);
	if (!new)
		return (NULL);
	new[0] = c;
	new[1] = '\0';
	return (new);
}

char	*add_char(char *str, char c)
{
	char	*fstr;
	int		i;

	if (!str)
		return (char_err(c));
	fstr = malloc(ft_strlen(str) + 2);
	if (!fstr)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		fstr[i] = str[i];
		i++;
	}
	fstr[i] = c;
	fstr[i + 1] = '\0';
	free(str);
	return (fstr);
}


char	*ft_utoa(unsigned int n)
{
	char			*string;
	unsigned long	count;
	unsigned long	nb;

	nb = (unsigned long)n;
	count = (ft_nbrlen(nb));
	string = malloc(sizeof(char) * (count + 1));
	if (!string)
		return (NULL);
	string[count] = '\0';
	if (nb == 0)
		string[--count] = '0';
	while (nb > 0)
	{
		string[--count] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (string);
}
