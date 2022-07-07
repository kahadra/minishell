/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:46:27 by heha              #+#    #+#             */
/*   Updated: 2022/06/28 20:20:32 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_parser_init(t_parser *p)
{
	p->input = NULL;
	p->output = NULL;
}

void	ft_parser_destroy(t_parser *p)
{
	(void)p;
}

void	ft_parser_error(t_parser *p, const char *errmsg)
{
	if (errmsg)
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	ft_parser_destroy(p);
}
