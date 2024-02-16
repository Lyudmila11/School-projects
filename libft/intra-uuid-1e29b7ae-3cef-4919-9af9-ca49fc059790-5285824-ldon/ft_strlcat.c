/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:34:37 by ldon              #+#    #+#             */
/*   Updated: 2023/11/20 21:49:11 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	int		dlen;
	int		slen;

	i = 0;
	k = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	dlen = i;
	while (i + 1 < size && src[k] != '\0')
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	if (i < size)
		dst[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	slen = i;
	return (dlen + slen);
}
