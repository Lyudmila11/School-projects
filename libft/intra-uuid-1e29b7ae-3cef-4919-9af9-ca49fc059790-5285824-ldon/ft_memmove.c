/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:26:34 by ldon              #+#    #+#             */
/*   Updated: 2023/11/10 19:20:10 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;

	i = 0;
	d = dest;
	s = src;
	if (dest > src)
	{
		i = n - 1;
	}
	while (i < n)
	{
		d[i] = s[i];
		if (dest < src)
		{
			i++;
		}
		else
			--i;
	}
	return (dest);
}

/*
int	main(void)
{
	char d[15] = "memory?";
//char s[16] = "where are you?";
	ft_memmove(d, d + 1, 6);
	printf("%s", d);
}*/
