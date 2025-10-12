/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:35:57 by masantos          #+#    #+#             */
/*   Updated: 2025/08/04 16:35:57 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	idx_a;
	size_t	idx_b;
	char	*s_join;

	if (!s1 && !s2)
		return (NULL);
	idx_a = 0;
	idx_b = 0;
	s_join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s_join)
		return (NULL);
	if (s1)
	{
		while (s1[idx_a])
			s_join[idx_b++] = s1[idx_a++];
	}
	idx_a = 0;
	if (s2)
	{
		while (s2[idx_a])
			s_join[idx_b++] = s2[idx_a++];
	}
	s_join[idx_b] = '\0';
	return (s_join);
}

char	*get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || stash[i] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash [i];
		i++;
	}
	if (stash[i] == '\n')
		line[i] = stash[i];
	line[++i] = '\0';
	return (line);
}

char	*get_remainder(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!stash || stash[i] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (NULL);
	i++;
	while (stash[i + j])
		j++;
	line = (char *)malloc(sizeof(char) * (j + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (stash[i])
		line[j++] = stash[i++];
	line[j] = '\0';
	return (line);
}
