/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:41:57 by heha              #+#    #+#             */
/*   Updated: 2022/06/30 12:00:52 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_builtins.h"

int	ft_pwd(char *const argv[], t_queue *envmap, t_builtininfo *info)
{
	char	*buff;

	(void)argv;
	(void)envmap;
	(void)info;
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (!getcwd (buff, BUFFER_SIZE))
		return (1);
	printf ("%s\n", buff);
	free (buff);
	return (0);
}
