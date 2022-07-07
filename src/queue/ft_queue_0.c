/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:18:08 by heha              #+#    #+#             */
/*   Updated: 2022/06/21 12:11:51 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void	ft_queue_create(t_queue *q)
{
	q->head = (t_list *)malloc(sizeof(t_list));
	if (!(q->head))
		ft_queue_error(q, ERR_QUE_MALLOC);
	ft_lstinit(q->head);
	q->size = 0U;
}

void	ft_queue_destroy(t_queue *q)
{
	if (q->head)
	{
		ft_queue_clear(q);
		free(q->head);
		q->head = NULL;
	}
}

void	ft_queue_clear(t_queue *q)
{
	while (!ft_queue_empty(q))
		ft_queue_pop(q);
}

void	ft_queue_error(t_queue *q, const char *errmsg)
{
	if (errmsg)
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	ft_queue_destroy(q);
	exit(EXIT_FAILURE);
}
