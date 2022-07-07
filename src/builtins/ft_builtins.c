/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:39:31 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 20:06:02 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

static t_builtintbl	*ft_builtin_lookup(const char *key)
{
	static t_builtintbl	tbl[MAX_BUILTINS + 1] = {\
		{"echo", ft_echo}, {"cd", ft_cd}, {"pwd", ft_pwd}, \
		{"export", ft_export}, {"unset", ft_unset}, \
		{"env", ft_env}, {"exit", ft_exit}, \
		{NULL, NULL}};
	t_builtintbl		*p;

	p = tbl;
	while (p->key)
	{
		if (!ft_strcmp(key, p->key))
			return (p);
		p++;
	}
	return (NULL);
}

bool	ft_isbuiltins(const char *cmd)
{
	t_builtintbl	*p;

	p = ft_builtin_lookup(cmd);
	return (p != NULL);
}

int	ft_builtins_exec(char *const argv[], t_queue *envmap, t_builtininfo *info)
{
	t_builtintbl	*p;
	int				exitstatus;

	exitstatus = EXIT_FAILURE;
	p = ft_builtin_lookup(argv[0]);
	if (p)
		exitstatus = p->ft(argv, envmap, info);
	return (exitstatus);
}
