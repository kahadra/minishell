/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:30:45 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 19:29:43 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# include "ft_enums.h"
# include "ft_queue.h"

typedef struct s_expr
{
	t_token	type;
	t_queue	*str;
	t_queue	*redir;
}	t_expr;

typedef struct s_redir
{
	t_token	type;
	char	*filename;
}	t_redir;

typedef struct s_builtininfo
{
	const char	*oldpath;
	const char	*homepath;
	const int	*exitstatus;
	bool		shellexit;
}	t_builtininfo;

#endif
