/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:47:51 by heha              #+#    #+#             */
/*   Updated: 2022/06/28 20:20:48 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_parser_setup(t_parser *p, t_queue *l, t_queue *output)
{
	size_t	i;
	t_expr	*expr;

	i = l->size;
	p->input = l;
	p->output = output;
	if (i == 1)
	{
		expr = ft_queue_front(p->input);
		ft_queue_push(p->output, expr, sizeof(t_expr));
		ft_queue_pop(p->input);
	}
	else if (i > 1)
		ft_parser_routine(p);
	else
		ft_parser_error(p, "no_input_data");
}
