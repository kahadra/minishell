/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:01:33 by heha              #+#    #+#             */
/*   Updated: 2021/12/17 10:53:26 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	new_len;
	size_t	src_len;

	new = NULL;
	if (s)
	{
		src_len = ft_strlen(s);
		if (start >= src_len)
			return (ft_strdup(""));
		if ((start + len) > src_len)
			new_len = src_len;
		else
			new_len = len;
		new = (char *)malloc(sizeof(char) * (new_len + 1));
		if (!new)
			return (NULL);
		ft_strlcpy(new, s + start, new_len + 1);
	}
	return (new);
}
