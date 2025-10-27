/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:13:29 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/27 13:02:51 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_addr_hexa(void *addr)
{
	unsigned long	address;
	char			*string;
	char			*hexa;
	long			count;

	count = ft_nbrlen(address);
	address = (unsigned long)addr;
	hexa = ft_strdup("0123456789abcdef");
	if (!hexa)
		return (NULL);
	string = malloc(count + 3);
	if (!string)
		return (NULL);
	string[0] = '0';
	string[1] = 'x';
	string[count] = '\0';
	while (address > 0)
	{
		string[--count] = hexa[address % 16];
		address /= 16;
	}
	return (string);
}
