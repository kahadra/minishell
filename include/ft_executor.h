/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:39:36 by heha              #+#    #+#             */
/*   Updated: 2022/07/04 11:39:04 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTOR_H
# define FT_EXECUTOR_H

# include "ft_structs.h"

typedef struct s_executor
{
	t_builtininfo	builtininfo;
	t_queue			*heredocs;
	t_queue			*envmap;
	t_queue			*exprs;
	t_queue			*pids;
	size_t			size;
}	t_executor;

void	ft_executor_init(t_executor *e);
void	ft_executor_destroy(t_executor *e);
void	ft_executor_error(t_executor *e, const char *errmsg);
void	ft_executor_builtininfo(t_executor *e, \
		const char *oldpath, const char *homepath, const int *exitstatus);
void	ft_executor_setup(t_executor *e, t_queue *envmap, t_queue *input);
int		ft_executor_heredoc(t_executor *e);
int		ft_executor_routine(t_executor *e);

void	ft_heredocs_cleanup(t_queue *heredocs);

#endif
