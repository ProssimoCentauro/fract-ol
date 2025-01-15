/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:47:05 by rtodaro           #+#    #+#             */
/*   Updated: 2024/12/11 16:47:06 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	ft_tolower(unsigned char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
