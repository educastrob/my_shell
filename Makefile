# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:58:43 by fcaldas-          #+#    #+#              #
#    Updated: 2024/10/10 21:10:20 by edcastro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror -g3
BIN			:= ./bin/
SRCS		:= $(addprefix ./sources/, main.c utils.c) \
				$(addprefix ./sources/tokenizer/, tokenizer.c utils.c get_states.c token_states_1.c token_states_2.c token_tests.c utils_list.c) \
				$(addprefix ./sources/environment/, env_func1.c env_func2.c) \
				$(addprefix ./sources/parser/, get_tree.c make_tree.c make_tree_cmd.c make_tree_cmd_recursive.c here_doc.c) \
				$(addprefix ./sources/builtin/, env.c pwd.c) \
				$(addprefix ./sources/expander/, expand_heredoc.c expand_cmd.c expand_string.c string_list.c utils.c) \
				$(addprefix ./sources/executor/, signals.c signal_handler.c signals_macros.c create_argv.c exec_tree.c exec_cmd.c exec_pipe.c exec_and_or.c exec_cmd_fork.c fd_list.c utils.c) 
OBJS		:= $(patsubst ./sources/%.c,$(BIN)%.o,$(SRCS))
LIB			:= ./libft/libft.a
INCLUDES	:= -I ./includes/ -I ./libft


# RULES

all: libft/libft.a $(BIN) $(NAME)

libft/libft.a:
	@make -sC ./libft 

$(BIN)%.o: ./sources/%.c
	@mkdir -p $(dir $@)
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