/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:52:43 by heha              #+#    #+#             */
/*   Updated: 2021/12/11 20:06:14 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*cp;
	const char	*last;
	char		find;

	cp = s;
	last = NULL;
	find = (char)c;
	while (1)
	{
		if (*cp == find)
			last = cp;
		if (*cp == '\0')
			break ;
		cp++;
	}
	return ((char *)last);
}
