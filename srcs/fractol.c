/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:30:20 by rtodaro           #+#    #+#             */
/*   Updated: 2025/01/24 15:10:57 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	win_pixel_put(t_app *app, int x, int y, int color)
{
	char	*dst;

	dst = app->img_addr + (y * app->size_line + x * (app->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fractal_select(t_app *app)
{
	t_fractal	*f;

	f = &app->f;
	if (f->set == 0)
		draw_mandelbrot(app);
	else if (f->set == 1)
		draw_julia(app);
	else if (f->set == 2)
		draw_ships(app);
}

int	main(int ac, char **av)
{
	t_app	app;

	check_and_initialize(&app, ac, av);
	fractal_select(&app);
	mlx_key_hook(app.window, events_handler, &app);
	mlx_mouse_hook(app.window, mouse_handler, &app);
	mlx_hook(app.window, 17, 0, exit_handler, &app);
	mlx_loop(app.mlx);
	return (0);
}
