/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:53:28 by nmoulin           #+#    #+#             */
/*   Updated: 2023/01/07 03:33:14 by nmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strndup(const char *s1, int len)
{
	char	*res;
	int		size;
	int		i;

	size = len;
	if (size == -1)
		size = ft_strlen(s1);
	res = malloc(size + 1);
	if (!res)
		return (res);
	i = -1;
	while (s1[++i] && i < size)
		res[i] = s1[i];
	res[i] = 0;
	return (res);
}

char	*newline_exist(char **line, int lastline)
{
	const char	*endl;
	char		*res;
	char		*tmp;

	if (!*line)
		return (*line);
	tmp = NULL;
	endl = ft_strchr(*line, '\n');
	if (endl && !lastline)
	{
		tmp = ft_strndup(endl + 1, -1);
		res = ft_strndup(*line, (endl - *line) + 1);
		free(*line);
		*line = tmp;
		return (res);
	}
	if (lastline && **line && !endl)
		tmp = ft_strndup(*line, -1);
	if (tmp || (*line && !**line))
	{
		free(*line);
		*line = NULL;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*res;
	char		buff;
	int			ret;

	if (fd < 3 && fd != 0)
		return (NULL);
	ret = 1;
	while (ret)
	{
		buff = malloc(sizeof(char)*(BUFFER_SIZE + 1));
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		buff[ret] = 0;
		ft_strjoin(&line, buff, ret);
		free(buff);
		res = newline_exist(&line, 0);
		if (res)
			return (res);
	}
	return (newline_exist(&line, 1));
}