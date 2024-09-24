/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:38:39 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/09/24 15:22:21 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "expander.h"
# include "tokenizer.h"

typedef struct s_token_list t_token_list;
typedef struct s_minishell t_minishell;

typedef struct s_tree
{
	int				type;
	t_token_list	*command;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

typedef struct s_aux_tree
{
	int				idx;
	int				pipe_idx;
	int				redir_counter;
	t_token_list	*aux;
	t_token_list	*args;
	t_token_list	*redir_list;
	t_token_list	*sublist_left;
	t_token_list	*sublist_right;
	t_tree			*tree;
}	t_aux_tree;

// get_tree.c
t_tree	*get_tree(t_token_list *token_list, t_minishell *data);
void	*free_tree(t_tree **tree);
void	*free_tree_all(t_tree **tree);

// make_tree.c
t_tree	*make_tree(t_token_list *token_list, t_minishell *data);

// make_tree_cmd.c
t_tree	*make_tree_cmd(t_token *token_list, t_minishell *data);

// syntax.c
char	*check_syntax(t_token_list *token_list);

#endif
