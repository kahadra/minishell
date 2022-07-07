/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:07:13 by heha              #+#    #+#             */
/*   Updated: 2022/06/03 16:24:41 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

static bool	ft_gnl_init(char **store)
{
	*store = ft_strndup("", 0);
	return (*store != NULL);
}

static char	*ft_gnl_read(char **store, char *buf, ssize_t *rsize, int fd)
{
	char	*find;
	char	*new;

	while (true)
	{
		find = ft_strchr(*store, '\n');
		if (find)
			return (ft_strndup(*store, find - *store + 1));
		else
		{
			*rsize = read(fd, buf, BUFFER_SIZE);
			if (*rsize <= 0)
				return (NULL);
			buf[*rsize] = '\0';
			new = ft_strjoin(*store, buf);
			if (!new)
				return (NULL);
			free(*store);
			*store = new;
		}
	}
}

static char	*ft_gnl_update(char *store, char **line, ssize_t rsize)
{
	char	*remain;
	size_t	str_len;
	size_t	line_len;

	if (store)
	{
		str_len = ft_strlen(store);
		if (!(*line) && !rsize && str_len)
			*line = ft_strndup(store, str_len);
		if (*line)
		{
			line_len = ft_strlen(*line);
			remain = ft_strndup(store + line_len, str_len - line_len);
			if (!remain)
				return (NULL);
			free(store);
			return (remain);
		}
		if (*store == '\0' && rsize <= 0)
		{
			free(store);
			return (NULL);
		}
	}
	return (store);
}

static int	ft_gnl_result(char *store, ssize_t rsize)
{
	if (rsize < 0)
		return (-1);
	else if (!store)
		return (0);
	else
		return (1);
}

int	ft_get_next_line(int fd, char **line)
{
	int			ret;
	char		*buf;
	ssize_t		rsize;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!store && !ft_gnl_init(&store))
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	*line = ft_gnl_read(&store, buf, &rsize, fd);
	store = ft_gnl_update(store, line, rsize);
	ret = ft_gnl_result(store, rsize);
	free(buf);
	return (ret);
}
