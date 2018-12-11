#include "fillit.h"

void	move_vector(int *y, int *x, int map_size)
{
	if (*x == map_size - 1)
	{
		*x = 0;
		*y += 1;
	}
	else
		*x += 1;
}

int	fill_map(char **map, t_shape **shapes, int i, int map_size)
{
	int y;
	int x;

	y = 0;
	x = 0;
	if (!shapes[i])
		return (1);
	while (map[y] && map[y][x])
	{
		if (place(map, shapes[i], y, x))
		{
			if (fill_map(map, shapes, i + 1, map_size))
				return (1);
		}	
		clear_placement(map, shapes[i]->id);
		move_vector(&y, &x, map_size);
	}
	return (0);
}

char	**fillit(t_shape **shapes, int map_size)
{
	char **map;
	
	map = generate_map(map_size, map_size);
	while (!fill_map(map, shapes, 0, map_size))
	{
		map_size++;
		map = generate_map(map_size, map_size);
	}
	printf("Solution found.\n");
	return (map);
}
