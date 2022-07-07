/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:36:39 by heha              #+#    #+#             */
/*   Updated: 2021/12/14 15:51:44 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = 0;
	dst_len = 0;
	while (dst && *dst && (dst_len < dstsize))
	{
		dst++;
		dst_len++;
	}
	while (*src && dstsize && (src_len + dst_len + 1 < dstsize))
	{
		*dst++ = *src++;
		src_len++;
	}
	while (*src++)
		src_len++;
	if (dstsize && (dst_len < dstsize))
		*dst = '\0';
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else
		return (src_len + dst_len);
}
