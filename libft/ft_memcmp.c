/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:47:34 by heha              #+#    #+#             */
/*   Updated: 2021/12/14 18:00:27 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cp1;
	unsigned char	*cp2;

	cp1 = (unsigned char *)s1;
	cp2 = (unsigned char *)s2;
	while (n)
	{
		if (*cp1 != *cp2)
			return (*cp1 - *cp2);
		cp1++;
		cp2++;
		n--;
	}
	return (0);
}
