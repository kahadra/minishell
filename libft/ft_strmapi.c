/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:36:10 by heha              #+#    #+#             */
/*   Updated: 2021/12/17 15:58:06 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	size_t			len;
	unsigned int	i;

	new = NULL;
	if (s)
	{
		len = ft_strlen(s);
		new = (char *)malloc(sizeof(char) * (len + 1));
		if (!new)
			return (NULL);
		i = 0;
		while (i < len)
		{
			new[i] = f(i, s[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
