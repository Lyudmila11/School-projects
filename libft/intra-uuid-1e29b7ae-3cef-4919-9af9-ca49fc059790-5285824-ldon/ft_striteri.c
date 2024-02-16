/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:59:47 by ldon              #+#    #+#             */
/*   Updated: 2023/11/20 17:01:47 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void	ft_fun(unsigned int n, char* s)
{
	*s = 'h';
	printf("n = %d, s = %c\n", n, *s);
}

int main()
{
	char str[]= "ghfjifjkd";
	ft_striteri(str, ft_fun);
	
	printf("result = %s \n", str );
	return (0);
}*/
