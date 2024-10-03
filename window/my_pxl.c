/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pxl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adonato <adonato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:01:55 by aconti            #+#    #+#             */
/*   Updated: 2024/10/03 18:00:37 by adonato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, unsigned int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_pixel_put(cub->mlx, cub->win, x, y, color);
}

int	put_player(t_cub *cub, int x, int y, unsigned int color)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	start_x = x - 2;
	start_y = y - 2;
	end_x = x + 2;
	end_y = y + 2;
	if (!cub->add_minimap)
		return (0);
	if (start_x < 0)
		start_x = 0;
	if (start_y < 0)
		start_y = 0;
	if (end_x >= WIDTH)
		end_x = WIDTH - 1;
	if (end_y >= HEIGHT)
		end_y = HEIGHT - 1;
	draw_player(cub, x, y, color);
	draw_rays_minimap(cub, x, y);
	return (1);
}
