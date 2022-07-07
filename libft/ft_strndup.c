/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:06:01 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 13:43:52 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (n + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, n + 1);
	return (new);
}
