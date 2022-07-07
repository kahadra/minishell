/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:50:17 by heha              #+#    #+#             */
/*   Updated: 2022/07/04 14:15:15 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_heredocs_cleanup(t_queue *hrds)
{
	if (hrds)
	{
		while (!ft_queue_empty(hrds))
		{
			ft_unlink((char *)ft_queue_front(hrds));
			ft_queue_pop(hrds);
		}
	}
}
