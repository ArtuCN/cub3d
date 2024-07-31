/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:28:39 by aconti            #+#    #+#             */
/*   Updated: 2024/07/31 17:29:07 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_d_left(char **map, int x, int y)
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
	if (map[y][x] != '1')
		return (0);	
	x = x1;
	y = y1;
	while (map[y][x] == '0' && x > 0 && x > 0)
	{
		x--;
		y--;
	}
	if (map[y][x] != '1')
		return (0);
	return (1);
}

int check_d_right(char **map, int x, int y)
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
	if (map[y][x] != '1')
		return (0);	
	x = x1;
	y = y1;
	while (map[y][x] == '0')
	{
		x++;
		y++;
	}
	if (map[y][x] != '1')
		return (0);
	return (1);
}

int	check_zero(char **map, int x, int y)
{
	int x1;
	int y1;

	y1 = y;
	x1 = x;
	while (map[y][x] == '0')
		x++;
	if (map[y][x] != '1')
		return (0);	
	x = x1;
	while (map[y][x] == '0' && x > 0)
		x--;
	if (map[y][x] != '1')
		return (0);
	x = x1;
	while (map[y][x] == '0')
		y++;
	if (map[y][x] != '1')
		return (0);
	y = y1;
	while (map[y][x] == '0' && y > 0)
		y--;
	if (map[y][x] != '1')
		return (0);	
	return (1);
}

int check_map(t_cub *cub)
{
	int x;
	int y;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == '0')
				if (!check_zero(cub->map, x, y)
					|| !check_d_left(cub->map, x, y)
					|| !check_d_right(cub->map, x, y))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}