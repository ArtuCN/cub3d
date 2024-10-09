/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:22:01 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 17:29:21 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	while_square(t_cub *cub, int mini_x, int mini_y, unsigned int color)
{
	int	i;
	int	j;

	j = mini_y;
	while (j <= mini_y + (TXT_SIZE * SCALE_FACTOR))
	{
		i = mini_x;
		while (i <= mini_x + (TXT_SIZE * SCALE_FACTOR))
		{
			if ((i == (int)mini_x) || (j == (int)mini_y))
				my_mlx_pixel_put(cub, i, j, BLACK);
			else
				my_mlx_pixel_put(cub, i, j, color);
			i++;
		}
		j++;
	}
}

int	draw_square(t_cub *cub, int x, int y, unsigned int color)
{
	int	offset_x;
	int	offset_y;
	int	minimap_x;
	int	minimap_y;

	offset_x = cub->player->x * SCALE_FACTOR
		- (MINI_WIDTH * SCALE_FACTOR) / 2;
	offset_y = cub->player->y * SCALE_FACTOR
		- (MINI_HEIGHT * SCALE_FACTOR) / 2;
	minimap_x = x * (TXT_SIZE * SCALE_FACTOR) - offset_x + MINIMAP_X;
	minimap_y = y * (TXT_SIZE * SCALE_FACTOR) - offset_y + MINIMAP_Y;
	while_square(cub, minimap_x, minimap_y, color);
	return (1);
}

void	single_square(t_cub *cub, char **map, int p_x, int p_y)
{
	if (map[p_y][p_x] == '1')
		draw_square(cub, p_x, p_y, BLUE);
	else if ((map[p_y][p_x] == '0' || map[p_y][p_x] == 'E'
		|| map[p_y][p_x] == 'W' || map[p_y][p_x] == 'N'
		|| map[p_y][p_x] == 'S'))
		draw_square(cub, p_x, p_y, WHITE);
	if (map[p_y][p_x] == 'D')
		draw_square(cub, p_x, p_y, DARK_GREEN);
	if (map[p_y][p_x] == 'O')
		draw_square(cub, p_x, p_y, GREEN);
}

void	in_while_map(t_cub *cub, int p_x, int p_y, char **map)
{
	int	final_x;
	int	final_y;

	final_y = p_y + 6;
	while (map[p_y] && p_y <= final_y)
	{
		p_x = (int)(cub->player->x * SCALE_FACTOR)
			/ (TXT_SIZE * SCALE_FACTOR);
		if (p_x < 3)
			p_x = 0;
		else
			p_x -= 3;
		final_x = p_x + 6;
		while (map[p_y][p_x] && p_x <= final_x)
		{
			single_square(cub, map, p_x, p_y);
			p_x++;
		}
		p_y++;
	}
}

int	draw_minimap(t_cub *cub, t_data *data, char **map)
{
	int	player_x;
	int	player_y;

	player_x = (int)(cub->player->x * SCALE_FACTOR)
		/ (TXT_SIZE * SCALE_FACTOR);
	player_y = (int)(cub->player->y * SCALE_FACTOR)
		/ (TXT_SIZE * SCALE_FACTOR);
	(void)data;
	if (!cub->add_minimap)
		return (0);
	if (player_y < 3)
		player_y = 0;
	else
		player_y -= 3;
	in_while_map(cub, player_x, player_y, map);
	put_player(cub, cub->player->x, cub->player->y, RED);
	return (1);
}
