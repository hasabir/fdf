/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:30:00 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/28 15:43:10 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define L_MAX 9223372036854775807

int	set_colors(t_map *map, int coordinate, char *arg, int n)
{
	if (n == 0)
	{
		if (coordinate == 0)
			return(16777215);
		else
			return (65280);
	}
	return (ft_atoi_base(arg, "0123456789ABCDEF"));
}

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
			{return (1);}
		i++;
	}
	return (-1);
}

void    ft_bzero(void   *s, size_t n)
{
        size_t  i;

        i = 0;
        while (i < n)
        {
                ((unsigned char *)s)[i] = 0;
                i++;
        }
}

void    *ft_calloc(size_t count, size_t size)
{
        void    *p;

        p = malloc(count * size);
        if (!p)
            return (0);
        ft_bzero (p, count * size);
        return (p);
}

void	ft_perror(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}

int	ft_conv_nbr(const char *str, int n)
{
	unsigned long int	i;
	unsigned long int	nb;

	i = 0;
	nb = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		if (n == 1 && nb >= L_MAX)
			return (-1);
		else if (n == -1 && nb >= (unsigned long )L_MAX + 1)
			return (0);
		i++;
	}
	return ((int)nb * n);
}

int	ft_atoi(const char *str)
{
	unsigned long int	i;
	int					n;

	i = 0;
	n = 1;
	// while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	// 	i++;
	if (str[i] == '-')
	{
		n = -n;
		i++;
	}
	else if (str[i] == '+' )
		i++;
	return (ft_conv_nbr(str + i, n));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if ((dst == 0 && src == 0) && (n == 0 || n != 0))
		return (0);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	// free (src);
	return (dst);
}

int	ft_strlenmap(const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] != ' ' && str[j] != '\n' && str[j])
			i++;
		while (str[j] != ' ' && str[j] != '\n' && str[j])
			j++;
		j++;
	}
	return (i);
}

