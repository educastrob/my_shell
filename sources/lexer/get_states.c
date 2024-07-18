/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:44:40 by edcastro          #+#    #+#             */
/*   Updated: 2024/07/18 16:53:33 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

int		get_token_type(int state)
{
	int	type;

	if (state == 20)
		type = OPEN_PARENTHESIS;
	else if (state == 30)
		type = CLOSE_PARENTHESIS;
	else if (state == 41)
		type = OR;
	else if (state == 42)
		type = PIPE;
	else if (state == 51)
		type = AND;
	else if (state == 61)
		type = REDIRECT_HEREDOC;
	else if (state == 62)
		type = REDIRECT_INPUT;
	else if (state == 71)
		type = REDIRECT_OUTPUT_APPEND;
	else if (state == 72)
		type = REDIRECT_OUTPUT;
	else if (state == 83)
		type = WORD;
	else
		type = -1;
	return (type);
}