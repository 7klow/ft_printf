/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:58 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/28 16:26:25 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_toupper(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (ft_isalpha(str[index]))
			str[index] = ft_toupper(str[index]);
		index++;
	}
}

static int	hexa_len(unsigned long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*addr_hexa(void *addr)
{
	unsigned long	address;
	char			*str;
	int				len;

	if (!addr)
		return (ft_strdup("0x0"));
	address = (unsigned long)addr;
	len = hexa_len(address);
	str = malloc(len + 3);
	if (!str)
		return (NULL);
	str[len + 2] = '\0';
	while (len-- > 0)
	{
		str[len + 2] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

char	*int_hexa(unsigned int nb, int is_toupper)
{
	char	*str;
	int		len;

	if (nb == 0)
		return (ft_strdup("0"));
	len = hexa_len((unsigned long)nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	if (is_toupper)
		str_toupper(str);
	return (str);
}
