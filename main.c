/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:42:58 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/10 17:52:22 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_shape	*generate_shape(void)
{
	t_shape *shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	shape->id = 'A';
	shape->placed = 0;
	shape->pattern = (char **)malloc(sizeof(char *) * 5);
	shape->pattern[4] = 0;
	shape->pattern[0] = ft_strdup("##..");
	shape->pattern[1] = ft_strdup("##..");
	shape->pattern[2] = ft_strdup("....");
	shape->pattern[3] = ft_strdup("....");
	return (shape);
}

void	print_struct(t_shape *shape)
{
	int i;

	i = 0;
	printf("Structure %c:\n", shape->id);
	printf("Placed = %i\n", shape->placed);
	printf("Pattern:\n");
	while (shape->pattern[i])
		printf("%s\n", shape->pattern[i++]);
}

int	main(int c, char **v)
{
	int		fd;
	t_shape *shape;
	char	**map;

	if (c != 2)
		ft_putendl("Usage: ./fillit file");
	if ((fd = open(v[1], O_RDONLY)) == -1)
	{
		ft_putendl("error in opening");
		return (0);
	}
	shape = generate_shape();
	print_struct(shape);
	map = generate_map(ft_atoi(v[2]), ft_atoi(v[3]));
	print_map(map);
	place(map, shape, ft_atoi(v[4]), ft_atoi(v[5]));
	print_map(map);
	return (c);
}
