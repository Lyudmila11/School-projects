/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:13 by ldon              #+#    #+#             */
/*   Updated: 2023/11/20 22:28:45 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lenbig;
	size_t	lenl;
	size_t	i;
	size_t	j;

	lenbig = ft_strlen(big);
	lenl = ft_strlen(little);
	i = 0;
	if (lenl == 0)
	{
		return ((char *)big);
	}
	while ((i + lenl) <= (lenbig) && (i + lenl) <= len)
	{
		j = 0;
		while (little[j] == big[i + j] && j < lenl)
			j++;
		if (j == lenl)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
