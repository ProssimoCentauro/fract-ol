/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:30:09 by rtodaro           #+#    #+#             */
/*   Updated: 2025/01/24 14:54:59 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	complex_calculator(t_app *app, int m, int j, int b)
{
	t_fractal	*f;
	double		base_x;
	double		base_y;

	f = &app->f;
	base_y = -1.5 + f->up;
	base_x = -2.0 + f->right;
	if (m == 1 || b == 1)
	{
		f->cr = base_x + ((double)app->i / app->width) * (3.0 / f->zoom);
		f->ci = base_y + ((double)app->j / app->height) * (3.0 / f->zoom);
	}
	if (j == 1)
	{
		f->zr = base_x + ((double)app->i / app->width) * (3.0 / f->zoom);
		f->zi = base_y + ((double)app->j / app->height) * (3.0 / f->zoom);
	}
}

void	put_color(t_app *app, int iter)
{
	int			r;
	int			g;
	int			b;
	int			color;
	t_fractal	*f;

	if (iter == MAX_ITERATIONS)
	{
		win_pixel_put(app, app->i, app->j, 0x00000000);
		return ;
	}
	f = &app->f;
	r = ((f->base_color >> 16) & 0xFF) * sqrt(((double)iter / MAX_ITERATIONS));
	g = ((f->base_color >> 8) & 0xFF) * sqrt(((double)iter / MAX_ITERATIONS));
	b = (f->base_color & 0xFF) * sqrt(((double)iter / MAX_ITERATIONS));
	color = (r << 16) | (g << 8) | b;
	win_pixel_put(app, app->i, app->j, color);
}

void	draw_ships(t_app *app)
{
	t_fractal	*f;
	int			iter;
	double		temp;

	f = &app->f;
	while (++app->i < app->width)
	{
		while (++app->j < app->height)
		{
			iter = -1;
			complex_calculator(app, 0, 0, 1);
			change_values(app, 0, 0, 1);
			while ((f->zr * f->zr) + (f->zi * f->zi) <= 4
				&& ++iter < MAX_ITERATIONS)
			{
				temp = f->zr * f->zr - f->zi * f->zi + f->cr;
				f->zi = fabs(2 * f->zr * f->zi + f->ci);
				f->zr = fabs(temp);
			}
			put_color(app, iter);
		}
		app->j = -1;
	}
	app->i = -1;
	mlx_put_image_to_window(app->mlx, app->window, app->image, 0, 0);
}

void	draw_mandelbrot(t_app *app)
{
	t_fractal	*f;
	int			iter;
	double		temp;

	f = &app->f;
	while (++app->i < app->width)
	{
		while (++app->j < app->height)
		{
			iter = -1;
			complex_calculator(app, 1, 0, 0);
			change_values(app, 0, 0, 1);
			while ((f->zr * f->zr) + (f->zi * f->zi) <= 4
				&& ++iter < MAX_ITERATIONS)
			{
				temp = f->zr * f->zr - f->zi * f->zi + f->cr;
				f->zi = 2 * f->zr * f->zi + f->ci;
				f->zr = temp;
			}
			put_color(app, iter);
		}
		app->j = -1;
	}
	app->i = -1;
	mlx_put_image_to_window(app->mlx, app->window, app->image, 0, 0);
}

void	draw_julia(t_app *app)
{
	t_fractal	*f;
	int			iter;
	double		temp;

	f = &app->f;
	while (++app->i < app->width)
	{
		while (++app->j < app->height)
		{
			iter = -1;
			complex_calculator(app, 0, 1, 0);
			while ((f->zr * f->zr) + (f->zi * f->zi) <= 4
				&& ++iter < MAX_ITERATIONS)
			{
				temp = f->zi;
				f->zi = 2 * f->zr * f->zi + f->ci;
				f->zr = f->zr * f->zr - temp * temp + f->cr;
			}
			put_color(app, iter);
		}
		app->j = -1;
	}
	app->i = -1;
	mlx_put_image_to_window(app->mlx, app->window, app->image, 0, 0);
}
