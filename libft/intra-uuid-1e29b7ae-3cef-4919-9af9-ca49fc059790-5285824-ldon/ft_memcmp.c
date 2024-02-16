/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:48:58 by ldon              #+#    #+#             */
/*   Updated: 2023/11/14 13:55:24 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sor1;
	const unsigned char	*sor2;
	size_t				i;

	sor1 = s1;
	sor2 = s2;
	i = 0;
	while (i < n)
	{
		if (sor1[i] != sor2[i])
		{
			return (sor1[i] - sor2[i]);
		}
		i++;
	}
	return (0);
}
