/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:38:00 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 21:24:50 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static char	**ft_cmd_create(size_t size)
{
	char	**cmd;
	size_t	i;

	cmd = (char **)malloc(sizeof(char *) * (size + 1));
	if (!cmd)
		return (NULL);
	i = 0U;
	while (i <= size)
		cmd[i++] = NULL;
	return (cmd);
}

char	**ft_commandline_make(t_queue *strs)
{
	const size_t	size = ft_queue_size(strs);
	char			**cmd;
	size_t			i;

	cmd = ft_cmd_create(size);
	if (!cmd)
		return (NULL);
	i = 0U;
	while (!ft_queue_empty(strs))
	{
		cmd[i] = ft_strdup((char *)ft_queue_front(strs));
		if (cmd[i] == NULL)
		{
			ft_tblclear(&cmd);
			return (NULL);
		}
		ft_queue_pop(strs);
		i++;
	}
	cmd[size] = NULL;
	return (cmd);
}
