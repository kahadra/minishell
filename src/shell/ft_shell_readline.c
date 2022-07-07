/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_readline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:26:37 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 19:29:07 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "ft_shell.h"
#include "ft_utils.h"

bool	ft_shell_readline(t_shell *s)
{
	char	*line;

	ft_set_termios(TTY_ECHOCTL_OFF);
	ft_set_signal(SIG_IN_SHELL_READLINE);
	line = readline("minishell$ ");
	if (!line)
	{
		ft_putstr_fd("\033[1A", STDOUT_FILENO);
		ft_putstr_fd("\033[10C", STDOUT_FILENO);
		ft_putendl_fd(" exit", STDOUT_FILENO);
	}
	else if (*line == '\0')
	{
		free(line);
	}
	else
	{
		add_history(line);
		s->readline = line;
	}
	return (line != NULL);
}
