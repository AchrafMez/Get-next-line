/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:22:52 by amezioun          #+#    #+#             */
/*   Updated: 2024/02/09 21:32:10 by amezioun         ###   ########.fr       */
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
    return result;
}
char *ft_line(char *s, int start, int l7ed)
{
    int size = l7ed - start;
    // char *line = malloc(size + 1);
    char *line;
    int i = 0;
    if(!s)
        return NULL;
    if(start > l7ed)
        return NULL;
    while (start < l7ed)
    {
        line[i] = s[i];
        i++;
    }
    // line[size - 1] = '\n';
    // line[size] = '\0';
    return s;
}
char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
    char *line;
    int bytes_read = read(fd, buffer, 10);
    char *result = ft_strdup(buffer, bytes_read);
    int l7ed = ft_check(result);
    // line = ft_line(result, 1, l7ed);
    
    return result;
}

int main()
{
    int fd = open("file.txt", O_RDONLY);
    if(fd == -1)
        printf("fd error");
    printf("%s", get_next_line(fd));
    //get_next_line(fd);
    // get_next_line(fd);
}