/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:49 by ncontrem          #+#    #+#             */
/*   Updated: 2025/11/01 12:27:36 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid_symb(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || \
			c == 'd' || c == 'i' || c == 'u' || \
			c == 'x' || c == 'X' || c == '%');
}

static int	ft_putchar_count(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr_count(char *s)
{
	int	count;
	int	index;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	index = 0;
	while (s[index])
	{
		write(1, &s[index], 1);
		count++;
		index++;
	}
	return (count);
}

static int	format_percent(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_count(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_count(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putstr_count_free(addr_hexa(va_arg(args, void *))));
	else if (c == 'd' || c == 'i')
		return (ft_putstr_count_free(ft_itoa(va_arg(args, int))));
	else if (c == 'u')
		return (ft_putstr_count_free(ft_utoa(va_arg(args, unsigned int))));
	else if (c == 'x')
		return (ft_putstr_count_free(hexa_lower(va_arg(args, unsigned int))));
	else if (c == 'X')
		return (ft_putstr_count_free(hexa_upper(va_arg(args, unsigned int))));
	else if (c == '%')
		return (ft_putchar_count('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;
	int		count;

	va_start(args, str);
	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] == '%' && str[index + 1] && \
			is_valid_symb(str[index + 1]))
		{
			count += format_percent(args, str[index + 1]);
			index += 2;
		}
		else
			count += ft_putchar_count(str[index++]);
	}
	va_end(args);
	return (count);
}

// #include <limits.h>

// int main(void)
// {
//     int				len1;
//     int				len2;
//     char			*s;
//     int 			d;
//     unsigned int	u;
//     unsigned int	x;
// 	char			*ptr_null;

// 	s = ft_strdup("Hello");
// 	if (!s)
// 		s = NULL;
// 	d = -42;
// 	u = 42;
// 	x = INT_MAX;
// 	ptr_null = 0;

//     len1 = ft_printf("Char: %c\n", 0);
//     len1 += ft_printf("String: %s\n", s);
//     len1 += ft_printf("Pointer: %p\n", &ptr_null);
//     len1 += ft_printf("Decimal: %d\n", d);
//     len1 += ft_printf("Integer: %i\n", d);
//     len1 += ft_printf("Unsigned: %u\n", u);
//     len1 += ft_printf("Hex lower: %x\n", x);
//     len1 += ft_printf("Hex upper: %X\n", x);
//     len1 += ft_printf("Percent: %%\n");
// 	len1 += ft_printf("NULL: %s\n", ptr_null);
//     ft_printf("ft_printf total: %d\n\n", len1);

//     len2 = printf("Char: %c\n", 0);
//     len2 += printf("String: %s\n", s);
//     len2 += printf("Pointer: %p\n", &ptr_null);
//     len2 += printf("Decimal: %d\n", d);
//     len2 += printf("Integer: %i\n", d);
//     len2 += printf("Unsigned: %u\n", u);
//     len2 += printf("Hex lower: %x\n", x);
//     len2 += printf("Hex upper: %X\n", x);
//     len2 += printf("Percent: %%\n");
// 	len2 += printf("NULL: %s\n", ptr_null);
//     printf("printf total: %d\n\n", len2);

// 	free(s);
//     return (0);
// }
// cc -Wall -Wextra -Werror ft_printf.c utils.c utils_hex.c libft/*.c -o test