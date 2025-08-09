/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlabban <adlabban@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:59:01 by adlabban          #+#    #+#             */
/*   Updated: 2025/08/09 17:19:57 by adlabban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_have_line(char *stash)
{
	int i;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int count_len(char *stash)
{
	int i;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char *get_line(char *stash)
{
	char *line;
	int i;
	int size;

	i = 0;
	size = count_len(stash);
	line = malloc(sizeof(char) * (size + 2));
	if (!line)
		return (NULL);
	while (i <= size)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *get_next_line(int fd)
{
	char *line;
	char *buf;
	static char *stash;
	int i;

	i = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	i = read(fd, buf, BUFFER_SIZE);
	if (i == -1)
		return (NULL);
	stash = ft_strjoin(stash, buf);
	while (!ft_have_line(stash) && i != 0 && i >= BUFFER_SIZE)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		stash = ft_strjoin(stash, buf);
	}
	line = get_line(stash);
	stash = empty_stash(stash);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	int fd1;
// 	int fd2;
// 	if (ac == 2)
// 	{
// 		fd1 = open(av[1], O_RDONLY);
// 		if (fd1 == -1)
// 			printf("Error ouverture");
// 		fd2 = open(av[1], O_RDONLY);
// 		if (fd2 == -1)
// 			printf("Error ouverture");

// 		printf("%s", get_next_line(fd1));
// 		close(fd1);
// 		close(fd2);

// 	}
// }
