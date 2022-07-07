/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:20:24 by heha              #+#    #+#             */
/*   Updated: 2021/12/11 16:22:44 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = 0;
	while (*src && (src_len + 1 < dstsize))
	{
		*dst++ = *src++;
		src_len++;
	}
	while (*src++)
		src_len++;
	if (dstsize)
		*dst = '\0';
	return (src_len);
}
