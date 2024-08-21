/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:37:12 by educastro         #+#    #+#             */
/*   Updated: 2024/08/21 05:11:58 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

// libs
# include "minishell.h"

// structs
typedef struct	s_envp_list
{
	char				*key;
	char				*value;
	struct s_envp_list	*next;
}				t_envp_list;

// functions
t_envp_list	*get_envp_list(char **envp);

#endif