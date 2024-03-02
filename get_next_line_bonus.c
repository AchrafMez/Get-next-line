/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:30:29 by amezioun          #+#    #+#             */
/*   Updated: 2024/02/29 20:04:37 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	ret;

	ret = 0;
	if (!s)
		return (-1);
	while (s[ret])
		ret++;
	return (ret);
}

char	*ft_read(int fd, char *sbuff, char *buffer)
{
	int	bytes_read;

	bytes_read = BUFFER_SIZE;
	if ((!sbuff && !buffer) || fd < 0)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(sbuff);
			free(buffer);
			buffer = NULL;
			sbuff = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		sbuff = ft_strjoin(sbuff, buffer);
		if (contains_nl(sbuff) == 1)
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (sbuff);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*sbuff[OPEN_MAX];
	char		*line;

	buffer = NULL;
	line = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(sbuff[fd]);
		sbuff[fd] = NULL;
		return (NULL);
	}
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	sbuff[fd] = ft_read(fd, sbuff[fd], buffer);
	if (!sbuff[fd])
		return (NULL);
	line = copy_until_nl(sbuff[fd]);
	sbuff[fd] = copy_after_nl(sbuff[fd]);
	return (line);
}
