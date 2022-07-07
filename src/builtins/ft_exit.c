/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:42:35 by heha              #+#    #+#             */
/*   Updated: 2022/07/04 20:37:27 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

static bool	ft_check_atoi(const char *str)
{
	bool	trigger;

	trigger = false;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isspace(*str) && !ft_isdigit(*str))
			return (false);
		if (ft_isdigit(*str))
			trigger = true;
		str++;
	}
	return (trigger);
}

static int	ft_two_or_more_arguments(t_builtininfo *info)
{
	info->shellexit = false;
	ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
	return (EXIT_FAILURE);
}

static int	ft_one_argument(const char *str, t_builtininfo *info)
{
	info->shellexit = true;
	if (!ft_check_atoi(str))
	{
		ft_putstr_fd("exit: ", STDERR_FILENO);
		ft_putstr_fd((char *)str, STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		return (EXIT_OUT_OF_RANGE);
	}
	else
		return (ft_atoi(str) & 0xFF);
}

static int	ft_no_arguments(t_builtininfo *info)
{
	info->shellexit = true;
	return (*(info->exitstatus) & 0xFF);
}

int	ft_exit(char *const argv[], t_queue *envmap, t_builtininfo *info)
{
	(void)envmap;
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (argv[1] && argv[2])
		return (ft_two_or_more_arguments(info));
	else if (argv[1])
		return (ft_one_argument(argv[1], info));
	else
		return (ft_no_arguments(info));
}
