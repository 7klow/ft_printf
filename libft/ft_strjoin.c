/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:30:09 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/17 09:53:16 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		j;
	char	*final_string;

	index = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	final_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!final_string)
		return (NULL);
	while (s1[index])
	{
		final_string[index] = s1[index];
		index++;
	}
	while (s2[j])
	{
		final_string[j + index] = s2[j];
		j++;
	}
	final_string[j + index] = '\0';
	return (final_string);
}

/* int	main(void)
{
	char	*str1 = "Ceci est un test !";
	char	*str2 = " Ca marche bien.";
	char	*str_final;

	str_final = ft_strjoin(str1, str2);
	printf("%s", str_final);
	free(str_final);
	return (1);
} */
