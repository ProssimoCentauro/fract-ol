/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:30:53 by rtodaro           #+#    #+#             */
/*   Updated: 2025/01/24 14:30:54 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_values(t_app *app, double n1, double n2, int flag)
{
	t_fractal	*f;

	f = &app->f;
	if (flag == 1)
	{
		f->zr = n1;
		f->zi = n2;
	}
	else if (flag == 2)
	{
		f->cr = n1;
		f->ci = n2;
	}
	else if (flag == 3)
	{
		app->mouse_x = n1;
		app->mouse_y = n2;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (1);
	else
		return (0);
}
