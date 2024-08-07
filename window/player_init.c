/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:14:11 by aconti            #+#    #+#             */
/*   Updated: 2024/08/07 14:35:34 by aconti           ###   ########.fr       */
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
				cub->player->x = fmap(x, WIDTH, data->max_x);
				cub->player->y = fmap(y, HEIGHT, data->max_y);
				return ;
			}
			x++;
		}
		y++;
	}
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
	find_player_pos(cub, cub->data);
}
