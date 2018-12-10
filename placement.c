/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:13:21 by bclaudio          #+#    #+#             */
/*   Updated: 2018/12/10 17:45:51 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// Clear the spaces that as been changed is the shape can't be placed
int		clear_placement(char **map, char id)
{
	int y;
	int x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == id)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (0);
}

// Check if shape can be placed in map at index y/x
int		place(char **map, t_shape *shape, int y, int x)
{
	int sy;
	int sx;

	sy = 0;
	sx = 0;
	while (shape->pattern[sy])
	{
		sx = 0;
		while (shape->pattern[sy][sx])
		{
			if (shape->pattern[sy][sx] == '#')
			{
				if (!map[y + sy] || !map[y + sy][x + sx] || map[y + sy][x + sx] != '.')
					return (clear_placement(map, shape->id));
				else
					map[y +sy][x + sx] = shape->id;	
			}
			sx++;
		}
		sy++;
	}
	return (0);
}
