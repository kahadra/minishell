/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:51:21 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 20:47:29 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/errno.h>
#include "libft.h"

static int	ft_error(const char *errmsg)
{
	extern int	errno;

	ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
	ft_putstr_fd((char *)errmsg, STDERR_FILENO);
	if (errno)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	return (-1);
}

pid_t	ft_process_create(int pipefd[])
{
	pid_t	pid;

	if (pipefd)
	{
		if (pipe(pipefd) < 0)
			return (ft_error("pipe"));
	}
	pid = fork();
	if (pid < 0)
	{
		if (pipefd)
		{
			close(pipefd[0]);
			close(pipefd[1]);
		}
		return (ft_error("fork"));
	}
	return (pid);
}
