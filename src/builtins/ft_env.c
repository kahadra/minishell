/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:42:25 by heha              #+#    #+#             */
/*   Updated: 2022/07/06 14:35:47 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_builtins.h"

int	ft_env(char *const argv[], t_queue *envmap, t_builtininfo *info)
{
	size_t	i;
	t_list	*cur;

	(void)info;
	if (argv[1])
	{
		ft_exp_error_msg(argv[1], "env", 2);
		return (1);
	}
	i = 0;
	cur = envmap->head->next;
	while (i < envmap->size)
	{
		printf("%s\n", (char *)cur->content);
		cur = cur->next;
		i++;
	}
	return (0);
}
