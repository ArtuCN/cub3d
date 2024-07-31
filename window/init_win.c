/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:07:32 by aconti            #+#    #+#             */
/*   Updated: 2024/07/31 18:38:16 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(t_cub *cub)
{
	printf("Closing window\n");
	mlx_destroy_image(cub->mlx,
		cub->img->img_ptr);
	printf("Closing window1\n");
	mlx_destroy_window(cub->mlx,
		cub->win);
	printf("Closing window2\n");
	mlx_destroy_display (cub->mlx);
	printf("Closing window3\n");
	free (cub->mlx);
	printf("Closing window4\n");
	return (EXIT_SUCCESS);
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
	cub->img = malloc(sizeof(t_img));
	if (!cub->img)
	{
		free(cub->mlx);
		free(cub->win);
		return (printf("Error\nmalloc failed\n"), 0);
	}
	cub->img->img_ptr = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img->addr = mlx_get_data_addr(&(cub->img->img_ptr),
			&(cub->img->bpp),
			&(cub->img->line_len), &(cub->img->endian));
	mlx_key_hook (cub->win, key_handler, cub);
	mlx_hook(cub->win, 17, 1L << 2, close_window, cub);
	mlx_loop(cub->mlx);
	return (1);
}
