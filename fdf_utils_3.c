/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:16:51 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/03 22:01:05 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define L_MAX 9223372036854775807

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
