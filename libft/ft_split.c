/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:58:18 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/21 08:57:17 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		if (s[index])
		{
			count++;
			while (s[index] && s[index] != c)
				index++;
		}
	}
	return (count);
}

static char	*malloc_word(const char *s, char c, int start)
{
	int		len;
	int		j;
	char	*word;

	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[start + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void	free_all(char **tab, int n)
{
	while (n > 0)
		free(tab[--n]);
	free(tab);
}

static char	**fill_tab(char const *s, char c, char **tab)
{
	int		index;
	int		start;
	int		word_index;

	index = 0;
	word_index = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		start = index;
		while (s[index] && s[index] != c)
			index++;
		if (index > start)
		{
			tab[word_index] = malloc_word(s, c, start);
			if (!tab[word_index])
				return (free_all(tab, word_index), NULL);
			word_index++;
		}
	}
	tab[word_index] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	tab = fill_tab(s, c, tab);
	return (tab);
}

/* int main(void)
{
	int		line;
	char	*str;
	char	**tab_str;

	str = malloc(16 + 1);
	str = "Test1 Test2 Test3";
	tab_str = ft_split(str, ' ');
	line = 0;
	while (tab_str[line] != NULL)
	{
		printf("%s", tab_str[line]);
		line++;
	}
	free(str);
	while (line >= 0)
	{
		free(tab_str[line]);
		line--;
	}
	free(tab_str);
	return (1);
} */