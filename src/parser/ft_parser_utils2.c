/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:16:39 by chpark            #+#    #+#             */
/*   Updated: 2022/06/28 20:21:10 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_routine1(t_list *now, t_expr *expr, t_redir *redir)
{
	char	*str;
	t_expr	*node;

	if (expr->str->head->next->content != NULL && expr->type != TK_STR)
		ft_queue_pop(expr->str);
	expr->type = TK_STR;
	node = (t_expr *)now->content;
	str = (char *)node->str->head->next->content;
	redir->filename = ft_strdup(str);
	ft_queue_push(expr->redir, redir, sizeof(t_redir));
	ft_queue_pop(node->str);
	while (node->str->head->next != node->str->head)
	{
		str = (char *)node->str->head->next->content;
		ft_queue_push(expr->str, str, ft_strlen(str) + 1);
		ft_queue_pop(node->str);
	}
	ft_expr_del(node);
	now = now->prev;
	node = (t_expr *)now->content;
	ft_lstdelone(now->next, ft_content_del);
}

static void	ft_routine2(t_list *now, t_expr *expr, t_redir *redir)
{
	char	*str;
	t_expr	*node;

	if (expr->str->head->next->content != NULL && expr->type != TK_STR)
		ft_queue_pop(expr->str);
	expr->type = TK_STR;
	node = (t_expr *)now->content;
	str = (char *)node->str->head->next->content;
	redir->filename = ft_strdup(str);
	ft_queue_push(expr->redir, redir, sizeof(t_redir));
	ft_expr_del(node);
	now = now->prev;
	node = (t_expr *)now->content;
	ft_lstdelone(now->next, ft_content_del);
}

void	ft_term_redir2(t_list *list, t_expr *expr, t_redir *redir, t_parser *p)
{
	t_list	*now;
	t_expr	*node;

	now = list->next;
	node = (t_expr *)now->content;
	redir->type = node->type;
	now = now->next;
	node = (t_expr *)now->content;
	if (node->str->size > 1)
	{
		ft_routine1(now, expr, redir);
		p->input->size -= 1;
	}
	else
	{
		ft_routine2(now, expr, redir);
		p->input->size -= 1;
	}
}
