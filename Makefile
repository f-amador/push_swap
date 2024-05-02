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

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -g
SRC_DIR = srcs
OBJ_DIR = objs
OBJBONUS_DIR = bonusobjs
SRC = costs.c  listutils.c  moves.c  push_swap.c  returntoa.c  sorted.c  sorts.c  superjoin.c
SRCBONUS = checker.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJBONUS = $(addprefix $(OBJBONUS_DIR)/, $(SRCBONUS:.c=.o))
BONUS = checker

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR) $(OBJBONUS_DIR)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

bonus: $(BONUS)

$(BONUS): $(OBJBONUS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJBONUS_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJBONUS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all re clean fclean bonus