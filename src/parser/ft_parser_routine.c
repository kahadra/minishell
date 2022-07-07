/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:07:11 by chpark            #+#    #+#             */
/*   Updated: 2022/06/30 22:03:14 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_make_term(t_list *list, t_expr *expr, t_parser *p)
{
	t_list	*now;
	t_redir	*redir;
	t_expr	*node;

	now = list->next;
	node = (t_expr *)now->content;
	if (node->type == TK_ORD || node->type == TK_ARD \
	|| node->type == TK_IRD || node->type == TK_HRD)
	{
		redir = (t_redir *)malloc(sizeof(t_redir));
		now = now->next;
		node = (t_expr *)now->content;
		now = ft_term_redir(list, expr, redir, p);
		free(redir);
		ft_make_expr_p(now, expr, p);
	}
	else
		ft_make_expr_p(list->prev, expr, p);
}

void	ft_make_expr_p(t_list *list, t_expr *expr, t_parser *p)
{
	t_list	*now;
	t_expr	*node;

	now = list->next;
	node = (t_expr *)now->content;
	if (now == p->input->head)
	{
		expr = ft_copy_expr(expr);
		ft_queue_push(p->output, expr, sizeof(t_expr));
		free(expr);
		return ;
	}
	else if (node->type == TK_PIPE)
	{
		expr = ft_copy_expr(expr);
		ft_queue_push(p->output, expr, sizeof(t_expr));
		free(expr);
		if (now->next == p->input->head)
			return ;
		now = now->next;
		node = (t_expr *)now->content;
		ft_make_expr_p(now, node, p);
	}
	else
		ft_make_term(list, expr, p);
}

void	ft_parser_routine(t_parser *p)
{
	t_list	*lexer_data;
	t_expr	*expr;

	lexer_data = p->input->head->next;
	expr = ft_queue_front(p->input);
	ft_make_expr_p(lexer_data, expr, p);
}
