/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:24:44 by amezioun          #+#    #+#             */
/*   Updated: 2024/02/17 20:33:28 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 99999
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

char* get_next_line(int fd);
int ft_strlen(const char* s);
char* ft_strdup(const char* s);
char *ft_strjoin(char *s1, char *s2);
int contains_nl(const char* s);
char* copy_until_nl(char* in);
char* copy_after_nl(char* in);

#endif