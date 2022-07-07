/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:51:42 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 11:24:59 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	n;
	unsigned long long	prev;
	int					sign;

	n = 0ULL;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str && ft_isdigit(*str))
	{
		prev = n;
		n = (*str - '0') + n * 10;
		if (prev != (n - (*str - '0')) / 10)
		{
			if (sign < 0)
				return ((int)LONG_MIN);
			else
				return ((int)LONG_MAX);
		}
		str++;
	}
	return (sign * (int)n);
}
