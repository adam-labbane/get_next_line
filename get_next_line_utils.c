/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlabban <adlabban@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:24:15 by adlabban          #+#    #+#             */
/*   Updated: 2025/08/09 17:10:40 by adlabban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	lendst;

	i = 0;
	lendst = ft_strlen(dst);
	if (size <= lendst)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && lendst + i + 1 < size)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst+ ft_strlen(src));
}


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
		char	*str;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return NULL;
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s1, ft_strlen(s1));
	str[ft_strlen(s1)] = '\0';
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (str);
}

char *empty_stash(char *stash)
{
	int size;
	int i;
	char *new_stash;
	int j;

	j = 0;
	size = count_len(stash);
	i = size + 1;
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - size));
	if (!new_stash)
		return (NULL);
	while (i < ft_strlen(stash))
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	new_stash[j] = '\0';
	return (new_stash);
}
