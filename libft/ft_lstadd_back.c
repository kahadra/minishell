/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:54:34 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 13:26:20 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *head, t_list *new)
{
	t_list	*tail;

	tail = head->prev;
	if (new)
	{
		new->prev = tail;
		new->next = tail->next;
		tail->next->prev = new;
		tail->next = new;
	}
}
