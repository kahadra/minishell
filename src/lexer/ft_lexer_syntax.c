/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:28:15 by chpark            #+#    #+#             */
/*   Updated: 2022/07/06 18:19:42 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void	ft_set_syntax(char *input, t_lexer *l, const int **syntax)
{
	if (l->type == D_BLANK)
		l->type = l->prev_type;
	if (input[l->end] == '\0')
		*syntax = l->syntax.end;
	else if (l->prev_type == false)
		*syntax = l->syntax.start;
	else
	{
		if (l->prev_type == D_PIPE)
			*syntax = l->syntax.pipe_next;
		else if (l->prev_type == D_CHARS)
			*syntax = l->syntax.str_next;
		else if (l->prev_type == D_IRD || l->prev_type == D_ORD || \
				l->prev_type == D_HRD || l->prev_type == D_ARD)
			*syntax = l->syntax.rd_next;
	}
}

int	ft_syntax_check(char *input, t_lexer *l, t_queue *output)
{
	const int			*syntax;

	syntax = NULL;
	if (l->type == D_BLANK && output->size == 0)
		return (false);
	if (l->dqt_flag || l->sqt_flag)
	{
		ft_lexer_err("quotes Not Pair!", output, l);
		return (false);
	}
	ft_set_syntax(input, l, &syntax);
	while (*syntax != D_NUM)
	{
		if (*syntax == (int)l->type)
			return (true);
		syntax++;
	}
	ft_lexer_err("Syntax Error!", output, l);
	if (input[l->start] == '\0')
		return (false);
	return (false);
}
