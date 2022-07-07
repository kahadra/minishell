/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:27:21 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 19:29:22 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#include "ft_executor.h"

void	ft_shell_execute(t_shell *s)
{
	t_executor	e;

	if (ft_queue_empty(&(s->parser_data)))
		return ;
	ft_executor_init(&e);
	ft_executor_builtininfo(&e, s->oldpath, s->homepath, &(s->exitstatus));
	ft_executor_setup(&e, &(s->envmap), &(s->parser_data));
	s->exitstatus = ft_executor_routine(&e);
	ft_executor_destroy(&e);
	if (e.builtininfo.shellexit)
	{
		ft_shell_destroy(s);
		exit(s->exitstatus);
	}
}
