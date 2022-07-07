/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:38:26 by heha              #+#    #+#             */
/*   Updated: 2022/06/28 20:20:24 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "ft_structs.h"
# include <stdio.h>

typedef struct s_parser
{
	t_queue	*input;
	t_queue	*output;
}	t_parser;

void	ft_parser_init(t_parser *p);
void	ft_parser_destroy(t_parser *p);
void	ft_parser_routine(t_parser *p);
void	ft_make_expr_p(t_list *list, t_expr *expr, t_parser *p);
void	ft_parser_error(t_parser *p, const char *errmsg);
void	ft_parser_setup(t_parser *p, t_queue *input, t_queue *output);
t_list	*ft_term_redir(t_list *list, t_expr *expr, t_redir *redir, t_parser *p);
void	ft_term_redir2(t_list *list, t_expr *expr, t_redir *redir, t_parser *p);
t_expr	*ft_copy_expr(t_expr *expr);
void	ft_expr_del(t_expr *node);
void	ft_content_del(void *content);

#endif
