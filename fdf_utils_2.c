/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:16:24 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/06 18:40:50 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ss;

	ss = (unsigned char *)s;
	while (*ss)
	{
		if (*ss == (unsigned char)c)
		{
			return ((char *)ss);
		}
		ss++;
	}
	if (c == 0)
		return ((char *)ss);
	return (0);
}

int	ft_strnstr(const char *s1, const char *s2, int len)
{
	int	i;
	int	j;

	i = 0;
	if (!s1 && s2[i] == 0)
		return (-1);
	if (s1[i] == 0 && s2[i] == 0)
		return (-1);
	if (len <= 0)
		return (-1);
	if (!s1)
		return (-1);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] && s2[j] && s2[j] == s1[i + j]
			&& i + j < len)
			j++;
		if (s2[j] == 0)
			return (1);
		i++;
	}
	return (-1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_malloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		ft_perror ();
	return (p);
}
