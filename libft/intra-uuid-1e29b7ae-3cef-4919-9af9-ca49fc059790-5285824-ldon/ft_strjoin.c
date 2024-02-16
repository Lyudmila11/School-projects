/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:39:11 by ldon              #+#    #+#             */
/*   Updated: 2023/12/12 13:10:22 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*buffer;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	buffer = malloc(lens1 + lens2 + 1);
	if (buffer == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(buffer, s1, lens1 + 1);
	ft_strlcpy(&buffer[lens1], s2, (lens2 + 1));
	return (buffer);
}
