/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:57:06 by heha              #+#    #+#             */
/*   Updated: 2021/12/14 15:01:36 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cp;
	unsigned char	*src_cp;

	if (!dst && !src)
		return (NULL);
	dst_cp = (unsigned char *)dst;
	src_cp = (unsigned char *)src;
	dst_cp += len - 1;
	src_cp += len - 1;
	while (len)
	{
		*dst_cp-- = *src_cp--;
		len--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		return (ft_memrcpy(dst, src, len));
	else
		return (ft_memcpy(dst, src, len));
}
