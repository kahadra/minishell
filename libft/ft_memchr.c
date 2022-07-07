/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:28:21 by heha              #+#    #+#             */
/*   Updated: 2021/12/13 16:46:26 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cp;
	unsigned char	find;

	cp = (unsigned char *)s;
	find = (unsigned char)c;
	while (n)
	{
		if (*cp == find)
			return ((void *)cp);
		cp++;
		n--;
	}
	return (NULL);
}
