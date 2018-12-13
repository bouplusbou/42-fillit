/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:44:41 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/13 12:04:46 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

typedef struct	s_shape
{
	char	id;
	char	pattern[5][5];
}				t_shape;

char			**generate_map(int y, int x);
void			print_map(char **map);
void			delete_map(char **map);
int				place(char **map, t_shape *shape, int y, int x);
void			print_struct(t_shape *shape);
int				fillit(t_shape **shapes, int map_size);
int				clear_placement(char **map, char id);
char			**reader(int fd, char **block);
int				check_error(char **block);
int				parser(char **block, t_shape **shape);
void			del_struct(t_shape **shape);

#endif
