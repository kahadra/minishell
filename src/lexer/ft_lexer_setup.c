/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:37:27 by heha              #+#    #+#             */
/*   Updated: 2022/06/28 20:20:06 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void	ft_lexer_setup(t_lexer *l, char *input, t_queue *output)
{
	while (input[l->start] != '\0' && l->loop_flag)
	{
		ft_check_start(input, l);
		ft_check_end(input, l);
		ft_lexer_make_expr(input, l, output);
	}
}
