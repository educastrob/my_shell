/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:37:12 by educastro         #+#    #+#             */
/*   Updated: 2024/08/28 13:12:06 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

// libs
# include "minishell.h"
#include "../libft/libft.h"

typedef struct s_minishell t_minishell;

// structs
typedef struct	s_env
{
	char		*name;
	char		*value;
}				t_env;

// env_func1.c
t_env	*add_env(t_list *envs, char *name, char *value);
t_list	*create_envs(char **envp);

// env_func2.c
t_env	*update_env(t_list *envs, char *name, char *value);

// utils.c
t_minishell     *init_minishell(char **envp);
int	print_env(t_minishell *minishell);

#endif
