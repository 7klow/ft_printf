/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:49 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/24 13:45:31 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	char		*fstring;
	va_list		args;
	int			index;
	
	index = 0;
	va_start(args, str);
	while (index < ft_strlen(str))
	{
		if (str[index] == '%')
			fstring = parse_args(&str[index]);
		index ++;
	}
	va_end(args);
}