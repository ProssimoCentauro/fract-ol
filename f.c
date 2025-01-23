#include "fractol.h"
#include "draw_functions.c"
#include "input_checker_utils.c"
#include "utils.c"

void	move_handler(int key, t_app *app)
{
	t_fractal	*f;

	f = &app->f;
	if (key == 65361)
		f->right -= 0.2 / f->zoom;
	else if (key == 65362)
		f->up -= 0.2 / f->zoom;
	else if (key == 65363)
		f ->right += 0.2 / f->zoom;
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

int	exit_handler(t_app *app)
{
	mlx_destroy_image(app->mlx, app->image);
	mlx_destroy_window(app->mlx, app->window);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	events_handler(int key, t_app *app)
{
	if (key == 65307 || key == 17)
		exit_handler(app);
	else if (key == 99)
		color_handler(app);
	else if (key == 65361 || key == 65362 || key == 65363 || key == 65364 || key == 65451 || key == 65453)
		move_handler(key, app);
	return (0);
}

void	win_pixel_put(t_app *app, int x, int y, int color)
{
	char	*dst;

	dst = app->img_addr + (y * app->size_line + x * (app->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fractal_select(t_app *app)
{
    t_fractal   *f;
	
    f = &app->f;
    if (f->set == 0)
		draw_mandelbrot(app);
	else if (f->set == 1)
		draw_julia(app);
	else if (f->set == 2)
		draw_ships(app);
}

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

int mouse_handler(int key, int x, int y, t_app *app)
{
    t_fractal *f;

    f = &app->f;
    app->mouse_x = x;
    app->mouse_y = y; 
    if (key == 5 || key == 4)
    {
        double mouse_x_rel = (x / (double)app->width) * (3.0 / f->zoom);
        double mouse_y_rel = (y / (double)app->height) * (3.0 / f->zoom);
        
        if (key == 5)
            f->zoom /= 1.2;
        else if (key == 4)
            f->zoom *= 1.2;
            
        if (key == 4)
        {
            f->right += mouse_x_rel * (1 - 1/1.2);
            f->up += mouse_y_rel * (1 - 1/1.2);
        }
        if (key == 5)
        {
            f->right -= mouse_x_rel * (1 - 1/1.2);
            f->up -= mouse_y_rel * (1 - 1/1.2);
        }
    }

    if (f->set == 0)
        draw_mandelbrot(app);
    else if (f->set == 1)
        draw_julia(app);
    else if (f->set == 2)
        draw_ships(app);
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
