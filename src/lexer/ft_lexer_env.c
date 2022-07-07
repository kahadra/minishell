/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:12:35 by chpark            #+#    #+#             */
/*   Updated: 2022/07/06 16:05:23 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

static int	ft_check_env_to_quote(t_lexer *l, char cur_ch)
{
	if (!l->dqt_flag)
	{
		if (cur_ch != '\'' && cur_ch != '"')
			return (1);
	}
	else if (l->dqt_flag)
	{
		if (cur_ch == '\'' || cur_ch == '"')
			return (1);
	}
	return (0);
}

static int	ft_check_special_char(t_queue *temp_queue, char *input, t_lexer *l, \
		int env_end)
{
	char	*itoa_exit_status;
	int		i;

	if (env_end - 1 == l->start)
	{
		if (input[env_end] == '?')
		{
			itoa_exit_status = ft_itoa(*l->exit_status);
			if (itoa_exit_status == NULL)
				ft_lexer_exit("Malloc Error!");
			i = 0;
			while (itoa_exit_status[i] != '\0')
				ft_queue_push(temp_queue, &itoa_exit_status[i++], sizeof(char));
			free(itoa_exit_status);
			l->start = env_end + 1;
		}
		else
		{
			if (ft_check_env_to_quote(l, input[env_end]))
				ft_queue_push(temp_queue, &input[env_end - 1], sizeof(char));
			l->start = env_end;
		}
		return (1);
	}
	return (0);
}

static char	*ft_check_type_and_envmap_get_value(t_lexer *l, char *key, \
		t_queue *temp_queue, char *input)
{
	char	*env_value;

	env_value = ft_envmap_get_value(l->envmap, key);
	if (l->prev_type == D_IRD || l->prev_type == D_ORD || l->prev_type == D_ARD)
	{
		if ((input[l->end] == '\0' || \
				ft_check_type(input[l->end + 1] != D_CHARS)) \
				&& l->start == l->end && env_value == NULL && \
				ft_queue_empty(temp_queue))
			ft_queue_push(temp_queue, "\0", sizeof(char));
	}
	return (env_value);
}

void	ft_replace_env(t_queue *temp_queue, char *input, t_lexer *l)
{
	int					env_end;
	char				*key;
	char				*env_value;

	env_end = l->start;
	if (ft_isdigit(input[env_end + 1]))
	{
		l->start += 2;
		return ;
	}
	while (++env_end < l->end)
		if (!ft_isalpha(input[env_end]) && !ft_isdigit(input[env_end]) \
				&& input[env_end] != '_')
			break ;
	if (ft_check_special_char(temp_queue, input, l, env_end))
		return ;
	key = ft_substr(input, l->start + 1, env_end - l->start - 1);
	l->start = env_end;
	env_value = ft_check_type_and_envmap_get_value(l, key, temp_queue, input);
	env_end = 0;
	while (env_value != NULL && env_value[env_end] != '\0')
		ft_queue_push(temp_queue, &env_value[env_end++], sizeof(char));
	free(key);
	free(env_value);
}
