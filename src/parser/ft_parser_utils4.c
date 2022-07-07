/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:46:48 by heha              #+#    #+#             */
/*   Updated: 2022/06/28 21:22:06 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_redirs_cleanup(t_queue *redirs)
{
	t_redir	*redir;

	while (!ft_queue_empty(redirs))
	{
		redir = (t_redir *)ft_queue_front(redirs);
		if (redir->filename)
			free(redir->filename);
		ft_queue_pop(redirs);
	}
}

void	ft_expr_del(t_expr *expr)
{
	if (expr->redir)
	{
		ft_redirs_cleanup(expr->redir);
		ft_queue_destroy(expr->redir);
		free(expr->redir);
		expr->redir = NULL;
	}
	if (expr->str)
	{
		ft_queue_destroy(expr->str);
		free(expr->str);
		expr->str = NULL;
	}
}

void	ft_content_del(void *content)
{
	free(content);
	content = NULL;
}
