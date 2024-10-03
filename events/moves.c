/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:21:12 by adonato           #+#    #+#             */
/*   Updated: 2024/10/03 18:04:31 by adonato          ###   ########.fr       */
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
	xd = (cub->player->x + 20 * cos(angle)) / TXT_SIZE;
	yd = (cub->player->y + 20 * sin(angle)) / TXT_SIZE;
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

int	go_backward(t_cub *cub, long double *x, long double *y, long double angle)
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

int	go_forward(t_cub *cub, long double *x, long double *y, long double angle)
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

void rotate_pov(t_cub *cub, int x, int y)
{
    static int prev_x = -1;
    static int prev_y = -1;
    int delta_x;
    long double angle_change;
	
	 {
		if (prev_x == -1 && prev_y == -1) 
		{
   	    	prev_x = x;
   	   		prev_y = y;
        	return;
  		}
    	delta_x = x - prev_x;
   		angle_change = delta_x * 0.25; 
    	cub->player->angle += angle_change;
    	mlx_mouse_move(cub->mlx, cub->win, WIDTH / 2, HEIGHT / 2);
    	prev_x = WIDTH / 2;
    	prev_y = HEIGHT / 2;
	}
}

int main_loop(t_cub *cub)
{

		mlx_mouse_get_pos(cub->mlx, cub->win, &cub->x_mouse, &cub->y_mouse);
   		cub->pressed = 0;
		rotate_pov(cub, cub->x_mouse, cub->y_mouse);
		mlx_clear_window(cub->mlx, cub->win);
		free_wall(cub->player);
		cub->num_walls = 0;
		start_dda(cub, cub->player->ray);
		draw_minimap(cub, cub->data,cub->data->map);
		cub->pressed = 1;
    return (0);
}

// int	mouse_rotate_pov(t_cubed *cubed)
// {
// 	t_player	*p;
// 	int			x;
// 	double		rotation;

// 	p = cubed->player;
// 	x = cubed->game->mouse_x;
// 	rotation = (x - (WIDTH / 2)) * SENSITIVITY * 0.001;
// 	p->angle += rotation;
// 	if (p->angle > 2 * PI)
// 		p->angle -= 2 * PI;
// 	if (p->angle < 0)
// 		p->angle += 2 * PI;
// 	p->d_x = cos(p->angle);
// 	p->d_y = sin(p->angle);
// 	if (x != WIDTH / 2)
// 		mlx_mouse_move(cubed->mlx, cubed->win, WIDTH / 2, HEIGHT / 2);
// 	return (1);
// }

