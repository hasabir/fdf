/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:56:17 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/28 15:40:28 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(const char *str)
{
	int	i;
	
	if (!str)
		return(-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int		n;
	int		i;

	n = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (n);
	while (src[i] && i < (dstsize))
	{
		dst[i] = (char)src[i];
		i++;
	}
	dst[i] = '\0';
	return (n);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	p = (char *)malloc(len * sizeof (char));
	if (!p)
		return (0);
	ft_strlcpy(p, (char *)s1, len);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		a1;
	int		a2;
	int		i;
	int		j;

	if (!*s1)
	{
		free((char *)s1);
		return (ft_strdup(s2));
	}
	a1 = ft_strlen((char *)s1);
	a2 = ft_strlen((char *)s2);
	p = (char *)malloc((a1 + a2 + 1) * sizeof(char));
	if (!p)
		return (0);
	i = -1;
	while (++i < a1)
		p[i] = s1[i];
	j = -1;
	while (++j < a2)
	p[i++] = s2[j];
	p[i] = '\0';
	free ((char *)s1);
	return (p);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*p;
	int		i;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return (0);
	p = (char *)malloc((len + 2) * sizeof(char));
	if (!p)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		p[i] = s[start];
		start++;
	}
	p[i] = '\0';
	free ((char *)s);
	return (p);
}
