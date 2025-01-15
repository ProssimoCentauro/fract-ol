#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include "libft/header_files/libft.h"
#include "libft/header_files/ft_printf.h"

#include "stdint.h"

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
}	t_app;
#endif
