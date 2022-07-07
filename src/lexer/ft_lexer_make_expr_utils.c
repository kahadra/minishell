/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_make_expr_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:34:12 by chpark            #+#    #+#             */
/*   Updated: 2022/07/06 16:54:17 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

char	*ft_queue_to_char(t_queue *q)
{
	int		i;
	int		size;
	char	*ret;

	if (q->size == 0)
		return (NULL);
	ret = ft_malloc(sizeof(char) * (q->size + 1));
	i = 0;
	size = q->size;
	while (i < size)
	{
		ret[i++] = *(char *)ft_queue_front(q);
		ft_queue_pop(q);
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_flag_check(char cur_ch, t_lexer *l, t_queue *temp_queue)
{
	if ((!l->dqt_flag && cur_ch == '\'') || (!l->sqt_flag && cur_ch == '"'))
	{
		if (!l->dqt_flag && cur_ch == '\'')
		{
			l->sqt_flag = ~l->sqt_flag;
			if (!l->sqt_flag && ft_queue_empty(temp_queue) \
			&& l->start == l->end - 1)
				ft_queue_push(temp_queue, "\0", sizeof(char));
		}
		else if (!l->sqt_flag && cur_ch == '"')
		{
			l->dqt_flag = ~l->dqt_flag;
			if (!l->dqt_flag && ft_queue_empty(temp_queue) \
			&& l->start == l->end - 1)
				ft_queue_push(temp_queue, "\0", sizeof(char));
		}
		l->start++;
		return (true);
	}
	else if (!l->sqt_flag && l->prev_type != D_HRD && cur_ch == '$')
		l->env_flag = true;
	return (false);
}
