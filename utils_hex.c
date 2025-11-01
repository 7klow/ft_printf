/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:48:56 by ncontrem          #+#    #+#             */
/*   Updated: 2025/11/01 12:27:53 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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
	int				index;

	if (!addr)
		return (ft_strdup("(nil)"));
	address = (unsigned long)addr;
	len = hexa_len(address);
	str = malloc(len + 3);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[len + 2] = '\0';
	index = len;
	while (index-- > 0)
	{
		str[index + 2] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	return (str);
}

char	*hexa_lower(unsigned int nb)
{
	char			*str;
	int				len;
	int				index;

	if (nb == 0)
		return (ft_strdup("0"));
	len = hexa_len(nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	index = len - 1;
	while (nb > 0)
	{
		str[index--] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	return (str);
}

char	*hexa_upper(unsigned int nb)
{
	char			*str;
	int				len;
	int				index;

	if (nb == 0)
		return (ft_strdup("0"));
	len = hexa_len(nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	index = len - 1;
	while (nb > 0)
	{
		str[index--] = "0123456789ABCDEF"[nb % 16];
		nb /= 16;
	}
	return (str);
}
