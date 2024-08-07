/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:20:38 by aconti            #+#    #+#             */
/*   Updated: 2024/08/07 15:47:09 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_move(int keysym, t_cub *cub, char **map)
{
	int x;
	int y;

	x = cub->player->x;
	y = cub->player->y;
	if (keysym == SYM_D)
		x += 10;
	if (keysym == SYM_A)
		x -= 5;
	if (keysym == SYM_W)
		y -= 5;
	if (keysym == SYM_S)
		y += 10;
	if (map[(int)(y / (HEIGHT / 50))][(int)(x / (WIDTH / 50))] == '1')
		return (0);
	return (1);
}

int	key_handler(int keysym, t_cub *cub)
{
	if (keysym == 65307)
		return(close_window (cub));
	if (keysym == SYM_D && check_move(SYM_D, cub, cub->data->map))
		cub->player->x += 5;
	if (keysym == SYM_A && check_move(SYM_A, cub, cub->data->map))
		cub->player->x -= 5;
	if (keysym == SYM_W && check_move(SYM_W, cub, cub->data->map))
		cub->player->y -= 5;
	if (keysym == SYM_S && check_move(SYM_S, cub, cub->data->map))
		cub->player->y += 5;
	
	draw_minimap(cub, cub->data->map);
	return (0);
}

void calling_mlx(t_cub *cub)
{
	draw_minimap(cub, cub->data->map);
	mlx_key_hook (cub->win, key_handler, cub);
	mlx_hook(cub->win, 17, 1L << 2, close_window, cub);
	// mlx_hook()
	mlx_loop(cub->mlx);
}