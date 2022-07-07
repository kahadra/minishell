/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:39:50 by heha              #+#    #+#             */
/*   Updated: 2022/07/04 14:15:03 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/errno.h>
#include "ft_executor.h"

void	ft_executor_init(t_executor *e)
{
	ft_memset(&(e->builtininfo), 0, sizeof(t_builtininfo));
	e->heredocs = NULL;
	e->envmap = NULL;
	e->exprs = NULL;
	e->pids = NULL;
	e->size = 0U;
}

void	ft_executor_destroy(t_executor *e)
{
	if (e->heredocs)
	{
		ft_heredocs_cleanup(e->heredocs);
		ft_queue_destroy(e->heredocs);
		free(e->heredocs);
		e->heredocs = NULL;
	}
	if (e->pids)
	{
		ft_queue_destroy(e->pids);
		free(e->pids);
		e->pids = NULL;
	}
	e->size = 0U;
}

void	ft_executor_error(t_executor *e, const char *errmsg)
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
	ft_executor_destroy(e);
	exit(ret);
}
