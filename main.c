/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:42:58 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/10 15:00:30 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int c, char **v)
{
	int		fd;

	if (c != 2)
		ft_putendl("Usage: ./fillit file");
	if ((fd = open(v[1], O_RDONLY)) == -1)
	{
		ft_putendl("error in opening");
		return (0);
	}
	return (c);
}
