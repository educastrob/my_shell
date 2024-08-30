/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:38:39 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/08/30 18:56:21 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "minishell.h"

typedef struct s_command
{
	char				*name;
	char				**argv;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;

char	*check_syntax(t_token_list *token_list);

#endif