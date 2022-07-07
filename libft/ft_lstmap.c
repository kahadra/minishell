/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:02:17 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 13:30:11 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstcreate(void)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	ft_lstinit(head);
	return (head);
}

t_list	*ft_lstmap(t_list *head, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_head;
	t_list	*new_node;

	new_head = NULL;
	if (f)
	{
		new_head = ft_lstcreate();
		if (!new_head)
			return (NULL);
		node = head->next;
		while (node != head)
		{
			new_node = ft_lstnew(f(node->content));
			if (!new_node)
			{
				ft_lstclear(new_head, del);
				return (NULL);
			}
			ft_lstadd_back(new_head, new_node);
			node = node->next;
		}
	}
	return (new_head);
}
