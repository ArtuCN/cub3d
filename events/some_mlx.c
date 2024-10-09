/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:20:38 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 14:38:57 by aconti           ###   ########.fr       */
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

int	key_handler_pause(int keysym, t_cub *cub)
{
	if (keysym == SYM_P)
		cub->pause = 0;
	if (keysym == ESC)
		return (close_window (cub));
	return (0);
}

int	key_press(int keysym, t_cub *cub)
{
	if (keysym == SYM_D || keysym == SYM_A || keysym == SYM_W || keysym == SYM_S
		|| keysym == SYM_UP || keysym == SYM_DOWN || keysym == SYM_LEFT
		|| keysym == SYM_RIGHT || keysym == SYM_SPACE)
		cub->pressed = 1;
	if (keysym == SYM_Q)
	{
		cub->pressed = 1;
		cub->change = 1;
		if (cub->show_sword)
			cub->show_sword = 0;
		else
			cub->show_sword = 1;
	}
	if (keysym == SYM_SPACE)
	{
		if (cub->show_sword == 1)
			cub->show_sword = 2;
		cub->frame = 0;
	}
	return (0);
}

int	key_release(int keysym, t_cub *cub)
{
	if (keysym == SYM_D || keysym == SYM_A || keysym == SYM_W
		|| keysym == SYM_S || keysym == SYM_UP || keysym == SYM_DOWN
		|| keysym == SYM_LEFT || keysym == SYM_RIGHT || keysym == SYM_Q
		|| keysym == SYM_SPACE)
		cub->pressed = 0;
	return (0);
}

void	calling_mlx(t_cub *cub)
{
	mlx_hook(cub->win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->win, 17, 1L << 2, close_window, cub);
	mlx_key_hook(cub->win, key_handler, cub);
	mlx_loop_hook(cub->mlx, main_loop, cub);
	mlx_hook(cub->win, 2, 1L << 0, key_press, cub);
	mlx_loop(cub->mlx);
}
