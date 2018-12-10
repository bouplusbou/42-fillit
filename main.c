/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:42:58 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/10 15:40:12 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

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

	if (c != 2)
		ft_putendl("Usage: ./fillit file");
	if ((fd = open(v[1], O_RDONLY)) == -1)
	{
		ft_putendl("error during opening");
		return (0);
	}
	if (!parser(fd, block))
	{
		ft_putendl("error during parsing");
		return (0);
	}
	TEST_read_tab(block);
	return (c);
}
