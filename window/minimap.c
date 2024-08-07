/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:22:01 by aconti            #+#    #+#             */
/*   Updated: 2024/08/07 12:47:17 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	my_mlx_pixel_put(t_cub *cub, int x, int y, unsigned int color)
{
	//char	*dst;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{	
		//dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		//*(unsigned int*)dst = color;	
		mlx_pixel_put(cub->mlx, cub->win, x, y, color);
	}
}

int	draw_square(t_cub *cub, int x, int y, unsigned int color)
{
	int i;
	int j;
	
	//i = (x * 50);
	j = (y * (HEIGHT / 50));
	while(j <= ((HEIGHT / 50) + (y * (HEIGHT / 50))))
	{
		i = (x * (WIDTH / 50));
		while(i <= ((WIDTH / 50) + (x * (WIDTH / 50))))
		{
			if ((i == 0) || (i % (WIDTH / 50) == 0) || (j == 0) || (j % (HEIGHT / 50) == 0))
				my_mlx_pixel_put(cub, i, j, 0xFFFFFF);
			else 
				my_mlx_pixel_put(cub, i, j, color);
			// printf("%d, %d \n", i, j);
			i++;
		}
		j++;
	}
	return (1);
}


int	put_player(t_cub *cub, int x, int y, unsigned int color)
{
	int start_x = x - 5;
	int start_y = y - 5;
	int end_x = x + 5;
	int end_y = y + 5;

	// Ensure we don't draw out of bounds
	if (start_x < 0) start_x = 0;
	if (start_y < 0) start_y = 0;
	if (end_x >= WIDTH) end_x = WIDTH - 1;
	if (end_y >= HEIGHT) end_y = HEIGHT - 1;

	for (int i = start_x; i <= end_x; i++)
	{
		for (int j = start_y; j <= end_y; j++)
		{
			my_mlx_pixel_put(cub, i, j, color);
		}
	}
	return (1);
}

int	draw_minimap(t_cub *cub, char **map)
{
	int	x;
	int y;

	y = 0;
	printf("%d, %d \n", fmap(cub->player->x, WIDTH, cub->data->max_x), fmap(cub->player->y, HEIGHT, cub->data->max_y));
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(cub, x, y, BLUE);
			else if (map[y][x] == '0' || map[y][x] == 'E' || map[y][x] == 'W' || map[y][x] == 'N' || map[y][x] == 'S')
				draw_square(cub, x, y, WHITE);		
//			else
//				draw_square(cub, x, y, 0xFFFFFF);
			// printf("PRIMA X %d, PRIMA Y %d \n", x, y);
			x++;
		}
		y++;
	}
	put_player(cub, fmap(cub->player->x, WIDTH, cub->data->max_x), fmap(cub->player->y, HEIGHT, cub->data->max_y), RED);
	return (1);
}