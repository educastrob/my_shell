/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_macros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:00:14 by edcastro          #+#    #+#             */
/*   Updated: 2024/09/26 18:42:23 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


// verifica se o processo foi encerrado por um sinal
int	term_by_signal(int status)
{
	return (((signed char)((status & 0x7f) + 1) >> 1) > 0);
}

// verifica se o processo foi encerrado normalmente
int	term_normaly(int status)
{
	return (term_by_signal(status) == 0);
}

// obtém o código de saída do processo
int	exit_status(int status)
{
	return ((status >> 8) & 0xFF);
}

// obtém o número do sinal que encerrou o processo
int	term_signal(int status)
{
	return (status & 0x7F);
}

// obtém o valor de retorno a ser usado pela função exit()
int	get_return_value(int status)
{
	if (term_by_signal(status))
	{
		if (term_signal(status) == SIGQUIT)
			ft_putendl_fd(RED"QUIT"RST " (core dumped)", STDERR_FILENO);
		return (term_signal(status) + 128);
	}
	return (exit_status(status));
}
