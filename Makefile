# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 10:56:43 by hopham            #+#    #+#              #
#    Updated: 2020/01/08 16:52:40 by hopham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker

NAME_P = push_swap

LIB = ./libft/libft.a
LIB_FODER = ./libft/
FLAGS = -Wextra -Werror -Wall -g

SRCS_C = ./srcs/checker/

SHARE_FOLDER = ./srcs/shared_functions/

FUNC_C = main.c
SHARE_FUNCS = build.c

SHARE_FILES = $(addprefix $(SHARE_FOLDER), $(SHARE_FUNCS))
FILES_C = $(addprefix $(SRCS_C), $(FUNC_C))
CH_OBJ = $(FUNC_C:.c=.o) $(SHARE_FUNCS:.c=.o)

INCLUDES = -I ./libft/ft_printf/includes/ -I ./libft/libft/includes/ -I ./includes/

all: library $(NAME_C)

library:
	make -C $(LIB_FODER)

$(NAME_C): all
	gcc $(FLAGS) $(INCLUDES) -c $(FILES_C) $(SHARE_FILES)
	gcc $(FLAGS) -o $(NAME_C) $(INCLUDES) $(CH_OBJ) $(LIB) 

clean:
	rm -rf $(CH_OBJ)
	make clean -C $(LIB_FODER)

fclean: clean
	rm -rf $(NAME_C)
	make fclean -C $(LIB_FODER)

re: fclean all

.PHONY: library clean fclean re all
