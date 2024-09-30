/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:21:12 by adonato           #+#    #+#             */
/*   Updated: 2024/09/30 11:51:18 by adonato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_next_door(t_cub *cub)
{
	int			xd;
	int			yd;
	int			x;
	int			y;
	long double	angle;

	angle = cub->player->angle * PI / 180;
	xd = (((cub->player->x + 20 * cos(angle)) * 10));
	yd = (((cub->player->y + 20 * sin(angle)) * 10));
	x = ((cub->player->x * 10));
	y = ((cub->player->y * 10));
	if (cub->data->map[yd][xd] == 'D')
	{
		cub->data->map[yd][xd] = 'O';
		return (1);
	}
	else if (cub->data->map[yd][xd] == 'O'
		&& (x != xd || y != yd))
	{
		cub->data->map[yd][xd] = 'D';
		return (1);
	}
	else
		cub->pressed = 0;
	return (0);
}

int	go_backward(t_cub *cub, long double *x, long double *y, long double angle)
{
	long double	xd;
	long double	yd;

	xd = *x - (long double)(0.1 * (cos(angle)) / 10);
	yd = *y - (long double)(0.1 * (sin(angle)) / 10);
	if (!is_wall2(xd, yd, cub))
		return (1);
	else
		cub->pressed = 0;
	return (0);
}

int	go_forward(t_cub *cub, long double *x, long double *y, long double angle)
{
	long double	xd;
	long double	yd;

	xd = *x + (long double)(0.1 * (cos(angle)) / 10);
	yd = *y + (long double)(0.1 * (sin(angle)) / 10);
	if (!is_wall2(xd, yd, cub))
		return (1);
	else
		cub->pressed = 0;
	return (0);
}

int	check_move(int keysym, t_cub *cub, char **map)
{
	long double	x;
	long double	y;
	long double	angle;

	x = cub->player->x;
	y = cub->player->y;
	angle = cub->player->angle * PI / 180;
	if (keysym == SYM_S)
	{
		if (!go_backward(cub, &x, &y, angle))
			return (0);
	}	
	if (keysym == SYM_W)
	{
		if (!go_forward(cub, &x, &y, angle))
			return (0);
	}
	else
		cub->pressed = 0;
	if (map[(int)(y / 10)][(int)(x / 10)] == '1')
		return (0);
	return (1);
}
