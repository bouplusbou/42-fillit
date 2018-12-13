/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:42:58 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/13 12:00:22 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int c, char **v)
{
	int		fd;
	int		nbr_blocks;
	char	*block[27];
	t_shape	**shape;

	if (c == 2)
	{
		if ((fd = open(v[1], O_RDONLY)) == -1
				|| !reader(fd, block)
				|| !(nbr_blocks = check_error(block)))
		{
			ft_putendl("error");
			return (0);
		}
		if (!(shape = (t_shape**)malloc(sizeof(t_shape*) * (nbr_blocks + 1))))
			return (0);
		if (!parser(block, shape))
			return (0);
		fillit(shape, 2);
		del_struct(shape);
	}
	else
		ft_putendl("Usage: ./fillit <file>");
	return (c);
}
