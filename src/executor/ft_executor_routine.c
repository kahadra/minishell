/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:40:41 by heha              #+#    #+#             */
/*   Updated: 2022/07/06 11:38:14 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_executor.h"
#include "ft_builtins.h"
#include "ft_process.h"
#include "ft_utils.h"

static void	ft_executor_loop_process(\
		t_expr *expr, int prev_pipe, int pipefd[], t_executor *e)
{
	close(pipefd[0]);
	ft_set_signal(SIG_IN_PROCESS);
	ft_set_termios(TTY_ECHOCTL_ON);
	ft_process_redir(expr->redir, prev_pipe, pipefd[1]);
	ft_process_exec(expr->str, e->envmap, &(e->builtininfo));
}

static void	ft_executor_last_process(\
		t_expr *expr, int prev_pipe, t_executor *e)
{
	pid_t	pid;

	pid = ft_process_create(NULL);
	if (pid < 0)
		ft_executor_error(e, NULL);
	if (pid == 0)
	{
		ft_set_signal(SIG_IN_PROCESS);
		ft_set_termios(TTY_ECHOCTL_ON);
		ft_process_redir(expr->redir, prev_pipe, STDOUT_FILENO);
		ft_process_exec(expr->str, e->envmap, &(e->builtininfo));
	}
	if (prev_pipe != STDIN_FILENO)
		close(prev_pipe);
	ft_queue_push(e->pids, &pid, sizeof(pid_t));
}

static int	ft_executor_processes_cleanup(t_executor *e)
{
	int		exitstatus;
	bool	sig_recv;
	int		stat;
	int		ret;
	pid_t	pid;

	ft_set_signal(SIG_IN_SHELL_WAITING);
	exitstatus = EXIT_FAILURE;
	sig_recv = false;
	while (e->size)
	{
		pid = ft_wait(&ret, &stat);
		if (pid < 0)
			ft_executor_error(e, NULL);
		if (WIFSIGNALED(stat) \
				&& ((SIGINT + 128) == ret || (SIGQUIT + 128) == ret))
			sig_recv = true;
		if (pid == *(pid_t *)ft_queue_rear(e->pids))
			exitstatus = ret;
		e->size--;
	}
	if (sig_recv)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (exitstatus);
}

static int	ft_executor_pipeline(t_executor *e)
{
	pid_t	pid;
	int		pipefd[2];
	int		prev_pipe;
	t_expr	*expr;

	prev_pipe = STDIN_FILENO;
	while (ft_queue_size(e->exprs) > 1U)
	{
		expr = (t_expr *)ft_queue_front(e->exprs);
		pid = ft_process_create(pipefd);
		if (pid < 0)
			ft_executor_error(e, NULL);
		if (pid == 0)
			ft_executor_loop_process(expr, prev_pipe, pipefd, e);
		close(pipefd[1]);
		if (prev_pipe != STDIN_FILENO)
			close(prev_pipe);
		prev_pipe = pipefd[0];
		ft_queue_push(e->pids, &pid, sizeof(pid_t));
		ft_expr_delone(expr);
		ft_queue_pop(e->exprs);
	}
	expr = (t_expr *)ft_queue_front(e->exprs);
	ft_executor_last_process(expr, prev_pipe, e);
	return (ft_executor_processes_cleanup(e));
}

int	ft_executor_routine(t_executor *e)
{
	int		exitstatus;
	t_expr	*expr;

	exitstatus = ft_executor_heredoc(e);
	if (EXIT_SUCCESS != exitstatus)
		return (exitstatus);
	expr = (t_expr *)ft_queue_front(e->exprs);
	if (e->size == 1 \
			&& expr->str && !ft_queue_empty(expr->str) \
			&& ft_isbuiltins((char *)ft_queue_front(expr->str)))
		return (ft_builtins_single_expr(expr, e->envmap, &(e->builtininfo)));
	else
		return (ft_executor_pipeline(e));
}
