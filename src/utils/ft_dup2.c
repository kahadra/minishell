/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:53:34 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 20:57:30 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/errno.h>
#include "libft.h"

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

void	ft_dup2(int oldfd, int newfd)
{
	int		fd;

	if (oldfd != newfd)
	{
		fd = dup2(oldfd, newfd);
		close(oldfd);
		if (fd < 0)
			ft_error("dup2", EXIT_FAILURE);
	}
}
