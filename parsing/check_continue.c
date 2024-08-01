/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_continue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:21:19 by aconti            #+#    #+#             */
/*   Updated: 2024/08/01 14:21:34 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
				if (!check_zero(matrix, x, y, player)
					|| !check_d_left(matrix, x, y, player)
					|| !check_d_right(matrix, x, y, player))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}