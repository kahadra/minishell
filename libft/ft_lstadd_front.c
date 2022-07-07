/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:53:28 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 13:26:27 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list *head, t_list *new)
{
	if (new)
	{
		new->prev = head;
		new->next = head->next;
		head->next->prev = new;
		head->next = new;
	}
}
