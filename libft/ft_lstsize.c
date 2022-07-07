/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:58:54 by heha              #+#    #+#             */
/*   Updated: 2022/05/02 17:10:31 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *head)
{
	int		size;
	t_list	*node;

	size = 0;
	node = head->next;
	while (node != head)
	{
		size++;
		node = node->next;
	}
	return (size);
}
