/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:22:01 by aconti            #+#    #+#             */
/*   Updated: 2024/08/02 19:11:19 by aconti           ###   ########.fr       */
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
	int i;
	int j;
	
	i = x;
	j = y;
	while(j < 50 + y)
	{
		i = x;
		while(i <50+ x)
		{
			my_mlx_pixel_put(cub->img, i, j, color);
			i++;
			// printf("i = %d\n", i);
		}
		j++;

	}
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
		while(map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(cub, fmap(x, WIDTH, cub->data->max_x), fmap(y + 1, HEIGHT, cub->data->max_y), 0x00FFFF);
			else if (map[y][x] == '0')
				draw_square(cub, fmap(x, WIDTH, cub->data->max_x), fmap(y + 1, HEIGHT, cub->data->max_y), 0x00FF00);	
			else if (map[y][x] == 'E')
				draw_square(cub, fmap(x, WIDTH, cub->data->max_x), fmap(y + 1, HEIGHT, cub->data->max_y), 0xFF0000);				
			else
				draw_square(cub, fmap(x, WIDTH, cub->data->max_x), fmap(y + 1, HEIGHT, cub->data->max_y), 0x000000);
			x++;
		}
		y++;
	}
	return (1);
}