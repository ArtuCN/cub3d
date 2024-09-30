/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:14:11 by aconti            #+#    #+#             */
/*   Updated: 2024/09/30 16:56:26 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	find_player_pos(t_cub *cub, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->player_dir)
			{
				cub->player->x = (x + 0.5);
				cub->player->y = (y + 0.5);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	set_angle(t_player *player, t_data *data)
{
	if (data->player_dir == 'N')
		player->angle = 270;
	else if (data->player_dir == 'S')
		player->angle = 90;
	else if (data->player_dir == 'W')
		player->angle = 180;
	else if (data->player_dir == 'E')
		player->angle = 0;
}

void	player_init(t_cub *cub)
{
	if (!cub->player)
	{
		free(cub->mlx);
		free(cub->win);
		free(cub->img);
		return ;
	}
	cub->player->ray = malloc(sizeof(t_ray) * WIDTH);
	cub->player->num_rays = WIDTH;
	cub->player->increment = 60L / (long double)WIDTH;
	set_angle(cub->player, cub->data);
	find_player_pos(cub, cub->data);
}
