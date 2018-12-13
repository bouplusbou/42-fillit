/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:49:16 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/13 11:56:32 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_touch(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i < 18 && str[i + 1] == '#')
				count++;
			if (i > 0 && str[i - 1] == '#')
				count++;
			if (i > 4 && str[i - 5] == '#')
				count++;
			if (i < 15 && str[i + 5] == '#')
				count++;
		}
		i++;
	}
	if (count != 6 && count != 8)
		return (0);
	return (1);
}

static int	check_block(char *str)
{
	int letter;
	int piece;

	letter = 0;
	piece = 0;
	while (*str)
	{
		if (*str != '#' && *str != '.' && *str != '\n')
			return (0);
		else
			letter++;
		if (*str == '#')
			piece++;
		if (*str == '\n' && letter % 5 != 0)
			return (0);
		str++;
	}
	if (letter != 20 || piece != 4)
		return (0);
	return (1);
}

int			check_error(char **block)
{
	int i;

	i = 0;
	while (block[i])
	{
		if (!check_block(block[i]))
			return (0);
		if (!check_touch(block[i]))
			return (0);
		i++;
	}
	return (i);
}
