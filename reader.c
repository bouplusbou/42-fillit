/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:44:51 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/13 12:08:34 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**reader(int fd, char **block)
{
	int			rd;
	int			i;
	char		*tmp;

	rd = 1;
	i = 0;
	while (rd != 0)
	{
		if (!(block[i] = ft_strnew(20))
				|| (rd = read(fd, block[i], 20)) < 0
				|| !(tmp = ft_strnew(1))
				|| (rd = read(fd, tmp, 1)) < 0
				|| (i > 25))
			return (NULL);
		ft_strdel(&tmp);
		i++;
	}
	block[i] = NULL;
	return (block);
}
