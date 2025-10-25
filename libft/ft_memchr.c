/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:01:55 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:57:47 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			index;

	str = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (str[index] == (unsigned char)c)
			return (&str[index]);
		index++;
	}
	return (NULL);
}

/* int main(void) 
{
   const char str[] = "Une phrase. Et une autre.";
   const char ch = '.';
   char *ret;
   ret = ft_memchr(str, ch, strlen(str));
   printf("%s\n", ret);
   return(0);
} */
