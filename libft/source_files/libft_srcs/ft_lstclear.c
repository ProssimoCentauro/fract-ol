/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:53:01 by rtodaro           #+#    #+#             */
/*   Updated: 2024/12/11 16:53:03 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*nextelem;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		nextelem = current->next;
		del(current->content);
		free(current);
		current = nextelem;
	}
	*lst = NULL;
}
