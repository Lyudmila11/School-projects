/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:49:11 by ldon              #+#    #+#             */
/*   Updated: 2023/11/21 14:08:13 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
	{
		return (0);
	}
	return (1);
}

/*
int	main(void)
{
	int	c;
	int	m;
	c = 'h';
	m = ft_isalpha(c);
	printf("%c %d\n", c, m);
	return(0);
}*/