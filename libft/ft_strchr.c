/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:31:20 by heha              #+#    #+#             */
/*   Updated: 2021/12/13 14:37:34 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*cp;
	char		find;

	cp = s;
	find = (char)c;
	while (1)
	{
		if (*cp == find)
			return ((char *)cp);
		if (*cp == '\0')
			break ;
		cp++;
	}
	return (NULL);
}
