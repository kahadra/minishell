/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:41:50 by heha              #+#    #+#             */
/*   Updated: 2022/07/06 15:21:12 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_lexer.h"
#include "ft_builtins.h"

char	*ft_cd_find_path(char *const argv[], t_queue *envmap, \
		const char *home_path)
{
	char	*new_path;

	if (argv[1] == NULL || ft_strcmp("--", argv[1]) == 0)
	{
		new_path = ft_envmap_get_value(envmap, "HOME");
		if (new_path == NULL)
		{
			write(2, "bash: cd: HOME not set\n", 24);
			return (NULL);
		}
	}
	else if (ft_strcmp("..", argv[1]) == 0)
		new_path = ft_strdup("..");
	else if (ft_strcmp ("-", argv[1]) == 0)
	{
		new_path = ft_envmap_get_value(envmap, "OLDPWD");
		printf("%s\n", new_path);
	}
	else if (ft_strcmp("~", argv[1]) == 0 || ft_strcmp("~/", argv[1]) == 0)
		new_path = ft_strdup(home_path);
	else
		new_path = ft_strdup(argv[1]);
	return (new_path);
}

int	ft_cd(char *const argv[], t_queue *envmap, t_builtininfo *info)
{
	char	*now_path;
	char	*new_path;

	now_path = NULL;
	now_path = getcwd(NULL, 0);
	new_path = ft_cd_find_path(argv, envmap, info->homepath);
	if (new_path == NULL)
		return (1);
	if (chdir(new_path) == -1)
	{
		perror(new_path);
		free(now_path);
		free(new_path);
		return (1);
	}
	free(new_path);
	new_path = getcwd(NULL, 0);
	ft_envmap_update(envmap, "OLDPWD", now_path);
	ft_envmap_update(envmap, "PWD", new_path);
	free (now_path);
	free (new_path);
	return (0);
}
