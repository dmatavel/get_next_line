/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:39:37 by dmatavel          #+#    #+#             */
/*   Updated: 2022/12/02 18:45:00 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:34:10 by dmatavel          #+#    #+#             */
/*   Updated: 2022/12/02 17:24:22 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("quadrilha", O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		exit (-1);
	}
	i = 0;
	while (i++ < 12)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	close(fd);
	free(line);
	return (0);
}

