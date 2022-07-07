/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:56:47 by heha              #+#    #+#             */
/*   Updated: 2021/12/15 14:33:17 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		n;
	const char	*s;
	const char	*find;

	while (1)
	{
		n = len;
		s = haystack;
		find = needle;
		while (n && *find && (*s == *find))
		{
			find++;
			s++;
			n--;
		}
		if (n == 0 || *s == '\0' || *find == '\0')
			break ;
		haystack++;
		len--;
	}
	if (*find == '\0')
		return ((char *)haystack);
	else
		return (NULL);
}
