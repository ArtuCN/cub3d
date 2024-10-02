/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:32:00 by aconti            #+#    #+#             */
/*   Updated: 2024/10/02 16:25:37 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(t_cub *cub)
{
	mlx_clear_window (cub->mlx,
		cub->win);
	mlx_destroy_image (cub->mlx,
		cub->img->img_ptr);
	mlx_destroy_window (cub->mlx,
		cub->win);
	mlx_destroy_display (cub->mlx);
	free (cub->mlx);
	free_cub (cub);
	exit(EXIT_SUCCESS);
}
