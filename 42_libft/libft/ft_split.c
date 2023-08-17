/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:33:21 by phenriq2          #+#    #+#             */
/*   Updated: 2023/08/10 15:34:03 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	word;

	word = 0;
	while (*s)
	{
		if (*s != c)
		{
			word++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (word);
}

static void	ft_clear(char **words, int len)
{
	int	i;

	i = 0;
	if (words == NULL)
	{
		return ;
	}
	while (i < len)
	{
		if (words[i] != NULL)
		{
			free(words[i]);
			words[i] = NULL;
		}
		i++;
	}
}

static char	**ft_verify(char const *s, char c, char **s_string, int i)
{
	size_t	len_subs;

	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len_subs = ft_strlen(s);
			else
				len_subs = ft_strchr(s, c) - s;
			s_string[i] = ft_substr(s, 0, len_subs);
			if (!s_string[i])
			{
				ft_clear(s_string, i);
				free(s_string);
				return (0);
			}
			i++;
			s += len_subs;
		}
	}
	s_string[i] = NULL;
	return (s_string);
}

char	**ft_split(char const *s, char c)
{
	char	**s_string;

	s_string = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!s || !s_string)
		return (0);
	return (ft_verify(s, c, s_string, 0));
}
