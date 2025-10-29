/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:41:15 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:58:23 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	index;
	int	nb;
	int	sign;

	index = 0;
	nb = 0;
	sign = 1;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || nptr[index] == ' ')
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			sign *= -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		nb = (10 * nb + (nptr[index] - '0'));
		index++;
	}
	return (nb * sign);
}

/* int	main(void)
{
	printf("\n%d", ft_atoi("    -283732"));
	printf("\n%d", ft_atoi("    +-2382"));
	printf("\n%d", ft_atoi("\t \n+9484"));
	return (1);
} */