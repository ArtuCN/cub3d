/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:07:32 by aconti            #+#    #+#             */
/*   Updated: 2024/07/31 13:13:19 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_cube(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
	{
		ft_printf("Error\nmlx_init failed\n");
		return (0);
	}
	cub->win = mlx_new_window(cub->mlx, WIDTH,
		HEIGHT, "cub3d");
	if (!cub->win)
	{
		free(cub->mlx);
		ft_printf("Error\nmlx_new_window failed\n");
		return (0);
	}
	cub->img = malloc(sizeof(t_img));
	if (!cub->img)
	{
		free(cub->mlx);
		free(cub->win);
		ft_printf("Error\nmalloc failed\n");
		return (0);
	}
	return (1);
}
