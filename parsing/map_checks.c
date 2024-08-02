/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:28:39 by aconti            #+#    #+#             */
/*   Updated: 2024/08/02 18:08:36 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_d_left(char **map, int x, int y, char player)
{
	int x1;
	int y1;

	y1 = y;
	x1 = x;
	while (map[y][x] == '0' && x > 0)
	{
		x--;
		y++;
	}
	if (map[y][x] != '1' && map[y][x] != player)
		return (0);	
	x = x1;
	y = y1;
	while (map[y][x] == '0' && x > 0 && x > 0)
	{
		x--;
		y--;
	}
	if (map[y][x] != '1' && map[y][x] != player)
		return (0);
	return (1);
}

int check_d_right(char **map, int x, int y, char player)
{
	int x1;
	int y1;

	y1 = y;
	x1 = x;
	while (map[y][x] == '0' && y > 0)
	{
		x++;
		y--;
	}
	if (map[y][x] != '1' && map[y][x] != player)
		return (0);	
	x = x1;
	y = y1;
	while (map[y][x] == '0')
	{
		x++;
		y++;
	}
	if (map[y][x] != '1' && map[y][x] != player)
		return (0);
	return (1);
}

int	check_zero(char **map, int x, int y, char player)
{
	int x1;
	int y1;

	y1 = y;
	x1 = x;
	while (map[y][x] == '0')
		x++;
	if (map[y][x] != '1' && map[y][x] != player)
		return (0);	
	x = x1;
	while (map[y][x] == '0' && x > 0)
		x--;
	if (map[y][x] != '1' && map[y][x] != player)
		return (0);
	x = x1;
	while (map[y][x] == '0')
		y++;
	if (map[y][x] != '1' && map[y][x] != player)
		return (0);
	y = y1;
	while (map[y][x] == '0' && y > 0)
		y--;
	if (map[y][x] != '1' && map[y][x] != player)
		return (0);	
	return (1);
}

int check_char(int c)
{
	if (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E'
		|| c == ' ' || c == '\n')
		return (1);
	return (0);
}

int	check_player(char **map, int x, int y, char *i)
{
	if (map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'W' || map[y][x] == 'E')
	{
		if (*i != 0)
			return (0);
		if ((map[y][x + 1] != '0' && map[y][x + 1] != '1')
			|| (map[y][x - 1] != '0' && map[y][x - 1] != '1')
			|| (map[y + 1][x] != '0' && map[y + 1][x] != '1')
			|| (map[y - 1][x] != '0' && map[y - 1][x] != '1')
			|| (map[y + 1][x + 1] != '0' && map[y + 1][x + 1] != '1')
			|| (map[y + 1][x - 1] != '0' && map[y + 1][x - 1] != '1')
			|| (map[y - 1][x + 1] != '0' && map[y - 1][x + 1] != '1')
			|| (map[y - 1][x - 1] != '0' && map[y - 1][x - 1] != '1'))
			return (0);
		(*i) = map[y][x];
	}
	return (1);
}

int check_map(char **matrix, t_data *data)
{
	int x;
	int y;
	char player;

	y = 0;
	player = 0;
	while(matrix[y])
	{
		x = 0;
		while(matrix[y][x])
		{
			if (!check_char(matrix[y][x]))
				return (0);
			if (!check_player(matrix, x, y, &player))
					return (0);
			x++;
		}
		y++;
	}
	data->player_dir = player;
	if (!check_map_continue(matrix, player))
		return (0);
	return (1);
}
