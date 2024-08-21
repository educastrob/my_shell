/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:37:12 by educastro         #+#    #+#             */
/*   Updated: 2024/08/21 13:08:45 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

// libs
# include "minishell.h"

// structs
typedef struct	s_env
{
	char				*key;
	char				*value;
	struct s_env	*next;
}				t_env;


// envp_list.c
int		add_env(t_env **env, char *name, char *value);
int		init_env(t_env **env, char **envp);
t_env	*get_env(t_env **env, char *name);
t_env	*get_env_value(char *name);
void	*free_all_env(void);

// utils.c
t_env **my_env(t_env *env);

#endif