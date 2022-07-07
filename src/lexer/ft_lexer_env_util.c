/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_env_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:16:14 by chpark            #+#    #+#             */
/*   Updated: 2022/07/06 14:17:02 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

char	*ft_envmap_malloc_value(char *value)
{
	int		i;
	char	*ret;

	value = ft_strchr(value, '=');
	if (value == NULL)
		return (NULL);
	ret = ft_malloc(sizeof(char) * (ft_strlen(++value) + 1));
	i = -1;
	while (value[++i] != '\0')
		ret[i] = value[i];
	ret[i] = '\0';
	return (ret);
}

char	*ft_envmap_get_value(t_queue *envmap, char *key)
{
	t_list	*head;
	char	*cur;
	char	*ret;
	int		i;
	int		j;

	i = -1;
	head = envmap->head->next;
	ret = NULL;
	while (++i < (int)envmap->size)
	{
		j = 0;
		cur = head->content;
		head = head->next;
		while (key[j] != '\0' && cur[j] != '\0' && cur[j] == key[j])
			j++;
		if ((cur[j] != '=' && cur[j] != '\0') || key[j] != '\0')
			continue ;
		return (ft_envmap_malloc_value(cur));
	}
	return (ret);
}
