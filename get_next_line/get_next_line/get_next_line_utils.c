/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:59:17 by ldon              #+#    #+#             */
/*   Updated: 2023/12/22 14:32:11 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
It counts the number of characters until the null terminator \0 is encountered.
Important when allocating memory to store joined string in ft_strjoin.
*/

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
Returns the lenght of source string
*/
char	*ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (dst);
}
/*
Allocates memory for the joined string and 
frees the memory of the first input string.
*/

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strlcpy(malloc(ft_strlen(s2) + 1), s2, ft_strlen(s2) + 1));
	else if (!s2)
		return (ft_strlcpy(malloc(ft_strlen(s1) + 1), s1, ft_strlen(s1) + 1));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	new_str = (char *)malloc(lens1 + lens2 + 1);
	if (new_str == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(new_str, s1, lens1 + 1);
	ft_strlcpy(&new_str[lens1], s2, lens2 + 1);
	return (new_str);
}
