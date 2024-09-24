/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:22:01 by aconti            #+#    #+#             */
/*   Updated: 2024/09/24 13:17:21 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	draw_square(t_cub *cub, int x, int y, unsigned int color)
{
	int	i;
	int	j;
	int player_minimap_x = cub->player->x;
    int player_minimap_y = cub->player->y;
    int offset_x = player_minimap_x - MINIMAP_WIDTH / 4;
    int offset_y = player_minimap_y - MINIMAP_HEIGHT / 4;
	int minimap_x = x * (WIDTH / 50) - offset_x + MINIMAP_X;
    int minimap_y = y * (HEIGHT / 50) - offset_y + MINIMAP_Y;
	
    j = minimap_y;
    while (j <= minimap_y + (HEIGHT / 50)) 
	{
        i = minimap_x;
        while (i <= minimap_x + (WIDTH / 50)) 
		{
            if ((i == (int)minimap_x) //|| (i % (int)((minimap_x)) == 0)
                || (j == (int)minimap_y)) //|| (j % (int)((minimap_y)) == 0))
                my_mlx_pixel_put(cub, i, j, 0x000000);
            else
                my_mlx_pixel_put(cub, i, j, color);
            i++;
        }
        j++;
    }
    return (1);
}

int	is_wall(long double x, long double y, t_cub *cub)
{
	long double	j;
	long double	i;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return (1);
	j = (y * 50 / HEIGHT);
	i = (x * 50 / WIDTH);
	if (cub->data->map[(int)j][(int)i] == '1'
		|| cub->data->map[(int)j][(int)i] == '\n'
		|| !cub->data->map[(int)j][(int)i]
		|| cub->data->map[(int)j][(int)i] == 'D')
		return (1);
	return (0);
}

void	draw_rays_minimap(t_cub *cub, int x, int y)
{
	int i;
	long double	temp_ang;
	double minimap_x;
	double	minimap_y;
	temp_ang = (long double)(cub->player->angle - 29);
	while (temp_ang <= cub->player->angle + 30)
	{
		i = -1;
		minimap_x = x - cub->data->offset_x + MINIMAP_X;
		minimap_y = y - cub->data->offset_y + MINIMAP_Y;
		while (++i <= 10)
		{
			minimap_x += 5 * cos(temp_ang * PI / 180);
			minimap_y += 5 * sin(temp_ang * PI / 180);
			if ((int)minimap_x < 0 || (int)minimap_y < 0 || (int)minimap_x >= MINIMAP_WIDTH
			|| (int)minimap_y >= MINIMAP_HEIGHT 
			|| is_wall(minimap_x + cub->data->offset_x, minimap_y + cub->data->offset_y, cub))
					   break;
            else
				my_mlx_pixel_put(cub, minimap_x, minimap_y, RED);
		}
		temp_ang += cub->player->increment;
	}
}

void	draw_player(t_cub *cub, int x, int y, unsigned int color)
{
	int	i;
	int	j;
	
	cub->data->offset_x = x - MINIMAP_WIDTH / 4;
    cub->data->offset_y = y - MINIMAP_HEIGHT / 4;
	int minimap_x = x - cub->data->offset_x + MINIMAP_X;
    int minimap_y = y - cub->data->offset_y + MINIMAP_Y;

	i = minimap_x - 1;
	while (i <= minimap_x + 2)
	{
		j = minimap_y - 1;
		while (j <= minimap_y + 2)
		{
			my_mlx_pixel_put(cub, i, j, color);
			j++;
		}
		i++;
	}
	minimap_x = x;
	minimap_y = y;
	draw_rays_minimap(cub, x, y);
}

int	draw_minimap(t_cub *cub, t_data *data, char **map)
{
	int	final_x;
	int	final_y;

	int player_x = (int)(cub->player->x) * 50 / WIDTH;
	int player_y = (int)(cub->player->y)* 50 / HEIGHT;
	(void)data;
	if (!cub->add_minimap)
		return (0);
	if (player_y < 3)
		player_y = 0;
	else
		player_y -= 3;
	final_x = player_x + 6;
	final_y = player_y + 6;
	while (map[player_y] && player_y <= final_y)
	{
		player_x = (int)(cub->player->x) * 50 / WIDTH;
		if (player_x < 3)
		player_x = 0;
		else
		player_x -= 3;
		while (map[player_y][player_x] && player_x <= final_x)
		{
			if (map[player_y][player_x] == '1')
				draw_square(cub, player_x, player_y, BLUE);
			else if ((map[player_y][player_x] == '0' || map[player_y][player_x] == 'E' || map[player_y][player_x] == 'W'
			|| map[player_y][player_x] == 'N' || map[player_y][player_x] == 'S'))
				draw_square(cub, player_x, player_y, WHITE);
			if (map[player_y][player_x] == 'D')
				draw_square(cub, player_x, player_y, DARK_GREEN);
			if (map[player_y][player_x] == 'O')
				draw_square(cub, player_x, player_y, GREEN);
//			else if (cub->add_minimap)
//				draw_square(cub, x, y, 0x000000);
			player_x++;
		}
		player_y++;
	}
	put_player(cub, cub->player->x, cub->player->y, RED);
	//if (cub->add_minimap)
	//	mlx_put_image_to_window(cub->mlx, cub->win, data->img_map->img_ptr, 1, 1);
	return (1);
}