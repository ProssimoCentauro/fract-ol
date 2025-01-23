#Variables
NAME = fractol

SRCS_PATH = ./srcs/
HEADER_PATH = ./header/
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx_Linux.a

SRCS =	$(SRCS_PATH)fractol.c $(SRCS_PATH)draw_functions.c $(SRCS_PATH)handlers.c \
	$(SRCS_PATH)utils.c $(SRCS_PATH)prints.c $(SRCS_PATH)init_functions.c \
	$(SRCS_PATH)input_checker_functions.c

OBJS = $(SRCS:.c=.o)

#Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(HEADER_PATH)
MINIFLAGS = -Imlx -Lmlx -lX11 -lXext

#Rules
all: $(NAME)

libft: $(LIBFT)
	@echo "Compiling Libft..."
	@make -C ./libft

fractol: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(MINIFLAGS) -lm $(LIBFT) -o fractol

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)
	@make -C ./libft clean

fclean: clean
	@echo "Cleaning binaries..."
	@rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
