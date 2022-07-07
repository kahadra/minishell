/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:37:13 by heha              #+#    #+#             */
/*   Updated: 2022/07/03 21:24:38 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tblclear(char ***tbl)
{
	char	**cp;

	if (*tbl)
	{
		cp = *tbl;
		while (*cp)
			free(*cp++);
		free(*tbl);
		*tbl = NULL;
	}
}

int	ft_gnl_without_newline(int fd, char **line)
{
	int		ret;
	size_t	len;

	ret = ft_get_next_line(fd, line);
	if (ret <= 0)
		return (ret);
	len = 0;
	if (*line)
		len = ft_strlen(*line);
	if (len && (*line)[len - 1] == '\n')
		(*line)[len - 1] = '\0';
	return (ret);
}
