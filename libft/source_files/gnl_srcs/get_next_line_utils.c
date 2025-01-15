/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:47:59 by rtodaro           #+#    #+#             */
/*   Updated: 2024/12/23 13:48:02 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

size_t	gnl_ft_strlen(char *str)
{
	size_t	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_ft_strdup(char *s)
{
	char	*dest;
	size_t	i;

	if (!s || !s[0])
	{
		return (NULL);
	}
	dest = (char *)gnl_ft_calloc(gnl_ft_strlen(s) + 2, 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	check_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

void	*gnl_ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	total;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	total = nmemb * size;
	p = (char *)malloc(total);
	if (!p)
		return (NULL);
	while (total--)
		p[total] = 0;
	return ((void *)p);
}
