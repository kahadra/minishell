/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:50:35 by heha              #+#    #+#             */
/*   Updated: 2021/12/14 15:01:18 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_cp;
	unsigned char	*src_cp;

	if (!dst && !src)
		return (NULL);
	dst_cp = (unsigned char *)dst;
	src_cp = (unsigned char *)src;
	while (n)
	{
		*dst_cp++ = *src_cp++;
		n--;
	}
	return (dst);
}
