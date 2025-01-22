#include "fractol.h"

void	complex_calculator(t_app *app, int m, int j, int b)
{
	t_fractal	*f;

	f = &app->f;
	if (m == 1)
	{
		f->cr = (-2.0 + f->right) + (app->i * ((1.0) - -2.0) / app->width)
			/ f->zoom;
		f->ci = (-1.5 + f->up) + (app->j * ((1.5) - -1.5) / app->height)
			/ f->zoom;
	}
	if (j == 1)
	{
		f->zr = (-2.0 + f->right) + (app->i * (2.0 - -2.0) / app->width)
			/ f->zoom;
		f->zi = (-2.0 + f->up) + (app->j * (2.0 - -2.0) / app->width) / f->zoom;
	}
	if (b == 1)
	{
		f->cr = (-2.0 + f->right) + (app->i * ((1.0) - -2.0) / app->width)
			/ f->zoom;
		f->ci = (-1.5 + f->up) + (app->j * ((1.5) - -1.5) / app->height)
			/ f->zoom;
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


void	draw_ships(t_app *app, int mouse_x, int mouse_y)
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
			f->zr = 0;
			f->zi = 0;
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

void	draw_mandelbrot(t_app *app, int mouse_x, int mouse_y)
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
			f->zr = 0;
			f->zi = 0;
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

	app->i = -1;
	app->j = -1;
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
	mlx_put_image_to_window(app->mlx, app->window, app->image, 0, 0);
}
