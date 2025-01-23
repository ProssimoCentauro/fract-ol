#Variables
NAME = fractol

SRCS_DIR = ./srcs/
HEADER_DIR = ./header/
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx_Linux.a

SRCS =	$(SRCS_DIR)fractol.c $(SRCS_DIR)draw_functions.c $(SRCS_DIR)handlers.c \
	$(SRCS_DIR)utils.c $(SRCS_DIR)prints.c $(SRCS_DIR)init_functions.c \
	$(SRCS_DIR)input_checker_utils.c

OBJS = $(SRCS:.c=.o)

CONFIGURE = cd minilibx-linux && ./configure && cd ..
#Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(HEADER_DIR)
MINIFLAGS = -Imlx -Lmlx -lX11 -lXext

#Rules
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	@echo "Compiling Libft..."
	@make -C ./libft

$(MINILIBX):
	@echo "Compiling MiniLibX..."
	@make -C ./minilibx-linux && $(CONFIGURE)

fractol: $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MINIFLAGS) -lm -o fractol

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)
	@make -C ./libft clean

fclean: clean
	@echo "Cleaning binaries..."
	@rm -f $(NAME)
	@make -C ./libft fclean
	@make -C ./minilibx-linux clean

re: fclean all
