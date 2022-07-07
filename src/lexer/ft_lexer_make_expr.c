/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_make_expr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:30:04 by chpark            #+#    #+#             */
/*   Updated: 2022/07/06 18:17:49 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

char	*ft_make_char_token(char *input, t_lexer *l)
{
	t_queue				*temp_queue;
	char				*ret;

	temp_queue = ft_malloc(sizeof(t_queue));
	ft_queue_create(temp_queue);
	while (l->start < l->end)
	{
		if (ft_flag_check(input[l->start], l, temp_queue))
			continue ;
		if (l->env_flag)
		{
			ft_replace_env(temp_queue, input, l);
			l->env_flag = false;
			continue ;
		}
		ft_queue_push(temp_queue, &input[l->start], sizeof(char));
		l->start++;
	}
	ret = ft_queue_to_char(temp_queue);
	ft_queue_destroy(temp_queue);
	free(temp_queue);
	return (ret);
}

char	*ft_make_non_char_token(char *input, t_lexer *l)
{
	int		i;
	char	*str;

	str = ft_malloc(sizeof(char) * (l->end - l->start + 1));
	i = 0;
	while (l->start < l->end)
		str[i++] = input[l->start++];
	str[i] = '\0';
	return (str);
}

static void	ft_push_expr(t_lexer *l, t_queue *output, char *str)
{
	t_expr	*e;

	e = ft_init_expr();
	e->type = ft_replace_type(l->type);
	ft_queue_push(e->str, str, ft_strlen(str) + 1);
	ft_queue_push(output, e, sizeof(t_expr));
	free(e);
	l->prev_type = l->type;
}

static void	ft_null_push(t_queue *output, t_lexer *l)
{
	t_expr	*e;

	if (l->type == D_BLANK || l->prev_type == D_CHARS)
		return ;
	e = ft_init_expr();
	e->type = TK_STR;
	ft_queue_push(output, e, sizeof(t_expr));
	free(e);
	l->prev_type = D_CHARS;
}

void	ft_lexer_make_expr(char *input, t_lexer *l, t_queue *output)
{
	char	*str;

	if (!ft_syntax_check(input, l, output))
		return ;
	if (l->type == D_CHARS)
		str = ft_make_char_token(input, l);
	else
		str = ft_make_non_char_token(input, l);
	if (str)
	{
		if (l->type == D_CHARS && l->prev_type == l->type)
			ft_queue_push(((t_expr *)ft_queue_rear(output))->str, \
				str, ft_strlen(str) + 1);
		else
			ft_push_expr(l, output, str);
		free(str);
	}
	else
		ft_null_push(output, l);
	if (l->prev_type == false)
		l->prev_type = D_CHARS;
}
