#include <stdlib.h>
#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || \
		(c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

unsigned long	ft_nbrlen(long nb)
{
	unsigned long	count;

	count = 0;
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	if (nb >= 0 && nb <= 9)
		count += 1;
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	index;

	index = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[index])
	{
		str[index] = s[index];
		index ++;
	}
	str[index] = '\0';
	return (str);
}

void	str_toupper(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (ft_isalpha(str[index]))
			str[index] = ft_toupper(str[index]);
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


char	*get_addr_hexa(void *addr)
{
	unsigned long	address;
	char			*str;
	int				len;

	if (!addr)
		return (ft_strdup("0x0"));
	address = (unsigned long)addr;
	len = hexa_len(address);
	str = malloc(len + 3);
	if (!str)
		return (NULL);
	str[len + 2] = '\0';
	while (len-- > 0)
	{
		str[len + 2] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

char	*get_int_hexa(unsigned int nb, int is_toupper)
{
	char	*str;
	int		len;

	if (nb == 0)
		return (ft_strdup("0"));
	len = hexa_len(nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	if (is_toupper)
		str_toupper(str);
	return (str);
}

int	main(void)
{
	char *str = NULL;
	int	adr = 1;
	printf("%s\n", get_addr_hexa(&str));
	printf("%p\n\n", &str);
	printf("%s\n", get_addr_hexa(&adr));
	printf("%p\n", &adr);
	free(str);
	return (0);
}

/* int	main(void)
{
	int	adr = 234243641;
	printf("%s\n", get_int_hexa(adr, 0));
	printf("%x\n\n", adr);
	return (0);
} */