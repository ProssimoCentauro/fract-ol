#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/header_files/ft_printf.h"
# include "libft/header_files/libft.h"
# include "minilibx-linux/mlx.h"
# include "stdint.h"
# include <math.h>

# define MAX_ITERATIONS 100

typedef struct s_fractal
{
	int				set;
	double			center_x;
	double			center_y;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	double			up;
	double			right;
	double			zoom;
	int				zoom_flag;
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
	int				i;
	int				j;
	double			x_win_center;
	double			y_win_center;
	double			mouse_x;
	double			mouse_y;
	t_fractal		f;
}					t_app;

int					key_hook(int keycode, void *param);
void				color_handler(t_app *app);
int					exit_handler(t_app *param);
int					events_handler(int key_code, t_app *app);
void				win_pixel_put(t_app *app, int x, int y, int color);
void    move_handler(int key, t_app *app);
int					ft_strcmp(char *s1, char *s2);
void				fractal_select(t_app *app);
void				fractal_init(t_fractal *f, int f_set, double cr, double ci);
void				app_init(t_app *app, int f_set, double cr, double ci);
int					mouse_debug(int button, int x, int y, t_app *param);

// input_checker_utils.c
int					ft_check_num(char *str);
void				check_and_initialize(t_app *app, int ac, char **av);
int					ft_check_fractal_name(char *input);
int					ft_check_input(int ac, char *s1, char *s2, char *s3);
double				ft_atod(char *str);

// utils.c
void				change_values(t_app *app, double n1, double n2, int flag);

// prints.c
void    print_usage_error(void);
void    print_manual(void);
#endif
