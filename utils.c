/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:44:00 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/24 13:05:40 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		write(1, &s[index], 1);
		index++;
	}
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= 10)
	{
		ft_putnbr((nbr / 10));
		ft_putnbr((nbr % 10));
	}
	else
		ft_putchar((nbr + '0'));
}

int	ft_atoi(const char *nptr)
{
	int	index;
	int	nb;

	index = 0;
	nb = 0;
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		nb = (10 * nb + (nptr[index] - '0'));
		index++;
	}
	return (nb);
}
