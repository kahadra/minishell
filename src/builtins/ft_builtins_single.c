/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_single.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:10:23 by heha              #+#    #+#             */
/*   Updated: 2022/07/06 11:47:31 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/errno.h>
#include "ft_builtins.h"
#include "ft_utils.h"

static void	ft_error(const char *errmsg)
{
	extern int	errno;
	int			ret;

	ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
	ft_putstr_fd((char *)errmsg, STDERR_FILENO);
	ret = EXIT_FAILURE;
	if (errno)
	{
		ret = errno;
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(ret);
}

static int	ft_getflag(t_token tokentype)
{
	if (TK_IRD == tokentype)
		return (OPEN_READ);
	else if (TK_HRD == tokentype)
		return (OPEN_HEREDOC);
	else if (TK_ORD == tokentype)
		return (OPEN_WRITE_TRUNC);
	else
		return (OPEN_WRITE_APPEND);
}

static int	ft_fileopen(const t_redir *redir, int *backupfd)
{
	int		tmp;

	if (redir->type != TK_HRD)
	{
		tmp = ft_open(redir->filename, ft_getflag(redir->type));
		if (backupfd && *backupfd != -1)
			close(*backupfd);
		if (backupfd)
			*backupfd = tmp;
		if (tmp < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_builtins_redir(t_queue *redirs)
{
	int		exitstatus;
	t_redir	*redir;
	int		fdout;

	exitstatus = EXIT_SUCCESS;
	fdout = -1;
	if (redirs)
	{
		while (!ft_queue_empty(redirs))
		{
			redir = (t_redir *)ft_queue_front(redirs);
			if (TK_ORD == redir->type || TK_ARD == redir->type)
				exitstatus = ft_fileopen(redir, &fdout);
			else
				exitstatus = ft_fileopen(redir, NULL);
			if (EXIT_SUCCESS != exitstatus)
				return (exitstatus);
			free(redir->filename);
			ft_queue_pop(redirs);
		}
	}
	if (fdout != -1)
		ft_dup2(fdout, STDOUT_FILENO);
	return (exitstatus);
}

int	ft_builtins_single_expr(t_expr *expr, t_queue *envmap, t_builtininfo *info)
{
	int		exitstatus;
	int		copyfd;
	char	**argv;

	argv = ft_commandline_make(expr->str);
	if (!argv)
		ft_error("malloc");
	copyfd = ft_dup(STDOUT_FILENO);
	exitstatus = ft_builtins_redir(expr->redir);
	if (EXIT_SUCCESS == exitstatus)
		exitstatus = ft_builtins_exec(argv, envmap, info);
	ft_dup2(copyfd, STDOUT_FILENO);
	ft_tblclear(&argv);
	return (exitstatus);
}
