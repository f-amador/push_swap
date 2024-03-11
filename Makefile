# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framador <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 17:10:20 by framador          #+#    #+#              #
#    Updated: 2024/03/09 17:05:11 by framador         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpushswap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude
SRC_DIR = srcs
OBJ_DIR = objs
OBJBONUS_DIR = bonusobjs
SRC = push_swap.c
SRCBONUS = ./srcs/checker.c
OBJBONUS = $(addprefix $(OBJBONUS_DIR)/, $(SRC:.c=.o))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
PROGRAM = push_swap
BONUS = checker
all: $(PROGRAM)

$(PROGRAM): $(NAME)
	$(CC) $(CFLAGS) -g $(NAME) -o $(PROGRAM)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

$(OBJ): $(SRC_DIR)/$(SRC)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean: all
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(PROGRAM)

re: fclean all

debog: all
	gdb $(PROGRAM)

bonus:  $(BONUS)

$(BONUS):
	$(CC) $(CFLAGS) $(SRCBONUS) -o $(BONUS)

.PHONY: all re clean fclean debog
