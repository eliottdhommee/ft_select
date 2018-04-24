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

NAME 		=	ft_select

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRC_DIR		=	./srcs/
SRC_NAME	=	main.c\
				ft_move.c\
				ft_term.c\
				get_list.c\
				init.c\
				printwords.c\
				sighandler.c\
				close_term.c\
				ft_goto.c\
				update_var.c\
				termcaps.c

KEYS_DIR	=	get_keys/
KEYS_NAME	=\
				do_arrows.c\
				do_keys.c\
				get_keys.c\
				is_arrows.c\
				is_key.c
SRC_NAME	+=	$(addprefix $(KEYS_DIR), $(KEYS_NAME))
SRC			=	$(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR		=	./obj/
OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ			=	$(addprefix $(OBJ_DIR),$(OBJ_NAME))

INCLUDES	=	-I ./includes -I ./libft/includes

LIB_DIR		=	./libft/
LIBFT		=	$(LIB_DIR)libft.a
LIB_LINK	=	-Llibft -lft -ltermcap

all: $(NAME)

$(NAME): obj $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS)  $(LIB_LINK) -o $(NAME) $(OBJ)

obj:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(KEYS_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(LIBFT):
	make -C $(LIB_DIR)

clean: cleanp
	make clean -C $(LIB_DIR)

cleanp:
	rm -rf $(OBJ_DIR)

fclean: clean fcleanp
	make fclean -C $(LIB_DIR)

fcleanp: cleanp
	rm -rf $(NAME)

re: fclean all

rep: fcleanp all

.PHONY: all clean fclean re obj cleanp fcleanp rep
