/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:33:59 by ldon              #+#    #+#             */
/*   Updated: 2023/11/20 22:00:47 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || \
			c == '\t' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	res;

	sign = 1;
	i = 0;
	res = 0;
	while (nptr && ft_isspace(nptr[i]))
		i++;
	if (nptr && nptr[i] == '-')
	{
		sign = sign * (-1);
	}
	if (nptr && (nptr[i] == '+' || nptr[i] == '-'))
		i++;
	while (nptr && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

/*
int	main()
{
	char *n = "  -2147483648";
	int	r;
	r = ft_atoi(n);
	printf("result %i", r);
	return(0);
}*/
