/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:49 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/27 20:11:45 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_symb(char c)
{
	return (c == 'c' || c == 's' || c == 'p' \
			|| c == 'd' || c == 'i' || c == 'u' \
			|| c == 'x' || c == 'X' || c == '%');
}

char	*format_pourcent(char *fstring, va_list args, char c)
{
	if (c == 'c')
		return (add_char(fstring, va_arg(args, char)));
	else if (c == 's')
		return (ft_free_strjoin(fstring, va_arg(args, char *)));
	else if (c == 'p')
		return (ft_free_strjoin(fstring, get_addr_hexa(va_arg(args, void *))));
	else if (c == 'i' || c == 'd')
		return (ft_free_strjoin(fstring, ft_itoa(va_arg(args, int))));
	else if (c == 'u')
		return (ft_free_strjoin(fstring, ft_utoa(va_arg(args, unsigned int))));
	else if (c == 'x')
		return (ft_free_strjoin(fstring, get_int_hexa(va_arg(args, int), 0)));
	else if (c == 'X')
		return (ft_free_strjoin(fstring, get_int_hexa(va_arg(args, int), 1)));
	else if (c == '%')
		return (add_char(fstring, '%'));
	return (NULL);
}


char	*format_string(char *str, char *fstring, va_list args)
{
	int	index;

	index = 0;
	
	while (str[index])
	{
		if (str[index] == '%' && is_valid_symb(str[index + 1]))
		{
			fstring = format_pourcent(fstring, args, str[index + 1]);
			index++;
		}
		index++;
	}
}

int	ft_printf(const char *str, ...)
{
	char		*fstring;
	va_list		args;
	int			index;

	index = 0;
	va_start(args, str);
	fstring = format_string(str, fstring, args);
	if (!fstring)
	{
		fstring = ft_strdup(str);
		if (!fstring)
			return (NULL);
	}
	va_end(args);
	return ((int)write(1, fstring, ft_strlen(fstring)));
}
