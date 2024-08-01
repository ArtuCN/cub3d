/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:22:01 by aconti            #+#    #+#             */
/*   Updated: 2024/08/01 17:20:33 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	my_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int*)dst = color;	
	}
}

int	draw_square(t_cub *cub, int x, int y, unsigned int color)
{
	printf("draw_square\n");
	my_mlx_pixel_put(cub->img, x * 100, y * 100, color);
	return (1);
}

int	draw_minimap(t_cub *cub, char **map)
{
	int	x;
	int y;

	y = 0;
	while(map[y])
	{
		x = 0;
		while(cub->data->map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(cub, x, y, 0x000000);
			else if (map[y][x] == '0' || cub->data->map[y][x] == cub->data->player_dir)
				draw_square(cub, x, y, 0x00FF00);	
			else
				draw_square(cub, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	return (1);
}