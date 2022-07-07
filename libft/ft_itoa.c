/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:00:54 by heha              #+#    #+#             */
/*   Updated: 2021/12/22 14:00:40 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_itoa_sub(char *s, int n, size_t len)
{
	unsigned int	nb;
	char			*cp;

	nb = n;
	cp = s + len;
	*cp = '\0';
	if (n < 0)
	{
		nb *= -1;
		*s = '-';
		len--;
	}
	while (len)
	{
		*--cp = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*new;
	size_t	len;

	len = ft_nbrlen(n);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_itoa_sub(new, n, len);
	return (new);
}
