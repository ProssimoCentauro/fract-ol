#include "fractol.h"

int ft_check_fractal_name(char *s1)
{
     if (ft_strcmp(input, "Mandelbrot") ||
             ft_strcmp(input, "m"))
         return (1);
     else if (ft_strcmp(input, "Julia") ||
             ft_strcmp(input, "j"))
         return (2);
     else if (ft_strcmp(input, "Burning Ships") ||
             ft_strcmp(input, "b"))
        return (3);
     return (0);
}

int ft_check_input(int ac, char *s1, char *s2, char *s3)
{
    int f;
    
    f = ft_check_fractal_name(s1);
    if (!f)
        return (0);
    if (f == 1 && ac != 2)
        return (0);
    if (f == 3 && ac != 2)
        return (0);
    if (f == 2 && ac == 4)
    {
        if (!ft_check_num(s2) || !ft_check_num(s3))
            return (0);
        return (1);
    }
    else
        return (0);
    return (1);
}

int	ft_check_num(char *str)
{
	size_t	i;

	i = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '2')
		str++;
	if (*str != '.' && *str != '\0')
		return (0);
	if (*str == '\0')
		return (1);
	str++;
	while (*str >= '0' && *str <= '9')
	{
		i++;
		str++;
	}
	if (*str != '\0' || i > 7)
		return (0);
	return (1);
}

double	ft_atod(char *str)
{
	double	res;
	size_t	i;
	size_t	j;
	int		sign;

	i = 0;
	j = 1;
	res = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	while (str[i] && str[i] != '.')
		res = res * 10 + (str[i++] - '0');
	if (str[i++] == '\0')
		return (res * sign);
	while (str[i])
	{
		res += ((str[i++] - '0') / pow(10, j));
		j++;
	}
	return (res * sign);
}
