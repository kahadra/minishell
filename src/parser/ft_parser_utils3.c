/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:21:26 by chpark            #+#    #+#             */
/*   Updated: 2022/06/28 20:21:17 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_redirs_copy(t_queue *parser_data, t_queue *lexer_data)
{
	t_redir	*l_redir;
	t_redir	*p_redir;
	t_list	*lex_list;

	if (lexer_data->head->next == NULL)
		return ;
	lex_list = lexer_data->head->next;
	l_redir = (t_redir *)lex_list->content;
	if (lex_list->content != NULL)
	{
		while (lex_list != lexer_data->head)
		{
			p_redir = (t_redir *)malloc(sizeof(t_redir));
			p_redir->type = l_redir->type;
			p_redir->filename = ft_strdup(l_redir->filename);
			ft_queue_push(parser_data, p_redir, sizeof(t_redir));
			lex_list = lex_list->next;
			l_redir = (t_redir *)lex_list->content;
			free(p_redir);
		}
	}
	else
		return ;
}

static void	ft_strs_copy(t_queue *parser_data, t_queue *lexer_data)
{
	const t_list	*lexer_head = lexer_data->head;
	t_list			*node;
	char			*str;

	if (lexer_data->head->next == NULL)
		return ;
	node = lexer_head->next;
	while (node != lexer_head)
	{
		str = (char *)node->content;
		ft_queue_push(parser_data, str, ft_strlen(str) + 1);
		node = node->next;
	}
}

t_expr	*ft_copy_expr(t_expr *expr)
{
	t_expr	*lexer_data;
	t_expr	*parser_data;

	lexer_data = expr;
	parser_data = (t_expr *)malloc(sizeof(t_expr));
	parser_data->type = lexer_data->type;
	parser_data->str = (t_queue *)malloc(sizeof(t_queue));
	parser_data->redir = (t_queue *)malloc(sizeof(t_queue));
	ft_queue_create(parser_data->str);
	ft_queue_create(parser_data->redir);
	ft_strs_copy(parser_data->str, lexer_data->str);
	ft_redirs_copy(parser_data->redir, lexer_data->redir);
	return (parser_data);
}
