/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:01:34 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/21 19:11:08 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"





void putmap(t_map *map)
{
	int i;
	int j;

	printf("x = %d\n", map->size_x);
	printf("y = %d\n", map->size_y);
	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x )
		{
			printf("%d",map->matrix[i][j]);
			printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}