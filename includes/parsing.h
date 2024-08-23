/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:19:00 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/08/22 18:16:53 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "lexing.h"

void	check_syntax(t_token_list *token_list);

typedef struct s_command
{
	int					type;
	char				*content;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;

#endif