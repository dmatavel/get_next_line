/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:39:55 by dmatavel          #+#    #+#             */
/*   Updated: 2022/12/02 23:08:40 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif //BUFFER_SIZE

# define OPEN_MAX 256
# define _EOF 0
# define STATUS_ERROR -1

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		find_newline(char *s);

#endif //GET_NEXT_LINE
