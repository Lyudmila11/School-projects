/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:45:36 by csharrie          #+#    #+#             */
/*   Updated: 2023/03/19 17:06:52 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

char	*read_dict(void);

void	num_to_words(char *num);

void	print_error()
{
	write (1, "Error\n", 7);
}

void	print_dict_error()
{
	write (1, "Dict Error\n", 12);
}

int	ft_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*dict;
	char	*number;

	dict = "numbers.dict";
	if (argc > 3 || argc <= 1)
	{
//		write error message
		print_error();
		return (-1);
	}
	if (argc == 2)
		number = argv[1];
		num_to_words(number);
	if (argc == 3)
	{
		dict = argv[1];
		number = argv[2];
		num_to_words(number);
	}

	if (ft_numeric(number) == 0)
	{
//		write error message
		print_error();
		return (-1);
	}
	if (read_dict() == NULL)
	{
		print_dict_error();
		return (-1);
	}
//	num_to_words(number);
	return (0);
}
