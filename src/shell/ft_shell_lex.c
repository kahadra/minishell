/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_lex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:26:53 by heha              #+#    #+#             */
/*   Updated: 2022/06/28 20:16:53 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#include "ft_lexer.h"

void	ft_shell_lex(t_shell *s)
{
	t_lexer	l;

	if (s->readline == NULL)
		return ;
	ft_lexer_init(&l, s);
	ft_lexer_setup(&l, s->readline, &s->lexer_data);
	ft_lexer_destroy(&l);
}
