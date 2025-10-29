/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:03:03 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/18 10:30:50 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	while (s[index])
	{
		write(fd, &s[index], 1);
		index++;
	}
}

/* int	main(void)
{
	ft_putchar_fd("abcd efg hijklmnop q     rs t u v wx, y et z", 1);
	return (1);
} */