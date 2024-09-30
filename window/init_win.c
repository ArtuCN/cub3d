/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:07:32 by aconti            #+#    #+#             */
/*   Updated: 2024/09/30 10:50:26 by adonato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub_img_malloc(t_cub *cub)
{
	cub->img = malloc(sizeof(t_img));
	if (!cub->img)
	{
		free(cub->mlx);
		free(cub->win);
		return (printf("Error\nmalloc failed\n"), 0);
	}
	return (1);
}

int	failing_img_addr(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->img->img_ptr) ;
	free(cub->mlx);
	free(cub->win);
	free(cub->img);
	return (printf("Error\nmlx_get_data_addr failed\n"), 0);
}

int	init_cube(t_cub *cub)
{
	cub->player = malloc(sizeof(t_player));
	cub->add_minimap = 0;
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (printf("Error\nmlx_init failed\n"), 0);
	cub->win = mlx_new_window(cub->mlx, WIDTH,
			HEIGHT, "cub3d");
	if (!cub->win)
		free(cub->mlx);
	if (!cub->win)
		return (printf("Error\nmlx_new_window failed\n"), 0);
	if (!cub_img_malloc(cub))
		return (0);
	cub->img->img_ptr = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img->addr = mlx_get_data_addr(cub->img->img_ptr,
			&(cub->img->bpp), &(cub->img->line_len),
			&(cub->img->endian));
	if (!cub->img->img_ptr)
		return (failing_img_addr(cub));
	player_init(cub);
	adding_wall(cub);
	// start_raycast(cub, cub->player);
	start_dda(cub, cub->player->ray);
	calling_mlx(cub);
	return (1);
}
