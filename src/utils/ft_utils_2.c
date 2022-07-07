/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:10:11 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 21:24:57 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static char	**ft_envp_create(size_t size)
{
	char	**envp;
	size_t	i;

	envp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!envp)
		return (NULL);
	i = 0U;
	while (i <= size)
		envp[i++] = NULL;
	return (envp);
}

char	**ft_envmap_to_envp(t_queue *envmap)
{
	const size_t	size = ft_queue_size(envmap);
	const t_list	*head = envmap->head;
	char			**envp;
	t_list			*node;
	size_t			i;

	envp = ft_envp_create(size);
	if (!envp)
		return (NULL);
	i = 0U;
	node = head->next;
	while (node != head)
	{
		envp[i] = ft_strdup((char *)node->content);
		if (envp[i] == NULL)
		{
			ft_tblclear(&envp);
			return (NULL);
		}
		node = node->next;
		i++;
	}
	envp[size] = NULL;
	return (envp);
}
