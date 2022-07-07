/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:37:55 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 20:57:08 by heha             ###   ########.fr       */
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

int	ft_dup(int oldfd)
{
	int		copyfd;

	copyfd = dup(oldfd);
	if (copyfd < 0)
		ft_error("dup", EXIT_FAILURE);
	return (copyfd);
}
