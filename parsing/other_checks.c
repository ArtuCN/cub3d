/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:22:44 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 14:31:36 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_d_left(char **map, int x, int y, char player)
{
	int	x1;
	int	y1;

	y1 = y;
	x1 = x;
	while ((map[y][x] == '0' || map[y][x] == 'D') && x > 0)
	{
		x--;
		y++;
	}
	if (map[y][x] != '1' && map[y][x] != player)
		return (0);
	x = x1;
	y = y1;
	while ((map[y][x] == '0' || map[y][x] == 'D') && x > 0 && y > 0)
	{
		x--;
		y--;
	}
	if (map[y][x] != '1' && map[y][x] != player)
		return (0);
	return (1);
}

int	check_d_right(char **map, int x, int y, char player)
{
	int	x1;
	int	y1;

	y1 = y;
	x1 = x;
	while ((map[y][x] == '0' || map[y][x] == 'D') && y > 0)
	{
		x++;
		y--;
	}
	if (map[y][x] != '1' && map[y][x] != player)
		return (0);
	x = x1;
	y = y1;
	while ((map[y][x] == '0' || map[y][x] == 'D'))
	{
		x++;
		y++;
	}
	if (map[y][x] != '1' && map[y][x] != player)
		return (0);
	return (1);
}
