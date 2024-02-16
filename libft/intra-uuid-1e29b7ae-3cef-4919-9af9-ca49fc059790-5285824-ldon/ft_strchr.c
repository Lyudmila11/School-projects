/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:26:56 by ldon              #+#    #+#             */
/*   Updated: 2023/11/13 15:48:13 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cha;	

	cha = c;
	i = 0;
	while (cha != s[i] && s[i] != '\0')
	{
		i++;
	}
	if (cha == s[i])
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
