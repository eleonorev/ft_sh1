#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evoisin <evoisin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 20:14:10 by evoisin           #+#    #+#              #
#    Updated: 2015/02/05 16:23:03 by evoisin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell1

SRC = main.c ft_exec.c ft_blop.c blop2.c

HEAD = ft_sh1.h 

CFLAGS = -Wall -Werror -Wextra

FLAGSLIBFT = -L libft -lft -I libft/includes

$(NAME):
		@make -C libft/
		@gcc $(CFLAGS) -o $(NAME) $(SRC) $(HEAD) $(FLAGSLIBFT)
		@echo "\033[1;37;40mOk. \033[0m"

all : $(NAME)

clean : 
		@rm -f $(OSRC)

fclean : clean
		@make -C libft/ fclean
		@rm -rf $(NAME)

re : fclean all 
