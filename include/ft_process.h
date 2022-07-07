/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:51:05 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 20:46:46 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESS_H
# define FT_PROCESS_H

# include "ft_structs.h"

pid_t	ft_process_create(int pipefd[]);
void	ft_process_exec(t_queue *strs, t_queue *envmap, t_builtininfo *info);
void	ft_process_redir(t_queue *redirs, int pipein, int pipeout);

#endif
