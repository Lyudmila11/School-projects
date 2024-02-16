/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:32:45 by ldon              #+#    #+#             */
/*   Updated: 2023/11/10 19:13:29 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*ptr;
	size_t				i;

	ptr = s;
	i = 0;
	while (i != n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

/*
int	main(void)
{
	char ptr[20] = "are you there?";
	int c = '8';
	char *s = ft_memset(ptr, c, 5);
	printf("%s", s);
	return(0);
}*/
