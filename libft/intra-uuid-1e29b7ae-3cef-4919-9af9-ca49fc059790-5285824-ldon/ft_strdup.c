/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:55:30 by ldon              #+#    #+#             */
/*   Updated: 2023/11/20 16:51:54 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buffer;
	size_t	lens;

	lens = ft_strlen(s);
	buffer = ft_calloc((lens + 1), 1);
	if (buffer == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(buffer, s, lens + 1);
	return (buffer);
}
