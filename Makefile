# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:58:43 by fcaldas-          #+#    #+#              #
#    Updated: 2024/07/23 13:00:01 by fcaldas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror -g3
BIN			:= ./bin/
SRCS		:= $(addprefix ./sources/, main.c tokenizer.c utils.c get_states.c) 
OBJS		:= $(patsubst ./sources/%.c,$(BIN)%.o,$(SRCS))
LIB			:= ./libft/libft.a
INCLUDES	:= -I ./includes/ -I ./libft


# RULES

all: libft/libft.a $(BIN) $(NAME)

libft/libft.a:
	@make -sC ./libft 

$(BIN)%.o: ./sources/%.c
	@$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES) && printf "Compiling: $(notdir $<)\n"

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