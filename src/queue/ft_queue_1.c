/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:18:24 by heha              #+#    #+#             */
/*   Updated: 2022/06/20 21:04:01 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

size_t	ft_queue_size(const t_queue *q)
{
	return (q->size);
}

bool	ft_queue_empty(const t_queue *q)
{
	return (q->size == 0U);
}

void	ft_queue_iter(t_queue *q, void (*f)(void *))
{
	ft_lstiter(q->head, f);
}
