/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:23:16 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 19:28:00 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHELL_H
# define FT_SHELL_H

# include "ft_queue.h"

typedef struct s_shell
{
	t_queue	envmap;
	char	*oldpath;
	char	*homepath;
	int		exitstatus;
	char	*readline;
	t_queue	lexer_data;
	t_queue	parser_data;
}	t_shell;

void	ft_shell_init(t_shell *s);
void	ft_shell_destroy(t_shell *s);
void	ft_shell_cleanup(t_shell *s);
void	ft_shell_error(t_shell *s, const char *errmsg);
void	ft_shell_setup(t_shell *s, int argc, char *argv[], char *envp[]);
bool	ft_shell_readline(t_shell *s);
void	ft_shell_lex(t_shell *s);
void	ft_shell_parse(t_shell *s);
void	ft_shell_execute(t_shell *s);

void	ft_exprs_cleanup(t_queue *exprs);

#endif
