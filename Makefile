# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: educastro <educastro@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:58:43 by fcaldas-          #+#    #+#              #
#    Updated: 2024/07/12 11:08:17 by educastro        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror -g3
BIN			:= ./objs/
SRCS		:= $(addprefix ./sources/, main.c)
OBJS		:= $(patsubst ./sources/%.c,$(BIN)%.o,$(SRCS))
LIB			:= ./libft/libft.a
HEADERS		:= -I ./include/minishell.h -I ./libft
#NAME_BONUS	:= pipex_bonus
#SRCS_BONUS	:= $(addprefix ./bonus/src/,)
#OBJS_BONUS	:= $(patsubst ./%.c,$(BIN_BONUS)%.o,$(SRCS_BONUS))
#BIN_BONUS	:= ./bin/
#HEADERS_BONUS:= -I ./bonus/include/pipex_bonus.h -I ./libft

# ifdef WITH_BONUS
# 	SRC = $(SRCS_BONUS)
# 	OBJS = $(OBJS_BONUS)
# 	BIN = $(BIN_BONUS)
# 	NAME = $(NAME_BONUS)
# 	HEADER = $(HEADERS_BONUS)
# endif

all: libft/libft.a $(BIN) $(NAME)

libft/libft.a:
	@make -sC ./libft 

$(BIN)%.o: ./sources/%.c
	@$(CC) $(FLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME) $(LIB) -lreadline

$(BIN):
	@mkdir -p $(BIN)



clean:
	rm -rf $(BIN)
	@make clean -sC ./libft 

fclean: clean
	rm -rf $(NAME) 
	rm -rf ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re