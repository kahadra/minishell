/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:53:42 by heha              #+#    #+#             */
/*   Updated: 2022/07/04 21:10:14 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include "ft_utils.h"

static int	ft_accessible(const char *path)
{
	struct stat	sb;

	if (stat(path, &sb) < 0)
		return (-1);
	if ((sb.st_mode & 0170000) == 0040000)
		return (1);
	if ((sb.st_mode & 0170000) != 0100000)
		return (2);
	return (0);
}

static char	*ft_findcommand(const char *cmd, char *const tbl[])
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	while (tbl[i])
	{
		tmp = ft_strjoin(tbl[i], "/");
		if (!tmp)
			return (NULL);
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!path)
			return (NULL);
		if (ft_accessible(path) == 0)
			return (path);
		free(path);
		i++;
	}
	return ((char *)cmd);
}

static char	*ft_getpath(const char *cmd, char *const envp[])
{
	char	**tbl;
	char	*path;

	if (cmd && !ft_strchr(cmd, '/'))
	{
		while (*envp && ft_strncmp(*envp, "PATH=", 5))
			envp++;
		if (*envp)
		{
			tbl = ft_split(*envp + 5, ':');
			if (!tbl)
				return (NULL);
			path = ft_findcommand(cmd, tbl);
			ft_tblclear(&tbl);
			return (path);
		}
	}
	return ((char *)cmd);
}

static void	ft_error(const char *errmsg, const char *path, int ret)
{
	extern int	errno;

	if (!path)
	{
		ft_putstr_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		if (errmsg)
			ft_putendl_fd((char *)errmsg, STDERR_FILENO);
		else
		{
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
			if (ENOENT == errno)
				ret = 126;
		}
	}
	exit(ret);
}

void	ft_execve(char *const argv[], t_queue *envmap)
{
	char	*path;
	char	**envp;

	if (**argv == '\0')
		ft_error("command not found", argv[0], 127);
	envp = ft_envmap_to_envp(envmap);
	if (!envp)
		ft_error("malloc", NULL, EXIT_FAILURE);
	path = ft_getpath(argv[0], envp);
	if (!path)
		ft_error("malloc", NULL, EXIT_FAILURE);
	if (ft_accessible(path) < 0)
		ft_error("command not found", path, 127);
	if (ft_accessible(path) == 1)
		ft_error("is a directory", path, 126);
	if (execve(path, argv, envp) < 0)
		ft_error(NULL, path, 127);
}
