/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:28:25 by ldon              #+#    #+#             */
/*   Updated: 2023/12/22 14:52:16 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
Checks if a newline character is present in a string.
Returns 1 if a newline character is found, 0 otherwise.
*/
int	ft_has_newline(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
Helper function to extract a line from the buffer.
*/
char	*ft_extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/*
Helper function to read a line from the file descriptor
*/

char	*ft_read_line(int fd, char *remain)
{
	int		bytes_read;
	char	*buffer;
	char	*temp;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (!ft_has_newline(remain) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = remain;
		remain = ft_strjoin(remain, buffer);
		free(temp);
	}
	free (buffer);
	return (remain);
}

/*
Helper function to update the remaining content after a newline character.
*/
char	*update_after_newline(char *str)
{
	int			i;
	int			j;
	char		*remain;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0' || (str[i] == '\n' && str[i + 1] == '\0'))
	{
		free(str);
		return (NULL);
	}
	remain = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (remain == NULL)
		return (NULL);
	i++;
	while (str[i] != '\0')
		remain[j++] = str[i++];
	remain[j] = '\0';
	free (str);
	return (remain);
}

/*
Reads the next line from the given file descriptor.
Uses a static variable join_content to keep track of the remaining content.
*/
char	*get_next_line(int fd)
{
	static char	*join_content = NULL;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	join_content = ft_read_line(fd, join_content);
	if (join_content == NULL)
		return (NULL);
	line = ft_extract_line(join_content);
	join_content = update_after_newline(join_content);
	return (line);
}
/*
#include <fcntl.h>
int main(void)
{
	char	*line;
	int		fd;
	
	fd = open("hello.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line = %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
*/
