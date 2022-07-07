/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:01:17 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 13:26:57 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list *head, void (*del)(void *))
{
	t_list	*node;
	t_list	*next;

	node = head->next;
	while (node != head)
	{
		next = node->next;
		ft_lstdelone(node, del);
		node = next;
	}
}
