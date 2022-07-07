/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:27:05 by heha              #+#    #+#             */
/*   Updated: 2022/06/28 20:17:01 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#include "ft_parser.h"

void	ft_shell_parse(t_shell *s)
{
	t_parser	p;

	if (ft_queue_empty(&(s->lexer_data)))
		return ;
	ft_parser_init(&p);
	ft_parser_setup(&p, &s->lexer_data, &s->parser_data);
	ft_parser_destroy(&p);
}
