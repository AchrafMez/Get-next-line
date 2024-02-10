/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:22:52 by amezioun          #+#    #+#             */
/*   Updated: 2024/02/10 15:18:53 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 42

int ft_strlen(const char *s)
{
    int i = 0;
    if(!s)
        return 0;
    while (s[i])
        i++;
    return i;
}
int ft_check(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if(s[i] == '\n')
            return i;
        i++;
    }
    return i;   
}
char *ft_strdup(const char *s, int size)
{
    int i = 0;
    char *result;
    if(!s)
        return NULL;
    result = malloc(size + 1);
    if(!result)
        return NULL;
    while (s && s[i])
    {
        result[i] = s[i];
        i++;
    }
    result[i] = '\0';
    free(result);
    return result;
}
char *ft_line(char *s, int start, int l7ed)
{

    if(!s)
        return NULL;
    int i = 0;
    int size = l7ed - start;
    char *line = malloc(l7ed + 1);
    if(start > l7ed)
        return NULL;
    while (s && s[i] != '\0' && start < l7ed)
    {
        line[i] = s[i];
        i++;
    }
    line[size - 1] = '\n';
    line[size] = '\0';
    return s;
}



char *ft_substr(char const *s, unsigned int start, size_t len)
{
    int i = 0;
    char *result;
    int size = len - start;
    if(!s)
        return NULL;
    result = malloc(size + 2);
    if(!result)
        return NULL;
    while (s && s[i] != '\0' && i < size)
    {
        result[i] = s[start + i];
        i++;
    }
    result[i] = '\0';
    result[i + 1] = '\n';
    return result;
}

char *get_next_line(int fd)
{
    int i = 0;
    static char *s;
    char buffer[BUFFER_SIZE + 1];
    char *line;
    int bytes_read = read(fd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    // char *result = ft_strdup(buffer, bytes_read);
    line = malloc(bytes_read + 1);
    if(!line)
        return NULL;
    while(buffer[i] != '\0')
    {
        line[i] = buffer[i];
        i++;
    }
    int l7ed = ft_check(line);
    s = ft_substr(line, 0, l7ed);
    // printf("%d\n", bytes_read);
    return s;
}

int main()
{
    int fd = open("file.txt", O_RDONLY);
    if(fd == -1)
        printf("fd error");
    printf("%s", get_next_line(fd));
    // get_next_line(fd);
    // get_next_line(fd);
    printf("%s", get_next_line(fd));
}