/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:35:18 by heha              #+#    #+#             */
/*   Updated: 2022/07/06 17:16:51 by chulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

static void	ft_lexer_syntax_init(t_syntax *syntax)
{
	static const int	start[D_NUM] = \
		{D_CHARS, D_IRD, D_ORD, D_HRD, D_ARD, D_NUM};
	static const int	str_next[D_NUM] = \
		{D_CHARS, D_IRD, D_ORD, D_HRD, D_ARD, D_PIPE, D_NUM};
	static const int	rd_next[D_NUM] = \
		{D_CHARS, D_NUM};
	static const int	pipe_next[D_NUM] = \
		{D_CHARS, D_IRD, D_ORD, D_HRD, D_ARD, D_NUM};
	static const int	end[D_NUM] = \
		{D_CHARS, D_NUM};

	syntax->start = start;
	syntax->str_next = str_next;
	syntax->rd_next = rd_next;
	syntax->pipe_next = pipe_next;
	syntax->end = end;
}

void	ft_lexer_init(t_lexer *l, t_shell *s)
{
	ft_lexer_syntax_init(&l->syntax);
	l->start = 0;
	l->end = 0;
	l->dqt_flag = false;
	l->sqt_flag = false;
	l->env_flag = false;
	l->type = false;
	l->prev_type = false;
	l->loop_flag = true;
	l->exit_status = &s->exitstatus;
	l->envmap = &s->envmap;
}

void	ft_lexer_destroy(t_lexer *l)
{
	(void)l;
}

void	ft_lexer_error(t_lexer *l, const char *errmsg)
{
	if (errmsg)
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	ft_lexer_destroy(l);
}
