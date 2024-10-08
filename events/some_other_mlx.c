/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_other_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:38:28 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 15:03:41 by aconti           ###   ########.fr       */
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
	xd = (cub->player->x + 70 * cos(angle)) / TXT_SIZE;
	yd = (cub->player->y + 70 * sin(angle)) / TXT_SIZE;
	x = ((cub->player->x)) / TXT_SIZE;
	y = ((cub->player->y)) / TXT_SIZE;
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

int	check_move(int keysym, t_cub *cub, char **map)
{
	long double	x;
	long double	y;
	long double	angle;

	x = cub->player->x;
	y = cub->player->y;
	angle = cub->player->angle * PI / 180;
	if (keysym == SYM_S || keysym == SYM_DOWN)
	{
		if (!go_backward(cub, &x, &y, angle))
			return (0);
	}
	if (keysym == SYM_W || keysym == SYM_UP)
	{
		if (!go_forward(cub, &x, &y, angle))
			return (0);
	}
	else
		cub->pressed = 0;
	if (map[(int)(y / TXT_SIZE)][(int)(x / TXT_SIZE)] == '1')
		return (0);
	return (1);
}

void	move(int keysym, t_cub *cub)
{
	if (keysym == SYM_D || keysym == SYM_RIGHT)
		cub->player->angle += 3;
	else if (keysym == SYM_A || keysym == SYM_LEFT)
		cub->player->angle -= 3;
	if (cub->player->angle > 360)
		cub->player->angle -= 360;
	else if (cub->player->angle <= 0)
		cub->player->angle += 360;
	else if ((keysym == SYM_W || keysym == SYM_UP)
		&& check_move(keysym, cub, cub->data->map))
	{
		cub->player->x += 10 * cos(cub->player->angle * PI / 180);
		cub->player->y += 10 * sin(cub->player->angle * PI / 180);
	}
	else if ((keysym == SYM_S || keysym == SYM_DOWN)
		&& check_move(keysym, cub, cub->data->map))
	{
		cub->player->x -= 10 * cos(cub->player->angle * PI / 180);
		cub->player->y -= 10 * sin(cub->player->angle * PI / 180);
	}
	mlx_mouse_get_pos(cub->mlx, cub->win, &cub->x_mouse, &cub->y_mouse);
	rotate_pov(cub, cub->x_mouse, cub->y_mouse);
	cub->pressed = 0;
}

int	key_handler(int keysym, t_cub *cub)
{
	if (keysym == ESC)
		return (close_window (cub));
	if (cub->pause)
		return (key_handler_pause(keysym, cub));
	if (keysym == SYM_P)
	{
		cub->pause = 1;
	}
	if (keysym == SYM_E)
		check_next_door(cub);
	if (cub->pressed)
		move(keysym, cub);
	adding_minimap(keysym, cub);
	cub->num_walls = 0;
	mlx_clear_window(cub->mlx, cub->win);
	free_wall(cub->player);
	cub->num_walls = 0;
	start_dda(cub, cub->player->ray);
	draw_minimap(cub, cub->data, cub->data->map);
	return (0);
}
