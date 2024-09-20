/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:21:12 by adonato           #+#    #+#             */
/*   Updated: 2024/09/12 14:51:37 by aconti           ###   ########.fr       */
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
	xd = (((cub->player->x + 20 * cos(angle)) * 50) / WIDTH);
	yd = (((cub->player->y + 20 * sin(angle)) * 50) / HEIGHT);
	x = ((cub->player->x * 50) / WIDTH);
	y = ((cub->player->y * 50) / HEIGHT);
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

	xd = *x - (long double)(2 * (cos(angle)));
	yd = *y - (long double)(2 * (sin(angle)));
	if (!is_wall(xd, yd, cub))
		return (1);
	else
		cub->pressed = 0;
	return (0);
}

int	go_forward(t_cub *cub, long double *x, long double *y, long double angle)
{
	long double	xd;
	long double	yd;

	xd = *x + (long double)(2 * (cos(angle)));
	yd = *y + (long double)(2 * (sin(angle)));
	if (!is_wall(xd, yd, cub))
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
	if (map[(int)(y / (HEIGHT / 50))][(int)(x / (WIDTH / 50))] == '1')
		return (0);
	return (1);
}
