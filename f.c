#include "fractol.h"
#include "draw_functions.c"
#include "minilibx-linux/mlx.h"

int	key_hook(int keycode, void *param)
{
	(void)param;
	ft_printf("Tasto premuto: %d\n", keycode);
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
		f ->right += 0.2 / f->zoom;
	else if (key == 65364)
		f->up += 0.2 / f->zoom;
	if (f->set == 0)
		draw_mandelbrot(app, 0 ,0);
	if (f->set == 1)
		draw_julia(app);
	if (f->set == 2)
		draw_mandelbrot(app, 0, 0);
	
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
		f->base_color = 0x00FFFF00;
	else if (i == 3)
		f->base_color = 0x000000FF;
	i++;
	if (i == 4)
		i = 0;
	if (f->set == 0)
		draw_mandelbrot(app, 0 ,0);
	else if (f->set == 1)
		draw_julia(app);
	else if (f->set == 2)
		draw_mandelbrot(app, 0, 0);
}

void	exit_handler(int key, t_app *app)
{
	if (key == 65307)
	{
		mlx_destroy_image(app->mlx, app->image);
		mlx_destroy_window(app->mlx, app->window);
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		free(app->selected_fractal);
		exit(EXIT_SUCCESS);
	}
}



int	events_handler(int key, t_app *app)
{
	if (key == 65307)
		exit_handler(key, app);
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

double	c_calculator(void)
{
	return (0.0);
}

void	max_init(t_fractal *f)
{
	return ;
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

void	fractal_select(char *input, t_app *app)
{
	if (ft_strcmp(input, "Mandelbrot") || ft_strcmp(input, "m"))
	{
		draw_mandelbrot(app, 0, 0);
	}
	else if (ft_strcmp(input, "Julia") || ft_strcmp(input, "j"))
	{
		draw_julia(app);
	}
	else if (ft_strcmp(input, "Burning Ships") || ft_strcmp(input, "b"))
	{
		draw_mandelbrot(app, 0 ,0);
	}
}

void	fractal_init(t_fractal *f, char *input)
{
	
	if (ft_strcmp(input, "Mandelbrot") || ft_strcmp(input, "m"))
		f->set = 0;
	else if (ft_strcmp(input, "Julia") || ft_strcmp(input, "j"))
		f->set = 1;
	else if (ft_strcmp(input, "Burning Ships") || ft_strcmp(input, "b"))
		f->set = 2;
	f->zr = 0;
	f->zi = 0;
	f->cr = 0;
	f->ci = 0;
	//f->min_re = -2.0;
	//f->max_re = 2.0;
	//f->min_im = -2.0;
	//f->max_im = 2.0;
	f->base_color = 0x000000FF;
	f->up = 0;
	f->right = 0;
	f->zoom = 1;
}

void	app_init(t_app *app, char *str)
{
	app->selected_fractal = ft_strdup(str);
	app->width = 1000;
	app->height = 1000;
	app->mlx = mlx_init();
	app->window = mlx_new_window(app->mlx, app->width, app->height,
			"FRACT-OL!");
	app->image = mlx_new_image(app->mlx, app->width, app->height);
	app->img_addr = mlx_get_data_addr(app->image, &app->bits_per_pixel,
			&app->size_line, &app->endian);
	fractal_init(&app->f, str);
}

int	mouse_debug(int key, int x, int y, t_app *app)
{
	t_fractal	*f;
	f = &app->f;
	ft_printf("Mouse event: button=%d, x=%d, y=%d\n", key, x, y);
	if (key == 5)
		f->zoom /= 1.2;
	else if (key == 4)
		f->zoom *= 1.2;
	if (f->set == 0)
		draw_mandelbrot(app, x, y);
	else if (f->set == 1)
		draw_julia(app);
	else if (f->set == 2)
		draw_mandelbrot(app, x, y);
	return (0);
}

int	main(int ac, char **av)
{
	t_app	app;

	app_init(&app, av[1]);
	fractal_select(app.selected_fractal, &app);
	// mlx_put_image_to_window(app.mlx, app.window, app.image, 0, 0);
	mlx_key_hook(app.window, events_handler, &app);
	mlx_mouse_hook(app.window, mouse_debug, &app);
	//mlx_key_hook(app.window, key_hook, NULL);
	// setup_hooks(&app);
	mlx_loop(app.mlx);
	return (0);
}
