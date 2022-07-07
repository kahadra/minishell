/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:25:22 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 19:28:30 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/errno.h>
#include "ft_shell.h"

void	ft_shell_init(t_shell *s)
{
	s->oldpath = NULL;
	s->homepath = NULL;
	s->readline = NULL;
	s->exitstatus = EXIT_SUCCESS;
	ft_queue_create(&(s->envmap));
	ft_queue_create(&(s->lexer_data));
	ft_queue_create(&(s->parser_data));
}

void	ft_shell_destroy(t_shell *s)
{
	if (s->oldpath)
	{
		free(s->oldpath);
		s->oldpath = NULL;
	}
	if (s->homepath)
	{
		free(s->homepath);
		s->homepath = NULL;
	}
	ft_shell_cleanup(s);
	ft_queue_destroy(&(s->envmap));
	ft_queue_destroy(&(s->lexer_data));
	ft_queue_destroy(&(s->parser_data));
}

void	ft_shell_cleanup(t_shell *s)
{
	if (s->readline)
	{
		free(s->readline);
		s->readline = NULL;
	}
	ft_exprs_cleanup(&(s->lexer_data));
	ft_exprs_cleanup(&(s->parser_data));
}

void	ft_shell_error(t_shell *s, const char *errmsg)
{
	extern int	errno;
	int			ret;

	ret = EXIT_FAILURE;
	if (errmsg)
	{
		ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
		ft_putstr_fd((char *)errmsg, STDERR_FILENO);
		if (errno)
		{
			ret = errno;
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putstr_fd(strerror(errno), STDERR_FILENO);
		}
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	ft_shell_destroy(s);
	exit(ret);
}
