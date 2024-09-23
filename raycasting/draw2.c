/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:41:03 by aconti            #+#    #+#             */
/*   Updated: 2024/09/23 10:48:31 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_all(t_cub *cub, t_player *player)
{
	int	i;
	t_ray *ray;
	int	temp;

	ray = player->ray;
	i = -1;
	while (++i < player->num_rays)
	{
		temp = 0;
		while (++temp < ray[i].wall_start && temp < HEIGHT)
			my_mlx_pixel_put(cub, i, temp, cub->data->color_ceiling);
		if (ray[i].wall->direction == 'A')
		{
			while (++temp < ray[i].wall_end && temp < HEIGHT)
				my_mlx_pixel_put(cub, i, temp, RED);
		}
		// if (!is_same(ray, i))
		if (ray[i].wall->direction != 'A')
			mlx_put_image_to_window(cub->mlx, cub->win, ray[i].column_img, i, ray[i].wall_start);
		temp = ray[i].wall_end - 1;
		while (++temp < HEIGHT)
			my_mlx_pixel_put(cub, i, temp, cub->data->color_floor);
	}
}
