/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:37:12 by educastro         #+#    #+#             */
/*   Updated: 2024/08/23 16:45:06 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

// libs
# include "minishell.h"

// structs
typedef struct	s_env
{
	char				*name;
	char				*value;
	struct s_env		*next;
}				t_env;


// env_func1.c
int		add_env(char *name, char *value);
int		init_env(char **envp);
t_env	*get_env(char *name);
char	*get_env_value(char *name);
void	*free_all_env(void);

// env_func2.c
void	*free_env(t_env *env);
t_env	*init_env_update(char *name, char *value);
int		update_env(char *name, char *value);

// utils.c
t_env **my_env(t_env *env);

#endif