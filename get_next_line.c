/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchang <warchang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:47:36 by warchang          #+#    #+#             */
/*   Updated: 2020/11/24 18:11:47 by warchang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "/Users/warchang/Documents/new_lib/libft/libft.h"

int	get_next_line(int fd, char **line) /// 1, 0, -1
{
	char 	buf[10 + 1];
	int 	byte_was_read;
	char 	*p_n;
	int 	flag;
	static char *reminder;

	flag = 1;
	if (reminder)
		*line = ft_strdup(reminder);
	else
		*line = ft_strnew(1);
	while (flag && (byte_was_read = read(fd, buf, 10)))
	{
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			flag = 0;
			p_n++;
			reminder = ft_strdup(p_n);
		}

		*line = ft_strjoin(*line, buf);
	}
	return (0);
}


