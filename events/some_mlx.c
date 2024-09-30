/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:20:38 by aconti            #+#    #+#             */
/*   Updated: 2024/09/30 10:49:22 by adonato          ###   ########.fr       */
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
		if (keysym == SYM_D)
			cub->player->angle += 3;
		else if (keysym == SYM_A)
			cub->player->angle -= 3;
		if (cub->player->angle > 360)
			cub->player->angle -= 360;
		else if (cub->player->angle <= 0)
			cub->player->angle += 360;
		else if (keysym == SYM_W && check_move(keysym, cub, cub->data->map))
		{
			cub->player->x += 1.5 * cos(cub->player->angle * PI / 180);
			cub->player->y += 1.5 * sin(cub->player->angle * PI / 180);
		}
		else if (keysym == SYM_S && check_move(keysym, cub, cub->data->map))
		{
			cub->player->x -= 1.5 * cos(cub->player->angle * PI / 180);
			cub->player->y -= 1.5 * sin(cub->player->angle * PI / 180);
		}
		cub->pressed = 0;
	}
	adding_minimap(keysym, cub);
	cub->num_walls = 0;
	mlx_clear_window(cub->mlx, cub->win);
	free_wall(cub->player);
	// mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, 0, 0);
	//start_raycast(cub, cub->player);
	cub->num_walls = 0;
	start_dda(cub, cub->player->ray);
	draw_minimap(cub, cub->data,cub->data->map);
	return (0);
}

int key_press(int keysym, t_cub *cub)
{
	if (keysym == SYM_D || keysym == SYM_A || keysym == SYM_W || keysym == SYM_S)
    	cub->pressed = 1; // Imposta lo stato del tasto come premuto
    return (0);
}

int key_release(int keysym, t_cub *cub)
{
    if (keysym == SYM_D || keysym == SYM_A || keysym == SYM_W || keysym == SYM_S)
    	cub->pressed = 0; // Imposta lo stato del tasto come rilasciato
    return (0);
}

void	calling_mlx(t_cub *cub)
{
	mlx_hook(cub->win, 2, 1L << 0, key_press, cub);     // Gestisce la pressione dei tasti
    mlx_hook(cub->win, 3, 1L << 1, key_release, cub);   
	mlx_key_hook (cub->win, key_handler, cub);
	mlx_hook(cub->win, 17, 1L << 2, close_window, cub);
	mlx_loop(cub->mlx);
}
