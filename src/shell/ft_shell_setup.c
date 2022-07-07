/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:25:59 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 19:28:48 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

static char	*ft_envmap_value_copy(t_shell *s, char *envp[], const char *key)
{
	char	**cp;
	char	*value;
	size_t	key_len;

	cp = envp;
	value = NULL;
	key_len = ft_strlen(key);
	while (*cp && ft_strncmp(*cp, key, key_len))
		cp++;
	if (*cp)
	{
		value = ft_strdup(*cp + key_len);
		if (!value)
			ft_shell_error(s, "malloc");
	}
	return (value);
}

void	ft_shell_setup(t_shell *s, int argc, char *argv[], char *envp[])
{
	char	**cp;

	(void)argc;
	(void)argv;
	cp = envp;
	while (*cp)
	{
		ft_queue_push(&(s->envmap), *cp, ft_strlen(*cp) + 1);
		cp++;
	}
	s->oldpath = ft_envmap_value_copy(s, envp, "OLDPWD=");
	s->homepath = ft_envmap_value_copy(s, envp, "HOME=");
}
