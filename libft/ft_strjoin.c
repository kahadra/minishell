/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:58:01 by heha              #+#    #+#             */
/*   Updated: 2021/12/17 10:54:19 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	new = NULL;
	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (!new)
			return (NULL);
		ft_strlcpy(new, s1, len1 + 1);
		ft_strlcat(new, s2, len1 + len2 + 1);
	}
	return (new);
}
