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

char	*get_addr_hexa(void *addr)
{
	unsigned long	address;
	char			*string;
	long			count;

	address = (unsigned long)addr;
	count = ft_nbrlen(address);
	string = malloc(count + 1);
	if (!string)
		return (NULL);
	string[count] = '\0';
	if (address == 0)
		string[--count] = '0';
	while (address > 0)
	{
		string[--count] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	string[count - 2] = '0';
	string[count - 1] = 'x';
	string = &string[count - 2];
	return (string);
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

char	*get_int_hexa(int nb, int is_toupper)
{
	char	*string;
	long	nbr;
	long	count;

	nbr = nb;
	count = ft_nbrlen((long)nbr);
	string = malloc(count + 1);
	string[count] = '\0';
	if (nbr == 0)
		string[--count] = '0';
	while (nbr > 0)
	{
		string[--count] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
	}
	string = &string[count];
	if (is_toupper)
		str_toupper(string);
	return (string);
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