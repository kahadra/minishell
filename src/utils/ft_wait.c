/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:52:07 by heha              #+#    #+#             */
/*   Updated: 2022/07/04 14:36:16 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/errno.h>
#include <sys/wait.h>
#include "libft.h"

static pid_t	ft_error(const char *errmsg, int *ret)
{
	extern int	errno;

	ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
	ft_putstr_fd((char *)errmsg, STDERR_FILENO);
	*ret = EXIT_FAILURE;
	if (errno)
	{
		*ret = errno;
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	return (-1);
}

pid_t	ft_wait(int *ret, int *stat)
{
	pid_t	pid;

	pid = wait(stat);
	if (pid < 0)
		return (ft_error("wait", ret));
	if (WIFEXITED(*stat))
		*ret = WEXITSTATUS(*stat);
	else if (WIFSIGNALED(*stat))
		*ret = 128 + WTERMSIG(*stat);
	else
		*ret = EXIT_FAILURE;
	return (pid);
}
