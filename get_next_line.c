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

char	*fill_buffer(char *bufferleft, int fd)
{
	char	*temp;
	int		reader;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	reader = 1;
	while (reader != 0 && !ft_strchr(bufferleft, '\n'))
	{
		reader = read(fd, temp, BUFFER_SIZE);
		if (reader < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[reader] = 0;
		bufferleft = ft_strjoin(bufferleft, temp);
	}
	free(temp);
	return (bufferleft);
}

char	*cut_line(char *bufferleft)
{
	int		i;
	char	*newline;

	i = 0;
	if (!bufferleft[i])
		return (NULL);
	newline = malloc(sizeof(char *) * (count_line(bufferleft) + 2));
	if (!newline)
		return (NULL);
	while (bufferleft[i] && bufferleft[i] != '\n')
	{
		newline[i] = bufferleft[i];
		i++;
	}
	if (bufferleft[i] == '\n')
		newline[i++] = '\n';
	newline[i] = 0;
	return (newline);
}

char	*new_buff(char *bufferleft)
{
	int		i;
	int		j;
	char	*newbuff;

	i = 0;
	j = 0;
	while (bufferleft[i] && bufferleft[i] != '\n')
		i++;
	if (!bufferleft[i])
	{
		free(bufferleft);
		bufferleft = NULL;
		return (NULL);
	}
	newbuff = malloc(sizeof(char *) * (ft_strlen(bufferleft) - i + 1));
	if (!newbuff)
		return (NULL);
	while (bufferleft[i])
		newbuff[j++] = bufferleft[++i];
	newbuff[j] = 0;
	free(bufferleft);
	return (newbuff);
}

char	*get_next_line(int fd)
{
	static char	*bufferleft;
	char		*line;

    if (BUFFER_SIZE < 0 || fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	bufferleft = fill_buffer(bufferleft, fd);
	if (bufferleft == NULL)
	{
		free(bufferleft);
		return (NULL);
	}
	line = cut_line(bufferleft);
	bufferleft = new_buff(bufferleft);
	return (line);
}