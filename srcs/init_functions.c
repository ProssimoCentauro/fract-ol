/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:30:29 by rtodaro           #+#    #+#             */
/*   Updated: 2025/01/24 14:30:30 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *f, int f_set, double cr, double ci)
{
	f->set = f_set;
	f->center_x = 0.0;
	f->center_y = 0.0;
	f->zr = 0;
	f->zi = 0;
	f->cr = cr;
	f->ci = ci;
	f->base_color = 0x00FFFF00;
	f->up = 0;
	if (f->set == 1)
		f->right = 0.6;
	else
	{
		f->right = 0;
	}
	f->zoom = 1;
	f->zoom_flag = 0;
}

void	app_init(t_app *app, int f_set, double cr, double ci)
{
	app->width = 500;
	app->height = 500;
	app->x_win_center = app->width / 2;
	app->y_win_center = app->height / 2;
	app->i = -1;
	app->j = -1;
	app->mlx = mlx_init();
	app->window = mlx_new_window(app->mlx, app->width, app->height,
			"FRACT-OL!");
	app->image = mlx_new_image(app->mlx, app->width, app->height);
	app->img_addr = mlx_get_data_addr(app->image, &app->bits_per_pixel,
			&app->size_line, &app->endian);
	fractal_init(&app->f, f_set, cr, ci);
}
