/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:47:36 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 20:49:15 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/errno.h>
#include "ft_builtins.h"
#include "ft_utils.h"

static void	ft_error(const char *errmsg, int ret)
{
	extern int	errno;

	ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
	ft_putstr_fd((char *)errmsg, STDERR_FILENO);
	if (errno)
	{
		ret = errno;
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(ret);
}

void	ft_process_exec(t_queue *strs, t_queue *envmap, t_builtininfo *info)
{
	char	**argv;

	if (strs && !ft_queue_empty(strs))
	{
		argv = ft_commandline_make(strs);
		if (!argv)
			ft_error("malloc", EXIT_FAILURE);
		if (ft_isbuiltins(argv[0]))
			exit(ft_builtins_exec(argv, envmap, info));
		else
			ft_execve(argv, envmap);
	}
	else
		exit(EXIT_SUCCESS);
}
