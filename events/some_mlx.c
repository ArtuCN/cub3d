/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:20:38 by aconti            #+#    #+#             */
/*   Updated: 2024/10/03 16:57:12 by adonato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	adding_minimap(int keysym, t_cub *cub)
{
	if (keysym == SYM_M && cub->add_minimap)
		cub->add_minimap = 0;
	else if (keysym == SYM_M && !cub->add_minimap)
		cub->add_minimap = 1;
}

int	key_handler(int keysym, t_cub *cub)
{
	if (keysym == 65307)
		return (close_window (cub));
	if (keysym == SYM_E)
		check_next_door(cub);
	if (cub->pressed)
	{	
		if (keysym == SYM_D || keysym == SYM_RIGHT)
			cub->player->angle += 3;
		else if (keysym == SYM_A || keysym == SYM_LEFT)
			cub->player->angle -= 3;
		if (cub->player->angle > 360)
			cub->player->angle -= 360;
		else if (cub->player->angle <= 0)
			cub->player->angle += 360;
		else if ((keysym == SYM_W || keysym == SYM_UP)&& check_move(keysym, cub, cub->data->map))
		{
			cub->player->x += 10 * cos(cub->player->angle * PI / 180);
			cub->player->y += 10 * sin(cub->player->angle * PI / 180);
		}
		else if ((keysym == SYM_S || keysym == SYM_DOWN) && check_move(keysym, cub, cub->data->map))
		{
			cub->player->x -= 10 * cos(cub->player->angle * PI / 180);
			cub->player->y -= 10 * sin(cub->player->angle * PI / 180);
		}
		mlx_mouse_get_pos(cub->mlx, cub->win, &cub->x_mouse, &cub->y_mouse);
		rotate_pov(cub, cub->x_mouse, cub->y_mouse);
		cub->pressed = 0;
	}
	adding_minimap(keysym, cub);
	cub->num_walls = 0;
	mlx_clear_window(cub->mlx, cub->win);
	free_wall(cub->player);
	cub->num_walls = 0;
	start_dda(cub, cub->player->ray);
	draw_minimap(cub, cub->data,cub->data->map);
	return (0);
}

int key_press(int keysym, t_cub *cub)
{
	if (keysym == SYM_D || keysym == SYM_A || keysym == SYM_W || keysym == SYM_S
		|| keysym == SYM_UP || keysym == SYM_DOWN || keysym == SYM_LEFT || keysym == SYM_RIGHT)
		cub->pressed = 1;
	if (keysym == SYM_Q)
	{
		if (cub->show_sword)
			cub->show_sword = 0;
		else
			cub->show_sword = 1;
		
	}
	if (keysym == SYM_SPACE)
	{
		if (cub->show_sword)
			cub->show_sword = 3;
	}
	return (0);
}

int key_release(int keysym, t_cub *cub)
{
	if (keysym == SYM_D || keysym == SYM_A || keysym == SYM_W || keysym == SYM_S)
		cub->pressed = 0;
	return (0);
}

int	uptade_animation(void *param)
{
	t_cub *cub;
	
	cub = (t_cub *)param;
	struct timeval	current_time;
	static struct timeval	last_update_time;
	long elapsed_time;

	gettimeofday(&current_time, NULL);
	
	// Calcola il tempo trascorso dall'ultimo aggiornamento
	elapsed_time = (current_time.tv_sec - last_update_time.tv_sec) * 1000;
	elapsed_time += (current_time.tv_usec - last_update_time.tv_usec) / 1000;	
	if ((cub->show_sword == 1) && (elapsed_time > 500))
	{
		mlx_clear_window(cub->mlx, cub->win);
		start_dda(cub, cub->player->ray);
		usleep(1000000);
	}
	return (0);
}


void	calling_mlx(t_cub *cub)
{
	mlx_hook(cub->win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, key_release, cub);   
	mlx_hook(cub->win, 17, 1L << 2, close_window, cub);
	mlx_loop_hook(cub->mlx, uptade_animation, (void *)cub);
	mlx_key_hook(cub->win, key_handler, cub);
	mlx_loop_hook(cub->mlx, main_loop, cub);
	mlx_loop(cub->mlx);
}

