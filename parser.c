/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:30:48 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/13 12:06:59 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		x_min(char *block)
{
	int	i;
	int	x_min;

	x_min = 5;
	i = 0;
	while (block[i])
	{
		if (block[i] == '#' && i % 5 == 0 && x_min > 0)
			x_min = 0;
		else if (block[i] == '#' && i % 5 == 1 && x_min > 1)
			x_min = 1;
		else if (block[i] == '#' && i % 5 == 2 && x_min > 2)
			x_min = 2;
		else if (block[i] == '#' && i % 5 == 3 && x_min > 3)
			x_min = 3;
		i++;
	}
	return (x_min);
}

static int		y_min(char *block)
{
	int	i;
	int	y_min;

	y_min = 0;
	i = 0;
	while (block[i])
	{
		if (block[i] == '#')
			return (y_min);
		if (block[i] == '\n')
			y_min++;
		i++;
	}
	return (-1);
}

static void		fill_pattern(t_shape *new_shape)
{
	int	y;
	int x;

	y = 0;
	x = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 4)
			new_shape->pattern[y][x++] = '.';
		new_shape->pattern[y++][x] = '\0';
	}
	new_shape->pattern[4][0] = '\0';
}

static t_shape	*ft_new_shape(int id, char *block)
{
	int		i;
	int		y;
	int		x;
	t_shape	*new_shape;

	if (!(new_shape = (t_shape*)malloc(sizeof(t_shape))))
		return (NULL);
	new_shape->id = 'A' + id;
	fill_pattern(new_shape);
	i = x_min(block) + y_min(block) * 5;
	y = 0;
	x = 0;
	while (i < 19)
	{
		if (block[i] == '\n')
		{
			x = 0;
			y++;
			i += x_min(block) + 1;
		}
		new_shape->pattern[y][x++] = block[i++];
	}
	return (new_shape);
}

int				parser(char **block, t_shape **shape)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (block[i])
	{
		shape[j++] = ft_new_shape(i, block[i]);
		i++;
	}
	shape[j] = NULL;
	return (1);
}
