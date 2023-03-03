/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:54:29 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/03 22:01:27 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_is_negative(char	*str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	if (n % 2 != 0)
		return (-1);
	return (1);
}

int	ft_is_base(char	*str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '+' || str[i] == '-'
			|| (str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
	}
	return (1);
}

static char	*my_atoi(char	*str)
{
	if (str[0] != '0' && str[1] != 'x')
		ft_perror();
	return (str + 2);
}

int	ft_atoi_base(char	*str, char	*base)
{
	int		i;
	int		j;
	int		nb;
	char	*str2;

	if (ft_is_base(base) == 0)
		return (0);
	i = 0;
	nb = 0;
	str2 = my_atoi(str);
	while (str2[i])
	{
		j = -1;
		while (base[++j])
		{
			if (str2[i] == base[j])
				break ;
		}
		if (base[j] == 0)
			return (0);
		nb = ft_strlen(base) * nb + j;
		i++;
	}
	nb *= ft_is_negative(str);
	return (nb);
}
