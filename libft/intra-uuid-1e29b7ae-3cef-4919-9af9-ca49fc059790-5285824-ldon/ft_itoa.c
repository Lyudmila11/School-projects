/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:42:17 by ldon              #+#    #+#             */
/*   Updated: 2023/11/20 16:46:00 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_count_digits(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_convert(char *buffer, int n)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (n == 0)
		buffer[0] = '0';
	if (n < 0)
		sign = -1;
	while (n != 0)
	{
		buffer[i] = n % 10 * sign + '0';
		n = n / 10;
		i++;
	}
	if (sign == -1)
		buffer[i] = '-';
}

static void	ft_reverse(char *buffer, size_t sz)
{
	int		l;
	int		r;
	char	c;

	l = 0;
	r = sz - 1;
	while (l < r)
	{
		c = buffer[l];
		buffer[l] = buffer[r];
		buffer[r] = c;
		l++;
		r--;
	}
}

char	*ft_itoa(int n)
{
	size_t	num;
	char	*buffer;

	num = ft_count_digits(n);
	buffer = malloc(num + 1);
	if (buffer == NULL)
		return (buffer);
	ft_convert(buffer, n);
	ft_reverse (buffer, num);
	buffer[num] = '\0';
	return (buffer);
}

/*int	main()
{
	char *s;
	s = ft_itoa(INT_MIN);
	printf("result = %s\n", s);
	return(0);
}*/
