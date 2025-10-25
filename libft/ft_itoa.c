/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:21:12 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/18 11:38:58 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(long n)
{
	if (n < 0)
		return (1);
	return (0);
}

static long	count_itoa(long nb)
{
	long	count;

	count = 0;
	if (nb < 0)
	{
		count += 1;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	if (nb >= 0 && nb <= 9)
		count += 1;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*string;
	long	count;
	long	nb;

	nb = (long)n;
	count = (count_itoa(nb));
	string = malloc(sizeof(char) * (count + 1));
	if (!string)
		return (NULL);
	string[count] = '\0';
	if (nb == 0)
		string[--count] = '0';
	if (is_negative(nb))
	{
		string[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		string[--count] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (string);
}

/* int	main(void)
{
	printf("\n%s", ft_itoa(10));
	printf("\n%s", ft_itoa(INT_MIN));
	return (1);
}
 */
