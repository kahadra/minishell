/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:42:05 by heha              #+#    #+#             */
/*   Updated: 2022/07/06 15:27:43 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_builtins.h"

void	ft_exp_error_msg(char *str, char *command, int sign)
{
	ft_putstr_fd(command, 2);
	ft_putstr_fd(" : '", 2);
	ft_putstr_fd(str, 2);
	if (sign == 1)
		ft_putstr_fd("' : not a valid identifier\n", 2);
	else if (sign == 2)
		ft_putstr_fd("' : No such file or directory\n", 2);
}

int	ft_valid_cmd_exp(char *str, char *command)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		ft_exp_error_msg(str, command, 1);
		return (1);
	}
	while (++i < (int)ft_strlen(str))
	{
		if (str[i] == '=')
			break ;
		else if (!ft_isalnum(str[i]) && !ft_isalpha(str[i]) && str[i] != '_')
		{
			ft_exp_error_msg(str, command, 1);
			return (1);
		}
	}
	return (0);
}

void	ft_queue_print(void *e)
{
	char	**split;
	char	*print_e;

	print_e = e;
	split = ft_split(print_e, '=');
	printf("declare -x %s", split[0]);
	ft_split_clear(split);
	print_e = ft_strchr(print_e, '=');
	if (print_e)
		printf("=\"%s\"", ++print_e);
	printf("\n");
}

int	ft_export(char *const argv[], t_queue *envmap, t_builtininfo *info)
{
	char	**split;
	char	*value;

	(void)info;
	if (argv[1] == NULL)
		ft_queue_iter(envmap, ft_queue_print);
	else
	{
		while (*(++argv))
		{
			if (ft_valid_cmd_exp(*argv, "export") == 1)
				continue ;
			split = ft_split(*argv, '=');
			value = ft_strchr(*argv, '=');
			if (value)
				value++;
			if (!ft_envmap_update(envmap, split[0], value))
				ft_queue_push(envmap, *argv, ft_strlen(*argv) + 1);
			ft_split_clear(split);
		}
	}
	return (0);
}
