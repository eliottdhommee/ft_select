# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edhommee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 09:49:17 by edhommee          #+#    #+#              #
#*   Updated: 2017/08/20 11:32:51 by edhommee         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME 		= ft_select

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./srcs/
SRC_NAME	= main.c sighandler.c utils.c init.c ft_move.c get_list.c\
			  get_keys.c get_arrows.c ft_moveword.c printwords.c ft_term.c

SRC			= $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR		= ./obj/
OBJ			= $(addprefix $(OBJ_DIR),$(SRC_NAME:.c=.o))

INCLUDES	=  -I ./includes -I ./libft/includes

LIB_DIR		= ./libft/
LIBFT		= $(LIB_DIR)libft.a
LIB_LINK	= -Llibft -lft

all: $(NAME)

$(NAME): obj $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -ltermcap $(LIB_LINK) -o $(NAME) $(OBJ)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIB_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
