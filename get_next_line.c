/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlabban <adlabban@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 18:57:40 by adlabban          #+#    #+#             */
/*   Updated: 2025/08/10 17:05:10 by adlabban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_find(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_init_stash(char *stash, char *buf)
{
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
		{
			free(buf);
			return (NULL);
		}
		stash[0] = '\0';
		return (stash);
	}
	return (stash);
}

char	*free_err(char **stash, char *buf)
{
	free(*stash);
	*stash = NULL;
	free(buf);
	return (NULL);
}

char	*ft_read(int fd, char *buf, char *stash)
{
	int		i;
	char	*tmp;

	i = 1;
	while (!line_find(stash) && i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (free_err(&stash, buf));
		buf[i] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		if (!stash || stash[0] == '\0')
			return (free_err(&stash, buf));
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*tmp;
	char		*line;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	stash = ft_init_stash(stash, buf);
	if (!stash)
		return (NULL);
	stash = ft_read(fd, buf, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	tmp = stash;
	stash = get_new_stash(tmp);
	if (stash && stash[0] == '\0')
	{
		free(stash);
		stash = (NULL);
	}
	free(tmp);
	free(buf);
	return (line);
}
