/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:41:09 by heha              #+#    #+#             */
/*   Updated: 2022/04/15 20:19:10 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_tblsize(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s == '\0')
			break ;
		size++;
		while (*s && (*s != c))
			s++;
	}
	return (size);
}

static void	ft_tblclear(char **tbl)
{
	char	**cp;

	cp = tbl;
	while (*cp)
	{
		free(*cp);
		cp++;
	}
	free(tbl);
	tbl = NULL;
}

static char	**ft_split_sub(char **tbl, char const *s, char c)
{
	char		**cp;
	char const	*begin;

	cp = tbl;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s == '\0')
			break ;
		begin = s;
		while (*s && (*s != c))
			s++;
		*cp = (char *)malloc(sizeof(char) * (s - begin + 1));
		if (!(*cp))
		{
			ft_tblclear(tbl);
			return (NULL);
		}
		ft_strlcpy(*cp, begin, s - begin + 1);
		cp++;
	}
	*cp = NULL;
	return (tbl);
}

char	**ft_split(char const *s, char c)
{
	char	**tbl;
	size_t	size;

	tbl = NULL;
	if (s)
	{
		size = ft_tblsize(s, c);
		tbl = (char **)malloc(sizeof(char *) * (size + 1));
		if (!tbl)
			return (NULL);
		tbl = ft_split_sub(tbl, s, c);
		if (!tbl)
			return (NULL);
	}
	return (tbl);
}
