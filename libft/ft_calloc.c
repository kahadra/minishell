/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:36:27 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 11:26:39 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;

	if (size && SIZE_MAX / size < count)
		return (NULL);
	new = (void *)malloc(size * count);
	if (!new)
		return (NULL);
	ft_bzero(new, size * count);
	return (new);
}
