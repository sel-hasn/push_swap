/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:00:00 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/09 15:20:48 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s == NULL)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (dsize > 0)
	{
		while (src[i] != '\0' && dsize - 1 > i)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen(src));
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	i = ft_strlen(dst);
	j = 0;
	while (src[j] != '\0' && j + 1 < (size - i))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s = (char *)malloc(sizeof(char) *(len_s1 + len_s2 + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, len_s1 + 1);
	ft_strlcat(s, s2, len_s2 + len_s1 + 1);
	free(s1);
	return (s);
}
