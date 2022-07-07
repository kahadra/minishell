/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:33 by chpark            #+#    #+#             */
/*   Updated: 2022/07/03 15:55:21 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void	ft_lexer_exit(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void	*ft_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		ft_lexer_exit("Malloc Error!\n");
	return (ret);
}

void	ft_lexer_err(char *msg, t_queue *output, t_lexer *l)
{
	printf("%s\n", msg);
	ft_exprs_cleanup(output);
	l->loop_flag = false;
	*l->exit_status = 258;
}

t_expr	*ft_init_expr(void)
{
	t_expr	*ret;

	ret = ft_malloc(sizeof(t_expr));
	ret->redir = ft_malloc(sizeof(t_queue));
	ret->str = ft_malloc(sizeof(t_queue));
	ft_queue_create(ret->redir);
	ft_queue_create(ret->str);
	return (ret);
}

enum e_token	ft_replace_type(enum e_delimeter type)
{
	if (type == D_HRD)
		return (TK_HRD);
	else if (type == D_ARD)
		return (TK_ARD);
	else if (type == D_IRD)
		return (TK_IRD);
	else if (type == D_ORD)
		return (TK_ORD);
	else if (type == D_PIPE)
		return (TK_PIPE);
	else if (type == D_CHARS)
		return (TK_STR);
	return (-1);
}
