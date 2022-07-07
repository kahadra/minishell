/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:16:41 by heha              #+#    #+#             */
/*   Updated: 2021/12/17 11:37:21 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*new;
	char const	*front;
	char const	*rear;

	new = NULL;
	if (s1)
	{
		front = s1;
		rear = s1 + ft_strlen(s1) - 1;
		while (*front && ft_strchr(set, *front))
			front++;
		while (*rear && ft_strchr(set, *rear) && front <= rear)
			rear--;
		if (front > rear)
			return (ft_strdup(""));
		new = (char *)malloc(sizeof(char) * (rear - front + 2));
		if (!new)
			return (NULL);
		ft_strlcpy(new, front, rear - front + 2);
	}
	return (new);
}
