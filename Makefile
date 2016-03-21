# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpayen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 15:06:22 by tpayen            #+#    #+#              #
#*   Updated: 2016/03/20 18:40:21 by tpayen           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

EXEC = fractol
CC = clang
CFLAGS = -Wall -Werror -Wextra

SRCDIR = src/
LIBFTDIR = libft/
OBJDIR = obj/

INCLUDES = -I$(LIBFTDIR)/includes -Iincludes
LIBS = $(LIBFTDIR)libft.a

SRC_FILES = main.c					\
			loop_hook.c				\
			key_hook.c				\
			mouse_hook.c			\
			mouse_move.c			\
			expose_hook.c			\
			rgba.c					\
			ft_put_px_img.c			\
			init_env.c				\
			get_valid_fractals.c	\
			frac_init.c				\
			frac_calc.c				\
			frac_julia.c			\
			frac_mandelbrot.c		\
			frac_douady.c			\
			frac_put_px.c			\

DIRS = $(OBJDIR)

SRC_OBJ = $(SRC_FILES:%.c=$(OBJDIR)%.o)

all: directories $(EXEC)

$(EXEC): $(SRC_OBJ)
	@($(MAKE) -C $(LIBFTDIR))
	$(CC) -o $@ $^ $(LIBS) -lmlx -framework OpenGL -framework Appkit

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

.PHONY: directories re clean fclean

re: fclean all

clean:
	rm -rf $(OBJDIR)
	@($(MAKE) -C $(LIBFTDIR) $@)
	
fclean: clean
	rm -rf $(EXEC)
	@($(MAKE) -C $(LIBFTDIR) $@)

directories: $(DIRS)

$(DIRS):
	mkdir $@
