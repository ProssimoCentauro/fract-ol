#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/header_files/ft_printf.h"
# include "libft/header_files/libft.h"
# include "minilibx-linux/mlx.h"
# include "stdint.h"
# include <math.h>

# define MAX_ITERATIONS 100

typedef struct complex_num
{
	double			xr;
	double			xi;
}					complex_num;

typedef struct s_fractal
{
	int	set;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	double			up;
	double			right;
	double			zoom;
	unsigned int	base_color;
}					t_fractal;

typedef struct s_app
{
	void			*mlx;
	void			*window;
	void			*image;
	void			*img_addr;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int	i;
	int	j;
	t_fractal		f;
	char			*selected_fractal;
}					t_app;

int     key_hook(int keycode, void *param);
void    color_handler(t_app *app);
int    exit_handler(t_app *param);
int     events_handler(int key_code, t_app *app);
void    win_pixel_put(t_app *app, int x, int y, int color);
int     ft_strcmp(char *s1, char *s2);
void    fractal_select(char *input, t_app *app);
void    fractal_init(t_fractal *f, char *input, double cr, double ci);
void    app_init(t_app *app, char *str, double cr, double ci);
int     mouse_debug(int button, int x, int y, t_app *param);

//utils
int ft_check_num(char *str);
void    check_and_initialize(t_app *app, int ac, char **av);
int ft_check_fractal_name(char *input);
int ft_check_input(int ac, char *s1, char *s2, char *s3);
double  ft_atod(char *str);
#endif
