/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:35:05 by masantos          #+#    #+#             */
/*   Updated: 2025/08/04 16:35:05 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_stash(char **stash)
{
	if (stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*tmp;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free_stash(&stash));
		buffer[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		free (tmp);
	}
	line = get_line(stash);
	tmp = stash;
	stash = get_remainder(tmp);
	free(tmp);
	return (line);
}
