/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:42:11 by heha              #+#    #+#             */
/*   Updated: 2022/07/06 15:21:09 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"
#include <stdio.h>

static void	ft_content_del(void *content)
{
	free(content);
}

static int	ft_check_split_and_free(t_queue *envmap, t_list *cur, \
		char **split, char *key)
{
	if (!ft_strcmp(split[0], key))
	{
		ft_lstdelone(cur, ft_content_del);
		envmap->size--;
		ft_split_clear(split);
		return (1);
	}
	ft_split_clear(split);
	return (0);
}

static int	ft_unset_valid_cmd_exp(char *str, char *command)
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
		if (!ft_isalnum(str[i]) && !ft_isalpha(str[i]) && str[i] != '_')
		{
			ft_exp_error_msg(str, command, 1);
			return (1);
		}
	}
	return (0);
}

int	ft_unset(char *const argv[], t_queue *envmap, t_builtininfo *info)
{
	char	**split;
	t_list	*head;
	int		i;

	(void)info;
	while (*(++argv))
	{
		if (ft_unset_valid_cmd_exp (*argv, "unset") == 1)
			continue ;
		i = -1;
		head = envmap->head->next;
		while (++i < (int)envmap->size)
		{
			split = ft_split(head->content, '=');
			if (!split)
				ft_malloc_error();
			if (ft_check_split_and_free(envmap, head, split, *argv))
				break ;
			head = head->next;
		}
	}
	return (0);
}
