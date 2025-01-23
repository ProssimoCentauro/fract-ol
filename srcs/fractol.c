#include "draw_functions.c"
#include "fractol.h"
#include "handlers.c"
#include "init_functions.c"
#include "input_checker_utils.c"
#include "utils.c"
#include "prints.c"

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

int	mouse_handler(int key, int x, int y, t_app *app)
{
	t_fractal	*f;
	double		mouse_x_rel;
	double		mouse_y_rel;

	f = &app->f;
	change_values(app, x, y, 3);
	mouse_x_rel = (x / (double)app->width) * (3.0 / f->zoom);
	mouse_y_rel = (y / (double)app->height) * (3.0 / f->zoom);
	if (key == 5)
	{
		f->zoom /= 1.2;
		f->right -= mouse_x_rel * (1 - 1 / 1.2);
		f->up -= mouse_y_rel * (1 - 1 / 1.2);
	}
	else if (key == 4)
	{
		f->zoom *= 1.2;
		f->right += mouse_x_rel * (1 - 1 / 1.2);
		f->up += mouse_y_rel * (1 - 1 / 1.2);
	}
	fractal_select(app);
	return (0);
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
