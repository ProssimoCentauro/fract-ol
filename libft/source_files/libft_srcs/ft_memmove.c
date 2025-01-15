/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:42:25 by rtodaro           #+#    #+#             */
/*   Updated: 2024/12/11 16:42:26 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cast;
	unsigned char	*src_cast;

	dest_cast = (unsigned char *)dest;
	src_cast = (unsigned char *)src;
	if (!dest_cast && !src_cast)
		return (NULL);
	if (dest > src)
	{
		dest_cast += n - 1;
		src_cast += n -1;
		while (n--)
			*dest_cast-- = *src_cast--;
	}
	else
	{
		while (n--)
			*dest_cast++ = *src_cast++;
	}
	return (dest);
}
