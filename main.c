/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlabban <adlabban@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:38:13 by adlabban          #+#    #+#             */
/*   Updated: 2025/08/10 17:05:49 by adlabban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*str;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			printf("erreur ouverture");
			return (1);
		}
		str = get_next_line(fd);
		printf("%s", str);
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
}
