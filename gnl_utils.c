/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:03:15 by amezioun          #+#    #+#             */
/*   Updated: 2024/02/09 21:40:02 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int ft_strlen(const char *s)
{
    int i = 0;
    if(!s)
        return 0;
    while (s[i])
        i++;
    return i;
}

// char *ft_strjoin(char const *s1, char const *s2)
// {
//     int i = 0;
//     int j = 0;
//     int size = 0;
//     if(!s1 && !s2)
//         return NULL;
//     size = ft_strlen(s1) + ft_strlen(s2);
//     char *result;
//     result = malloc(size + 1);
//     if(!result)
//         return NULL;   
//     while (s1 && s1[i] != '\0')
//     {
//         result[i] = s1[i];
//         i++;
//     }
//     while (s2 && s2[j] != '\0')
//     {
//         result[i + j] = s2[j];
//         j++;
//     }
//     result[i + j] = '\0';
//     return result;
// }

// char *ft_strdup(const char *s)
// {
//     int i = 0;
//     char *result;
//     if(!s)
//         return NULL;
//     result = malloc(ft_strlen(s) + 1);
//     if(!result)
//         return NULL;
//     while (s && s[i])
//     {
//         result[i] = s[i];
//         i++;
//     }
//     result[i] = '\0';
//     return result;
// }


// char *ft_substr(char const *s, unsigned int start, size_t len)
// {
//     int i = 0;
//     char *result;
//     int size = len - start;
//     if(!s)
//         return NULL;
//     result = malloc(size + 1);

//     if(!result)
//         return NULL;
//     while (s && s[i] != '\0' && i < size)
//     {
//         result[i] = s[start + i];
//         i++;
//     }
//      result[i] = '\0';
//      return result;
// }

// int main()
// {
    // char s[] = "";
    // char s2[] = "";
    // int c = 'o';
    // printf("%d", ft_strchr("achraf lostro", c));
    // printf("%s", ft_strdup(NULL));
    // printf("%s", ft_substr("achraf abdo youness", 5, 21));
// }


int ft_check(char *s, int fd)
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

int main()
{
    int fd = open("file.txt", O_RDONLY);
    if(fd == -1)
        printf("fd error");
    char *buffer;
    read(fd, buffer, 10);
    printf("%d\n", ft_check(buffer, fd));
    printf("%d\n", ft_check(buffer, fd));
    printf("%d\n", ft_check(buffer, fd));
    printf("%d\n", ft_check(buffer, fd));
    //get_next_line(fd);
    // get_next_line(fd);
}