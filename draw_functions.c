#include "fractol.h"


void	color_select(t_app *app, int iter, int i, int j)
{
	if (iter <= 20)
	{
		return;
	}
}

void    draw_mandelbrot(t_app *app, int mouse_x, int mouse_y)
{
        int                     i;
        int                     j;
        t_fractal       *f;
        int                     iter;
        double          temp;

        i = -1;
        j = -1;
        f = &app->f;
        while (++i <= app->width)
        {
                while (++j <= app->height)
                {
                        iter = -1;
                        //min_i = -1.5 + (1.0 - -2.0) * 1000 / 1000;
                        double mouse_cr = (-2.0 + f->right) +
				(mouse_x * (1.0 - (-2.0)) / app->width) / f->zoom;
			double mouse_ci = (-1.5 + f->up) +
				(mouse_y * (1.5 - (-1.5)) / app->height) / f->zoom;
                        double offset_x = mouse_cr - new_mouse_cr;
			double offset_y = mouse_ci - new_mouse_ci;

			f->right += offset_x;
			f->up += offset_y;
			f->cr =  (-2.0 + f->right) + (i * ((1.0) - -2.0) / app->width) / f->zoom;
                        f->ci = (-1.5 + f->up) + (j * ((1.5) - -1.5) / app->height) / f->zoom;

			//f->cr /= x;
                        //f->ci /= y;
			f->zr = 0;
                        f->zi = 0;
                        iter = -1;
                        while ((f->zr * f->zr) + (f->zi * f->zi) <= 4
                                && ++iter < MAX_ITERATIONS)
                        {
                                temp = f->zr * f->zr - f->zi * f->zi + f->cr;
                                f->zi = 2 * f->zr * f->zi + f->ci;
                                f->zr = temp;
                        }
                        if (iter == MAX_ITERATIONS)
                                win_pixel_put(app, i, j, 0x00000000);
                        else
                                win_pixel_put(app, i, j, app->f.base_color + (iter * 100)); //-200));
                }
                j = -1;
        }
        mlx_put_image_to_window(app->mlx, app->window, app->image, 0, 0);
}

void    draw_julia(t_app *app)
{
        int                     i;
        int                     j;
        t_fractal       *f;
        int                     iter;
        double          temp;

        i = 0;
        j = 0;
        f = &app->f;
        while (i++ <= app->width)
        {
                while (j++ <= app->height)
                {
			iter = -1;
                        f->zr = (-2.0 + f->right) + (i * (2.0- -2.0) / app->width) / f->zoom;
                        f->zi = (-2.0 + f->up) + (j * (2.0 - -2.0) / app->width) / f->zoom;
                        f->cr = -0.8;
                        f->ci = 0.156;
                        while ((f->zr * f->zr) + (f->zi * f->zi) <= 4
                                && ++iter < MAX_ITERATIONS)
                        {
                                temp = f->zi;
                                f->zi = 2 * f->zr * f->zi + f->ci;
                                f->zr = f->zr * f->zr - temp * temp + f->cr;
                        }
                        if (iter == MAX_ITERATIONS)
                                win_pixel_put(app, i, j, 0x00000000);
                        else
                                win_pixel_put(app, i, j, app->f.base_color + (iter * 100));
                
                }
                j = -1;
        }
        mlx_put_image_to_window(app->mlx, app->window, app->image, 0, 0);
}
