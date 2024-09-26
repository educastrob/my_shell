/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:37:12 by educastro         #+#    #+#             */
/*   Updated: 2024/09/26 17:14:33 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

// libs
# include "minishell.h"
# include "environment.h"
# include "parsing.h"
# include "tokenizer.h"
# include "expander.h"
# include "executor.h"
# include "../libft/libft.h"


// signals.c
void	sig_handler_heredoc(int signal __attribute__((unused)));
void	sig_handler_sigint(int signal __attribute__((unused)));
void	sig_handler_redo_readline(int signal __attribute__((unused)));

// signals_handler.c
void	init_signals(void);
void	heredoc_signals(void);
void	execution_signals(int pid);

// signals_macros.c
int		term_by_signal(int status);
int		term_normaly(int status);
int		exit_status(int status);
int		term_signal(int status);
int		get_return_value(int status);


#endif