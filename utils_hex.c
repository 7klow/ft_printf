#include "ft_printf.h"
#include "libft/libft.h"

static void	str_toupper(char *s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] >= 'a' && s[index] <= 'z')
			ft_toupper(s[index]);
		index++;
	}
}

static int	hexa_len(unsigned long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*addr_hexa(void *addr)
{
	unsigned long	address;
	char			*str;
	int				len;
	int				index;

	if (!addr)
		return (ft_strdup("(nil)"));
	address = (unsigned long)addr;
	len = hexa_len(address);
	str = malloc(len + 3);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[len + 2] = '\0';
	index = len;
	while (index-- > 0)
	{
		str[index + 2] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	return (str);
}

char	*int_hexa(unsigned int nb, int is_upper)
{
	char	*str;
	int		len;
	unsigned int	tmp;
	int		index;

	if (nb == 0)
		return (ft_strdup("0"));
	tmp = nb;
	len = 0;
	while (tmp > 0)
	{
		tmp /= 16;
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	index = len - 1;
	while (nb > 0)
	{
		str[index--] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	if (is_upper)
		str_toupper(str);
	return (str);
}
