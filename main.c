/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:42:58 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/12 00:30:33 by alastri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_shape	*generate_shape(void)
{
	t_shape *shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	shape->id = 'A';
	shape->pattern = (char **)malloc(sizeof(char *) * 5);
	shape->pattern[4] = 0;
	shape->pattern[0] = ft_strdup("#...");
	shape->pattern[1] = ft_strdup("#...");
	shape->pattern[2] = ft_strdup("#...");
	shape->pattern[3] = ft_strdup("#...");
	return (shape);
}

t_shape	*generate_shape2(void)
{
	t_shape *shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	shape->id = 'B';
	shape->pattern = (char **)malloc(sizeof(char *) * 5);
	shape->pattern[4] = 0;
	shape->pattern[0] = ft_strdup("####");
	shape->pattern[1] = ft_strdup("....");
	shape->pattern[2] = ft_strdup("....");
	shape->pattern[3] = ft_strdup("....");
	return (shape);
}

t_shape	*generate_shape3(void)
{
	t_shape *shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	shape->id = 'C';
	shape->pattern = (char **)malloc(sizeof(char *) * 5);
	shape->pattern[4] = 0;
	shape->pattern[0] = ft_strdup("###.");
	shape->pattern[1] = ft_strdup("..#.");
	shape->pattern[2] = ft_strdup("....");
	shape->pattern[3] = ft_strdup("....");
	return (shape);
}

t_shape	*generate_shape4(void)
{
	t_shape *shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	shape->id = 'D';
	shape->pattern = (char **)malloc(sizeof(char *) * 5);
	shape->pattern[4] = 0;
	shape->pattern[0] = ft_strdup(".##.");
	shape->pattern[1] = ft_strdup("##..");
	shape->pattern[2] = ft_strdup("....");
	shape->pattern[3] = ft_strdup("....");
	return (shape);
}

t_shape	*generate_shape5(void)
{
	t_shape *shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	shape->id = 'E';
	shape->pattern = (char **)malloc(sizeof(char *) * 5);
	shape->pattern[4] = 0;
	shape->pattern[0] = ft_strdup("##..");
	shape->pattern[1] = ft_strdup("##..");
	shape->pattern[2] = ft_strdup("....");
	shape->pattern[3] = ft_strdup("....");
	return (shape);
}

t_shape	*generate_shape6(void)
{
	t_shape *shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	shape->id = 'F';
	shape->pattern = (char **)malloc(sizeof(char *) * 5);
	shape->pattern[4] = 0;
	shape->pattern[0] = ft_strdup("##..");
	shape->pattern[1] = ft_strdup(".##.");
	shape->pattern[2] = ft_strdup("....");
	shape->pattern[3] = ft_strdup("....");
	return (shape);
}

t_shape	*generate_shape7(void)
{
	t_shape *shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	shape->id = 'G';
	shape->pattern = (char **)malloc(sizeof(char *) * 5);
	shape->pattern[4] = 0;
	shape->pattern[0] = ft_strdup("##..");
	shape->pattern[1] = ft_strdup(".#..");
	shape->pattern[2] = ft_strdup(".#..");
	shape->pattern[3] = ft_strdup("....");
	return (shape);
}

t_shape	*generate_shape8(void)
{
	t_shape *shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	shape->id = 'H';
	shape->pattern = (char **)malloc(sizeof(char *) * 5);
	shape->pattern[4] = 0;
	shape->pattern[0] = ft_strdup("###.");
	shape->pattern[1] = ft_strdup(".#..");
	shape->pattern[2] = ft_strdup("....");
	shape->pattern[3] = ft_strdup("....");
	return (shape);
}

void	print_struct(t_shape *shape)
{
	int i;

	i = 0;
	printf("Structure %c:\n", shape->id);
	printf("Pattern:\n");
	while (shape->pattern[i])
		printf("%s\n", shape->pattern[i++]);
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
	array = (t_shape **)malloc(sizeof(t_shape *) * 9);
	array[8] = NULL;
	array[0] = generate_shape();
	array[1] = generate_shape2();
	array[2] = generate_shape3();
	array[3] = generate_shape4();
	array[4] = generate_shape5();
	array[5] = generate_shape6();
	array[6] = generate_shape7();
	array[7] = generate_shape8();
	fd = 0;
	while (array[fd])
		print_struct(array[fd++]);
	print_map(fillit(array, 2));
	return (c);
}
