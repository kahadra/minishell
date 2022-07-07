/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:39:46 by heha              #+#    #+#             */
/*   Updated: 2022/07/06 11:38:05 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <readline/readline.h>
#include "ft_executor.h"
#include "ft_process.h"
#include "ft_utils.h"

static char	*ft_filename_make(size_t n)
{
	char	*filename;
	char	*postfix;
	char	*tmp;

	tmp = ft_strdup("/tmp/.heredoc");
	if (!tmp)
		return (NULL);
	postfix = ft_itoa((int)n);
	if (!postfix)
	{
		free(tmp);
		return (NULL);
	}
	filename = ft_strjoin(tmp, postfix);
	free(postfix);
	free(tmp);
	return (filename);
}

static void	ft_heredoc_process(const char *filename, const char *limiter)
{
	int		exitstatus;
	char	*line;
	int		fd;

	ft_set_signal(SIG_IN_HEREDOC);
	fd = ft_open(filename, OPEN_WRITE_TRUNC);
	if (fd < 0)
		exit(EXIT_FAILURE);
	exitstatus = EXIT_SUCCESS;
	while (true)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (!ft_strcmp(line, limiter))
			break ;
		if (ft_putendl_fd(line, fd) < 0)
			exitstatus = EXIT_FAILURE;
		if (EXIT_SUCCESS != exitstatus)
			break ;
		free(line);
	}
	close(fd);
	free(line);
	exit(exitstatus);
}

static int	ft_heredoc_cleanup(char *filename, t_redir *redir, t_executor *e)
{
	int		exitstatus;
	int		stat;
	pid_t	pid;

	ft_set_signal(SIG_IN_SHELL_WAITING);
	pid = ft_wait(&exitstatus, &stat);
	if (pid < 0)
	{
		free(filename);
		ft_executor_error(e, NULL);
	}
	if (EXIT_SUCCESS != exitstatus)
		free(filename);
	else
	{
		free(redir->filename);
		redir->type = TK_IRD;
		redir->filename = filename;
		if (ft_queue_empty(e->heredocs) \
				|| ft_strcmp(filename, (char *)ft_queue_rear(e->heredocs)))
			ft_queue_push(e->heredocs, filename, ft_strlen(filename) + 1);
	}
	if (WIFSIGNALED(stat) && (SIGINT + 128) == exitstatus)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (exitstatus);
}

static int	ft_heredoc(t_redir *redir, size_t n, t_executor *e)
{
	int		exitstatus;
	char	*filename;
	pid_t	pid;

	if (TK_HRD == redir->type)
	{
		filename = ft_filename_make(n);
		if (!filename)
			ft_executor_error(e, "malloc");
		pid = ft_process_create(NULL);
		if (pid < 0)
			ft_executor_error(e, NULL);
		if (pid == 0)
			ft_heredoc_process(filename, redir->filename);
		exitstatus = ft_heredoc_cleanup(filename, redir, e);
		if (EXIT_SUCCESS != exitstatus)
			exitstatus = EXIT_FAILURE;
		return (exitstatus);
	}
	else
		return (EXIT_SUCCESS);
}

int	ft_executor_heredoc(t_executor *e)
{
	t_list	*exprs_node;
	t_list	*redirs_node;
	int		exitstatus;
	size_t	i;

	i = 0U;
	exprs_node = e->exprs->head->next;
	while (exprs_node != e->exprs->head)
	{
		if (((t_expr *)exprs_node->content)->redir)
		{
			redirs_node = ((t_expr *)exprs_node->content)->redir->head->next;
			while (redirs_node != ((t_expr *)exprs_node->content)->redir->head)
			{
				exitstatus = ft_heredoc((t_redir *)redirs_node->content, i, e);
				if (EXIT_SUCCESS != exitstatus)
					return (exitstatus);
				redirs_node = redirs_node->next;
			}
		}
		i++;
		exprs_node = exprs_node->next;
	}
	return (EXIT_SUCCESS);
}
