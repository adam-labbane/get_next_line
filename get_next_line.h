/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlabban <adlabban@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:24:27 by adlabban          #+#    #+#             */
/*   Updated: 2025/08/09 17:13:50 by adlabban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GCL_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>

int		count_len(char *stash);
char	*get_next_line(int fd);
char	*empty_stash(char *stash);
char	*ft_strjoin(char *s1, char *s2);



#endif
