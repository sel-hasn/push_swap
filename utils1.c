/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:59:52 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/09 15:22:06 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > (slen - start))
		len = slen - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < slen && s[start + i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	wordcount(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
		}
	}
	return (count);
}

char	**freeword(char **str, size_t idx)
{
	while (idx > 0)
	{
		free(str[idx - 1]);
		idx--;
	}
	free(str);
	return (NULL);
}

char	**mysplit(char **wd, char *st, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (st[j] && i < wordcount(st, c))
	{
		while (st[j] == c)
			j++;
		len = 0;
		while (st[j + len] != '\0' && st[j + len] != c)
			len++;
		wd[i] = ft_substr(st, j, len);
		if (!wd[i])
			return (free(st), freeword(wd, i));
		j = j + len;
		i++;
	}
	wd[i] = NULL;
	free(st);
	return (wd);
}

char	**ft_split(char *s, char c)
{
	char	**word;

	if (!s)
		return (NULL);
	word = (char **)malloc (sizeof(char *) * (wordcount(s, c) + 1));
	if (!word)
		return (NULL);
	return (mysplit(word, s, c));
}
