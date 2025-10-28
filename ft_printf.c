/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:49 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/28 16:26:19 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid_symb(char c)
{
	return (c == 'c' || c == 's' || c == 'p' \
			|| c == 'd' || c == 'i' || c == 'u' \
			|| c == 'x' || c == 'X' || c == '%');
}

static char	*format_percent(char *fstring, va_list args, char c)
{
	if (c == 'c')
		return (add_char(fstring, va_arg(args, int)));
	else if (c == 's')
		return (ft_fjoin(fstring, va_arg(args, char *)));
	else if (c == 'p')
		return (ft_fjoin(fstring, addr_hexa(va_arg(args, void *))));
	else if (c == 'i' || c == 'd')
		return (ft_fjoin(fstring, ft_itoa(va_arg(args, int))));
	else if (c == 'u')
		return (ft_fjoin(fstring, ft_utoa(va_arg(args, unsigned int))));
	else if (c == 'x')
		return (ft_fjoin(fstring, int_hexa(va_arg(args, unsigned int), 0)));
	else if (c == 'X')
		return (ft_fjoin(fstring, int_hexa(va_arg(args, unsigned int), 1)));
	else if (c == '%')
		return (add_char(fstring, '%'));
	return (ft_fjoin(fstring, "(null)"));
}

static char	*format_string(char *str, char *fstring, va_list args)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '%' && str[index + 1] && \
			is_valid_symb(str[index + 1]))
		{
			fstring = format_percent(fstring, args, str[index + 1]);
			index += 2;
		}
		else
		{
			fstring = add_char(fstring, str[index]);
			index++;
		}
	}
	return (fstring);
}

int	ft_printf(const char *str, ...)
{
	char		*fstring;
	va_list		args;
	int			res;

	va_start(args, str);
	fstring = ft_strdup("");
	if (!fstring)
		return (0);
	fstring = format_string((char *)str, fstring, args);
	va_end(args);
	res = write(1, fstring, ft_strlen(fstring));
	free(fstring);
	return (res);
}

/* int main(void)
{
    int				len1;
    int				len2;
    char			c;
    char			*s;
    int 			d;
    unsigned int	u;
    unsigned int	x;
	char			*ptr_null;

	c = 'A';
	s = ft_strdup("Hello");
	if (!s)
		s = NULL;
	d = -42;
	u = 42;
	x = 255;
	ptr_null = 0;

    len1 = ft_printf("Char: %c\n", 0);
    len1 += ft_printf("String: %s\n", s);
    len1 += ft_printf("Pointer: %p\n", &ptr_null);
    len1 += ft_printf("Decimal: %d\n", d);
    len1 += ft_printf("Integer: %i\n", d);
    len1 += ft_printf("Unsigned: %u\n", u);
    len1 += ft_printf("Hex lower: %x\n", x);
    len1 += ft_printf("Hex upper: %X\n", x);
    len1 += ft_printf("Percent: %%\n");
	len1 += ft_printf("NULL: %s\n", ptr_null);
    ft_printf("ft_printf total: %d\n\n", len1);

    len2 = printf("Char: %c\n", 0);
    len2 += printf("String: %s\n", s);
    len2 += printf("Pointer: %p\n", &ptr_null);
    len2 += printf("Decimal: %d\n", d);
    len2 += printf("Integer: %i\n", d);
    len2 += printf("Unsigned: %u\n", u);
    len2 += printf("Hex lower: %x\n", x);
    len2 += printf("Hex upper: %X\n", x);
    len2 += printf("Percent: %%\n");
	len2 += printf("NULL: %s\n", ptr_null);
    printf("printf total: %d\n\n", len2);

	free(s);
    return (0);
} */
// cc -Wall -Wextra -Werror ft_printf.c utils.c utils_hex.c libft/*.c -o test