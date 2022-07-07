/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaprk <chaprk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:37:32 by heha              #+#    #+#             */
/*   Updated: 2022/07/06 17:16:00 by chulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# include <stdio.h>
# include "ft_shell.h"
# include "ft_structs.h"

enum	e_delimeter {
	D_BLANK = 1,
	D_PIPE,
	D_IRD,
	D_ORD,
	D_HRD,
	D_ARD,
	D_CHARS,
	D_NULL,
	D_NUM
};

typedef struct s_syntax
{
	const int	*start;
	const int	*str_next;
	const int	*rd_next;
	const int	*pipe_next;
	const int	*end;
}	t_syntax;

typedef struct t_lexer
{
	t_syntax			syntax;
	int					start;
	int					end;
	int					sqt_flag;
	int					dqt_flag;
	int					loop_flag;
	int					env_flag;
	int					*exit_status;
	enum e_delimeter	prev_type;
	enum e_delimeter	type;
	t_queue				*envmap;
}	t_lexer;

void				ft_lexer_init(t_lexer *l, t_shell *s);
void				ft_lexer_setup(t_lexer *l, char *input, t_queue *output);
void				ft_lexer_destroy(t_lexer *l);
void				ft_lexer_err(char *msg, t_queue *output, t_lexer *l);
t_expr				*ft_init_expr(void);
void				ft_check_end(char *input, t_lexer *l);
void				ft_check_start(char *input, t_lexer *l);
void				ft_replace_env(t_queue *temp_queue, char *input, \
					t_lexer *l);
t_token				ft_replace_type(enum e_delimeter type);
void				ft_lexer_make_expr(char *input, t_lexer *l, \
					t_queue *output);
void				ft_set_syntax(char *input, t_lexer *l, const int **syntax);
int					ft_syntax_check(char *input, t_lexer *l, t_queue *output);
void				ft_lexer_exit(char *msg);
void				*ft_malloc(size_t size);
enum e_delimeter	ft_check_type(char input);
char				*ft_queue_to_char(t_queue *q);
int					ft_flag_check(char cur_ch, t_lexer *l, t_queue *temp_queue);

char				*ft_envmap_malloc_value(char *value);
char				*ft_envmap_get_value(t_queue *envmap, char *key);

#endif
