/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:54:50 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 13:28:16 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *node, void (*del)(void *))
{
	if (node)
	{
		if (del)
			del(node->content);
		node->prev->next = node->next;
		node->next->prev = node->prev;
		free(node);
	}
}
