#include "fractol.h"
#include "minilibx-linux/mlx.h"

int 	exit_handler(int key_code, void	*param)
{
	t_app	*app = (t_app *)param;
	if (key_code == 65307)
	{
		mlx_destroy_image(app->mlx, app->image);
		mlx_destroy_window(app->mlx, app->window);
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	win_pixel_put(t_app *app, int x, int y, int color)
{
	char	*dst;
	dst = app->img_addr + (y * app->size_line + x * (app->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main()
{
	t_app	app;
	uint32_t	*buffer;


	app.width = 500;
	app.height = 500;
	
	app.mlx = mlx_init();
	app.window = mlx_new_window(app.mlx, 500, 500, "holawei!");
	
	app.image = mlx_new_image(app.mlx, app.width, app.height);
	app.img_addr = mlx_get_data_addr(app.image, &app.bits_per_pixel, &app.size_line, &app.endian);
	
	int	i = -1;
	int	j = -1;
	while (i++ <= 500)
	{
		while (j++ <= 500)
		{
			win_pixel_put(&app, i, j, 0x00FF0000);
		}
		j = -1;
	}	
	mlx_put_image_to_window(app.mlx, app.window, app.image, 0, 0);
	mlx_key_hook(app.window, exit_handler, &app);
	mlx_loop(app.mlx);
	return (0);
}
