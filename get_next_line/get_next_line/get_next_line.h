/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:36:35 by ldon              #+#    #+#             */
/*   Updated: 2023/12/22 14:30:14 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_has_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_line(int fd, char *remain);
char	*update_after_newline(char *str);
char	*get_next_line(int fd);
char	*ft_extract_line(char *buffer);

#endif
