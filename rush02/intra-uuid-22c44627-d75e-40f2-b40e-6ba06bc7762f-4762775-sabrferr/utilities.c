/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:46:16 by csharrie          #+#    #+#             */
/*   Updated: 2023/03/19 14:40:29 by csharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Return the number of characters in a string*/
int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*Check if a given char is numeric*/
int	is_numeric(char num)
{
	if (num >= '0' && num <= '9')
		return (1);
	return (0);
}


/*Given a number of digits and the first digit, return the 
 * corresponding multiple of 10, e.g. multiple_10(5, 4) == 5000*/
char	*multiple_10(char first_n, int n_digits)
{
	char	*multiple_10;
	int	i;

	multiple_10 = malloc(sizeof(char) * n_digits);
	multiple_10[0] = first_n;
	i = 1;
	while (i < n_digits)
		multiple_10[i++] = '0';
	return (multiple_10);
}

/*Take a string, and return a portion of that string according
 * to a given offset, and size of target string.*/
char	*ft_truncate(char *num, int offset, int n_digits)
{
	char	*truncated;
	int	i;

	truncated = malloc(sizeof(char) * n_digits);
	i = 0;
	while (i < n_digits)
	{
		truncated[i] = num[i + offset];
		i++;
	}
	return (truncated);
}
