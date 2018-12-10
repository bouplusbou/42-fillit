/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:49:16 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/10 15:57:49 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

static int	check_block(char *str)
{
	int letter;
	int piece;

	letter = 0;
	piece = 0;
	ft_putstr(str);
	while (*str)
	{
		if (*str != '#' && *str != '.' && *str != '\n')// Check validité des char (3)
		{
			ft_putendl("Wrong char in block.");
			return (0);
		}
		else
			letter++;
		if (*str == '#')
			piece++;
		if (*str == '\n' && letter % 5 != 0) // Check des la taille des lignes (1) et des multi newline (5)
		{
			ft_putendl("Wrong size of line.");
			return (0);
		}
		str++;
	}
	if (letter != 20 || piece != 4)// Check du nombre total de char (6), de ligne (2), et de '#' (4)
	{
		ft_putendl("Wrong number of letters/pieces");
		printf("Letter: %i. Piece: %i\n", letter, piece);
		return (0);
	}
	return (1);
}

int	check_error(char **block)
{
	int i;

	i = 0;
	while (block[i])
	{
		if (!check_block(block[i]))
		{
			printf("Error in bloc %i.\n", i);
			return (0);
		}
		printf("Bloc %i is valid.\n", i);
		i++;
	}
	if (!i)
		return (0);
	return (i);
}
