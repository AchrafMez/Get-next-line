/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:24:44 by amezioun          #+#    #+#             */
/*   Updated: 2024/02/11 09:22:15 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
// #define BUFFER_SIZE 10
#endif

char *get_next_line(int fd);
int ft_strlen(const char* s);
void* ft_memset(unsigned char* dst, unsigned char c, int len);
char* ft_strdup(const char* s);
char *ft_strjoin(char *s1, char *s2);
int contains_nl(const char* s);
char* copy_until_nl(char* in);
char* copy_after_nl(char* in);
char* get_next_line(int fd);

#endif