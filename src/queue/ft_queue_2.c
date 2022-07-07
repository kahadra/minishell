/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:18:50 by heha              #+#    #+#             */
/*   Updated: 2022/06/21 12:12:13 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

static void	ft_content_del(void *content)
{
	free(content);
	content = NULL;
}

void	ft_queue_push(t_queue *q, void *content, size_t n)
{
	t_list	*node;

	if (!content || !n)
		ft_queue_error(q, ERR_QUE_DATA);
	node = ft_lstnew(content);
	if (!node)
		ft_queue_error(q, ERR_QUE_MALLOC);
	node->content = malloc(n);
	if (!(node->content))
	{
		free(node);
		ft_queue_error(q, ERR_QUE_MALLOC);
	}
	ft_memcpy(node->content, content, n);
	ft_lstadd_back(q->head, node);
	q->size++;
}

void	ft_queue_pop(t_queue *q)
{
	t_list	*node;

	if (ft_queue_empty(q))
		ft_queue_error(q, ERR_QUE_EMPTY);
	node = ft_lstfirst(q->head);
	ft_lstdelone(node, ft_content_del);
	q->size--;
}

void	*ft_queue_front(t_queue *q)
{
	t_list	*node;

	if (ft_queue_empty(q))
		ft_queue_error(q, ERR_QUE_EMPTY);
	node = ft_lstfirst(q->head);
	return (node->content);
}

void	*ft_queue_rear(t_queue *q)
{
	t_list	*node;

	if (ft_queue_empty(q))
		ft_queue_error(q, ERR_QUE_EMPTY);
	node = ft_lstlast(q->head);
	return (node->content);
}
