/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor_setup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:40:28 by heha              #+#    #+#             */
/*   Updated: 2022/07/04 14:15:04 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static t_queue	*ft_queue_make(void)
{
	t_queue	*q;

	q = (t_queue *)malloc(sizeof(t_queue));
	if (!q)
		return (NULL);
	ft_queue_create(q);
	return (q);
}

void	ft_executor_builtininfo(t_executor *e, \
		const char *oldpath, const char *homepath, const int *exitstatus)
{
	e->builtininfo.oldpath = oldpath;
	e->builtininfo.homepath = homepath;
	e->builtininfo.exitstatus = exitstatus;
	e->builtininfo.shellexit = false;
}

void	ft_executor_setup(t_executor *e, t_queue *envmap, t_queue *input)
{
	t_queue	*heredocs;
	t_queue	*pids;

	heredocs = ft_queue_make();
	if (!heredocs)
		ft_executor_error(e, "malloc");
	pids = ft_queue_make();
	if (!pids)
		ft_executor_error(e, "malloc");
	e->heredocs = heredocs;
	e->envmap = envmap;
	e->exprs = input;
	e->pids = pids;
	e->size = ft_queue_size(input);
}
