#include "fractol.h"

void    print_usage_error(void)
{
        ft_printf("------------------------------\n");
        ft_printf("|        \033[1;4;33mUSAGE MANUAL\033[0m        |\n");
        ft_printf("|----------------------------|\n");
        ft_printf("|  \033[1;32mto use the software type: \033[0m|\n");
        ft_printf("|  ./fractol <fractal name>  |\n");
        ft_printf("|                            |\n");
        ft_printf("|  \033[1;32mavailable fractals list:\033[0m  |\n");
        ft_printf("|       Mandelbrot or m      |\n");
        ft_printf("|         Julia or j         |\n");
        ft_printf("|      Burning Ships or b    |\n");
        ft_printf("|                            |\n");
        ft_printf("| \033[1;34mJulia set is customizable!\033[0m |\n");
        ft_printf("|  \033[1;34mjust type the parameters\033[0m  |\n");
        ft_printf("|   \033[1;34mafter the fractal name!\033[0m  |\n");
        ft_printf("|                            |\n");
        ft_printf("|      parameters range:     |\n");
        ft_printf("|          -2 to 2           |\n");
        ft_printf("|                            |\n");
        ft_printf("|       \033[1;32mUSAGE EXAMPLES:\033[0m      |\n");
        ft_printf("|  ./fractol m               |\n");
        ft_printf("|  ./fractol \"Burning Ships\" |\n");
        ft_printf("|  ./fractol j 0.285 0.01    |\n");
        ft_printf("|----------------------------|\n");
}

void    print_manual(void)
{
        ft_printf("------------------------------\n");
        ft_printf("|       \033[1;4;33mFRACTOL MANUAL\033[0m       |\n");
        ft_printf("|----------------------------|\n");
        ft_printf("|  \033[1;33marrows\033[0m: \033[1;32mmove the fractal\033[0m  |\n");
        ft_printf("|                            |\n");
        ft_printf("|  \033[1;33mc\033[0m: \033[1;32mchange color\033[0m           |\n");
        ft_printf("|                            |\n");
        ft_printf("|  \033[1;33mmouse wheel\033[0m: \033[1;32mzoom in/out\033[0m  |\n");
        ft_printf("------------------------------\n");
}
