/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:13:29 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/27 20:11:43 by ncontrem         ###   ########.fr       */
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

char	*get_addr_hexa(void *addr)
{
	unsigned long	address;
	char			*string;
	long			count;

	address = (unsigned long)addr;
	count = ft_nbrlen(address);
	string = malloc(count + 1);
	if (!string)
		return (NULL);
	string[count] = '\0';
	if (address == 0)
		string[--count] = '0';
	while (address > 0)
	{
		string[--count] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	string[count - 2] = '0';
	string[count - 1] = 'x';
	string = &string[count - 2];
	return (string);
}

char	*get_int_hexa(int nb, int is_toupper)
{
	char	*string;
	long	nbr;
	long	count;

	nbr = nb;
	count = ft_nbrlen((long)nbr);
	string = malloc(count + 1);
	string[count] = '\0';
	if (nbr == 0)
		string[--count] = '0';
	while (nbr > 0)
	{
		string[--count] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
	}
	string = &string[count];
	if (is_toupper)
		str_toupper(string);
	return (string);
}
