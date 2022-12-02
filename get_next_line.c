/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:40:14 by dmatavel          #+#    #+#             */
/*   Updated: 2022/12/02 18:42:35 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *stock)
{
	char	*tmp;
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_bytes] = '\0';
		if (!stock)
		{
			stock = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
			stock = ft_strcpy(stock, tmp);
		}
		else
			stock = ft_strjoin(stock, tmp);
		if (find_newline(tmp))
		{
			free(tmp);
			break ;
		}
		free(tmp);
	}
	return (stock);
}

static char	*get_excess(char *stock)
{
	char	*excess;
	size_t	i;
	size_t	j;

	if (!stock)
	{	
		free(stock);
		return (NULL);
	}
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	excess = ft_calloc(ft_strlen(stock) - i + 1, sizeof(char));
	if (excess == NULL)
		return (NULL);
	i++;
	j = 0;
	while (stock[i])
		excess[j++] = stock[i++];
	excess[j] = '\0';
	free(stock);
	return (excess);
}

static char	*get_line(char *stock)
{
	char	*new_line;
	int		i;
	int		j;

	if (!stock)
	{
		free(stock);
		return (NULL);
	}
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	new_line = ft_calloc(i + 2, sizeof(char));
	if (new_line == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_line[j] = stock[j];
		j++;
	}
	if (stock[i] == '\n')
	{
		new_line[j] = '\n';
		new_line[j + 1] = '\0';
	}
	else
		new_line[j] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stock = read_file(fd, stock);
	line = get_line(stock);
	stock = get_excess(stock);
	return (line);
}

