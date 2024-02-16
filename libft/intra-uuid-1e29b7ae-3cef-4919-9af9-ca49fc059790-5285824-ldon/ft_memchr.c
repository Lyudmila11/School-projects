/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:16:58 by ldon              #+#    #+#             */
/*   Updated: 2023/11/20 21:21:48 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cha;
	size_t			i;

	str = (unsigned char *)s;
	cha = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == cha)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
