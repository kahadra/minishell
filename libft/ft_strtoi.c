/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:38:49 by heha              #+#    #+#             */
/*   Updated: 2022/06/02 18:45:32 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static int	ft_getsign(const char **str)
{
	const char	*cp = *str;
	int			sign;

	sign = 1;
	while (*cp && ft_isspace(*cp))
		cp++;
	if (*cp == '-' || *cp == '+')
		if (*cp++ == '-')
			sign = -1;
	*str = cp;
	return (sign);
}

static int	ft_getbase(const char **str, int base)
{
	const char	*cp = *str;

	if ((base == 0 || base == 16) && *cp == '0')
	{
		if (*(cp + 1) == 'x' || *(cp + 1) == 'X')
		{
			base = 16;
			*str = cp + 2;
		}
	}
	if (base == 0)
	{
		base = 10;
		if (*cp == '0')
			base = 8;
	}
	return (base);
}

static int	ft_calculate(unsigned long long *n, int base, int sign, char c)
{
	unsigned char	digit;

	if (ft_isdigit(c))
		digit = c - '0';
	else if (ft_isalpha(c))
		digit = ft_toupper(c) - 'A' + 10;
	else
		digit = 127;
	if (digit >= base)
		return (0);
	*n = digit + *n * base;
	if ((sign == 1 && *n > INT_MAX) || (sign == -1 && *n && *n - 1 > INT_MAX))
		return (-1);
	return (1);
}

static char	*ft_endptr_update(int ret, \
		const char *str, const char *cp1, const char *cp2)
{
	if (ret < 0)
		return ((char *)str);
	else if (cp1 == cp2)
		return ((char *)str);
	else
		return ((char *)cp2);
}

int	ft_strtoi(const char *str, char **endptr, int base)
{
	unsigned long long	n;
	int					ret;
	int					sign;
	const char			*cp1 = str;
	const char			*cp2 = str;

	n = 0ULL;
	ret = 0;
	sign = 1;
	if (base >= 0 && base < 36)
	{
		sign = ft_getsign(&cp1);
		base = ft_getbase(&cp1, base);
		cp2 = cp1;
		while (*cp2)
		{
			ret = ft_calculate(&n, base, sign, *cp2);
			if (ret <= 0)
				break ;
			cp2++;
		}
	}
	if (endptr)
		*endptr = ft_endptr_update(ret, str, cp1, cp2);
	return (sign * (int)n);
}
