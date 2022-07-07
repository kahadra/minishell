/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_set_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:03:46 by chpark            #+#    #+#             */
/*   Updated: 2022/07/06 18:02:45 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

enum e_delimeter	ft_check_type(char input)
{
	if (input == ' ')
		return (D_BLANK);
	else if (input == '|')
		return (D_PIPE);
	else if (input == '<')
		return (D_IRD);
	else if (input == '>')
		return (D_ORD);
	else
		return (D_CHARS);
}

static int	ft_single_double_quotes_check(t_lexer *l, char cur_ch)
{
	if (!l->dqt_flag && cur_ch == '\'')
		l->sqt_flag = ~l->sqt_flag;
	else if (!l->sqt_flag && cur_ch == '"')
		l->dqt_flag = ~l->dqt_flag;
	return (l->sqt_flag || l->dqt_flag);
}

void	ft_check_start(char *input, t_lexer *l)
{
	while (input[l->start] != '\0')
	{
		l->type = ft_check_type(input[l->start]);
		ft_single_double_quotes_check(l, input[l->start]);
		if (l->type != D_BLANK)
			break ;
		l->start++;
	}
}

void	ft_check_end(char *input, t_lexer *l)
{
	l->end = l->start;
	while (input[l->end] != '\0' && input[++l->end] != '\0')
	{
		if (ft_single_double_quotes_check(l, input[l->end]))
			continue ;
		if (l->type == ft_check_type(input[l->end]))
		{
			if (l->type == D_IRD || l->type == D_ORD)
			{
				if (l->type == D_IRD)
					l->type = D_HRD;
				else if (l->type == D_ORD)
					l->type = D_ARD;
				l->end++;
			}
			if (l->type == D_IRD || l->type == D_ORD || \
				l->type == D_PIPE || l->type == D_HRD || l->type == D_ARD)
				break ;
		}
		else if (l->type != ft_check_type(input[l->end]))
			break ;
	}
}
