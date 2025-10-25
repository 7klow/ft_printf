/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:49 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/25 12:27:37 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_pourcent(char *fstring, va_list args, char c)
{
	if (c == 'c')
		return ;
	else if (c == 's')	
		return ;
	else if (c == 'p')	
		return ;
	else if (c == 'i' || c == 'd')	
		return ;
	else if (c == 'u')	
		return ;
	else if (c == 'x')	
		return ;
	else if (c == 'X')	
		return ;
	else if (c == '%')	
		return ;
	return (NULL);
}

char	*format_string(char *str, char *fstring, va_list args, int count_pourcent)
{
	char	*tmp;
	int		index;

	tmp = str;
	index = 0;
	while ((tmp[index] != '%' || count_pourcent > 0) && tmp[index])
	{
		if (tmp[index] == '%')
			count_pourcent--;
		if (count_pourcent == 1)
			tmp = &tmp[index];
		index++;
	}
	tmp[index] = '\0';
	fstring = ft_free_strjoin(fstring, tmp);
	free(tmp);
	fstring = format_pourcent(fstring, args, str[index + 1]);
	return (fstring);
}

int	is_valid_symb(char c)
{
	return (c == 'c' || c == 's' || c == 'p' \
			|| c == 'd' || c == 'i' || c == 'u' \
			|| c == 'x' || c == 'X' || c == '%');
}

int	ft_printf(const char *str, ...)
{
	char		*fstring;
	va_list		args;
	int			index;
	int			count_pourcent;
	
	index = 0;
	count_pourcent = 0;
	va_start(args, str);
	while (str[index])
	{
		if (str[index] == '%' && is_valid_symb(str[index + 1]))
		{
			fstring = format_string(str, fstring, args, count_pourcent);
			count_pourcent++;
			index++;
		}
		index ++;
	}
	if (!fstring)
		fstring = ft_strdup(str);
	va_end(args);
	return ((int)write(1, fstring, ft_strlen(fstring)));
}
