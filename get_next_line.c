/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:12:39 by amezioun          #+#    #+#             */
/*   Updated: 2024/02/26 13:56:22 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

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

char	*ft_read(int fd, char *chi_7aja, char *buffer)
{
	int	bytes_read;

	bytes_read = BUFFER_SIZE;
	if ((!chi_7aja && !buffer) || fd < 0)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(chi_7aja);
			free(buffer);
			buffer = NULL;
			chi_7aja = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		chi_7aja = ft_strjoin(chi_7aja, buffer);
		if (contains_nl(chi_7aja) == 1)
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (chi_7aja);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*chi_7aja = NULL;
	char		*line;

	buffer = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(chi_7aja);
		chi_7aja = NULL;
		return (NULL);
	}
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	chi_7aja = ft_read(fd, chi_7aja, buffer);
	if (!chi_7aja)
		return (NULL);
	line = copy_until_nl(chi_7aja);
	chi_7aja = copy_after_nl(chi_7aja);
	return (line);
}

// int main() {

//     int fd = open("file.txt", O_RDONLY);
//     // int fd = STDIN_FILENO;
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));

//     return (0);
// }
