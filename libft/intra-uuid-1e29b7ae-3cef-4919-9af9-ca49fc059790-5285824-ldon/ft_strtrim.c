/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:55:00 by ldon              #+#    #+#             */
/*   Updated: 2023/11/20 19:48:19 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_isset(char const *sor, char l)
{
	int	i;

	i = 0;
	while (sor[i] != '\0')
	{
		if (sor[i] == l)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*buffer;
	size_t	lens1;

	i = 0;
	lens1 = ft_strlen(s1);
	j = lens1 - 1;
	while (ft_isset(set, s1[i]) == 1)
		i++;
	while (ft_isset(set, s1[j]) == 1 && j > i)
		j--;
	buffer = malloc(j - i + 2);
	if (buffer == NULL)
		return (NULL);
	ft_strlcpy(buffer, &s1[i], (j - i + 2));
	return (buffer);
}

/*int main()
{
	char const *s = "abcdspogk";
	char const *set = "bcak";
	printf("result = %d", ft_strtrim(s, set));
	return(0);	
}*/
