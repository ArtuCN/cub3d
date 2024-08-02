/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:07:32 by aconti            #+#    #+#             */
/*   Updated: 2024/08/02 17:18:24 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int cub_img_malloc(t_cub *cub)
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

int failing_img_addr(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->img->img_ptr);
	free(cub->mlx);
	free(cub->win);
	free(cub->img);
	return (printf("Error\nmlx_get_data_addr failed\n"), 0);
}

int	close_window(t_cub *cub)
{
	mlx_destroy_image(cub->mlx,
		cub->img->img_ptr);
	mlx_destroy_window(cub->mlx,
		cub->win);
	mlx_destroy_display (cub->mlx);
	free (cub->mlx);
	free_cub(cub);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_cub *cub)
{
	if (keysym == 65307)
		close_window (cub);
	return (0);
}

int	init_cube(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (printf("Error\nmlx_init failed\n"), 0);
	cub->win = mlx_new_window(cub->mlx, WIDTH,
		HEIGHT, "cub3d");
	if (!cub->win)
	{
		free(cub->mlx);
		return (printf("Error\nmlx_new_window failed\n"), 0);
	}
	if (!cub_img_malloc(cub))
		return (0);
	cub->img->img_ptr = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img->addr = mlx_get_data_addr(cub->img->img_ptr,
			&(cub->img->bpp), &(cub->img->line_len),
			&(cub->img->endian));
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, 0, 0);
	if (!cub->img->img_ptr)
		return (failing_img_addr(cub));
	draw_minimap(cub, cub->data->map);
	mlx_key_hook (cub->win, key_handler, cub);
	mlx_hook(cub->win, 17, 1L << 2, close_window, cub);
	mlx_loop(cub->mlx);
	return (1);
}
