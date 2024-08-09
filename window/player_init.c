/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:14:11 by aconti            #+#    #+#             */
/*   Updated: 2024/08/09 09:55:01 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	find_player_pos(t_cub *cub, t_data *data)
{
	int y;
	int x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->player_dir)
			{
				cub->player->x = x * (WIDTH / 50);
				cub->player->y = y * (HEIGHT / 50);
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
		player->angle = 0;
	else if (data->player_dir == 'S')
		player->angle = 180;
	else if (data->player_dir == 'W')
		player->angle = 270;
	else if (data->player_dir == 'E')
		player->angle = 90;
}

void	player_init(t_cub *cub)
{
	t_player *player;
	player = malloc(sizeof(t_player));
	cub->player = player;
	if (!cub->player)
	{
		free(cub->mlx);
		free(cub->win);
		free(cub->img);
		return ;
	}
	set_angle(cub->player, cub->data);
	find_player_pos(cub, cub->data);
}
