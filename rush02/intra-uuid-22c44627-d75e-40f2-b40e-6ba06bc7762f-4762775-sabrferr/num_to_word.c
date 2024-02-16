/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_word_COPY.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:46:33 by sabrferr          #+#    #+#             */
/*   Updated: 2023/03/19 17:45:53 by csharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	str_len(char *str);

int	is_numeric(char num);

char	*multiple_10(char first_n, int n_digits);

char	*ft_truncate(char *num, int offset, int n_digits);

/*reads dictionary, returning whole file as a string*/
char	*read_dict(void)
{
	int 	fd;
	char		*path;
	char		*buffer;
	char		*line;

	path = "numbers.dict";
	buffer = malloc(sizeof(char) * 1024);
	fd = open(path, O_RDONLY);
	read(fd, buffer, 1024);

	close(fd);
	return (buffer);
}

/* Given a 'key' and a line from the dictionary, return 1 if this
 * key is found. If this is not the right dictionary entry,
 * return 0 */
int	check_line(char *key, char *line)
{
	while (*key && *key == *line)
	{
		key++;
		line++;
	}
	if (is_numeric(*key) || is_numeric(*line))
		return (0);
	return (1);
}

/*Knowing that this key is in the dictionary, write the element
 * associated with the key.*/
void	write_element(char *key, char *line)
{
	while (*key == *line)
	{
		key++;
		line++;
	}
	while (*line == ' ' || *line == ':')
		line++;
	while (*line)
		write(1, line++, 1);
	write(1, " ", 1);
}

/*Search dictionary buffer line by line. If check_line(number, line) 
 * returns 1, execute write_element(number, line)*/
int	search_element(char *number,int write)
{
	char	*buffer;
	char	*line;
	int		i;
	int		j;
	
	buffer = read_dict();
 	while (*buffer)
	{
		i = 0;
		while (buffer[i] != '\n')
			i++;
		line = malloc(sizeof(char) * i);
		j = 0;
		while (j < i)
			line[j++] = *buffer++;
		if (check_line(number, line) == 1)
		{	
		 	if (write)
				write_element(number, line);
		 	free(line);
			return (1);
		}
		i++;
		buffer++;
	}
	free(line);
	return (0);
}	

/*MAKE IT ALL WORK. Take a string of digits and write out 
 * the number words.*/
void	num_to_words(char *num)
{
	while(str_len(num))
	{	
//		printf("n_digits = %i\n", n_digits);	
//		printf("\nnum = %s\n", num);
		if ((str_len(num) % 3 == 0) && (*num != '0'))
		{
/*two*/			search_element(ft_truncate(num, 0, 1), 1);
/*hundred*/		search_element(multiple_10('1', 3), 1);
		}
		if (str_len(num) % 3 == 2)
		{
			if (*num >= '2')
/*twenty*/			search_element(multiple_10(*num, 2), 1);
			else
/*thirteen*/			search_element(ft_truncate(num, 0, 2), 1);
		}
		if ((str_len(num) % 3 == 1) && (*num != '0'))
		{	
			if (!(search_element(ft_truncate(num, -1, 2), 0)))
			{
/*three*/			search_element(ft_truncate(num, 0, 1), 1);
			}
		}
		if (str_len(num) > 3)
/**/			search_element(multiple_10('1', str_len(num)), 1);
		num++;
	}
}

int	main(int argc, char **argv)
{
//	printf("CONTENTS OF DICTIONARY = %s", read_dict());
//	printf("\nResult = %i\n", search_element("100"));
	num_to_words(argv[1]);
//	num_to_words("3213221");
	return (0);
}
