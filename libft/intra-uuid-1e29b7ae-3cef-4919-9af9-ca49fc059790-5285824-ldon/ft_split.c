/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:24:19 by ldon              #+#    #+#             */
/*   Updated: 2023/11/20 15:49:37 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_alloc_memory(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (ft_calloc(sizeof(char *), (word + 1)));
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	rind;
	char	**res;

	res = ft_alloc_memory(s, c);
	if (res == NULL)
		return (NULL);
	i = 0;
	rind = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (i == j)
			return (res);
		res[rind] = ft_calloc(j - i + 1, 1);
		ft_strlcpy(res[rind], &s[i], j - i + 1);
		i = j;
		rind++;
	}
	return (res);
}

/*int	main()
{
	char	*s;
	char	c;
	//s = "    hell    there  anyone  sun // 'hi l' , oi  ";
	s = "        ";
	c = ' ';
	char **ret = ft_split(s,c);
	char **p =  ret;
	while (*p != NULL)
	{
		printf("result = %s\n", *p);
		p++;
	}
	return (0);
}*/
