/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:52:34 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 20:54:20 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_structs.h"

# define OPEN_READ			0x1
# define OPEN_HEREDOC		0x2
# define OPEN_WRITE_TRUNC	0x4
# define OPEN_WRITE_APPEND	0x8

typedef enum e_signal
{
	SIG_IN_SHELL_READLINE,
	SIG_IN_SHELL_WAITING,
	SIG_IN_PROCESS,
	SIG_IN_HEREDOC
}	t_signal;

typedef enum s_termios
{
	TTY_ECHOCTL_OFF,
	TTY_ECHOCTL_ON
}	t_termios;

int		ft_dup(int oldfd);
void	ft_dup2(int oldfd, int newfd);
void	ft_execve(char *const argv[], t_queue *envmap);
int		ft_open(const char *file, int flags);
int		ft_unlink(const char *path);
pid_t	ft_wait(int *ret, int *stat);

void	ft_set_signal(t_signal mode);
void	ft_set_termios(t_termios mode);

void	ft_tblclear(char ***tbl);
int		ft_gnl_without_newline(int fd, char **line);
char	**ft_commandline_make(t_queue *strs);
char	**ft_envmap_to_envp(t_queue *envmap);
void	ft_expr_delone(t_expr *expr);

#endif
