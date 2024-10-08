/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:21:12 by adonato           #+#    #+#             */
/*   Updated: 2024/10/08 16:35:54 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	go_b(t_cub *cub, long double *x, long double *y, long double angle)
{
	long double	xd;
	long double	yd;

	xd = *x - (long double)(20 * (cos(angle)));
	yd = *y - (long double)(20 * (sin(angle)));
	if (!is_wall(xd, yd, cub))
		return (1);
	else
		cub->pressed = 0;
	return (0);
}

int	go_f(t_cub *cub, long double *x, long double *y, long double angle)
{
	long double	xd;
	long double	yd;

	xd = *x + (long double)(20 * (cos(angle)));
	yd = *y + (long double)(20 * (sin(angle)));
	if (!is_wall(xd, yd, cub))
		return (1);
	else
		cub->pressed = 0;
	return (0);
}

void	rotate_pov(t_cub *cub, int x, int y)
{
	static int	prev_x = -1;
	static int	prev_y = -1;
	int			delta_x;
	long double	angle_change;

	{
		if (prev_x == -1 && prev_y == -1)
		{
			prev_x = x;
			prev_y = y;
			return ;
		}
		delta_x = x - prev_x;
		angle_change = delta_x * 0.25;
		cub->player->angle += angle_change;
		mlx_mouse_move(cub->mlx, cub->win, WIDTH / 2, HEIGHT / 2);
		prev_x = WIDTH / 2;
		prev_y = HEIGHT / 2;
	}
}

int	update_animation(t_cub *cub)
{
	static int		first = 0;
	struct timeval	last_update_time;
	long			time_diff;

	if (first == 0)
		gettimeofday(&cub->current_time, NULL);
	first = 1;
	gettimeofday(&last_update_time, NULL);
	time_diff = (last_update_time.tv_sec - cub->current_time.tv_sec) * 1000;
	time_diff += (last_update_time.tv_usec - cub->current_time.tv_usec) / 1000;
	if ((cub->show_sword == 1) && (time_diff > 200))
	{
		cub->current_time = last_update_time;
		cub->change = 1;
		return (1);
	}
	if ((cub->show_sword == 2) && (time_diff > 50))
	{
		cub->current_time = last_update_time;
		cub->change = 1;
		return (1);
	}
	cub->change = 0;
	return (0);
}

int	main_loop(t_cub *cub)
{
	static int	t_mouse_x = 0;
	static int	t_mouse_y = 0;

	if (cub->pause == 1)
	{
		draw_pause(cub);
		return (0);
	}
	mlx_mouse_get_pos(cub->mlx, cub->win, &cub->x_mouse, &cub->y_mouse);
	if (update_animation(cub) || cub->x_mouse != t_mouse_x
		|| cub->y_mouse != t_mouse_y)
	{
		rotate_pov(cub, cub->x_mouse, cub->y_mouse);
		cub->pressed = 0;
		rotate_pov(cub, cub->x_mouse, cub->y_mouse);
		mlx_clear_window(cub->mlx, cub->win);
		free_wall(cub->player);
		cub->num_walls = 0;
		start_dda(cub, cub->player->ray);
		draw_minimap(cub, cub->data, cub->data->map);
		cub->pressed = 1;
	}
	t_mouse_x = cub->x_mouse;
	t_mouse_y = cub->y_mouse;
	return (0);
}
