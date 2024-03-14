# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 10:46:43 by sel-hasn          #+#    #+#              #
#    Updated: 2024/03/10 10:32:17 by sel-hasn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
SRC = push_swap.c parcing.c utils.c utils1.c utils2.c error_handel.c list_function.c \
instructions.c sort.c sort1.c utils3.c instructions1.c
OBJ = $(SRC:.c=.o)
SRC_BON = bonus/checker.c bonus/parcing.c bonus/utils.c bonus/utils1.c bonus/utils2.c bonus/error_handel.c \
bonus/list_function.c bonus/utils3.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/instructions.c \
bonus/instructions1.c bonus/utils4.c
OBJ_BON = $(SRC_BON:.c=.o)
FLAGC = -Wall -Wextra -Werror
CC = cc 
RM = rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(FLAGC) $(OBJ) -o $(NAME)

$(NAME_BONUS): $(OBJ_BON)
	$(CC) $(FLAGC) $(OBJ_BON) -o $(NAME_BONUS)

bonus/%.o: bonus/%.c bonus/checker.h
	$(CC) $(FLAGC) -c $< -o $@

%.o: %.c push_swap.h
	$(CC) $(FLAGC) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BON)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
