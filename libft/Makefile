# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 13:37:26 by mtrudel           #+#    #+#              #
#    Updated: 2017/04/27 15:24:54 by mtrudel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
OBJECTS = ft_lstdel.o ft_memmove.o ft_putstr_fd.o ft_strjoin.o ft_strrchr.o ft_atoi.o ft_lstdelone.o ft_memset.o ft_strcat.o ft_strlcat.o ft_strsplit.o ft_bzero.o ft_lstiter.o ft_putchar.o ft_strchr.o ft_strlen.o ft_strstr.o ft_isalnum.o ft_lstmap.o ft_putchar_fd.o ft_strclr.o ft_strmap.o ft_strsub.o ft_isalpha.o ft_lstnew.o ft_putchar_fd_uni.o ft_strcmp.o ft_strmapi.o ft_strtrim.o ft_isascii.o ft_memalloc.o ft_putchar_uni.o ft_strcpy.o ft_strncat.o ft_tolower.o ft_isdigit.o ft_memccpy.o ft_putendl.o ft_strdel.o ft_strncmp.o ft_toupper.o ft_isprint.o ft_memchr.o ft_putendl_fd.o ft_strdup.o ft_strncpy.o ft_iswhitespace.o ft_memcmp.o ft_putnbr.o ft_strequ.o ft_strnequ.o ft_itoa.o ft_memcpy.o ft_putnbr_fd.o ft_striter.o ft_strnew.o ft_lstadd.o ft_memdel.o ft_putstr.o ft_striteri.o ft_strnstr.o ft_strfreejoin.o get_next_line.o
SRCS = ft_lstdel.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strrchr.c ft_atoi.c ft_lstdelone.c ft_memset.c ft_strcat.c ft_strlcat.c ft_strsplit.c ft_bzero.c ft_lstiter.c ft_putchar.c ft_strchr.c ft_strlen.c ft_strstr.c ft_isalnum.c ft_lstmap.c ft_putchar_fd.c ft_strclr.c ft_strmap.c ft_strsub.c ft_isalpha.c ft_lstnew.c ft_putchar_fd_uni.c ft_strcmp.c ft_strmapi.c ft_strtrim.c ft_isascii.c ft_memalloc.c ft_putchar_uni.c ft_strcpy.c ft_strncat.c ft_tolower.c ft_isdigit.c ft_memccpy.c ft_putendl.c ft_strdel.c ft_strncmp.c ft_toupper.c ft_isprint.c ft_memchr.c ft_putendl_fd.c ft_strdup.c ft_strncpy.c ft_iswhitespace.c ft_memcmp.c ft_putnbr.c ft_strequ.c ft_strnequ.c ft_itoa.c ft_memcpy.c ft_putnbr_fd.c ft_striter.c ft_strnew.c ft_lstadd.c ft_memdel.c ft_putstr.c ft_striteri.c ft_strnstr.c ft_strfreejoin.c get_next_line.c

all: $(NAME)
$(NAME):
	gcc  -Wall -Werror -Wextra -c -I  $(HEADER) $(SRCS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all
