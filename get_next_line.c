/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:40:14 by dmatavel          #+#    #+#             */
/*   Updated: 2022/12/02 23:09:01 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*str_check(char *str);
static char	*read_file(int fd, char *stock);
static char	*get_line(char *stock);
static char	*get_excess(char *stock);

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd == STATUS_ERROR || fd > OPEN_MAX
		|| BUFFER_SIZE <= _EOF || read(fd, 0, 0) < 0)
		return (NULL);
	stock = read_file(fd, stock);
	line = get_line(stock);
	stock = get_excess(stock);
	return (line);
}

static char	*read_file(int fd, char *stock)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes > _EOF)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == STATUS_ERROR)
			return (NULL);
		buf[read_bytes] = '\0';
		if (!stock)
		{
			stock = malloc(BUFFER_SIZE + 1 * sizeof(char));
			stock = ft_strcpy(stock, buf);
		}
		else
			stock = ft_strjoin(stock, buf);
		if (find_newline(buf))
			break ;
	}
	return (stock);
}

static char	*get_line(char *stock)
{
	char	*new_line;
	int		i;
	int		j;

	stock = str_check(stock);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	new_line = malloc(i + 2 * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	j = -1;
	while (++j < i)
		new_line[j] = stock[j];
	if (stock[i] == '\n')
	{
		new_line[j] = '\n';
		new_line[j + 1] = '\0';
	}
	else
		new_line[j] = '\0';
	return (new_line);
}

static char	*get_excess(char *stock)
{
	char	*excess;
	size_t	i;
	size_t	j;

	stock = str_check(stock);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	excess = malloc(ft_strlen(stock) - i + 1 * sizeof(char));
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

static char	*str_check(char *str)
{
	if (!str)
	{	
		free(str);
		return (NULL);
	}
	return (str);
}
