/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:44:00 by ncontrem          #+#    #+#             */
/*   Updated: 2025/11/01 12:06:57 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrlen_u(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		len;
	int		index;

	len = nbrlen_u(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	index = len - 1;
	if (n == 0)
		str[index--] = '0';
	while (n > 0)
	{
		str[index--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_putstr_count_free(char *s)
{
	int	count;
	int	index;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	index = 0;
	while (s[index])
	{
		write(1, &s[index], 1);
		count++;
		index++;
	}
	return (free(s), s = NULL, count);
}
