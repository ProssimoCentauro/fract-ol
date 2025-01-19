#include "fractol.h"
#include "minilibx-linux/mlx.h"

int key_hook(int keycode, void *param)
{
    (void)param;
    ft_printf("Tasto premuto: %d\n", keycode);
    return (0);
}

void	exit_handler(int key_code, void	*param)
{
	t_app	*app = (t_app *)param;
	if (key_code == 65307)
	{
		mlx_destroy_image(app->mlx, app->image);
		mlx_destroy_window(app->mlx, app->window);
		mlx_destroy_display(app->mlx);
		free(app->mlx);
        free(app->selected_fractal);
		exit(EXIT_SUCCESS);
	}
}

void    events_handler(int key_code, t_app app)
{
    if (key_code == 65307)
        exit_handler(key_code, &app);
    //else if (key_code == 99)
}

void	win_pixel_put(t_app *app, int x, int y, int color)
{
	char	*dst;
	dst = app->img_addr + (y * app->size_line + x * (app->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double  c_calculator()
{
    return (0.0);
}

void    max_init(t_fractal *f)
{
    return;
}


void    color_handler(t_app)
{
    return;
}

void    draw_mandelbrot(t_app  *app)
{
	int	i = -1;
	int	j = -1;
    t_fractal   *f;
    int iter;
    double temp;

    f = &app->f;
	while (++i <= app->width)
	{
        while (++j <= app->height)
		{
            double min_i = -1.5 + (1.0 - -2.0) * 1000 / 1000;
            f->cr = (-2.0) + (i * (1.0 - -2.0) / app->width);
            f->ci = (-1.5) + (j * (1.5 - -1.5) / app->height);
            //f->cr = -2.0 + ((double)i / app->width) * (1.5 - (-2.0));
            //f->ci = -1.5 + ((double)j / app->height) * (1.5 - (-1.5));


            f->zr = 0;
            f->zi = 0;
            iter = -1;
            while ((f->zr * f->zr) + (f->zi * f->zi) <= 4 &&
                    ++iter < MAX_ITERATIONS)
            {
                temp = f->zr * f->zr - f->zi * f->zi + f->cr;
                f->zi = 2 * f->zr * f->zi + f->ci;
                f->zr = temp;
            }

            if (iter == MAX_ITERATIONS)
                win_pixel_put(app, i, j, 0x00000000);
            else
                win_pixel_put(app, i, j, 0x000000FF + (iter * 1000000));
            iter = -1;
        }
		j = -1;
	}	
	mlx_put_image_to_window(app->mlx, app->window, app->image, 0, 0);
}

void    draw_julia(t_app  *app)
{
	int	i = 0;
	int	j = 0;
    t_fractal *f;
    int iter = -1;
    double temp;

    f = &app->f;
	while (i++ <= app->width)
	{

        while (j++ <= app->height)
		{
            f->zr = -2.0 + (i * (2.0 - -2.0)/app->width);
            f->zi = -2.0 + (j * (2.0 - -2.0)/app->width);
            f->cr = -0.8;
            f->ci = 0.156;
            while ((f->zr * f->zr) + (f->zi * f->zi) <= 4 &&
                    ++iter < MAX_ITERATIONS)
            {
                temp = f->zi;
                f->zi = 2 * f->zr * f->zi + f->ci;
                f->zr = f->zr * f->zr - temp * temp + f->cr;
            }
            if (iter == MAX_ITERATIONS)
                win_pixel_put(app, i, j, 0x00000000);
            else
                win_pixel_put(app, i, j, 0x000000FF + (iter * 1000000));
            iter = -1;
		}
		j = -1;
	}	
	mlx_put_image_to_window(app->mlx, app->window, app->image, 0, 0);
}

int ft_strcmp(char *s1, char *s2)
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

void    fractal_select(char *input, t_app *app)
{
    if (ft_strcmp(input, "Mandelbrot") ||
            ft_strcmp(input, "m"))
    {
        draw_mandelbrot(app);
    }
    else if (ft_strcmp(input, "Julia") ||
            ft_strcmp(input, "j"))
    {
        draw_julia(app);
    }
    else if (ft_strcmp(input, "Burning Ships") ||
            ft_strcmp(input, "m"))
    {
        draw_mandelbrot(app);
    }
}

void    fractal_init(t_fractal *f)
{
    f->zr = 0;
    f->zi = 0;
    f->cr = 0;
    f->ci = 0;
    f->min_re = -2.0;
    f->max_re = 2.0;
    f->min_im = -2.0;
    f->max_im = 2.0;
    f->base_color = 0x000000FF;
}

void    app_init(t_app  *app, char *str)
{
    app->selected_fractal = ft_strdup(str);
	app->width = 1000;
	app->height = 1000;
	
	app->mlx = mlx_init();
	app->window = mlx_new_window(app->mlx,
            app->width, app->height, "FRACT-OL!");
	
	app->image = mlx_new_image(app->mlx,
            app->width, app->height);
	app->img_addr = mlx_get_data_addr(app->image,
            &app->bits_per_pixel, &app->size_line, &app->endian);
    fractal_init(&app->f);
}

int mouse_debug(int button, int x, int y, void *param)
{
    (void)param;
    ft_printf("Mouse event: button=%d, x=%d, y=%d\n", button, x, y);
    return (0);
}

int	main(int ac, char **av)
{
	t_app	app;
	
    app_init(&app, av[1]);
    fractal_select(app.selected_fractal, &app);
	//mlx_put_image_to_window(app.mlx, app.window, app.image, 0, 0);
	//mlx_key_hook(app.window, events_handler, &app);
    mlx_key_hook(app.window, key_hook, NULL);
    //setup_hooks(&app);
	mlx_loop(app.mlx);
	return (0);
}
