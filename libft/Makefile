#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evoisin <evoisin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 07:56:39 by evoisin           #+#    #+#              #
#    Updated: 2015/01/30 15:25:40 by evoisin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	:=	libft.a

SRC		:= 	ft_isalnum.c ft_isascii.c ft_isprint.c ft_strrchr.c\
		   	ft_tolower.c ft_isalpha.c ft_isdigit.c ft_strdup.c\
			ft_strchr.c ft_strlen.c ft_toupper.c ft_memset.c ft_bzero.c\
			ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
			ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strstr.c\
	  		ft_strcat.c ft_strncat.c ft_strlcat.c ft_strcmp.c ft_atoi.c\
	  		ft_strnstr.c ft_strncmp.c ft_memalloc.c ft_memdel.c ft_strnew.c\
			ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
			ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
		 	ft_putchar.c ft_putstr.c ft_putcolor.c\
			ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c\
			ft_strsplit.c ft_isblank.c ft_strtrim.c get_next_line.c

HEAD	:=	includes/libft.h includes/get_next_line.h

OSRC	:= 	$(SRC:.c=.o)

CFLAGS	:= 	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OSRC)
	@ar rcs $(NAME) $^

%.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	@rm -f $(OSRC)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
