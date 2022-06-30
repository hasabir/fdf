/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:40:18 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/28 15:39:27 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "fdf.h"

#define BUFFER_SIZE 1

char	*my_strchr(char *s, int c)
{
	unsigned char	*ss;
	unsigned int	i;
	unsigned int	len;

	if (!s)
		return (NULL);
	ss = (unsigned char *)s;
	i = 0;
	len = 0;
	while (ss[i])
	{
		if (ss[i] == (unsigned char)c)
		{
			len = ft_strlen((char *)ss) - i;
			return (ft_substr(s, i + 1, len));
		}
		i++;
	}
	free (s);
	return (0);
}

int	ft_check_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_read(char *stock, int fd)
{
	int		i;
	char	*buf;

	i = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	while (ft_check_newline(stock) == 0 && i)
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buf[i] = '\0';
		stock = ft_strjoin(stock, buf);
	}
	free (buf);
	return (stock);
}

char	*ft_read_line(char *stock)
{
	int		i;
	char	*line;

	i = 0;
	if (!stock)
		return (NULL);
	while (stock[i] != '\n' && stock[i])
		i++;
	if (stock[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(line, stock, i);
	line[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (0);
	if (!stock)
	{
		stock = (char *)malloc(sizeof(char) * 1);
		*stock = '\0';
	}
	stock = ft_read(stock, fd);
	if (!*stock)
	{
		free (stock);
		stock = NULL;
		return (NULL);
	}
	buf = ft_read_line(stock);
	stock = my_strchr(stock, '\n');
	return (buf);
}
