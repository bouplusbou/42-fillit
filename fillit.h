/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:44:41 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/10 17:45:55 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_shape
{
	char	id;
	int		placed;
	char	**pattern;
}				t_shape;

char	**generate_map(int y, int x);
void	print_map(char **map);
void	destroy_map(char **map);
int		place(char **map, t_shape *shape, int y, int x);
void	print_struct(t_shape *shape);

#endif
