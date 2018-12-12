/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:42:58 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/12 14:27:05 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_struct(t_shape *shape)
{
	int i;

	i = 0;
	printf("Structure %c:\n", shape->id);
	printf("Pattern:\n");
	while (shape->pattern[i])
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
	t_shape **array;

	if (c != 2)
		ft_putendl("Usage: ./fillit file");
	if ((fd = open(v[1], O_RDONLY)) == -1)
	{
		ft_putendl("error in opening");
		return (0);
	}
	print_map(fillit(array, ft_sqrt(fd * 4)));
	return (c);
}
