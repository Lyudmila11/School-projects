/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:07:32 by ldon              #+#    #+#             */
/*   Updated: 2023/11/20 17:08:40 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		write(fd, s, ft_strlen(s));
		ft_putchar_fd('\n', fd);
	}	
}

/*
int main()
{
	ft_putstr_fd("durak", 1);
	return (0);
}*/
