/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:28:28 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 21:24:27 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <string.h>
#include <term.h>
#include "ft_utils.h"

static int	ft_tcgetattr(int fd, struct termios *t)
{
	int		ret;

	ret = tcgetattr(fd, t);
	if (ret < 0)
	{
		ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
		ft_putstr_fd("tcgetattr", STDERR_FILENO);
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
	return (ret);
}

static int	ft_tcsetattr(int fd, int action, const struct termios *t)
{
	int		ret;

	ret = tcsetattr(fd, action, t);
	if (ret < 0)
	{
		ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
		ft_putstr_fd("tcsetattr", STDERR_FILENO);
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
	return (ret);
}

static void	ft_termios_off(int fd)
{
	struct termios	term;

	if (isatty(fd))
	{
		ft_tcgetattr(fd, &term);
		term.c_lflag &= ~(ECHOCTL);
		ft_tcsetattr(fd, TCSANOW, &term);
	}
}

static void	ft_termios_on(int fd)
{
	struct termios	term;

	if (isatty(fd))
	{
		ft_tcgetattr(fd, &term);
		term.c_lflag |= ECHOCTL;
		ft_tcsetattr(fd, TCSANOW, &term);
	}
}

void	ft_set_termios(t_termios mode)
{
	if (TTY_ECHOCTL_OFF == mode)
	{
		ft_termios_off(STDIN_FILENO);
		ft_termios_off(STDOUT_FILENO);
		ft_termios_off(STDERR_FILENO);
	}
	else
	{
		ft_termios_on(STDIN_FILENO);
		ft_termios_on(STDOUT_FILENO);
		ft_termios_on(STDERR_FILENO);
	}
}
