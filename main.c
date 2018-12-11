/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:42:58 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/11 15:26:34 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

void	TEST_read_struct(t_shape *shape)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	while (i < 4)
	{
		printf("shape[%i].id: %c\n", i, shape[i].id);
		y = 0;
		while (y < 4) // je ne NULL termine pas shape[i].pattern[y], c'est ok pour toi ?
		{
			x = 0;
			while (shape[i].pattern[y][x])
			{	
				printf("shape[%i].pattern[%i][%i]: %c\n", i, y, x, shape[i].pattern[y][x]);
				x++;
			}
			y++;
		}
		i++;
	}
}

void	TEST_read_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("tab[%i]:\n%s\n", i, tab[i]);
		i++;
	}
}

int	main(int c, char **v)
{
	int		fd;
	char	*block[27];
	t_shape	shape[27];

	if (c != 2)
		ft_putendl("Usage: ./fillit file");
	if ((fd = open(v[1], O_RDONLY)) == -1)
	{
		ft_putendl("Error during opening");
		return (0);
	}
	if (!reader(fd, block))
	{
		ft_putendl("Error during parsing");
		return (0);
	}
	TEST_read_tab(block);
	if (!check_error(block))
	{
		ft_putendl("Error during check_error");
		return (0);
	}
	if (!parser(block, shape))
	{
		ft_putendl("Error during parsing");
		return (0);
	}
	TEST_read_struct(shape);
	return (c);
}
