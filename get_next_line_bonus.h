/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:29:59 by amezioun          #+#    #+#             */
/*   Updated: 2024/02/29 20:04:37 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_read(int fd, char *sbuff, char *buffer);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		contains_nl(char *sbuff);
char	*copy_until_nl(char *sbuff);
char	*copy_after_nl(char *in);

#endif