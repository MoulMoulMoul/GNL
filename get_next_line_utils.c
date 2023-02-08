/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:53:28 by nmoulin           #+#    #+#             */
/*   Updated: 2023/01/07 03:33:14 by nmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (char) c)
		s++;
	if (*s == (char) c)
		return (s);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *buffer, char *str)
{
	char	*mstr;
	int		i;
	int		j;

	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	mstr = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(str) + 1));
	if (!mstr)
		return (NULL);
	i = -1;
	while (buffer[++i])
		mstr[i] = buffer[i];
	j = 0;
	while (str[j])
		mstr[i++] = str[j++];
	mstr[i] = '\0';
	free(buffer);
	return (mstr);
}