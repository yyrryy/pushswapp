/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:01:28 by aaliali           #+#    #+#             */
/*   Updated: 2025/12/30 17:19:11 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*buildingbuffer(char *oldbuffer, char *newbuffer)
{
	char	*holder;

	holder = ft_strjoin(oldbuffer, newbuffer);
	free(oldbuffer);
	return (holder);
}

char	*deletereadline(char *oldbuffer)
{
	int		i;
	int		j;
	char	*newbuffer;

	i = 0;
	while (oldbuffer[i] && oldbuffer[i] != '\n')
		i++;
	if (!oldbuffer[i])
	{
		newbuffer = malloc(1);
		newbuffer[0] = '\0';
		return (free(oldbuffer), newbuffer);
	}
	newbuffer = malloc((ft_strlen(oldbuffer) - i + 1));
	if (!newbuffer)
		return (free(oldbuffer), NULL);
	i++;
	j = 0;
	while (oldbuffer[i])
		newbuffer[j++] = oldbuffer[i++];
	newbuffer[j] = '\0';
	return (free(oldbuffer), newbuffer);
}

char	*getcurrentline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*readfromfile(int fd, char *oldbuffer)
{
	char	*newbuffer;
	int		byte_read;

	if (oldbuffer && ft_strchr(oldbuffer, '\n'))
		return (oldbuffer);
	newbuffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!newbuffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, newbuffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(newbuffer), NULL);
		newbuffer[byte_read] = '\0';
		oldbuffer = buildingbuffer(oldbuffer, newbuffer);
		if (ft_strchr(newbuffer, '\n'))
			break ;
	}
	return (free(newbuffer), oldbuffer);
}

char	*get_next_line(int fd)
{
	static char	*staticholder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	staticholder = readfromfile(fd, staticholder);
	if (!staticholder)
	{
		free(staticholder);
		staticholder = NULL;
		return (NULL);
	}
	line = getcurrentline(staticholder);
	if (!line)
	{
		free(staticholder);
		staticholder = NULL;
		return (NULL);
	}
	staticholder = deletereadline(staticholder);
	return (line);
}
