/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:34:37 by aconti            #+#    #+#             */
/*   Updated: 2024/10/08 17:34:40 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_rays_minimap(t_cub *cub, int x, int y)
{
	int			i;
	long double	temp_ang;
	double		minimap_x;
	double		minimap_y;

	temp_ang = (long double)(cub->player->angle - 29);
	while (temp_ang <= cub->player->angle + 30)
	{
		i = -1;
		minimap_x = x * SCALE_FACTOR - cub->data->offset_x + MINIMAP_X;
		minimap_y = y * SCALE_FACTOR - cub->data->offset_y + MINIMAP_Y;
		while (++i <= 10)
		{
			minimap_x += 5 * cos(temp_ang * PI / 180);
			minimap_y += 5 * sin(temp_ang * PI / 180);
			if ((int)minimap_x < 0 || (int)minimap_y < 0
				|| (int)minimap_x >= MINI_WIDTH || (int)minimap_y >= MINI_HEIGHT
				|| is_wall_minimap(minimap_x + cub->data->offset_x,
					minimap_y + cub->data->offset_y, cub))
				break ;
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
	int	minimap_x;
	int	minimap_y;

	minimap_x = x * SCALE_FACTOR - cub->data->offset_x + MINIMAP_X;
	minimap_y = y * SCALE_FACTOR - cub->data->offset_y + MINIMAP_Y;
	cub->data->offset_x = x * SCALE_FACTOR
		- (MINI_WIDTH * SCALE_FACTOR) / 2;
	cub->data->offset_y = y * SCALE_FACTOR
		- (MINI_HEIGHT * SCALE_FACTOR) / 2;
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
	draw_rays_minimap(cub, x, y);
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
	return (1);
}

int	is_wall(long double x, long double y, t_cub *cub)
{
	long double	j;
	long double	i;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return (1);
	j = (y / TXT_SIZE);
	i = (x / TXT_SIZE);
	if (cub->data->map[(int)j][(int)i] == '1'
		|| cub->data->map[(int)j][(int)i] == '\n'
		|| !cub->data->map[(int)j][(int)i]
		|| cub->data->map[(int)j][(int)i] == 'D')
		return (1);
	return (0);
}

int	is_wall_minimap(long double x, long double y, t_cub *cub)
{
	long double	j;
	long double	i;

	x /= SCALE_FACTOR;
	y /= SCALE_FACTOR;
	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return (1);
	j = (y / TXT_SIZE);
	i = (x / TXT_SIZE);
	if (cub->data->map[(int)j][(int)i] == '1'
		|| cub->data->map[(int)j][(int)i] == '\n'
		|| !cub->data->map[(int)j][(int)i]
		|| cub->data->map[(int)j][(int)i] == 'D')
		return (1);
	return (0);
}
