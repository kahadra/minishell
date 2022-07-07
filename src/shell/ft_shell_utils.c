/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:04:34 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 19:29:33 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_exprs_cleanup(t_queue *exprs)
{
	t_expr	*expr;

	while (!ft_queue_empty(exprs))
	{
		expr = (t_expr *)ft_queue_front(exprs);
		ft_expr_delone(expr);
		ft_queue_pop(exprs);
	}
}
