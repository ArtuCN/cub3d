/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_continue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:21:19 by aconti            #+#    #+#             */
/*   Updated: 2024/10/07 19:17:21 by adonato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_door(char **map, int y, int x, char player)
{
	if (map[x + 1][y] == '0' || map[x + 1][y] == player)
	{
		if (map[x - 1][y] == '0'
			|| map[x][y + 1] == '0' || map[x][y - 1] == '0')
			return (1);
	}
	if (map[x - 1][y] == '0' || map[x - 1][y] == player)
	{
		if (map[x + 1][y] == '0'
			|| map[x][y + 1] == '0' || map[x][y - 1] == '0')
			return (1);
	}
	if (map[x][y + 1] == '0' || map[x][y + 1] == player)
	{
		if (map[x + 1][y] == '0'
			||  map[x - 1][y] == '0' || map[x][y - 1] == '0')
			return (1);
	}
	if (map[x][y - 1] == '0' || map[x][y - 1] == player)
	{
		if (map[x + 1][y] == '0'
			|| map[x - 1][y] == '0' || map[x][y + 1] == '0')
			return (1);
	}
	return (0);
}

int	check_char(int c)
{
	if (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E'
		|| c == ' ' || c == '\n' || c == 'D')
		return (1);
	return (0);
}

int	check_map_continue(char **matrix, char player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == '0')
			{
				if (!check_zero(matrix, x, y, player)
					|| !check_d_left(matrix, x, y, player)
					|| !check_d_right(matrix, x, y, player))
					return (0);
			}
			else if (matrix[y][x] == 'D')
			{
				if (!check_door(matrix, x, y, player))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
