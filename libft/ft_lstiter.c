/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:01:51 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 13:29:11 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *head, void (*f)(void *))
{
	t_list	*node;

	if (f)
	{
		node = head->next;
		while (node != head)
		{
			f(node->content);
			node = node->next;
		}
	}
}
