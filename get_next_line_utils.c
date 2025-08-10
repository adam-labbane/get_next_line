/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlabban <adlabban@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:10:47 by adlabban          #+#    #+#             */
/*   Updated: 2025/08/10 16:15:55 by adlabban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *stash, char *buf)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] != '\0')
	{
		str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buf[j] != '\0')
	{
		str[i] = buf[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	get_len_line(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;
	int		size;

	if (!line_find(stash))
		size = ft_strlen(stash);
	else
		size = get_len_line(stash);
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < size)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_new_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		size;
	int		j;

	size = ft_strlen(stash) - get_len_line(stash);
	new_stash = malloc(sizeof(char) * (size + 1));
	if (!new_stash)
		return (NULL);
	i = 0;
	j = get_len_line(stash);
	while (i < size)
	{
		new_stash[i] = stash[j + i];
		i++;
	}
	new_stash[i] = '\0';
	return (new_stash);
}
