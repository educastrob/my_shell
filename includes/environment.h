/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:37:12 by educastro         #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/25 18:43:34 by edcastro         ###   ########.fr       */
=======
/*   Updated: 2024/09/25 17:07:07 by fcaldas-         ###   ########.fr       */
>>>>>>> 595c50609bb96446aa16bdef772d4cf4724245b2
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

// libs
# include "minishell.h"
# include "../libft/libft.h"

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
t_env	*update_env(t_list *envs, char *name, char *value);
t_env	*export_env(t_minishell *minishell, char *name, char *value);

// env_func2.c
t_env	*find_env(t_list *envs, char *name);
char	*find_env_value(t_list *envs, char *name);
t_list	*find_env_element(t_list *envs, char *name);
void	uptade_pwd_env(t_list *envs);

// utils.c
t_minishell	*init_minishell(char **envp);

#endif
