/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:42:58 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/12 15:44:01 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_struct(t_shape *shape)
{
	int i;

	i = 0;
	printf("Structure %c:\n", shape->id);
	printf("Pattern:\n");
	while (shape->pattern[i][0])
		printf("%s\n", shape->pattern[i++]);
}

int		ft_sqrt(int nb)
{
	int i;
	int result;

	i = 1;
	result = 0;
	while (result <= nb)
	{
		result = i * i;
		i++;
	}
	return (i - 1);
}

int	main(int c, char **v)
{
	int		fd;
	int		nbr_blocks;
	char	*block[27];
	t_shape	**shape;

	if (c != 2)
		ft_putendl("Usage: ./fillit file");
	if ((fd = open(v[1], O_RDONLY)) == -1)
	{
		ft_putendl("Error during opening");
		return (0);
	}
	if (!reader(fd, block))
	{
		ft_putendl("Error during reading");
		return (0);
	}
	printf("Reader success\n");
	if (!(nbr_blocks = check_error(block)))
	{
		ft_putendl("Error during check_error");
		return (0);
	}
	printf("Nbr block = %i\n", nbr_blocks);
	if (!(shape = (t_shape**)malloc(sizeof(t_shape*) * (nbr_blocks + 1))))
	{
		ft_putendl("Error during mmaloc shape array");
		return (0);
	}
	shape[nbr_blocks] = NULL;
	if (!parser(block, shape))
	{
		ft_putendl("Error during parsing");
		return (0);
	}
	fd = 0;
	while (shape[fd])
		print_struct(shape[fd++]);
	print_map(fillit(shape, ft_sqrt(nbr_blocks * 4)));
	return (c);
}
