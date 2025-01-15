/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:48:26 by rtodaro           #+#    #+#             */
/*   Updated: 2024/12/11 16:48:30 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_cast;
	unsigned char		c_cast;
	size_t				i;

	s_cast = (const unsigned char *)s;
	c_cast = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_cast[i] == c_cast)
			return ((void *)&s_cast[i]);
		i++;
	}
	return (NULL);
}
