/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:32:08 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 21:25:22 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_structs.h"

static void	ft_strs_iter(void *content)
{
	t_expr	*expr;
	t_list	*strs_head;
	t_list	*strs_node;

	expr = (t_expr *)content;
	if (expr->str)
	{
		strs_head = expr->str->head;
		strs_node = strs_head->next;
		while (strs_node != strs_head)
		{
			printf("%s ", (char *)strs_node->content);
			strs_node = strs_node->next;
		}
		printf(" | ");
	}
}

static void	ft_redirs_iter(void *content)
{
	t_expr	*expr;
	t_redir	*redir;
	t_list	*redirs_head;
	t_list	*redirs_node;

	expr = (t_expr *)content;
	if (expr->redir)
	{
		redirs_head = expr->redir->head;
		redirs_node = redirs_head->next;
		while (redirs_node != redirs_head)
		{
			redir = (t_redir *)redirs_node->content;
			printf("(%u)%s ", redir->type, redir->filename);
			redirs_node = redirs_node->next;
		}
		printf(" | ");
	}
}

void	ft_exprs_print(t_queue *exprs, const char *msg)
{
	printf("[%s]\n", msg);
	printf("str: ");
	ft_queue_iter(exprs, ft_strs_iter);
	printf("\n");
	printf("redir: ");
	ft_queue_iter(exprs, ft_redirs_iter);
	printf("\n");
}
