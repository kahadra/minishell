/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:55:40 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 13:32:27 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t		len;
	ssize_t		wsize;
	const char	*buf = s;

	if (s && fd >= 0)
	{
		len = ft_strlen(s);
		while (len)
		{
			wsize = write(fd, buf, len);
			if (wsize < 0)
				return (-1);
			buf += wsize;
			len -= wsize;
		}
		return (0);
	}
	return (-1);
}
