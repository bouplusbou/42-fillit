/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:13:21 by bclaudio          #+#    #+#             */
/*   Updated: 2018/12/12 18:48:27 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		place(char **map, t_shape *shape, int y, int x)
{
	int sy;
	int sx;

	sy = 0;
	sx = 0;
	while (shape->pattern[sy][0])
	{
		sx = 0;
		while (shape->pattern[sy][sx])
		{
			if (shape->pattern[sy][sx] == '#')
			{
				if (!map[y + sy] || !map[y + sy][x + sx]
						|| map[y + sy][x + sx] != '.')
					return (0);
				else
					map[y + sy][x + sx] = shape->id;
			}
			sx++;
		}
		sy++;
	}
	return (1);
}
