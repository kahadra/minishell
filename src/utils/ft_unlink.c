/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:36:44 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 21:05:43 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include "libft.h"

static int	ft_error(const char *errmsg, const char *path)
{
	extern int	errno;

	if (errno)
	{
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd((char *)errmsg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd((char *)path, STDERR_FILENO);
	}
	return (-1);
}

static int	ft_accessible(const char *path)
{
	struct stat	sb;

	if (stat(path, &sb) < 0)
		return (-1);
	if ((sb.st_mode & 0170000) != 0100000)
		return (-1);
	return (0);
}

int	ft_unlink(const char *path)
{
	int		ret;

	ret = 0;
	if (ft_accessible(path) == 0)
	{
		ret = unlink(path);
		if (ret < 0)
			return (ft_error("unlink", path));
	}
	return (ret);
}
