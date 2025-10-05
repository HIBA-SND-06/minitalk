/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:51:25 by yopeng            #+#    #+#             */
/*   Updated: 2025/05/12 14:54:32 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char	const *s, char c)
{
	size_t	word_begin;
	size_t	count;

	word_begin = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !word_begin)
		{
			word_begin = 1;
			count++;
		}
		else if (*s == c)
			word_begin = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(char const *s, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*extract_word(char const **s_ptr, char c)
{
	char const	*start;
	size_t		len;
	char const	*s;

	s = *s_ptr;
	while (*s && *s == c)
		s++;
	start = s;
	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	*s_ptr = s;
	return (word_dup(start, len));
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	size_t		wordcount;
	size_t		i;

	if (!s)
		return (NULL);
	wordcount = count_word(s, c);
	split = malloc((wordcount + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (i < wordcount)
	{
		split[i] = extract_word(&s, c);
		if (!split[i])
		{
			while (i--)
				free(split[i]);
			free(split);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}
