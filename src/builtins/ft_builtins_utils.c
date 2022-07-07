/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:48:54 by heha              #+#    #+#             */
/*   Updated: 2022/07/04 21:30:59 by chulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_builtins.h"

void	ft_malloc_error(void)
{
	printf("Error!\n");
	exit(1);
}

void	ft_split_clear(char **str)
{
	char	**temp;

	temp = str;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(str);
}

int	ft_envmap_update(t_queue *envmap, char *key, char *value)
{
	t_list	*head;
	char	*temp;
	char	**split;

	head = envmap->head->next;
	while (envmap->head != head)
	{
		split = ft_split(head->content, '=');
		if (!split)
			ft_malloc_error();
		if (!ft_strcmp(split[0], key))
		{
			temp = ft_strjoin(split[0], "=");
			if (value)
				free(head->content);
			if (value)
				head->content = ft_strjoin(temp, value);
			free(temp);
			ft_split_clear(split);
			return (1);
		}
		ft_split_clear(split);
		head = head->next;
	}
	return (0);
}
