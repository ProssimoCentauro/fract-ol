/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:52:09 by rtodaro           #+#    #+#             */
/*   Updated: 2024/12/11 16:52:10 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	count;
	size_t	inword;

	i = 0;
	count = 0;
	inword = 0;
	while (str[i])
	{
		while (str[i] != c && str[i] != '\0')
		{
			inword = 1;
			i++;
		}
		if (inword == 1)
			count++;
		while (str[i] == c && str[i] != '\0')
		{
			inword = 0;
			i++;
		}
	}
	return (count);
}

static size_t	word_len(char const *s, size_t index, char c)
{
	size_t	count;

	count = 0;
	while (s[index] != c && s[index])
	{
		count++;
		index++;
	}
	return (count);
}

static void	string_copy(char *dst, char const *src, size_t i, char c)
{
	size_t	j;

	j = 0;
	while (src[i] != c && src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
}

size_t	go_to_next_word(char const *s, char c, size_t i)
{
	while (s[i] != c && s[i])
		i++;
	while (s[i] == c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	matrix = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		matrix[j] = (char *)malloc(word_len(s, i, c) + 1);
		if (!matrix[j])
			return (NULL);
		string_copy(matrix[j++], s, i, c);
		i = go_to_next_word(s, c, i);
	}
	matrix[j] = 0;
	return (matrix);
}
