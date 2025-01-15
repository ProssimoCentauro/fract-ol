/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:50:41 by rtodaro           #+#    #+#             */
/*   Updated: 2024/12/11 16:50:43 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1) - 1;
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[s1_len]))
		s1_len--;
	str = ft_substr(s1, i, s1_len - i + 1);
	if (!str)
		return (NULL);
	return (str);
}
