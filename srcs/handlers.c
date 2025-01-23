#include "fractol.h"

int	events_handler(int key, t_app *app)
{
	if (key == 65307 || key == 17)
		exit_handler(app);
	else if (key == 99)
		color_handler(app);
	else if (key == 65361 || key == 65362 || key == 65363 || key == 65364
		|| key == 65451 || key == 65453)
		move_handler(key, app);
	return (0);
}

int	exit_handler(t_app *app)
{
	mlx_destroy_image(app->mlx, app->image);
	mlx_destroy_window(app->mlx, app->window);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	move_handler(int key, t_app *app)
{
	t_fractal	*f;

	f = &app->f;
	if (key == 65361)
		f->right -= 0.2 / f->zoom;
	else if (key == 65362)
		f->up -= 0.2 / f->zoom;
	else if (key == 65363)
		f->right += 0.2 / f->zoom;
	else if (key == 65364)
		f->up += 0.2 / f->zoom;
	if (f->set == 0)
		draw_mandelbrot(app);
	if (f->set == 1)
		draw_julia(app);
	if (f->set == 2)
		draw_ships(app);
}

void	color_handler(t_app *app)
{
	static int	i = 0;
	t_fractal	*f;

	f = &app->f;
	if (i == 0)
		f->base_color = 0x00FF0000;
	else if (i == 1)
		f->base_color = 0x0000FF00;
	else if (i == 2)
		f->base_color = 0x000000FF;
	else if (i == 3)
		f->base_color = 0x00FFFF00;
	i++;
	if (i == 4)
		i = 0;
	if (f->set == 0)
		draw_mandelbrot(app);
	else if (f->set == 1)
		draw_julia(app);
	else if (f->set == 2)
		draw_ships(app);
}
