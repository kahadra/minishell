/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:22:51 by heha              #+#    #+#             */
/*   Updated: 2022/06/28 20:02:06 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_core.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	s;

	ft_shell_init(&s);
	ft_shell_setup(&s, argc, argv, envp);
	while (ft_shell_readline(&s))
	{
		ft_shell_lex(&s);
		ft_shell_parse(&s);
		ft_shell_execute(&s);
		ft_shell_cleanup(&s);
	}
	ft_shell_destroy(&s);
	return (EXIT_SUCCESS);
}
