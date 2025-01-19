#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include "libft/header_files/libft.h"
#include "libft/header_files/ft_printf.h"

#include "stdint.h"

#define MAX_ITERATIONS 50

typedef struct  complex_num
{
    double  xr;
    double  xi;
}   complex_num;

typedef struct  s_fractal
{
    double  zr;
    double  zi;
    double  cr;
    double  ci;
    double  min_re;
    double  max_re;
    double  min_im;
    double  max_im;
    unsigned int base_color;
}   t_fractal;

typedef	struct	s_app
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*img_addr;
	int	width;
	int	height;
	int bits_per_pixel;
	int size_line;
	int endian;
    t_fractal f;
    char    *selected_fractal;
}	t_app;
#endif
