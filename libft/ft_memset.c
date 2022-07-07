/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:36:33 by heha              #+#    #+#             */
/*   Updated: 2021/12/10 18:39:42 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cp;
	unsigned char	ch;

	cp = (unsigned char *)b;
	ch = (unsigned char)c;
	while (len)
	{
		*cp++ = ch;
		len--;
	}
	return (b);
}
