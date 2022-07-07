/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:35:16 by heha              #+#    #+#             */
/*   Updated: 2022/07/06 14:32:11 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTINS_H
# define FT_BUILTINS_H

# include "ft_structs.h"

# define MAX_BUILTINS		7

# define EXIT_OUT_OF_RANGE	255

typedef struct s_builtintbl
{
	const char	*key;
	int			(*ft)(char *const *, t_queue *, t_builtininfo *);
}	t_builtintbl;

bool	ft_isbuiltins(const char *cmd);
int		ft_builtins_exec(\
		char *const argv[], t_queue *envmap, t_builtininfo *info);
int		ft_builtins_single_expr(\
		t_expr *expr, t_queue *envmap, t_builtininfo *info);

int		ft_echo(char *const argv[], t_queue *envmap, t_builtininfo *info);
int		ft_cd(char *const argv[], t_queue *envmap, t_builtininfo *info);
int		ft_pwd(char *const argv[], t_queue *envmap, t_builtininfo *info);
int		ft_export(char *const argv[], t_queue *envmap, t_builtininfo *info);
int		ft_unset(char *const argv[], t_queue *envmap, t_builtininfo *info);
int		ft_env(char *const argv[], t_queue *envmap, t_builtininfo *info);
int		ft_exit(char *const argv[], t_queue *envmap, t_builtininfo *info);

int		ft_echo_with_opt(char *const cmd[]);
char	*ft_cd_find_path(char *const argv[], t_queue *envmap, \
		const char *home_path);
int		ft_valid_cmd_exp(char *str, char *command);
int		ft_envmap_update(t_queue *envmap, char *key, char *value);
void	ft_split_clear(char **str);
void	ft_malloc_error(void);
void	ft_exp_error_msg(char *str, char *command, int sign);

#endif
