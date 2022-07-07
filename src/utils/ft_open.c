/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:46:39 by heha              #+#    #+#             */
/*   Updated: 2022/07/06 13:40:53 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include "ft_utils.h"

static int	ft_error(const char *errmsg, const char *file)
{
	extern int	errno;

	if (errmsg && file)
	{
		ft_putstr_fd((char *)file, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	else
	{
		if (errno)
		{
			ft_putstr_fd((char *)file, STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
		}
	}
	return (-1);
}

static int	ft_accessible(const char *path)
{
	struct stat	sb;

	if (stat(path, &sb) < 0)
		return (-1);
	return (0);
}

static int	ft_open_read(const char *file)
{
	int		fd;

	if (ft_accessible(file) < 0)
		return (ft_error("No such file or directory", file));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error(NULL, file));
	return (fd);
}

static int	ft_open_write(const char *file, int oflag)
{
	int		fd;

	if (!file[0])
		return (ft_error("No such file or directory", file));
	fd = open(file, oflag, 0644);
	if (fd < 0)
		return (ft_error(NULL, file));
	return (fd);
}

int	ft_open(const char *file, int flags)
{
	int		oflag;

	if (flags & OPEN_READ)
		return (ft_open_read(file));
	else
	{
		oflag = O_WRONLY | O_TRUNC | O_CREAT;
		if (flags & OPEN_WRITE_APPEND)
			oflag = O_WRONLY | O_APPEND | O_CREAT;
		return (ft_open_write(file, oflag));
	}
}
