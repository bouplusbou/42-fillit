/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:59:04 by bclaudio          #+#    #+#             */
/*   Updated: 2018/12/12 14:33:15 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**generate_map(int y, int x)
{
	char **map;

	if (!(map = (char **)malloc(sizeof(char *) * y + 1)))
		return (NULL);
	map[y--] = 0;
	while (y >= 0)
	{
		if (!(map[y] = ft_strnew(x)))
			return (NULL);
		ft_memset(map[y], 46, x);
		y--;
	}
	return (map);
}

void		print_map(char **map)
{
	while (*map)
		ft_putendl(*map++);
}

void	delete_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		ft_strdel(&map[i++]);
}
