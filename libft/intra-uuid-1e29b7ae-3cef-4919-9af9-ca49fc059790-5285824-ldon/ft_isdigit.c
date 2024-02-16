/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:06:41 by ldon              #+#    #+#             */
/*   Updated: 2023/11/21 14:07:47 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
	{
		return (1);
	}
	return (0);
}

/*
int	main(void)
{
	int	c;
	int	m;
	c = '8';
	m = ft_isdigit(c);
	printf("%c, %d\n",c, m);
	return(0);
} */
