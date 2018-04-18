# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/13 09:15:16 by mtrudel           #+#    #+#              #
#    Updated: 2017/09/26 13:47:22 by mtrudel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #

NAME = fdf

# ---------------------------------------------------------------------------- #

LIB = -L ./minilibx/ -lmlx -framework OpenGL -framework AppKit -L ./libft/ -lft

CFLAGS = -Wall -Wextra -Werror

OBJECTS = fdf.o\
		  parsing.o\
		  key_function.o\
		  print_image.o\
		  initialisation.o\
		  ft_ray_linker.o

SRCS = fdf.c\
	   parsing.c\
	   key_function.c\
	   print_image.c\
	   initialisation.c\
	   ft_ray_linker.c

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.SILENT :

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft/
	@make -C minilibx/
	@gcc $(CFLAGS) -c -I $(SRCS)
	@gcc $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIB)
	@echo "$(GREEN)[✓] FDF: READY!$(NC)"

clean:
	@make clean -C libft/
	@make clean -C minilibx/
	@rm -f $(OBJECTS)
	@echo "$(RED)[-] FDF: SUPPRESSION DES FICHIERS OBJETS.$(NC)"

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@echo "$(RED)[-] FDF: SUPPRESSION DE L'EXECUTABLE.$(NC)"

re: fclean all
	@make re -C libft/

.PHONY : all re clean fclean
